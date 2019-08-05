#include<stdio.h>



int main ()
{
	int a,b,c,d,high;

	
	printf("Please input a number:\n");
	scanf("%d" , & high);
	
	printf("\n( 1 )\n");
	
	for (a=1 ; a <= high ; a++)
	{	
		for(b=1 ; b <= high-a;  b++)
		{
			printf(".");
		}
		
		for(c=high; c < high+a  ; c++)
		{
			printf("*");
		}
		
		printf(" - %d\n", a);
	}
	
	for (a=high-1 ; a >= 1 ; a--)
	{
		for(c=high ; c>= 1+a; c --)
		{
			printf(".");
		}
		
		for(b=high ;b < high+a ; b++)
		{
			printf("*");
		}
	
		printf(" - %d\n", a);
	}

	printf("\n( 2 )\n");
	
	for (a=high ; a >= 1 ; a--)
	{
		
		for(b=1 ; b <high+1-a ; b++) 
		{
			printf(".");
		}
		
		for(c=1 ; c<= a*2  ; c=c+1)
		{
			printf("%d" ,high+1-b);
		}
		
		for(b=1 ; b <high+1-a ; b++) 
		{
			printf(".");
		}
		printf("\n");
	}
	
	for(a=1; a<= high-1 ; a++)
	{
		for(b=1; b < high-a;b++)
		{
			printf(".");
		}
		
		for(c=1 ; c<= a*2+2  ; c=c+1)
		{
			printf("%d" ,a+1);
		}

		for(b=1; b < high-a;b++)
		{
			printf(".");
		}
			
		printf("\n");
	}	
	return 0;
} 
