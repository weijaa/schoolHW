// One-star problem
// Problem 10282 Babelfish
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

typedef struct { // A dictionary entry.
  char english[11];
  char foreign[11];
} Entry;

// Translate a foreign word to an English word.
char *translate(char *word, Entry *dictionary, int count) {
  int low=0, high=count-1, mid;
  int order, found = 0;
  
  // Use binary search to look up the dictionary.
  while (!found && low<=high) {
    mid = low + (high - low) / 2;
    if ((order=strcmp(word, dictionary[mid].foreign))==0) found = 1;
    else if (order<0) high = mid - 1;
    else low = mid + 1;
  }
  if (found) return dictionary[mid].english;
  else return "eh";
}

int main(void) {
  Entry *dictionary; // Use dynamic memory to store the dictionary, maximum 100000 entries.
  char word[11]; // An English word.
  int dictionary_done = 0; // To indicate if the dintionary is done.
  int count = 0; // Number of dictionary entries.
  int max_entry = 100; // The maximum entries of the dictionary, initial 100.
  char c; // A character to test space, newline, or reaching end-of-file.
  Entry temp; // For dictioanry entry swap operation.
  int i, j; // Loop variables.
  
  dictionary = (Entry *) malloc(max_entry*sizeof(Entry));
  
  while (scanf("%s", word)==1) { // Input an English word.
    if (!dictionary_done) { // The dictionary entries have not collected completely.
      scanf("%c", &c); // The character must be the space, newline, or reaching end-of-file.
      if (c==' ') { // If the character is a space, this is a dictionary entry.
        strcpy(dictionary[count].english, word);
        scanf("%s", dictionary[count].foreign);
        count++;
        if (max_entry==count) { // The dictionay is full; increase the memory space.
          max_entry += 100; // Increase space for 100 entries more.
          realloc(dictionary, max_entry*sizeof(Entry));
		}
	  }
	  else {
	  	dictionary_done = 1; // This is not a dictionary entry. Start translation.
	  	
	  	// Sort the dictionary according to the alphabetical order of foreign words.
	  	for (i=count-1; i>1; i--)
	  	  for (j=1; j<=i; j++)
	  	    if (strcmp(dictionary[j-1].foreign, dictionary[j].foreign)>0) { // Compare dictionary entries.
	  	      strcpy(temp.english, dictionary[j-1].english); // Swap dictionary entries.
	  	      strcpy(temp.foreign, dictionary[j-1].foreign);
	  	      strcpy(dictionary[j-1].english, dictionary[j].english);
	  	      strcpy(dictionary[j-1].foreign, dictionary[j].foreign);
			  strcpy(dictionary[j].english, temp.english); 
			  strcpy(dictionary[j].foreign, temp.foreign); 
			}
	  	    
	  	
	  	printf("%s\n", translate(word, dictionary, count));
	  }
    }
	else printf("%s\n", translate(word, dictionary, count));  
  }
  free(dictionary); // Release the memory space for dictionary.
  return 0;
}
