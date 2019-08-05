#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int MAX = 1;

int convert(char s)
{
	int digit;
	
	if (s >= '0' && s <= '9')
	{
    	digit = s - '0';
	}
	
	return digit;
}

char* set()
{
	char temp, *str, *num = (char*)malloc(sizeof(char));
    int len = 0, i;
    
    while(len == 0)
    {
    	free(str);
    	while((temp = getchar()) != '\n')
    	{		
    	    str = (char*)calloc(len+1, sizeof(char));
    	    str[len] = convert(temp);
        
    	    for(i = 0; i < len; i++)
				str[i] = num[len - i - 1];
			
    	    free(num);
    	    num = (char*)calloc(len+1, sizeof(char));
        
    	    for(i = 0; i < len + 1; i++)
				num[i] = str[len - i];  
			
			len++;   
    	}
	}
		
	if(num[len - 1] == 0)
		return "-1";
	
    if(len > MAX)
    {
    	MAX = len;
	}
    
	return num;
}

char* recheck(char *num)
{
	char *str = (char*)calloc(MAX, sizeof(char));
    int len = strlen(num), i;
    
    if(len < MAX)
    {
    	for(i = 0; i < len; i++)
			str[i] = num[i];
			
		for(i = len; i < MAX; i++)
			str[i] = 0;
		
		return str;
	}
    
    return num;
}

char* add(char *num1, char *num2)
{
	char *ans = (char*)calloc(MAX+1, sizeof(char));
 	int i, len;
	
 	for(i = 0; i < MAX; i++)
   		ans[i] = num1[i] + num2[i];

 	for(i = 0; i < MAX - 1; i++) {
   		if(ans[i] >= 10) {
     		ans[i + 1] += ans[i] / 10;
     		ans[i] = ans[i] % 10;
   		}
 	}
 	
 	return ans;
}

void Print(char ans[])
{
 	int i;

	for(i = MAX-1; i >= 0; i--)
		printf("%d", ans[i]);

 	printf("\n");
}

int main()
{
	bool run = 1;
	while(run)
	{
	 	char *num1, *num2, *ans;
	 	num1 = set();
	 	if(num1 == "-1")
	 	{
	 		run = 0;
	 		break;
		}
		
	 	num2 = set();
	 	if(num2 == "-1")
	 	{
	 		run = 0;
	 		break;
		}
		
		num1 = recheck(num1);
		num2 = recheck(num2);
		
	 	ans = add(num1, num2);

	 	Print(ans);
	 	
	 	MAX = 0;
	 	free(ans);
	}
	
	printf("\n");
	system("pause");
	return 0;
}
