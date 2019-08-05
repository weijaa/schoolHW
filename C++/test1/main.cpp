#include <iostream>

using namespace std;

int main(int argc, char** argv) 
{	
	int month , day;
	/*month = 12;
	day = 31;*/
	/*cout << month << " " << day << endl;*/
	
	for(month=12 ,day=31  ; day>=1,month>=1  ;month= month-1 , day = day -2) // 會超過的要放後面 
	{ 
	cout << month << "/" << day <<  endl;
	}
/*	cout << month << "/" << day << endl;
	month = month - 1;
	day = day - 2;
	cout << month << "/" << day << endl;
	month = month - 1;
	day = day - 2;
	cout << month << "/" << day << endl;
	month = month - 1;
	day = day - 2;
	cout << month << "/" << day << endl;
	month = month - 1;
	day = day - 2;
	double circle;
	circle = 3.14159;
	cout << month << "/" << day << "=" << circle << endl;
	string name1 , name2;
	name1 = "lebron";
	name2 = "james";
	cout << name1 << " " << name2 << endl;
	string twoname;
	twoname = name1 + " " + name2;
	cout << twoname << endl;
	cout << month << twoname << day << "@#$%" << circle<< endl;*/ 
	 
	
	return 0;
}
