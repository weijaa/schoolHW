#include<stdio.h>
#include<stdlib.h>

// 宣告結構
// Declear this structure
typedef struct node{
    /*******Fix start*******/
	// 定義此結構
	// 至少需要有 num 變數記錄分區編號
    // Define this structure
    // At least need a variable called "num" to record zone number.

	/******Fix end*******/
}NODE;

// 新增一節點，傳入值為分區的編號
// Add a new nodw, parameter is zone number
NODE* GenerateNode(int n){
	NODE *new_node;
	/*******Fix start*******/
	// 請實作
    // Please complete this function

	/******Fix end*******/
	return new_node;
}

int solution(int n, int m){

	int ans;
    /*******Fix start*******/
	// 將1 ~ n個分區以環狀鏈結串列實作(即最後一個 node->next 需要指向 head)
	// 設計演算法透過這個副函式回傳正確的解ans
	// 提示: 題目不要求實作環狀鏈結串列的刪除，可用標記的方法紀錄已停水過的區域。
    // Use singal direction circle linked list to complete this function.(It means the last node's next need point to head)
    // Design a algorithm to slove the question and return the answer by variable "ans".
    // Hint: This question do not ask to implement delete node from circle linked list, so you can just make a mark to record it.

	/******Fix end*******/
	return ans;
}

int main(){
	// 主程式已定義完成，無需做任何更動
	// The main program has been completed and the code cannot be changed.
	int i, k, n, m;
	scanf("%d", &k);
	for(i=0; i<k; i++){
		scanf("%d %d", &n, &m);
		printf("%d\n", solution(n, m));
	}

	return 0;
}

