#include<stdio.h>
#include<stdlib.h>

// �ŧi���c
// Declear this structure
typedef struct node{
    /*******Fix start*******/
	// �w�q�����c
	// �ܤֻݭn�� num �ܼưO�����Ͻs��
    // Define this structure
    // At least need a variable called "num" to record zone number.

	/******Fix end*******/
}NODE;

// �s�W�@�`�I�A�ǤJ�Ȭ����Ϫ��s��
// Add a new nodw, parameter is zone number
NODE* GenerateNode(int n){
	NODE *new_node;
	/*******Fix start*******/
	// �й�@
    // Please complete this function

	/******Fix end*******/
	return new_node;
}

int solution(int n, int m){

	int ans;
    /*******Fix start*******/
	// �N1 ~ n�Ӥ��ϥH�����쵲��C��@(�Y�̫�@�� node->next �ݭn���V head)
	// �]�p�t��k�z�L�o�Ӱƨ禡�^�ǥ��T����ans
	// ����: �D�ؤ��n�D��@�����쵲��C���R���A�i�μаO����k�����w�����L���ϰ�C
    // Use singal direction circle linked list to complete this function.(It means the last node's next need point to head)
    // Design a algorithm to slove the question and return the answer by variable "ans".
    // Hint: This question do not ask to implement delete node from circle linked list, so you can just make a mark to record it.

	/******Fix end*******/
	return ans;
}

int main(){
	// �D�{���w�w�q�����A�L�ݰ�������
	// The main program has been completed and the code cannot be changed.
	int i, k, n, m;
	scanf("%d", &k);
	for(i=0; i<k; i++){
		scanf("%d %d", &n, &m);
		printf("%d\n", solution(n, m));
	}

	return 0;
}

