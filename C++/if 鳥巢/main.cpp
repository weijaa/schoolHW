#include <iostream>

using namespace std;

int main(int argc, char** argv) 
{
	int sex;
	int age;
	cout << "please enter your sex : (1 for man 2 for woman ) " ;
	cin >> sex;
	
	if ( sex == 1)
{	
	cout << " plaese enter your age : ";
	cin >> age ;
	if( age >= 18)
{ 	cout <<  "you are marriageable" << endl;}
	else
{	cout << "you are not marriageable" << endl;}

}
	if ( sex == 2)
{
	cout << " plaese enter your age : ";
	cin >> age;
	if ( age >= 16)
{	cout << "you are marriageable " << endl; }
	else 
{	cout << "you are not marriageable " << endl; }
}

	return 0;
}
