#include<stdio.h>



int main ()
{
	
	float calculus,english,computer,x,n,calnum,ennum,comnum;//x=�[�v�`��  n=�[�v���� 

	int calculusnum,englishnum,computernum;

	
	printf("�п�J�L�n�����Z:");
	scanf("%f" , &calculus);
	printf("�п�J�^�妨�Z:");
	scanf("%f" , &english);
	printf("�п�J�p�����Z:");
	scanf("%f" , &computer);
	printf("   \n");
	printf("�п�J�L�n���Ǥ�:");
	scanf("%d" , &calculusnum );
	printf("�п�J�^��Ǥ�:");
	scanf("%d" , &englishnum);
	printf("�п�J�p�����Z:");
	scanf("%d" , &computernum);
	printf(" \n");
	calnum=calculus * calculusnum;
	ennum=english * englishnum;
	comnum=computer * computernum;
	x = calnum + ennum + comnum;
	n = x/(calculusnum+englishnum+computernum);
	printf("��� :  �L�n��  �^��   �p��    �[�v�`��       �[�v����\n");
	printf("--------------------------------------------------------\n");
	printf("���Z :  %.1f    %.1f    %.1f    %.2f         %.2f\n" , calculus,english,computer,x,n);
	printf("�Ǥ� :  %-d       %-d       %-d\n",calculusnum,englishnum,computernum);
	printf("========================================================\n");
	printf("�[�v :  %.1f   %.1f   %.1f\n",calnum,ennum,comnum);
	
	
	
	
	
	
	
	return 0;
}





 
