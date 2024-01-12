#include <iostream>
#include <vector>
#include <string>

class Task {
public:
	int s_no;
	std::string task;
	std::string time;
	
	Task(int s_no,const std::string& task,const std::string& time) : s_no(s_no), task(task),time(time) 
	{}
};

std::ostream& operator<< (std::ostream& stream, const Task& task) {
	stream << "\n";
	stream << "S_no : " << task.s_no << "\n";
	stream << "Task : " << task.task << "\n";
	stream << "Time : " << task.time << "\n";
	return stream;
}

class ToDoList {
private:
	std::vector<Task> tasks;
public:
	void AddTask(Task& task) {
		tasks.emplace_back(task);
		std::cout << "Task Added Successfully!" << std::endl;
	}

	void DeleteTask(Task& task) {
		for (int i = 0; i < tasks.size(); i++) {
			if (tasks[i].s_no == task.s_no) {
				tasks.erase(tasks.begin() + i);
				std::cout << "Deleted Successfully!" << std::endl;
				break;  // break out of the loop after erasing the element
			}
		}
	}

	void ViewTasks() {
		for (int i = 0; i < tasks.size(); i++)
		{
			std::cout << tasks[i] << std::endl;
		}
	}
};



int main() {
	ToDoList testToDo;

	Task t1(1,"Washing Dishes", "5 PM");
	testToDo.AddTask(t1);
	Task t2(2,"Cleaning Desk", "6 PM");
	testToDo.AddTask(t2);
	Task t3(3,"Make Bed", "10 PM");
	testToDo.AddTask(t3);

	testToDo.ViewTasks();
}