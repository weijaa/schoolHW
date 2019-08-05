#include <iostream>

using namespace std;

int main(int argc, char** argv) 
{
		
	
	/*int i,n;
	i = 1;
	cout << "enter first number: " ;
	cin >> i;
	cout << "enter limit number :";
	cin >> n;
	while ( i <= n)
{

	cout << i << endl;
		i = i + 1;
	
}*/
/*	int a,b,i ;
	cout << "first student number : " ;
	cin >> i;
	
	while ( i <= 10)
{
	cin >> a >> b ;
	cout << a+b << endl;
	i = i +1;
	}*/
	int money,minute = 0 ;
	cout << "you have money:" ;
	cin >> money ;
	
	while ( money >= 39)
{
	money = money - 39;
	
	cout << minute << ":00 you ate a humburger" << endl;
	cout << "remain money : " << money << endl;
	minute = minute +5;
}
	
	return 0;
}
