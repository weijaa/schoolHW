#include <iostream>

using namespace std;

const int NUM_ROWs = 6;
const int NUM_COLs = 5;
typedef int ArrayType [NUM_ROWs] [NUM_COLs];

struct TwoDArray //自定義數據類型 
{
	int rowsFilled; //用戶實際輸入數字量 
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
	//cout << "Rows =" << structure.rowsFilled << endl; //測試數據是否正確寫入 
//	cout << "cols =" << structure.colsFilled << endl;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
