// One-star problem
// Problem 11309 Counting Chaos
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

// Check palidrome of hours and minutes. Ignore ':' and leading zeros.
int is_palindrome(char *HH, char *MM) {
  char str[5];
  int low, high;
  
  strcpy(str, HH); // Copy HH to str.
  strcat(str, MM); // Append MM to str.
  while (str[0]=='0') strcpy(str, str+1); // Remove all leading zeros.
  if (str[0]=='\0') strcpy(str, "0"); // Make str to "0", if the time is 00:00.
  low = 0; // Lower index of str.
  high = strlen(str) - 1; // High index of str.
  while (low<high)	if (str[low++]!=str[high--]) return 0; // Not a palindrome, return 0.
  return 1; // A palindrome, return 1.
}

// Time passed one minute.
void next_minute(char *HH, char *MM) {
  
  if (MM[1]<'9') MM[1]++; // The minute is not X9.
  else if (MM[0]<'5') {MM[0]++; MM[1] = '0';} // The minute is not 59.
  else if (HH[0]!='2' && HH[1]<'9') {HH[1]++;  MM[0] = '0'; MM[1] = '0';} // The hour is not X9.
  else if (HH[0]!='2' && HH[1]=='9') {HH[0]++; HH[1] = '0';  MM[0] = '0'; MM[1] = '0';} // The hour is X9.
  else if (HH[1]<'3') {HH[1]++;  MM[0] = '0'; MM[1] = '0';} // The hour is not 23.
  else {HH[0] = '0'; HH[1] = '0'; MM[0] = '0'; MM[1] = '0';} // 23:59 => 00:00.
}

int main(void) {
  int cases; // Number of cases.
  char HH[3]; // Digits for hours.
  char MM[3]; // Digits for minutes.
  int i; // Loop variable.
  
  scanf("%d", &cases);
  
  for (i=0; i<cases; i++) { // Performe all cases.
    do {scanf("%c", &HH[0]);
	} while (!isdigit(HH[0]));
    scanf("%c:%c%c", &HH[1], &MM[0], &MM[1]); // Input hours and minutes, skip ':'.
    HH[2] = '\0'; // Add end of string.
    MM[2] = '\0'; // Add end of string.
    
    // Find the first occurence of time which is a palindrome.
    do {next_minute(HH, MM);} while (!is_palindrome(HH, MM));
    
    printf("%s:%s\n", HH, MM);
  }
  return 0;
}
