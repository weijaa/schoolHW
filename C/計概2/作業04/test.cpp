#include<stdio.h>



int plus(int,int);//¬Û¥[ 
int matrixDouble(int);//¤º­È­¼2 
int matrixCross(int,int);//­¼¿n 



int main()
{
	int matrixOne[3][3],matrixTwo[3][3],i,j,k,save[3],ans[3][3] = {0};
	
	
	printf("Input matrixOne : ");	
	for(i=0;i<3;i++)
		{
		for(j=0;j<3;j++)
		{
			scanf("%d",&matrixOne[i][j]);
		}
	}
	for(i=0;i<3;i++)
	{
		printf("  ");
		for(j=0;j<3;j++)
		{
			printf("%3d ",matrixOne[i][j]);
		}
		printf("\n");
	}
	
	printf("==========================\n\n");
	printf("Input matrixTwo : ");	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&matrixTwo[i][j]);
		}
	}
	for(i=0;i<3;i++)
	{
		printf("  ");
		for(j=0;j<3;j++)
		{
			printf("%3d ",matrixTwo[i][j]);
		}
		printf("\n");
	}
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			
		}
	}
	//(1)
	printf("==========================\n\n");
	printf("matrixOne plus matrixTwo : \n");
	
	 plus(matrixOne[][],matrixTwo[][]);


	//(2)
/*	printf("==========================\n\n");
	printf("Two times matrixOne plus matrixTwo : \n");
	
			plus(matrixDouble(matrixOne[3][3]),matrixTwo[3][3]);*/
	
	//(3)
	printf("==========================\n\n");
	printf("Eight times matrixTwo:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%3d ",matrixDouble(matrixTwo[i][j])+matrixDouble(matrixTwo[i][j])+matrixDouble(matrixTwo[i][j])+matrixDouble(matrixTwo[i][j]));
		}
		printf("\n");
	}
	//(4)
	printf("==========================\n\n");
	printf("matrixOne cross matrixTwo : \n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			for(k=0;k<3;k++)
			{
				save[k] = matrixCross(matrixOne[i][k],matrixTwo[k][j]);
				ans[i][j] = ans[i][j] + save[k];
			}
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%3d ",ans[i][j]);
		}	
		printf("\n");
	}
	
	return 0;
}

int plus(int a[][],int b[][])
{
	int ans[3][3],i,j;
	printf("%d,%d",a[3][3],b[3][3]);
/*	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			ans[i][j] = a[i][j] +b[i][j];
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d", ans[i][j]);
		}
	}
*/
}
int matrixDouble(int matrix)
{
	return 2*matrix;
}
int matrixCross(int a,int b)
{
	return a*b;
}

