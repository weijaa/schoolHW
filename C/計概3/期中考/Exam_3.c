#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {

    //a 是分子
    //b 是分母
    //with 是係數
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
    // 主程式已定義完成，無需做任何更動
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
    // 做分數乘法
    // Complete fractions multiplication

    // 答案透過ptr指標給值
    // Use ptr pointer to assign your answer

    // 印出答案 範例：1+2/3
    // print out answer, for example: 1+2/3

    /*******Fix end*******/
    printf("%llu+%llu/%llu", ptr->with, ptr->a, ptr->b);
}

unsigned long long int gcd ( unsigned long long int a, unsigned long long int b )
{
    /*******Fix start*******/
    // 用遞迴做 gcd，並return答案
    // Use recursive to complete gcd function, and return your gcd answer.

    /*******Fix end*******/
}
