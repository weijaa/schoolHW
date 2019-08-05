#include <iostream>

using namespace std;

int main(int argc, char** argv) 
{	
	int x1;
	int A=10, B=11 ,C=12, D=13 ,E=14 , F=15;
	int B1;
	int B2;
	int X2;
	int r,x,i;
	int num[100];
	cout << "number:" ;
	cin >> x1;
	
	cin >> B1;
	r=x1/B1;
	x=x1%B1;
	i=r*10+x;
	cout << r*10+x << endl;
	
	cin  >> B2;
	r= i/B2;
	x= i%B2;
	i=r*10+x;
	cout << r*10+x;
	
	
	
	
	
	
	return 0;
}
