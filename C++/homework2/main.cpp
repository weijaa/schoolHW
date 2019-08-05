#include <iostream>
#include <math.h>
using namespace std;

double square(double);

int main(int argc, char** argv) 
{
	const double u = 398600;
	const double pi = 3.14;
	double a,b,c;//R=(a,b,c)
	a=2615; 
	b=15881;
	c=3980;
	double d,e,f;//V=(d,e,f)
	d=-2.767;
	e=-0.791;
	f=4.980;
	
	double r,v;
	r=sqrt(square(a)+square(b)+square(c));
	v=sqrt(square(d)+square(e)+square(f);
	cout << "r=" << r << endl;
	cout << "v=" << v << endl;
	double dot;
	
	dot=a*d+b*e+c*f;// step 2
	cout << "R*V=" << dot << endl; 
	
	double E;//step3
	
	E = v*v/2 - u/r;
	cout << "E=" << E <<endl;
	
	double i,j,k,h;//step 4
	i = a*d;
	j = b*e;
	k = c*f;
	h = sqrt(square(i)+square(j)+square(k));
	cout << "h=" << h << endl;
	
	
	double A;//step 5
	A =-u/2/E;
	cout << "A=" << A << endl;
	
	double Z;//step 6
	Z = h/u - h/v;
	cout << "Z=" << Z << endl;
	
	double I;
	I = acos(k/h) * (180/pi);//step7
	cout << "I=" << I << endl; 
	
	double ki,kj,kk; //K=(0,0,1)
	ki=0;
	kj=0;
	kk=1;
	
	double ni,nj,nk,n;//step8
	ni = kj*k - kk*j;
	nj = kk*i - ki*k;
	nk = ki*j - kj*i;
	n =sqrt(ni*ni+nj*nj+nk*nk);
	
	double omega;
	omega = acos(ni/n) * (180/pi);
	
	if (nj>=0)
{
	cout <<"omega=" <<omega <<endl;
}
	else
{
	cout << "omega=" << 360-omega << endl;
}
	
	
	return 0;
}
	double square( double n)
{
	return n*n;
}







