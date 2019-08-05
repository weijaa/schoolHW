#include<stdio.h>


int main()
{
	int money,a,b,c,d,x;
	a=10;
	b=50;
	c=100;
	d=87;
	
	printf("請輸入投入金額:");
	scanf("%d" , &money);
	
	printf("1  :  %d元\n" ,a);
	printf("2  :  %d元\n" ,b);
	printf("3  :  %d元\n" ,c);
	printf("4  :  %d元\n" ,d);
	
	printf("請輸入商品代號:");
	scanf("%d" , &x);
	
	switch(x)
	{
		case 1 : 
			if(money > a)
			{
				printf("商品 1 購買完成，退幣%d", money - a);
			}
			else
			{
				printf("商品 %d 購買失敗" , x);
			}
		break;
		
		case 2 : 
			if(money > b)
			{
				printf("商品 2 購買完成，退幣%d", money - b);
			}
			else
			{
				printf("商品 %d 購買失敗" , x);
			}
		break;
		
		case 3 : 
			if(money > c)
			{
				printf("商品 3 購買完成，退幣%d", money - c);
			}
			else
			{
				printf("商品 %d 購買失敗" , x);
			}
		break;
		
		case 4 : 
			if(money > d)
			{
				printf("商品 4 購買完成，退幣%d", money - d);
				
			}
			else
			{
				printf("商品 %d 購買失敗" , x );
			}
		break;
			
		default : 
		printf("無此商品");
		
	return 0;
	
}
	
	
	
	
	
	return 0;
 } 
