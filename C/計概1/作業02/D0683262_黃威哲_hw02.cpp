#include<stdio.h>


int main ()
{
	int a,b,c;
	float e,f,g;
	
	printf("please enter A:");
	scanf("%d" , & a);
	
	printf("please enter B:");
	scanf("%d" , & b);
	
	printf("please enter C:");
	scanf("%d" , & c);
	
	if( (2*c) !=0 ) 
	{
		e=(double)(5*a+3*b)/(2*c);
		printf("一式解:%.2f\n" , e);
	}
	else if( (2*c) == 0)
	{
		printf("error!\n"); 
	}
	 if ( (c-b) !=0)
	{
	
		f=(double)(a+3*(b-c))/(c-b);
		printf("二式解:%.2f\n" , f);
	}
	else if ( (c-b) == 0 ) 
	{
		printf("error!\n"); 
	}
	
	 if ( (((b+2)*c)-2) !=0)
	{
	
		g=(double)(3*b+5*a)/(((b+2)*c)-2);
		printf("三式解:%.2f\n" , g);
	}

	else if ( (((b+2)*c)-2) == 0) 
	{
		printf("error!\n"); 
	}
	
	
	
	
	return 0;
 } 
