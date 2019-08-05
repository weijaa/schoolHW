// One-star problem
// Problem 10093 An Easy Problem!
/*
This program is written by
    Prof. Chua-Huang Huang
	Department of Information Engineering and Computer Science
	Feng Chia University
	Taichung, Taiwan
Disclaimer:
    The programming problem is downloaded from UVa Online Judge (https://uva.onlinejudge.org/).
    The program solution is provided for helping students to prepare Collegiate Programming
	Examination	(CPE). The author does not guarantee the program is completely correct to pass 
	UVa Online Judge platform or CPE examination platform.
	This program is not intended for a student to copy only. He/She should practice the 
	programming problem himself/herself. Only use the program solution as a reference. 
    
	The author is not responsible if the program causes any damage of your computer or 
	personal properties.
	No commercial use of this program is allowed without the author's written permission.	
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void) {
  unsigned long long int number; // Input number. Type unsigned long long int allows 8-byte integer.
  int radix[4] = {100, 10, 100, 100}; // Radix of Bangla numbers starting from "shata" to "kuti".
  char unit[4][6] ={"shata", "hajar", "lakh", "kuti"}; // Unit term of Bangla numbers starting from "shata" to "kuti".
  int  Bangla[10]; // Bangla number, maximum 9 digits (maximum decimal value is 9 99 99 9 99 99 99 9 99.
  int index=1;
  int i;
  
  // The maximum value 9 99 99 9 99 99 99 9 99 will cause unsigned long overflow.
  while (scanf("%llu", &number)==1) { // The format specifier is "%llu".
  	for (i=0; i<10; i++) { // Get one digit of the Bangla number, stored in the reversed orer. 
  	  Bangla[i] = number % radix[i%4]; 
  	  number = number / radix[i%4];
  	  if (number==0) break; // The digit breaking is done.
	}
	//printf("***%d:", i);
	printf("%4d. ", index++); // Print the Bangla digit
	for (; i>0; i--) {
	  if (Bangla[i]!=0) printf("%d %s ", Bangla[i], unit[(i-1)%4]); // Print the Bangla radix.
	  else if ((i-1)%4==3) printf("%s ", unit[(i-1)%4]); // If the Bangla radix i 0 and the kuti, don't print unit name.
    }
	if (Bangla[i]!=0) printf("%d\n", Bangla[i]); // The least significant final Bangla digit.
	else if (number==0) printf("%d\n", number);
	else printf("\n"); // Not print deigit, but the newline must be sent.
  }
  return 0;
}
