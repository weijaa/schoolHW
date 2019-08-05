#include <iostream>

using namespace std;
int main(int argc, char** argv) 
{
	int student[100];
	int i, x;
	cin >> x;
	i=0;
	while (i<x)
{	
	cin >> student[i];
	i=i+1;
}
	i=i-1;
	while ( i >=0)	
{
	cout << student [i] << " ";
	i=i-1;
} 
	
	
	
	return 0;
}
