#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char stack[20];
int top = -1;
void push(char x){
    stack[++top] = x;
}
 
char pop(){
    if(top == -1)
        return -1;
    else
        return stack[top--];
}
 
int priority(char x){
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
}
 
int main(){
    char num[20];
    char *n, x;
    scanf("%s",num);
    n = num;
    while(*n != '\0')
    {
        if(*n <= '9' && *n >= '0'){
            printf("%c",*n);
        }
        else if(*n == '('){
            push(*n);
        }
        else if(*n == ')'){
            while((x = pop()) != '('){
                printf("%c", x);
            }
        }
        else{
            while(priority(stack[top]) >= priority(*n)){
                printf("%c",pop());
            }
            push(*n);
        }
        n++;
    }
    while(top != -1)
    {
        printf("%c",pop());
    }
}
