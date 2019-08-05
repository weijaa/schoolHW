#include <iostream>

using namespace std;

int main(int argc, char** argv) 
{
/*	int a ;
	int b ;
	int c;
	cout << "please enter a:" ;
	cin >>a ;
	cout << "plaese enter b:";
	cin >> b;
	cout << "please enter c:" ;
	cin >> c;
	if( a+b>=c && a+c>=b && b+c>=a)
{
	cout << "yes" <<endl;
}
	else 
{
	cout << " no " << endl;
}*/
	int a , b , c ;
	while (cin >> a >> b >> c )
{
	if (a+b >= c && a+c >= b && b+c >=a )
{
	cout << "yes" << endl;
}
	else 
{
	cout << "no " << endl;
}
}
	
	
	
	 
	
	return 0;
}
