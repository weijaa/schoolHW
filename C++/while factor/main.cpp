#include <iostream>

using namespace std;

int main(int argc, char** argv) 
{
	int n , factor ;
	factor = 1;
	cout << "please enter  a number :";
	cin >> n;
	while ( factor <= n)
{
	if ( n%factor == 0)
{
	
	cout << factor << " "  ;
}

	factor = factor +1;
}

	
	
	
	
	
	return 0;
}
