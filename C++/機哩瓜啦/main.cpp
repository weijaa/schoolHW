#include <iostream>

using namespace std;

int main(int argc, char** argv) 
{
	int n;
	cout << " please enter n : " ;
	cin >> n;
	if ( n ==1)
{ 
	cout << n << endl ;
}
	else if (n%2)
{
	n=3*n+1;
	cout << n << endl;
}
	else 
{
	n=n/2;
	cout << n << endl;
}

	
	return 0;
}
