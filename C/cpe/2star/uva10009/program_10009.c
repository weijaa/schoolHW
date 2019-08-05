// Two-star problem
// Problem 10009 All Roads Lead Where?
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

// Assume the name of cities is not more than 20 characters.
typedef struct {
  char from[21]; // Name of the source city of a road.
  char to[21]; // Name of the destination of a road.
} Road;

// Recursive function to find the way to Rome.
void find_way_to_Rome(char *path, char *city_name, int *destination, Road *roads) {
  int length = strlen(path);
  
  path[length] = city_name[0]; // Add the first letter of the city name to the path.
  path[length+1] = '\0';
  // Recursively find the way to Rome if not arrive Rome yet.
  // "roads[destination[city_name[0]-'A']].from" gives the city of the source to
  // the city of "city_name". We back track the path until arriving Rome.
  if (strcmp(city_name, "Rome")!=0)
    find_way_to_Rome(path, roads[destination[city_name[0]-'A']].from,
	                 destination, roads);
}

int main(void) {
  int cases; // Number of testing cases.
  int road; // Number of roads.
  int query; // Number of queries.  
  int destination[26]; // The road where a city is the destination.
  // Rome cannot be a destination city because it is the city of the lowest level, 0.
  // Maximum 25 roads since each city can have only one road from the lower level. 
  Road roads[25];
  char from_name[21], to_name[21]; // Name of source and destination cities in a query.
  // The paths to and from Rome. Record first letter in each of the cities in the path.
  char way_to_Rome[26], way_from_Rome[26];
  int i, j, k; // Loop variable.
  
  scanf("%d", &cases); // Input number of testing cases.
  
  while ((cases--)>0) { // Continue if there more cases to test.
    scanf("%d %d", &road, &query); // Input number of roads and number of queries.
    
    // Reset the destination as from no where.
    for (i=0; i<26; i++) destination[i] = -1;
	
	for (i=0; i<road; i++) { 
	  // Input two city names of a road.
	  scanf("%s %s", roads[i].from, roads[i].to);
	  // Record the road index of the destination city.
	  destination[roads[i].to[0] - 'A'] = i; 
	}
	
	for (i=0; i<query; i++) {
      scanf("%s %s", from_name, to_name); // Input two city names of a query.
      way_to_Rome[0] = '\0'; // Reset to the empty path.
      way_from_Rome[0] = '\0'; // Reset to the empty path. 
      // Path from destinaton to Rome.
      find_way_to_Rome(way_to_Rome, from_name, destination, roads);
      // Path from source to Rome.
      find_way_to_Rome(way_from_Rome, to_name, destination, roads);
      
	  // Remove the idential cities at the end of two paths.
	  j = strlen(way_to_Rome);
	  k = strlen(way_from_Rome);
	  while (j>0 && k>0 && way_to_Rome[j-1]==way_from_Rome[k-1]) {
	  	// If more than one identical cities, remove that city from both paths.
	  	if (j>1 && k>1 && way_to_Rome[j-2]==way_from_Rome[k-2]) {
	      way_to_Rome[j-1] = '\0'; // Move end of string one character to left.
	      way_from_Rome[k-1] = '\0';
	      j--; // Check next character.
	      k--;
	    }
	    // If it is the last identical city, remove one from the return path.
	    else {
	      way_from_Rome[k-1] = '\0'; // Move end of string one character to left.
	      k--; // Check next character.
		}
	  }
	  // Attatch the reverse of the path from the destination 
	  // to the path from the source.
	  j = strlen(way_to_Rome); // Length of the path from the destination .
	  for (k=strlen(way_from_Rome)-1; k>=0; k--) {
	  	// Attatch one character to the path from the source.
	  	way_to_Rome[j] = way_from_Rome[k]; 
	  	way_to_Rome[++j] = '\0'; // Place end of string symbol.
	  }
	  printf("%s\n", way_to_Rome); // Output the path from source to destination.
    }
    printf("\n"); // A newline between two cases.
  }
  return 0;
}
