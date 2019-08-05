// Two-star problem
// Problem 10020 Minimal Coverage
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

// A data type a pair of integers denoting the interval of a line segment.
typedef struct {
  int L;
  int R;
} Segment;

int main(void) {
  int cases; // Number of cases.
  int m; // input integer m.
  Segment *segments; // Collection of line segments.
  Segment **coverage; // Pointers of line segements as the minimum coverage of [0,m].
  int count; // Number of valid segments input.
  int coverage_count; // Number of segements in the coverage.
  int max_count; // Maximum number of segment.
  int left, right; // Input pair of integers.
  int current; // Current segement as a candidate of the coverage.
  int low; // Low boundary of the segment to be covered.
  int done; // 1: the coverage search is done; -1: the coverage search fails.
  int c, i, j; // Loop variables.
  
  scanf("%d", &cases); // Input number of cases.
  
  segments = NULL; // Initial the segments to the null pointer.
  
  for (c=0; c<cases; c++) { // Process all cases.
    scanf("%d", &m); // Input integer m.
    
    max_count = 10; // Initial limit of the segment count.
    // Allocate memory space for line segments.
    segments = (Segment *) realloc(segments, sizeof(Segment) * max_count);
    count = 0; // Initial segment count to 0.
    while (1) { // Continue to input line segments until "0 0" are input.
      scanf("%d %d", &left, &right); // Input a pair of integers.
      
      if (left==0 & right==0) break; // The input is "0 0", stop the loop and process the segments.
      
      if (left<=right && left<=m && right>=0) { // If the pairs of integer are valid segment.
        segments[count].L = left; // Add this interval to the segments for coverage serach.
        segments[count].R = right;
        count++;
        if (count==max_count) {
          max_count += 10; // Extend the mximum count to allow 10 more segements.
          // Request more memory for the segments.
          segments = (Segment *) realloc(segments, sizeof(Segment) * max_count);
		}
	  }    
	}
	
	// Sort the pair of integers in ascending order.
	for (i=count-1; i>0; i--)
	  for (j=1; j<=i; j++) {
	  	if (segments[j-1].L>segments[j].L || // The two segments are out of order.
		    (segments[j-1].L==segments[j].L && segments[j-1].R>segments[j].R)) {
		  left  = segments[j-1].L;
		  right = segments[j-1].R;
		  segments[j-1].L = segments[j].L;
		  segments[j-1].R = segments[j].R;
		  segments[j].L = left;
		  segments[j].R = right;
		}
	  }
	// Allocate memory for pointers to segments; maximum "count" segments.
	coverage = (Segment **) malloc(sizeof(Segment *) * count);
	coverage_count = 0; // No segment in the coverage yet.
	low = 0; // Low boundary of the coverage.
	current = 0; // The current selected segment.
	done = 0; // Coverage search is not done yet.
	// If the segement starts from a positive integer, the coverage does not exist.
	if (0<segments[0].L) done = -1; // Coverage fails.
	for (i=0; i<count && !done; i++) { // Check all segments.
	  // If the lower boundary of this segment is larger than the low boundary,
	  // add the current segment to the coverage.
	  if (segments[i].L>low) { 
	  	coverage[coverage_count++] = &segments[current]; // Add the current to the coverage.
	  	// Update low as the next integer larger than current high boundyary.
	  	low = segments[current].R + 1;
	  	i = current; // Backtrack the segment under inspection to the one next to current.
	  	current = i + 1; // Next selected segment.
	  	// If the low boundary of the coverage is large than m, the search is done.
	  	// otherwise, if low boundary of the coverage is smaller than the low boundary of 
		// the next segment, the search fails. 
	  	if (low>m) done = 1;
	  	else if (low<segments[i].L) done = -1; 
	  }
	  // If the high boundary of this segment is larger than m, add this segment to the coverage 
	  // and the search is done.
	  else if (segments[i].R>=m) {
	    coverage[coverage_count++] = &segments[i];
	  	done = 1;
	  }
	  // If the high boundary of this segment is larger than the high boundary of the selected 
	  // segment, select this segment as the coverage candidate.
	  else if (segments[i].R>segments[current].R) current = i;
	}
	
	if (done==1) { // A coverage is found.
	  printf("%d\n", coverage_count); // Output the number segments in the coverage.
	  // Out the segements in the coverage.
	  for (i=0; i<coverage_count; i++) printf("%d %d\n", coverage[i]->L, coverage[i]->R);
	}
	else printf("0\n"); // No coverage is found
	printf("\n");
  }
  free(coverage); // Release memory of coverage.
  free(segments); // Release memory of segments.
  return 0;
}
