#include <iostream>

using namespace std;

int main(int argc, char** argv) 
{
	int age;
	string word1,word2,word3;
	word1 ="You are not allow to smoke";
	word2 = "You can smoke";
	word3 = "Error age";
	cout << "Plaese enter your age ";
	cin >>age;
	if(age < 18 && age>=0)
{
	cout <<word1 <<endl;
	
}
	else if (age>=18 && age < 100)
{
	cout << word2 << endl;
}
	else 
{
	cout <<word3;
}
	
	
	return 0;
}
