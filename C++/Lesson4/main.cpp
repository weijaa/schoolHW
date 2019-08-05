#include <iostream>

using namespace std;

int main(int argc, char** argv) 
{
	int age ;
	while (age<18)
	{
		cout << "Please enter your age:";
		cin >> age;
	}

	
	/*do
	{
		cout << "Please enter your age:";
		cin >> age;
	} while(age<18);*/ 
	
	cout << "your are old Enough" << endl;
	
	/*int data [4]={1,2,3,4};
	cout << data[0] << endl;
	cout << data[1] << endl;
	cout << data[2] << endl;
	cout << data[3] << endl;
	cout << data[4] << endl;//編譯沒錯 但邏輯有問題 
	cout << data[5] << endl; //同4*/ 
	/*for (int i = 2; i <= 5; i ++)
	{
		data[i] = i; 
	}
	for (int i = 2; i <= 5; i ++)
	{
		cout << data[i] << endl;
	}*/ 
	
	
	
	
	
	
	return 0;
}
