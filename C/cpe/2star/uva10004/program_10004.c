// Two-star problem
// Problem 10004 Bicoloring
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

// Edge type denoted as two nodes. Also, we will have n1<n2.
typedef struct {
  int n1;
  int n2;
} Edge;

int main(void) {
  int n; // Number of nodes, maximum 199 nodes.
  int l; // Number of edges, maximum 199*198=39402 edges
  Edge *graph=NULL; // The memory for edges will be allocated as needed.
  char color[199]; // The node color: ' ': unmarked, 'R': red, 'B': blue.
  int bicolorable; // To show if the graph if bicolorable.
  int temp1, temp2; // Temporary variable for swapping operation.
  int i, j; // Loop variable.
  
  while (1) { // Continue until the number of nodes, n, input is zero.
    scanf("%d", &n); // Input number of nodes.
    
    if (n==0) break; // If no nodes, stop the loop and terminate the program.
    
    scanf("%d", &l); // Input number of edges.
    graph = (Edge *) realloc(graph, l * sizeof(Edge));
    
    for (i=0; i<l; i++) {
      scanf("%d %d", &graph[i].n1, &graph[i].n2); // Input an edge.
      if (graph[i].n1>graph[i].n2) {
      	temp1 = graph[i].n1;
      	graph[i].n1 = graph[i].n2;
      	graph[i].n2 = temp1;
	  }
	}
	
	// Sort the edges in lexically ascending order.
	for (i=l-1; i>0; i--)
	  for (j=1; j<=i; j++) { 
	  	if ((graph[j-1].n1>graph[j].n1) || // The two edges are out of order.
		    (graph[j-1].n1==graph[j].n1 && (graph[j-1].n2>graph[j].n2))) { 
		  temp1 = graph[j-1].n1; // Swap operation.
		  temp2 = graph[j-1].n2;
		  graph[j-1].n1 = graph[j].n1; 
		  graph[j-1].n2 = graph[j].n2;
		  graph[j].n1 = temp1; 
		  graph[j].n2 = temp2;
		}
	  }
	  
	for (i=0; i<n; i++) color[i] = ' '; // Unmark all nodes.
	bicolorable = 1; // Initially, assume the graph is bicolorable.
	
	// Mark the node color for all edges, if it si bicolorable.
	for (i=0; i<l && bicolorable; i++) {
	  // If the two nodes of this edge are uncolored, 
	  // mark one node 'R' and another one 'B'.
	  if (color[graph[i].n1]==' ' && color[graph[i].n2]==' ') {
	  	color[graph[i].n1] = 'R';
	  	color[graph[i].n2] = 'B';
	  }
	  // If both nodes are colored the same color, the graph is unbicolored. 
	  else if (color[graph[i].n1]==color[graph[i].n2]) bicolorable = 0;
	  else if (color[graph[i].n1]=='R' && color[graph[i].n2]==' ' )
	    color[graph[i].n2] = 'B'; // If node n1 is marked 'R', then mark n2 as 'B'.
	  else if (color[graph[i].n1]=='B' && color[graph[i].n2]==' ' )
	    color[graph[i].n2] = 'R'; // If node n1 is marked 'B', then mark n2 as 'R'.
	  else if (color[graph[i].n1]==' ' && color[graph[i].n2]=='R' )
	    color[graph[i].n1] = 'B'; // If node n2 is marked 'R', then mark n1 as 'B'.
	  else if (color[graph[i].n1]==' ' && color[graph[i].n2]=='B' )
	    color[graph[i].n1] = 'R'; // If node n2 is marked 'B', then mark n2 as 'R'.
	  else ; // This case means both nodes are colored with different colors. Do nothing.
	}
	
	// Output the result.
	if (bicolorable) printf("BICOLORABLE\n");
	else printf("NOT BICOLORABLE\n");
  }
  free(graph); // Release memory of the graph.
  return 0;
}
