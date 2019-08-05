#include<stdio.h> 

int value=10;
void pro_one() {
 int one_1;
 int one_2;
 { 
 int one_3; //\\ ¢u inner scope 1
 int one_4; //\\ ¢x
 } 
}
void pro_two() {
 int two_1;
 int two_2;
}
int main(){
	
	
	
	return 0;
}
