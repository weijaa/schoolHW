// One-star problem
// Problem 10226 Hardwood Species
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
  //No species name exceeds 30 characters.
  //There are no more than 10,000 species and no more than 1,000,000 trees.
  char trees[10000][31];
  int tree_count[10000]; // Count the number of species.
  char new_tree[31]; // A new tree to be added to trees[].
  char c; // An input character.
  int length; // Length of new_tree string.
  int species; // Number of species found.
  int total; // Total number of trees.
  int cases; // Number of testing cases.
  int new_line = 0; // Indicate a new line has been started.
  int case_done; // As case is completed.
  int i, j, k; // Loop variables.
  
  scanf("%d", &cases); // Input the number of cases, skip two newline.
  scanf("%c%c", &c, &c); // Ignore the two newlines.
  
  for (i=0; i<cases; i++) {
  	for (j=0; j<10000; j++) tree_count[j] = 0;
	species = 0; // Reset the number of species to 0.
	total = 0; // Reset the number of trees to 0.
	length = 0; // The new_tree is an empty string.
	case_done = 0; // A case is just started, not done yet.
    while (!case_done && scanf("%c", &c)==1) {// Input a character if there is any.
      if (c!=0X0A) {
	    //result_printed = 0; // No resulted has been printed.
	    new_tree[length++] = c; // Store the character.
	    new_line = 0; // There are text in this line.
      }
      else if (!new_line) {
      	new_tree[length] = '\0'; // Add end-of-string.
      	length = 0; // Reset length to zero.
      	total++; // Increase the total number of trees by 1.
      	// Insert the tree name to species count.
      	for (j=0; j<species; j++) {
      	  if (strcmp(trees[j], new_tree)==0) { // The species has been found.
      	    tree_count[j]++; // Add one one more tree to the tree count of that species.
      	    break; // Stop the loop.
		  }
		  else if (strcmp(new_tree, trees[j])<0) { // The inserting point has found.
		    for (k=species-1; k>=j; k--) { // Shift the rest of the species one position to the right.
		      strcpy(trees[k+1], trees[k]);
		      tree_count[k+1] = tree_count[k];
			}
			strcpy(trees[j], new_tree); // Insert the name of the new species to position j.
			tree_count[j] = 1; // Species 1 has one tree.
			species++; // Increase the number of species.
			break; // Stop the loop.
	      }
	    }
		if (j==species) { // The new species is at the end of the species list.
		  strcpy(trees[j], new_tree); // Insert the tree name of the end of the  species list.
		  tree_count[j] = 1; // The new species has one tree. 
		  species++; // Increase the number of species.
        }
		new_line = 1; 	
	  }
	  else { // A blank line is encountered. The end of the case is reached.
		for (j=0; j<species; j++) { 
		  printf("%s %6.4f\n", trees[j],  (float) tree_count[j]/total*100.0); // Output species name and ratio.
		  tree_count[j] = 0; // Reset tree count to 0.
	    }
	    printf("\n"); // Print the empty line.
	    case_done = 1; // A case is completed.
	  }
    }
  }
  if (!case_done) { // Check if the last case has been completed. If not, finish it.
	for (j=0; j<species; j++) { 
	  printf("%s %6.4f\n", trees[j],  (float) tree_count[j]/total*100.0); // Output species name and ratio.
	  tree_count[j] = 0; // Reset tree count to 0.
    }
  }
  return 0;
}
