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
		printf("�п�J�b��s�� : ");
		scanf("%d", &i);
		if(i==1 || i == 2 || i ==3)
		{ 
			printf("1. ���\n");
			printf("2. �s��\n");
			printf("Option : ");
			scanf("%d", &x);
			
			while(x < 1 || x >2)
			{
				printf("wrong option\n");
				printf("1. ���\n");
				printf("2. �s��\n");
				printf("Option : ");
				scanf("%d", &x);	
			}
			
			if(x==1)
			{
				printf("���B : ");
				scanf("%d", &y);
				bank[i] = bank[i] - y;
				
				if(bank[i] < 0)
				{						
					printf("�S���F\n");
					printf("�b��_0%d �l�B: 0\n", i);
					bank[i] = 0;
				}
				else
				{
					printf("�b��_0%d �l�B: %d\n", i ,bank[i]);
				}
			}
			else if(x==2)
			{
				printf("���B : ");
				scanf("%d", &y);
				bank[i] = bank[i] + y;
				printf("�b��_0%d �l�B: %d\n", i ,bank[i]);
			}
		}
		else if(i != 0 )
		{
			printf("�L���Τ�\n");	
		}	
	}
	printf("bye bye\n");
	return 0;
 } 
