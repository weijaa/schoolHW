#include<stdio.h>


int main()
{
	int money,a,b,c,d,x;
	a=10;
	b=50;
	c=100;
	d=87;
	
	printf("�п�J��J���B:");
	scanf("%d" , &money);
	
	printf("1  :  %d��\n" ,a);
	printf("2  :  %d��\n" ,b);
	printf("3  :  %d��\n" ,c);
	printf("4  :  %d��\n" ,d);
	
	printf("�п�J�ӫ~�N��:");
	scanf("%d" , &x);
	
	switch(x)
	{
		case 1 : 
			if(money > a)
			{
				printf("�ӫ~ 1 �ʶR�����A�h��%d", money - a);
			}
			else
			{
				printf("�ӫ~ %d �ʶR����" , x);
			}
		break;
		
		case 2 : 
			if(money > b)
			{
				printf("�ӫ~ 2 �ʶR�����A�h��%d", money - b);
			}
			else
			{
				printf("�ӫ~ %d �ʶR����" , x);
			}
		break;
		
		case 3 : 
			if(money > c)
			{
				printf("�ӫ~ 3 �ʶR�����A�h��%d", money - c);
			}
			else
			{
				printf("�ӫ~ %d �ʶR����" , x);
			}
		break;
		
		case 4 : 
			if(money > d)
			{
				printf("�ӫ~ 4 �ʶR�����A�h��%d", money - d);
				
			}
			else
			{
				printf("�ӫ~ %d �ʶR����" , x );
			}
		break;
			
		default : 
		printf("�L���ӫ~");
		
	return 0;
	
}
	
	
	
	
	
	return 0;
 } 
