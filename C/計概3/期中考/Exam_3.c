#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {

    //a �O���l
    //b �O����
    //with �O�Y��
    //a is numerator
    //b is denominator
    //c is integer part
    unsigned long long int a;
    unsigned long long int b;
    unsigned long long int with;
} node;

unsigned long long int gcd (unsigned long long int,unsigned long long int );
void solution(FILE *, struct node*);

int main(int argc, char *argv[]) {
    // �D�{���w�w�q�����A�L�ݰ�������
	// The main program has been completed and the code cannot be changed.
	node *ptr = NULL;
    ptr = (node *)realloc(ptr, sizeof(node));
    FILE *fp;
    if (argc == 2)
        fp = fopen(argv[1], "r");
    else
        fp = fopen("input.txt", "r+");
    solution(fp, ptr);
    return 0;
}

void solution(FILE *fp, struct node *ptr) {
    /*******Fix start*******/
    // �����ƭ��k
    // Complete fractions multiplication

    // ���׳z�Lptr���е���
    // Use ptr pointer to assign your answer

    // �L�X���� �d�ҡG1+2/3
    // print out answer, for example: 1+2/3

    /*******Fix end*******/
    printf("%llu+%llu/%llu", ptr->with, ptr->a, ptr->b);
}

unsigned long long int gcd ( unsigned long long int a, unsigned long long int b )
{
    /*******Fix start*******/
    // �λ��j�� gcd�A��return����
    // Use recursive to complete gcd function, and return your gcd answer.

    /*******Fix end*******/
}
