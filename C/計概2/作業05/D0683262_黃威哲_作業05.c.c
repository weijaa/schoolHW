#include<stdio.h>

double fofx(double,double);

int main ()
{
	double ans,x,y,i;
	printf("½Ð¿é¤J(X,Y) :");
	scanf("%lf%lf", &x, &y);
	
	for(i=1;i<=y;i++)
	{
		ans = ans + fofx(x,i);
	}
	printf("%lf", ans);
	return 0;
}

double  fofx(double x, double n)
{
	
	
	
	if (n == 1)
	{
		
		return x;
	}
	else
	{
			return fofx(x,n-1)*x/n;
	}
	
}
