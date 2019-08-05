#include <iostream>

using namespace std;

int main(int argc, char** argv) 
{
		int N[100], T[1000];
	int x,i,z; 
	cout << "please enter clients number:" ;
	
	for (x=0 ; x <= 100 ; x= x+1)
{	
	N[x] =0;
}
	
	while( cin >> x)
{

	cout << "1 is deposit money , 2 is take money out :" ;
	cin >> i;
	if ( i==1)
{ 	
	cout << "plaese enter the figure: ";
	cin >> z;
	N[x] = N[x] + z;
}
	if( i==2)
{
	cout << "plaese enter the figure: ";
	cin >> z;
	N[x] = N[x] - z;
}
	cout << "there " << N[x] << "dollor in the bank" << endl; 
	cout << "please enter clients number:" ;
} 
	
	
	return 0;
}
