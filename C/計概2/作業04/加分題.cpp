#include<stdio.h>

int fofx(int);



int main()
{
	int n=1,t;
	printf("t = ");
 	scanf("%d",&t);
	
	while(n <= t)
	{
		printf("%3d  ",fofx(n));
		n++;
	}
	return 0;
 } 
 
 int fofx(int n)
 {
 	if(n%2==1)
 	{
 		n=n+2;
 		return n;
	}
	else if(n%2==0)
 	{
 		return n+fofx(n-1);
	}
 }
 
 
 
