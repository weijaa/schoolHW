// One-star problem
// Problem 10473 Simple Base Conversion
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

// We treat a number as a string. The maximum lenght for a hexadecimal number is 10,
// i.e., 0x followed by eight hexadecimal digits.
int main(void) {
  char string[11]; // The string to hold the input.
  int n; // The resulting value.
  int i; // Loop index.
  
  while (scanf("%s", &string)) { // Input a number as a string, if there is any.
    if (string[0]!='-') { // If it is a negative number. Do not process. Just ignore it.
      if (string[0]=='0' && string[1]=='x') { // This is a hexadecimal number.
        n = 0; // Initial n to 0.
        for (i=2; i<strlen(string); i++) { // Scan every hexadecimal digit.
          if (isdigit(string[i])) n = n * 16 + string[i] - '0'; // The digit is '0' to '9'.
          else n = n = n * 16 + toupper(string[i]) - 'A' + 10; // The digit is 'A' to 'F'.
		}
		printf("%d\n", n); // Output n in the decimal format.
      }
      else { // This is a decimal number.
        n = 0;
        for (i=0; i<strlen(string); i++) // Scan every decimal digit.
          n = n * 10 + string[i] - '0'; // The digit must be '0' to '9'.
		printf("0x%X\n", n); // Print n in the hexadecimal format.
      }
    }
    else return 0; // Terminate the program when a negative number is read.
  }
}
