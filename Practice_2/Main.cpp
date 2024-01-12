#include <iostream>
#include<string>
#include <vector>

struct SingleTask {
	int sno;
	std::string task;
	std::string time;

};

std::ostream& operator<<(std::ostream& stream, const SingleTask& Task) {
	stream << Task.sno << " || " << Task.task << " || " << Task.time;
	return stream;
}

std::vector<SingleTask> ToDoList;

void PrintToDo() {
	for (int i = 0; i < ToDoList.size(); i++)
	{
		std::cout << ToDoList[i] << std::endl;
	}
}

void DeleteTaskFromToDo(int index) {
	ToDoList.erase(ToDoList.begin() + (index - 1));
}


int main() {
	ToDoList.push_back({ 1,"Wash Dishes","Evening" });
	ToDoList.push_back({ 2,"Wash Clothes","Evening" });
	ToDoList.push_back({ 3,"Wash Hands:)","Evening" });
	DeleteTaskFromToDo(2);
	PrintToDo();
}