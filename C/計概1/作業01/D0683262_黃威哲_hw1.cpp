#include<stdio.h>



int main ()
{
	
	float calculus,english,computer,x,n,calnum,ennum,comnum;//x=加權總分  n=加權平均 

	int calculusnum,englishnum,computernum;

	
	printf("請輸入微積分成績:");
	scanf("%f" , &calculus);
	printf("請輸入英文成績:");
	scanf("%f" , &english);
	printf("請輸入計概成績:");
	scanf("%f" , &computer);
	printf("   \n");
	printf("請輸入微積分學分:");
	scanf("%d" , &calculusnum );
	printf("請輸入英文學分:");
	scanf("%d" , &englishnum);
	printf("請輸入計概成績:");
	scanf("%d" , &computernum);
	printf(" \n");
	calnum=calculus * calculusnum;
	ennum=english * englishnum;
	comnum=computer * computernum;
	x = calnum + ennum + comnum;
	n = x/(calculusnum+englishnum+computernum);
	printf("科目 :  微積分  英文   計概    加權總分       加權平均\n");
	printf("--------------------------------------------------------\n");
	printf("成績 :  %.1f    %.1f    %.1f    %.2f         %.2f\n" , calculus,english,computer,x,n);
	printf("學分 :  %-d       %-d       %-d\n",calculusnum,englishnum,computernum);
	printf("========================================================\n");
	printf("加權 :  %.1f   %.1f   %.1f\n",calnum,ennum,comnum);
	
	
	
	
	
	
	
	return 0;
}





 
