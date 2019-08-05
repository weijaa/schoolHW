#include <iostream>

using namespace std;


int main(int argc, char** argv) 
{ 
	int grade;
	cout << "please enter your grade =" ;
	cin >> grade;
	if(  grade >= 60, grade<= 100)
{
	cout << "pass!" << endl;
}
 else if (grade <=59)
{
	cout << "fall" << endl;
}
  else if (grade >= 101) 
{
	cout << "error" << endl;
}
	return 0;
}
