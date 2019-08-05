#include<stdio.h>
#include<string.h>

#define bigInt 21

int main()
{
	char array[5][bigInt],num[bigInt],x[5][21];
	int k[21],i,j,a;
	memset(num,'0',sizeof(num)-1);
	
	for(i=0;i<5;i++)
	{
		scanf("%s", array[i]);
	}
	
	for(i=0;i<5;i++)
	{
		k[i] = strlen(array[i]);
		printf("%d\n", k[i]);
		strcpy(x[i],array[i]);
	}
	
	for(i=0;i<5;i++)
	{
		for(j=20-k[i],a=0;j<20,a<=k[i];j++,a++)
		{
			array[i][j] = x[i][a];
		}
	 } 
	
	for(i=0;i<5;i++)
	{
		for(j=0;j < 20-k[i];j++)
		{
			
				array[i][j] = '0';
			
		}
	}
	
	for(i=0 ;i< 5 ;i++)
	{
		printf("%s\n",array[i]);
	}
	
	for(i=0;i<5;i++)
	{
		for(j=19;j>=0;j--)
		{
			num[j] = num[j]+ (array[i][j]-48);
			if(num[j]>57)
			{
				
				num[j]= num[j] - 10; 
				num[j-1]++;
			}
		
		}
	}
	for(i=0;i<20;i++)
	{
		if(num[i] != '0')
		{
			for(j=i;j <20; j++)
			{
				printf("%c",num[j]);
			}
			break;
		}
		
	}
	
	return 0;
 } 
