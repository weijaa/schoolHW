#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main()
{
	srand(time(NULL));
	int num[100],i,x,a;
	
	for(i=0;i<100;i++)
	{
		num[i] =(rand()%1000);
		
		for(x=0 ; x < i ; x++)
		{
			if(num[x] == num[i])
			{
				num[i] = (rand()%1000);
				x=-1;
			}
			
		}
	}
	for(i=0;i<100;i++)
	{
		for(x=0;x<i;x++)
		{
			if(num[i] < num[x])
			{
				a = num[i];
				num[i] = num[x];
				num[x] = a;
			}
		}
	}
	
	printf("材竤<Ю计0>\n");
	for(i=0;i<100;i++)
	{
		if(num[i]%10==0)
		{
			printf("%d ", num[i]);
		}
	}
	printf("\n");
	printf("材竤<Ю计1>\n");
	for(i=0;i<100;i++)
	{
		if(num[i]%10==1)
		{
			printf("%d ", num[i]);
		}
	}
	printf("\n");
	printf("材竤<Ю计2>\n");
	for(i=0;i<100;i++)
	{
		if(num[i]%10==2)
		{
			printf("%d ", num[i]);
		}
	}
	printf("\n");
	printf("材竤<Ю计3>\n");
	for(i=0;i<100;i++)
	{
		if(num[i]%10==3)
		{
			printf("%d ", num[i]);
		}
	}
	printf("\n");
	printf("材き竤<Ю计4>\n");
	for(i=0;i<100;i++)
	{
		if(num[i]%10==4)
		{
			printf("%d ", num[i]);
		}
	}
	printf("\n");
	printf("材せ竤<Ю计5>\n");
	for(i=0;i<100;i++)
	{
		if(num[i]%10==5)
		{
			printf("%d ", num[i]);
		}
	}
	printf("\n");
	printf("材竤<Ю计6>\n");
	for(i=0;i<100;i++)
	{
		if(num[i]%10==6)
		{
			printf("%d ", num[i]);
		}
	}
	printf("\n");
	printf("材竤<Ю计7>\n");
	for(i=0;i<100;i++)
	{
		if(num[i]%10==7)
		{
			printf("%d ", num[i]);
		}
	}
	printf("\n");
	printf("材竤<Ю计8>\n");
	for(i=0;i<100;i++)
	{
		if(num[i]%10==8)
		{
			printf("%d ", num[i]);
		}
	}
	printf("\n");
	printf("材竤<Ю计9>\n");
	for(i=0;i<100;i++)
	{
		if(num[i]%10==9)
		{
			printf("%d ", num[i]);
		}
	}
	return 0;
 } 
