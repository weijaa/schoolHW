#include <iostream>

using namespace std;

const int NUM_ROWs = 6;
const int NUM_COLs = 5;
typedef int ArrayType [NUM_ROWs] [NUM_COLs];

struct TwoDArray //�۩w�q�ƾ����� 
{
	int rowsFilled; //�Τ��ڿ�J�Ʀr�q 
	int colsFilled;
	ArrayType table; 
};

void PrintArray(TwoDArray structure);

int main(int argc, char** argv) 
{
	TwoDArray structure;
	
	/*cout<< "Enter the number of rows" << endl;
	cin >> structure.rowsFilled;
	cout<< "Enter the number of cols" << endl;
	cin >> structure.colsFilled;*/
	cout << "Enter the number of rows and cols:" << endl;
	cin >> structure.rowsFilled >> structure.colsFilled;
	//cout << "Rows =" << structure.rowsFilled << endl; //���ռƾڬO�_���T�g�J 
//	cout << "cols =" << structure.colsFilled << endl;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
