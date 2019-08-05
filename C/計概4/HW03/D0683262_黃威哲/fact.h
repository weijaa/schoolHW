#ifndef FACT_H
#define FACH_H

#include <stdio.h>

typedef struct fraction{
	int nume;	//分子
	int deno;	//分母
}fact;

fact fadd(fact addition, fact added);//補上加法宣告(10%)
fact fsub(fact reduced, fact substraction);			//分數減法，通分相減無須化簡(20%) 
fact fmulti(fact multiplicand, fact multiplier);	//分數乘法，無須化簡(20%)
fact fdivis(fact dividend, fact divisor);			//分數除法，無須化簡(20%)
fact ftimes(fact source, int times);				//分數的擴分(10%)
fact ftrans(fact source);							//倒數(10%)
fact freduce(fact source);							//分數化簡(10%)
void factprint(fact source);						//印出分數

#endif
