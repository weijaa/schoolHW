#include <iostream>

using namespace std;

int main(int argc, char** argv) 
{
		int a,b;
	while (cin >> a >> b)
{ 
	if( a ==7 && b >=30 && b <= 60 || a<17 && b <=60  && a >=8)
{
	 cout << " at school " << endl;
}
	else
{
	cout << " Off school " <<endl;
}
}
	return 0;
}
