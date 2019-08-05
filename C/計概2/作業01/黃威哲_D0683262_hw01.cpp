#include<stdio.h>



int main()
{
	int bank[4],i,x,y;
	
	
	for(i=0;i<4;i++)
	{
		bank[i] = 0;
	}
	while( i != 0 )
	{
		printf("========IECS BANK========\n");
		printf("請輸入帳戶編號 : ");
		scanf("%d", &i);
		if(i==1 || i == 2 || i ==3)
		{ 
			printf("1. 領錢\n");
			printf("2. 存錢\n");
			printf("Option : ");
			scanf("%d", &x);
			
			while(x < 1 || x >2)
			{
				printf("wrong option\n");
				printf("1. 領錢\n");
				printf("2. 存錢\n");
				printf("Option : ");
				scanf("%d", &x);	
			}
			
			if(x==1)
			{
				printf("金額 : ");
				scanf("%d", &y);
				bank[i] = bank[i] - y;
				
				if(bank[i] < 0)
				{						
					printf("沒錢了\n");
					printf("帳戶_0%d 餘額: 0\n", i);
					bank[i] = 0;
				}
				else
				{
					printf("帳戶_0%d 餘額: %d\n", i ,bank[i]);
				}
			}
			else if(x==2)
			{
				printf("金額 : ");
				scanf("%d", &y);
				bank[i] = bank[i] + y;
				printf("帳戶_0%d 餘額: %d\n", i ,bank[i]);
			}
		}
		else if(i != 0 )
		{
			printf("無此用戶\n");	
		}	
	}
	printf("bye bye\n");
	return 0;
 } 
