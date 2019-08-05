#include<stdio.h>
#include<string.h>


int main()
{
	char ans[100],i;
	
	gets(ans);
	
//	printf("%d",strlen(ans));
	
	for(i=0;i<strlen(ans);i++)
	{
		if(ans[i] >= 'a' && ans[i] <= 'g')
		{
			ans[i] = ans[i] +26-7;		
		}
		else if(ans[i] >= 'h' && ans[i] <= 'z')
		{
			ans[i] = ans[i] -7;
		}	
	}
	for(i=0;i<strlen(ans);i++)
	{
		printf("%c", ans[i]);
	}
	
	
	return 0;
} 
