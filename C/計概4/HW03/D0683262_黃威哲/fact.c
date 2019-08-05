#include "fact.h"
#include "gcdlcm.h"

fact fadd(fact addition, fact added){
	fact result = {0, 0};
	if(addition.deno != added.deno){
		int add_lcm = lcm(addition.deno, added.deno);
		result.nume = (addition.nume * (add_lcm / addition.deno) + added.nume * (add_lcm / added.deno));
		result.deno = add_lcm;
	}
	else{
		result.nume = addition.nume + added.nume;
		result.deno = addition.deno;
	}
	return result;
}
fact fsub(fact reduced, fact substraction){
	fact x;
	x.deno=lcm(reduced.deno,substraction.deno);
	x.nume=(x.deno / reduced.deno)*reduced.nume - (x.deno / substraction.deno)*substraction.nume;
	return x;
}
fact fmulti(fact multiplicand, fact multiplier){
	fact x;
	x.deno = multiplicand.deno * multiplier.deno;
	x.nume = multiplicand.nume * multiplier.nume;
	return x;	
}
fact fdivis(fact dividend, fact divisor){
	fact x;
	x.deno = dividend.deno * divisor.nume;
	x.nume = dividend.nume * divisor.deno;
	return x;
}
fact ftimes(fact source, int times){
	fact x;
	x.deno = source.deno*times;
	x.nume = source.nume*times;
	return x;
}
fact ftrans(fact source){
	fact x;
	x.deno = source.nume;
	x.nume = source.deno;
	return x;
}
fact freduce(fact source){
	fact x;
	int big;
	big = gcd(source.deno,source.nume);
	x.deno = source.deno/big;
	x.nume = source.nume/big;
	return x;
}

void factprint(fact source){
	printf("%d/%d\n", source.nume, source.deno);
}
