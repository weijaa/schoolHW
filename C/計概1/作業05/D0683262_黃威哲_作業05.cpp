#include<stdio.h>
#include<stdlib.h>
#include<time.h> 


int main()
{
	srand(time(NULL));
	int a=0,b[30],c=0,d;
	
	while(a<30)
	{
		scanf("%d", &b[a]);
		if(b[a] ==0)
		{
			break;
		}
		else if(b[a] >= 100 || b[a] < 0)
		{
			b[a] = (rand()%100)+1;
		}
		for(c=0;c<a;c++)
		{
			if(b[a] == b[c])
			{
				b[a] = (rand()%100)+1;
				c=-1;
			}
		}
		
		a++;
	}
	while(a <30)
	{
		b[a] = (rand()%100)+1;
		for(c=0;c<a;c++)
		{
			if(b[a] == b[c])
			{
				b[a] = (rand()%100)+1;
				c=-1;
			}
		}
		a++;		
	}
	d=0;
	while(d < a)
	{
		printf("%3d ", b[d]);
		
		if(d ==9 || d==19 || d ==29)
		{
			printf("\n");
		}
		d++;
	}

	return 0;
 } 
