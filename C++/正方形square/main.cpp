#include <iostream>
#include<math.h>
using namespace std;

int square (int);

int main(int argc, char** argv) 
{
	int n , x  ;
	cout << "please enter how long of one side:" ;
	cin >> n;
	for (x=1; x<=n; x=x+1)
{
	cout << "you have " << square(x)<< "squares" << endl;
}
/*	x=1;
	while ( n >= x)
{
	cout << "you have " << square(n)<< "squares" << endl;
	
}*/ 
	/*int n, i ,ans;//ans©Ç©Çªº 
	
	while(cin >> n)
{ 
	if( n==0)
	break;
	
	ans=0;
	i=0;
	while( i < n)
{ 
	ans =ans+(n-i)*(n-1);
	i=i+1;
}
 cout << ans <<endl;//©Ç©Çªº 
}*/ 
	
	return 0;
}

int square (int q)
{
	
	return q * (q+1) * (2*q+1) / 6;
}



