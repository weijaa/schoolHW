#ifndef GCDLCM_H
#define GCDLCM_H

int gcd(int a, int b){				//ㄢ计程そ计 
	if(a == 0 || b == 0) return 1;
	while(b != 0) { 
        int r = a % b; 
        a = b; 
        b = r; 
    }
	return a;
}

int lcm(int a, int b){				//ㄢ计程そ计 
	return (a*b / gcd(a, b));
}

#endif 
