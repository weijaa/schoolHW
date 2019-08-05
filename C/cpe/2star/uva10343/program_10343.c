// Two-star problem
// Problem 10343 Base64 Decoding
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

int main(void) {
  char base64[4]; // Input base64 character.
  int base64_cnt; // Count the number of base64 characters in character, 0 to 3.
  int decode_cnt; // Decoded character count in character, 0 to 2.
  int pad_cnt; // Number of equal sigh (pad symbol) count.
  int empty_line; // 1: if the line has no data; 0: otherwise.
  int finished = 0; // 0: to finish the program; 1: not to finish.
  
  pad_cnt = 0; // Initially, no paddings.
  base64_cnt = 0; // No characters output yet.
  do { // Input a base64 character until an empty line is encountered.
    base64[base64_cnt] = getchar(); // Input a character.
    // If the input character is a letter, a digit, '+', '/', or '=' proceeds.
    if (isalnum(base64[base64_cnt]) || base64[base64_cnt]=='+' ||
	    base64[base64_cnt]=='/' || base64[base64_cnt]=='=') {
	  // Upper case letter, decoded value 0 to 25.
      if (isupper(base64[base64_cnt])) base64[base64_cnt] = base64[base64_cnt] - 'A';
      // Lower case letter, decoded value 26 to 51.
      else if (islower(base64[base64_cnt])) base64[base64_cnt] = base64[base64_cnt] - 'a' + 26;
      // Digit, decoded value 52 to 61.
      else if (isdigit(base64[base64_cnt])) base64[base64_cnt] = base64[base64_cnt] - '0' + 52;
      else if (base64[base64_cnt]=='+') base64[base64_cnt] = 62; // '+' decoded as 62.
      else if (base64[base64_cnt]=='/') base64[base64_cnt] = 63; // '/' decoded as 63.
      else if (base64[base64_cnt]=='=') pad_cnt++; // Padding symbol, increment padding count.
      base64_cnt = (base64_cnt + 1) % 4; // Increment base64 character counter.
	  if (base64_cnt==0) { // If four valid characters are input.
	  	empty_line = 0; // Not an empty line.
	    decode_cnt  = 3 - pad_cnt; // Number of decoded characters is 3 subtract pad count.
	    // First character, 6 bits from base64[0] and 2 bits from base64[1].
	    printf("%c", ((base64[0] << 2) & 0XFC) | ((base64[1] >> 4) & 0X03));
	    // Second character, 4 bits from base64[1] and 4 bits from base64[2].
	    if (decode_cnt>=2) printf("%c", ((base64[1] << 4) & 0XF0) | ((base64[2] >> 2) & 0X0F));
	    // Third character, 2 bits from base64[1] and 6 bits from base64[3].
	    if (decode_cnt==3) printf("%c", ((base64[2] << 6) & 0XC0) | (base64[3] & 0X03F));
	  }
    }
	if (base64[base64_cnt]=='#') { // A hash sign is input.
	  if (!empty_line) { // If the text is not empty.
	    printf("#"); // Output a hash sign, end-of-line.
	    empty_line = 1; // Set the line to empty.
	    pad_cnt = 0; // Clear pad count.
	  }
	  else finished = 1; // The preious line is empty.
	}
  } while (!finished); // End-of-file, stop the program.
  printf("\n"); // Output a newline.
  
  return 0;
}
