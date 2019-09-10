/*
	题目描述（此题未找到原型）
	输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数即999。
*/


class Solution {
public:
    void print1ToMaxOfNDigits(int n)
	{
        if(n <= 0)
			return;
		char *number = new char[n+1];
		for(int i = 0; i < n; i++)
			number[i] = '0';
		number[n] = '\0';
		
		print1ToN(number, 0);
		
		delete[] number;
    }
	
	void print1ToN(char *number, int digit)
	{
		if(digit == strlen(number))
		{
			printNumber(number);
			return;
		}
		for(int i = 0; i < 10; i++)
		{
			number[digit] = (char)('0'+i);
			print1ToN(number, digit+1);
		}
	}
	
	void printNumber(char *number)
	{
		int index = 0;
		while(index < strlen(number) && number[index] == '0')
			index++;
		while(index < strlen(number))
			std::cout << number[index++];
		std::cout << "\n";
	}
};


//以下为vc测试源代码

#include <iostream>

void printNumber(char *number)
{
	int index = 0;
	while(index < strlen(number) && number[index] == '0')
		index++;
	while(index < strlen(number))
		std::cout << number[index++];
	std::cout << "\n";
}

void print1ToN(char *number, int digit)
{
	if(digit == strlen(number))
	{
		printNumber(number);
		return;
	}
	for(int i = 0; i < 10; i++)
	{
		number[digit] = '0'+i;
		print1ToN(number, digit+1);
	}
}

void print1ToMaxOfNDigits(int n)
{
	if(n <= 0)
		return;
	char *number = new char[n+1];
	for(int i = 0; i < n; i++)
		number[i] = '0';
	number[n] = '\0';
	
	print1ToN(number, 0);
	
	delete[] number;
   }
	
int main()
{
	print1ToMaxOfNDigits(4);
	getchar();
	return 0;
}