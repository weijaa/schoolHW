#include <iostream>

using namespace std;

int main(int argc, char** argv) 
{
	
	int boy;
	int girl;
	cout << "please enter boy age " ;
	cin >> boy;

	if ( boy >= 18 )
{
	cout << "you are marriageable " << endl;
}
   if ( boy <= 17 )
{
	cout << " You are not marriageable" << endl;
}

	cout << "please enter girl age ";
	cin >> girl;
	if ( girl >= 16 )
{
	cout << "you are marriageable " << endl;
}
	if ( girl <= 15 )
{
	cout << "you are not marriageable " << endl;
}












	return 0;
}
