#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �ŧi���c
// Declear this structure
typedef struct node{
    /*******Fix start*******/
	// �w�q�����c
    // Define this structure

    /******Fix end*******/
}NODE;

// �s�W�@�`�I
NODE* GenerateNode(int num, char name[]){
	NODE *new_node;
    /*******Fix start*******/
	// �O����t�m
    // Allocate memory

	// �]�w���X
    // Set number

	// �]�w�W�r
    // Set Name

    /******Fix end*******/
	return new_node;
}

// �̷Ӹ��X�Ƨ�
// Sort by number
NODE* SortList(/*******Fix here:�ۦ�]�w(Set by Yourself)*******/) {
    NODE* temp;
    NODE* curr = head;
    NODE* prev = head;
    NODE* tail = NULL;

    while(head != tail) {
        curr = head;
        prev = head;

        while(curr != NULL && curr -> next != NULL && curr -> next != tail) {

        	// �ݭn�洫
            // Need to change
            if((curr -> num) > (curr -> next -> num)) {
                /*******Fix start*******/
            	// �����P�_�����e
                // Complete this condition content

                /*******Fix end*******/
            }

            // ���ݥ洫�A���ܤU�@��
            // Do not need to change, go to the next node
			else {
				/*******Fix start*******/
            	// �����P�_�����e
                // Complete this condition content

                /*******Fix end*******/
            }
        }

        tail = curr;
    }

    return /*******Fix here:�ۦ�]�w(Set by Yourself)*******/;
}


int main(int argc, char *argv[]){
	FILE *inptr = NULL, *outptr = NULL;
    NODE *head = NULL, *current, *temp_node, *sorting_head = NULL;
    int i = 0, num = 0, temp = 0;
    char ch, name[20], digit[20];

	memset(name, '\0', sizeof(name));
	memset(digit, '\0', sizeof(digit));

	// �ɮ׫���
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

	// Ū��
    // Read file
	while( /*******Fix here:�����P�_��(Complete this condition)*******/){
		/*******Fix start*******/
		// �I�s�禡�A�s�W�`�I
        // Call subroutine and create new node

        /*******Fix end*******/
	}

	// �I�s�禡�i��Ƨ�
    // Call subrouutine to sort
	sorting_head = SortList( /*******Fix here:�ۦ�]�w(Set by Yourself)*******/ );

	current = sorting_head;
	while( /*******Fix here:�����P�_��(Complete this condition)*******/){
		/*******Fix start*******/
		// �g��
        // Write file

        /*******Fix end*******/
	}


    /*******Fix start*******/
    //�����ɮ�

    /*******Fix end*******/
	return 0;
}



