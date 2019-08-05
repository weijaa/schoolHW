#include <iostream>

using namespace std;

int S(int M, int D);

int main(int argc, char** argv) 
{
	int month;
	int day ;
	int X;
	cout << "Please enter month:" ;
	cin >> month;
	cout << " Please enter day:" ;
	cin >> day; 
	X= S(month,day);
	if(X==0)
{
	cout << " ´¶³q" <<endl;
}
	else if (X==1)
{
	cout << " ¦N " << endl;
}
	else if( X == 2)
{
	cout << " ¤j¦N" << endl;
}
	
	
	
	return 0;
}
 S (int M,int D)
{
	int S;
	return S = (M*2+D)%3 ; 
}






