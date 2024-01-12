#include <iostream>
#include <string>
#define Output(x) std::cout<<x<<std::endl

int num1, num2, result;

int Simple_Cal() {
	std::string oper;
	Output("Enter your number 1 : ");
	std::cin >> num1;
	Output("Enter your operator : ");
	std::cin >> oper;
	Output("Enter your number 2 : ");
	std::cin >> num2;

	result = (oper == "+") ? (num1 + num2) :
		(oper == "-") ? (num1 - num2) :
		(oper == "*") ? (num1 * num2) :
		(oper == "/") ? (num1 / num2) :
		(oper == "**") ? std::pow(num1,num2) :
		0; // Default Value

	return result;
}

int Square() {
	Output("Enter your number  : ");
	std::cin >> num1;
	return num1 * num1;
}

int Cube() {
	Output("Enter your number  : ");
	std::cin >> num1;
	return num1 * num1 * num1;
}

int SquareRoot() {
	Output("Enter your number  : ");
	std::cin >> num1;
	return sqrt(num1);
}

int CubeRoot(){
	Output("Enter your number  : ");
	std::cin >> num1;
	return std::cbrt(num1);
}

unsigned long long Factorial() {
	Output("Enter your number  : ");
	std::cin >> num1;
	unsigned long long f_result = 1;
	for (size_t i = 1; i <= num1; ++i)
	{
		f_result *= i;
	};
	return f_result;
}


int main() {
	std::string s_cont;
	std::string user_choice;
	Output("--------------WELCOME TO SHAPATAR CALCULATOR-------------");
	while (true)
	{
		Output("Choose the mode : ");
		Output("1 : Simple Calculation || Plus/Minus/Divide/Multiply/Exponential");
		Output("2 : Square");
		Output("3 : Cube");
		Output("4 : Square Root");
		Output("5 : Cube Root");
		Output("6 : Factorial (Only from 1 to 30)");

		std::cin >> user_choice;
		user_choice == "1" ? result = Simple_Cal() :
			user_choice == "2" ? result = Square() :
			user_choice == "3" ? result = Cube() :
			user_choice == "4" ? result = SquareRoot() :
			user_choice == "5" ? result = CubeRoot() :
			user_choice == "6" ? result = static_cast<int>(Factorial()) :
			0;



		Output("Answer is : ");
		Output(result);
		Output("\n");

		Output("Do you want to continue? ---- Enter Y to continue.....");
		std::cin >> s_cont;
		if (s_cont[0] != 'Y' && s_cont[0] != 'y')
		{
			break;
		}

	}
	std::cin.get();

}