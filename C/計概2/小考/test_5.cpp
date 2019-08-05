#include<stdio.h>

int fofx(int x);

int main()
{
	int time,x=0,r,i;
	
	scanf("%d\n",&time);
	
	
	while(x < time)
	{
		
		scanf("%d", &r);
		
		printf("%d = ", r);
		for(i=22;i>=0;i--)
		{
			if(r >= fofx(i) )
			{
				printf("1");
				r = r - fofx(i);
				break;
			}
		}
		i--;
		for(i;i>=0;i--)
		{
			if(r>=fofx(i))
			{
				printf("1");
				r = r - fofx(i);
			}
			else if(r < fofx(i))
			{
				printf("0");
			}
		}
		printf("\n");
		x++;
	}
	return 0;
 } 
 
 int fofx(int x)
 {
 	if (x==0)
 	{
 		return 1;
	}
	else if(x == 1)
	{
		return 2;
	}
	else if (x > 1)
	{
		return fofx(x-1) + fofx(x-2);
	}
 }
 
 
 
 
 
