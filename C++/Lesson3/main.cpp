#include <iostream>
#include <math.h>
using namespace std;

int square(int);
double seadragon(double,double,double);

int main (int argc, char** argv) 
{
	/*cout << "the square of 3 =" << square(3) <<endl;*/
/*	for (int a =10;a>=1;a=a-1)
{
	cout <<"the square of" << a << " = " << square(a) << endl;
	
	
}*/ 
/*	int count = 1;
	while (count<=10)
{
	cout <<"the square of" << count << " = " << square(count) << endl;
	count ++; // count = count +1
}*/ 
	
	
	
	
	cout<< "The seadragon is good ="<< seadragon(3,4,5)<< endl;
	return 0;
}


	int square(int x)
{
	return x*x;
}




	
double SeaDragon(double a,double b,double c)
{
	double p;
	double r;
	double x;
	p=(a+b+c)/2;
	r=(p*(p-a)*(p-b)*(p-c));
	x=sqrt(r);
	return x;
	
}
 
 
 
 
 
 
 
