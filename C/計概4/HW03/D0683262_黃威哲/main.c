#include <stdio.h>
#include "fact.h"

int main(){
	fact a = {1, 2};
	fact b = {2, 3};
	fact c, d, e;
	
	c = fadd(a, b);
	factprint(c);			//1/2 + 2/3 = 7/6
	
	d = fsub(a, b);
	factprint(d);			//1/2 - 2/3 = -1/6
	
	e = fmulti(a, c);
	factprint(e);			//1/2 * 7/6 = 7/12
	
	e = fdivis(e, a);
	factprint(e);			//7/12 / 1/2 = 7/12 * 2 = 14/12
	
	d = ftimes(e, 2);
	factprint(d);			//14/12 * 2 = 28/24
	
	d = freduce(d);
	factprint(d);			//reduce(28/24) = 7/6
	
	factprint(ftrans(d));	//trans(7/6) = 6/7
	
	return 0;
}
