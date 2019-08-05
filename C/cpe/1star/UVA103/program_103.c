// One-star problem
// Problem UVA103 Stacking Boxes
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

// Alphabetical order less than comparison operator.
// Return 1 if box1 is less than box2; otherwise, return 0.
int seq_lessp(int box1[10], int box2[10], int dim) {
  int i; // Loop variable.
  
  for (i=0; i<dim; i++)
    if (box1[i]<box2[i]) return 1; // box1 is less than box2 in dimension i.
    else if (box1[i]>box2[i]) return 0; // box1 is greater than box2 in dimension i.
  return 0; // box1 and box2 have the same size, i.e., box1==box2.  
}

// Test whether box1 can be nested in box2.
// Return 1, if box1 can be nested in box2; return  0, otherwise.
int nested(int box1[10], int box2[10], int dim) {
  int i;
  
  for (i=0; i<dim; i++) 
    if (box1[i]>=box2[i]) return 0; // box1 cannot be nested in box2 on dimension i.
  return 1; // box1 is nested in box2.
}

int main(void) {
  // The maximum dimensionality is 10 and the minimum dimensionality is 1.
  // The maximum number of boxes in a sequence is 30.
  int boxes[30][10];
  int num_of_boxes; // Number of boxes.
  int dimension; // Dimension of boxes.
  int ordered[30]; // Boxes in alphabetical order.
  int nest[30][30]; // The nested relation between boxes.
  int non_nested[30]; // Count the number of non-nested boxes.
  int removed[30]; // Box removed from nested sequence.
  int removed_next; // Search the next box to be removed.
  int max_non_nested; // The largest count of the non-nested boxes.
  int nested_chain_found; // 1: a chain of nested boxes is found; 0:, otherwise.
  int temp; // Temporary variable.
  int i, j, k; // Loop variables.
  int cases=0;
  
  while (scanf("%d %d", &num_of_boxes, &dimension)==2) { // Input the box dimensions. 
    for (k=0; k<num_of_boxes; k++)
      for (i=0; i<dimension; i++) scanf("%d", &boxes[k][i]); // Dimension i of box k.
      
    for (k=0; k<num_of_boxes; k++) // Sort the dimensions of each box.
      for (i=dimension-1; i>0; i--) // Using selection sort algorithm.
        for (j=1; j<=i; j++) {
          if (boxes[k][j-1]>boxes[k][j]) { // Compare and swap operation.
            temp = boxes[k][j-1];
            boxes[k][j-1] = boxes[k][j];
            boxes[k][j] = temp; } }
            
    for (k=0; k<num_of_boxes; k++) ordered[k] = k; // Initial sequence order.    
    // Sort the sequence in alphabetical ascending order.
    for (i=num_of_boxes-1; i>0; i--)
      for (j=1; j<=i; j++)
        // If boxes[ordered[j-1]] and boxes[ordered[j]] are out of order,
        // swap their position.
        if (seq_lessp(boxes[ordered[j]], boxes[ordered[j-1]], dimension)) {
          temp = ordered[j-1];
          ordered[j-1] = ordered[j];
          ordered[j] = temp;
		}
	
	// Calculate nested relation for all boxes.
	// Assume a box can be nested in itself.
	// If (box[ordered[i]], box[ordered[j]]) are nested, also mark (box[ordered[j]],
	// box[ordered[i]]) as nested. Hence, the square matrix forms a symmetric matrix.
	for (i=0; i<num_of_boxes; i++) {
	  nest[i][i] = 1; 
	  for (j=i+1; j<num_of_boxes; j++) {
	    nest[i][j] = nested(boxes[ordered[i]], boxes[ordered[j]], dimension);
		nest[j][i] = nest[i][j];
      }
	}
	
	// Count the number of non-nested boxes for all boxes.
	for (i=0; i<num_of_boxes; i++) {
	  non_nested[i]=0;
	  for (j=0; j<num_of_boxes; j++) if (nest[i][j]==0) non_nested[i]++;
	}
	
	for (i=0; i<num_of_boxes; i++) removed[i] = 0; // Initially, no box is removed.
	do {
	  nested_chain_found = 1; // Assume nested chain of boxes is found.
	  removed_next = -1; // Initial the box to be removed next is -1.
      max_non_nested = -1; // Initial the number of non-nested boxes is 0.
      
      // Search the unremoved box with the largest non_nested boxes.
      // The search direction is backward. When there are more than one solutions,
	  // the box with smallest value in the alphabetical order will be selected. 
      for (i=num_of_boxes-1; i>=0; i--) 
	    if (non_nested[i]>max_non_nested && removed[i]==0) {
	      removed_next = i;
	      max_non_nested = non_nested[i];
		}
	  // The removed_next is the box to be removed.
	  if (removed_next>=0 && max_non_nested>0) removed[removed_next] = 1; 
	  // If all unremoved boxes are nested, these boxes form the longest nested chain.
	  // That is, all unremoved box i and box j, they are nested.
	  // The submatrix of unremoved boxes have nested[i][j]==1.
	  // If one pair of boxes i and j are not nested, i.e., nest[i][j]==0,
	  // set nested_chain_found to false and continue to remove anohter box.
	  for (i=0; i<num_of_boxes && nested_chain_found; i++) 
	    for (j=0; j<num_of_boxes && nested_chain_found; j++)
	      if (removed[i]==0 && removed[j]==0 && nest[i][j]==0)
		      nested_chain_found = 0;
	} while (!nested_chain_found); // Nested chain not found yet, repeat the loop.
	
	// Output all remained boxes in alphabetical order.
	for (i=0; i<num_of_boxes; i++)
	  if (!removed[i]) printf("%d ", ordered[i]+1); 
	printf("\n");
  }
  return 0;
}
