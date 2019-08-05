#include<stdio.h>



int main()
{
	int num[10],i,k,j,t;
	
	for(i=0;i<=9;i++)
	{
		scanf("%d", &num[i]);
		if(num[i] == 0)
		{
			break;
		}
	}
	if(i > 9)
	{
		i = 9;
	}

	for(k=0;k<=i;k++)
	{
		for(j=0;j<=i;j++)
		{
			if(num[k] < num[j])
			{
				t = num[k];
				num[k] = num[j];
				num[j] = t;
			}
		}
	}
	for(k=0;k<=i;k++)
	{
		if(num[k] != 0)
		{
			printf("%d ", num[k]);
		}
	}
	printf("\n");
	for(k=0;k<=i;k++)
	{
		if(num[k] %2 == 1)
		{
			printf("%d ", num[k]);
		}
	}
	
	
	
	
	
	return 0;
 } 
