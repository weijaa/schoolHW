#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 宣告結構
// Declear this structure
typedef struct node{
    /*******Fix start*******/
	// 定義此結構
    // Define this structure

    /******Fix end*******/
}NODE;

// 新增一節點
NODE* GenerateNode(int num, char name[]){
	NODE *new_node;
    /*******Fix start*******/
	// 記憶體配置
    // Allocate memory

	// 設定號碼
    // Set number

	// 設定名字
    // Set Name

    /******Fix end*******/
	return new_node;
}

// 依照號碼排序
// Sort by number
NODE* SortList(/*******Fix here:自行設定(Set by Yourself)*******/) {
    NODE* temp;
    NODE* curr = head;
    NODE* prev = head;
    NODE* tail = NULL;

    while(head != tail) {
        curr = head;
        prev = head;

        while(curr != NULL && curr -> next != NULL && curr -> next != tail) {

        	// 需要交換
            // Need to change
            if((curr -> num) > (curr -> next -> num)) {
                /*******Fix start*******/
            	// 完成判斷式內容
                // Complete this condition content

                /*******Fix end*******/
            }

            // 不需交換，移至下一個
            // Do not need to change, go to the next node
			else {
				/*******Fix start*******/
            	// 完成判斷式內容
                // Complete this condition content

                /*******Fix end*******/
            }
        }

        tail = curr;
    }

    return /*******Fix here:自行設定(Set by Yourself)*******/;
}


int main(int argc, char *argv[]){
	FILE *inptr = NULL, *outptr = NULL;
    NODE *head = NULL, *current, *temp_node, *sorting_head = NULL;
    int i = 0, num = 0, temp = 0;
    char ch, name[20], digit[20];

	memset(name, '\0', sizeof(name));
	memset(digit, '\0', sizeof(digit));

	// 檔案指標
	// File pointer
	if (argc == 2) {
        inptr = fopen(argv[1], "r+");
        outptr = fopen("output.txt", "w+");
    }
    else if (argc == 3) {
        inptr = fopen(argv[1], "r+");
        outptr = fopen(argv[2], "w+");
    }
    else {
        inptr = fopen("input.txt", "r");
        outptr = fopen("output.txt", "w+");
    }

    if (inptr == NULL)   {
        printf("file not found\n");
        return 0;
    }

	// 讀檔
    // Read file
	while( /*******Fix here:完成判斷式(Complete this condition)*******/){
		/*******Fix start*******/
		// 呼叫函式，新增節點
        // Call subroutine and create new node

        /*******Fix end*******/
	}

	// 呼叫函式進行排序
    // Call subrouutine to sort
	sorting_head = SortList( /*******Fix here:自行設定(Set by Yourself)*******/ );

	current = sorting_head;
	while( /*******Fix here:完成判斷式(Complete this condition)*******/){
		/*******Fix start*******/
		// 寫檔
        // Write file

        /*******Fix end*******/
	}


    /*******Fix start*******/
    //關閉檔案

    /*******Fix end*******/
	return 0;
}



