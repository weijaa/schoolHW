#ifndef FACT_H
#define FACH_H

#include <stdio.h>

typedef struct fraction{
	int nume;	//���l
	int deno;	//����
}fact;

fact fadd(fact addition, fact added);//�ɤW�[�k�ŧi(10%)
fact fsub(fact reduced, fact substraction);			//���ƴ�k�A�q���۴�L����²(20%) 
fact fmulti(fact multiplicand, fact multiplier);	//���ƭ��k�A�L����²(20%)
fact fdivis(fact dividend, fact divisor);			//���ư��k�A�L����²(20%)
fact ftimes(fact source, int times);				//���ƪ��X��(10%)
fact ftrans(fact source);							//�˼�(10%)
fact freduce(fact source);							//���Ƥ�²(10%)
void factprint(fact source);						//�L�X����

#endif
