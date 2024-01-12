#include <iostream>
#define Log(x) std::cout<<x<<std::endl

void AddIntegers(int x, int y) {
	Log(x + y);
}

void ReverseString() {
	std::string str;
	std::cin >> str;
	int str_len = str.length();
	for (int i = str_len - 1; i >= 0; i--) {
		Log(str[i]);
	}
}

void DoubleNum() {
	int nums[5];
	int mod_nums[5];
	for (int i = 0; i < 5; i++)
	{
		std::cin >> nums[i];
		mod_nums[i] = nums[i] * 2;
		Log(mod_nums[i]);
	}
	for (int i = 0; i < 5; i++)
	{
		Log(mod_nums[i]);
	}
	
}

void EvenOrOdd(int num) {
	if (num % 2 == 0)
	{
		Log("Even");
	}
	else
		Log("Odd");
}

void PointerBasics(int num) {
	int* ptr = &num;
	*ptr = 39;
	Log(num);
}

void ArrayOperations() {
	int arr1[5]{ 1,2,3,4,5 };
	int arr2[5]{ 2,4,6,8,10 };
	int arr3[5];
	for (int i = 0; i < 5; i++)
	{
		arr3[i] = arr1[i] + arr2[i];
		Log(arr3[i]);
	}
}

void StringAddition() {
	const char* str1 = "Hello";
	const char* str2 = " Salman";

	size_t size1 = 0;
	while (str1[size1] != '\0')
	{
		++size1;
	}

	size_t size2 = 0;
	while (str2[size2] != '\0')
	{
		++size2;
	}
	
	size_t TotalSize = size1 + size2 + 1; // +1 for the null terminator

	char* result = new char[TotalSize];

	for (size_t i = 0; i < size1; i++)
	{
		result[i] = str1[i];
	}

	for (size_t i = 0; i < size2; i++)
	{
		result[size1 + i] = str2[i];
	}

	result[TotalSize-1] = '\0';

	Log(result);

	delete[] result;
}

void FibonnaciSeq() {
	int num1 = 0;
	int num2 = 1;
	int num3;
	Log(num1);
	Log(num2);
	for (int i = 0; i < 10;i++)
	{
		num3 = num1 + num2;
		Log(num3);
		num1 = num2;
		num2 = num3;
		

	}
}

int main() {
	std::cin.get();
}