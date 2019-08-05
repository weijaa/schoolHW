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
    
    // The solution uses case analysis to consider all possible cases of HH and MM
    // and update them to the next possible palindrome.
    if (strcmp(HH,"00")==0) {
      if (MM[0]=='0') {
      	if (MM[1]<'9') MM[1]++;
      	else strcpy(MM,"11");
      }
      else if (MM[0]>MM[1]) MM[1] = MM[0];
      else if (MM[0]<'5') {MM[0]++; MM[1] = MM[0];}
      else {strcpy(HH, "01"); strcpy(MM, "01");}	  
	}
	else if (HH[0]=='0') {
	  if (HH[1]>MM[1]) MM[1] = HH[1];
	  else if (HH[1]<'9' || MM[0]<'5') {MM[0]++; MM[1] = HH[1];}
	  else {strcpy(HH, "10"); strcpy(MM, "01");}	  
	}
	else if (HH[0]=='1') {
	  if (HH[1]<'5') {
	  	if (HH[1]<MM[0]) {HH[1]++; MM[0] = HH[1]; MM[1] = HH[0];}
	  	else if (HH[1]>MM[0]) {MM[0] = HH[1]; MM[1] = HH[0];}
	  	else if (MM[1]=='0') MM[1]++;
		else {HH[1]++; MM[0] = HH[1]; MM[1] = HH[0];}
	  }
	  else if (HH[1]=='5') {
	  	if (MM[0]<'5' || strcmp(MM, "50")==0) strcpy(MM, "51");
	  	else {strcpy(HH, "20"); strcpy(MM, "02");}
	  }
	  else {strcpy(HH, "20"); strcpy(MM, "02");}
	}
	else if (HH[0]=='2') {
	  if (HH[1]<MM[0] && HH[1]<'3') {HH[1]++; MM[0] = HH[1]; MM[1] = '2';}
	  else if (HH[1]<MM[0] && HH[1]=='3') {strcpy(HH, "00"); strcpy(MM, "00");}
	  else if (HH[1]==MM[0] && MM[1]<'2') MM[1] = '2';
	  else if (HH[1]==MM[0] && HH[1]<'3' && MM[1]>='2') {HH[1]++; MM[0] = HH[1]; MM[1] = '2';}
	  else if (HH[1]==MM[0] && HH[1]=='3' && MM[1]>='2') {strcpy(HH, "00"); strcpy(MM, "00");}
	  else if (HH[1]>MM[0] || (HH[1]==MM[0] && MM[1]<'2')) {MM[0] = HH[1]; MM[1] = '2';}
	}
    
    printf("%s:%s\n", HH, MM);
  }
  return 0;
}
