// One-star problem
// Problem 10281 Average Speed
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

typedef struct {
  int hour;
  int minute;
  int second;
} Time; // Data structure of time.

int main(void) {
  Time t1, t2; // Two consecutive times.
  float speed; // Car speed.
  float elapse_hour, elapse_minute, elapse_second; // To calculate the elapsing time.
  float distance; // Distance travelled.
  char c; // Character for checking space or newline.
  
  scanf("%d:%d:%d", &t1.hour, &t1.minute, &t1.second); // Read the initial time.
  scanf("%f", &speed); // Read the initial speed.
  distance = 0.0; // At the starting location.

  while (scanf("%d:%d:%d", &t2.hour, &t2.minute, &t2.second)==3) { // Read the next time.
    elapse_second = t2.second - t1.second; // Elapse seconds from the reading.
    elapse_minute = t2.minute - t1.minute; // Elapse minutes from the reading.
    elapse_hour = t2.hour - t1.hour; // Elapse hours from the reading.
    if (elapse_second<0) // Calculate the tree elapse minutes.
      elapse_minute = elapse_minute - 1.0 + (60 + elapse_second) / 60.0;
    else elapse_minute = elapse_minute + elapse_second / 60.0;
    if (elapse_minute<0) // Calculate the tree elapse hours.
      elapse_hour = elapse_hour - 1.0 + (60 + elapse_minute) / 60.0;
    else elapse_hour = elapse_hour + elapse_minute / 60.0;
    
    distance += speed * elapse_hour; // The distance at the current.
    
	scanf("%c", &c); // This character is a space, a newline, or reach end-of-file.
	if (c==' ')  // If a space is detected, the next data is the adjusted speed.
	  scanf("%f", &speed); // A query is detected, print the time and distance.
	else printf("%02d:%02d:%02d %4.2f km\n", t2.hour, t2.minute, t2.second, distance);
	
	// Set t2 to be the new current time.
	t1.hour = t2.hour;
	t1.minute = t2.minute;
	t1.second = t2.second;
  }
  return 0;
}
