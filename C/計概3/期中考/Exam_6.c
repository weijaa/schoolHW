#include <stdio.h>
#include <stdlib.h>

typedef struct rectangle{
    /*******Fix start*******/

    /*******Fix end*******/
}RECTANGLE;

RECTANGLE *createList(int);
RECTANGLE *bubbleSort(RECTANGLE *, int);
RECTANGLE *swap(RECTANGLE *, RECTANGLE *, RECTANGLE *);
void printList(RECTANGLE *);

int main(int argc, char *argv[])
{
    int n;
    RECTANGLE *first = createList(atoi(argv[1]));
    printf("0:exit, 1:sort by width, 2:sort by hight, 3:sort by area\n");
    while(scanf("%d",&n)==1&&n){
        first = bubbleSort(first, n-1);
        printList(first);
    }
    return 0;
}
RECTANGLE *createList(int total){
    /*******Fix start*******/

    /*******Fix end*******/
}
RECTANGLE *bubbleSort(RECTANGLE *start, int i)
{
    /*******Fix start*******/
    // 必須要使用RECTANGLE *swap(RECTANGLE *p, RECTANGLE *a, RECTANGLE *b)函數
    // You need to use function "RECTANGLE *swap(RECTANGLE *p, RECTANGLE *a, RECTANGLE *b)".

    /*******Fix end*******/
}
RECTANGLE *swap(RECTANGLE *previous, RECTANGLE *a, RECTANGLE *b)
{
    /*******Fix start*******/

    /*******Fix end*******/
}
void printList(RECTANGLE *start)
{
    /*******Fix start*******/

    /*******Fix end*******/
}
