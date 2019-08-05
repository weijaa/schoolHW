#include <stdio.h>
#include <stdlib.h>

typedef union{
    /*******Fix start*******/
    
    /*******Fix end*******/
}shape_length;

typedef enum{
    /*******Fix start*******/
    
    /*******Fix end*******/
}shape_type;

typedef struct shape{
    shape_type type;
    shape_length length;
    struct shape *next;
}__attribute__((packed))SHAPE;

void saveList(SHAPE *, FILE *);
SHAPE *createList(char *[]);
SHAPE *reloadList(FILE *,int);
void printList(SHAPE *);

int main(int argc, char *argv[])
{
    SHAPE *head = createList(argv);
    FILE *fw = fopen("shape.bin", "wb");
    saveList(head, fw);
    FILE *fr = fopen("shape.bin", "rb");
    head = reloadList(fr,atoi(argv[1])+atoi(argv[2]));
    printList(head);
}
SHAPE *createList(char *argv[]){
    /*******Fix start*******/
    
    /*******Fix end*******/
}
void saveList(SHAPE *head, FILE *f){
    /*******Fix start*******/
    
    /*******Fix end*******/
}
SHAPE *reloadList(FILE *f,int num){
    /*******Fix start*******/
    
    /*******Fix end*******/
}
void printList(SHAPE *head)
{
    /*******Fix start*******/
    
    /*******Fix end*******/
}
