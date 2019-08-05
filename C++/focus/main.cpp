#include <iostream>

using namespace std;

int main(int argc, char** argv) 
{
	int n[100];
	int i,x;
	int num_max,num_min;
	cout << "how many student in your class" ;
	cin >> x; 
	i=0;
	while ( i <x)
{
	cin >> n[i];
	i=i+1;
}
	num_max =0;
	num_min=2000;
	i=0;
	while (i <x)
{
	if (n[i] > num_max)
	{ num_max =n[i];}
	
	
	if ( n[i] < num_min )
	{ num_min = n[i] ;}
	i=i+1;
}
cout << num_max  << " " << num_min << endl;
	return 0;
}
