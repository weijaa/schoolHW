#include <iostream>

using namespace std ;

int Z (int Q , int A) ;

int main(int argc, char** argv) 
{
	int V,T,X ;
	cout << "Please enter speed and time : " << endl;
	cin >> V;
	cin >> T;
	cout << 2*T << " after you already pass " << Z(V,T) << " meter" << endl; 
	
	
	
	
	
	
	return 0;
}






int Z (int Q,int A)
{	
	
	return	 Q*2*2*A/2;
}



