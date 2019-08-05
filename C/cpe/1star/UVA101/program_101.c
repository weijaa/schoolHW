// One-star problem
// Problem UVA101 The Blocks Problem
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

// Stack type definition with array implementation
typedef struct {
  int data[24]; // Maximum 24 elements
  int top; // Top pointer
} Stack;

// Initial stack s.
void initial_stack(Stack *s) {
  s->top = -1;
}

// Check if stack s is empty.
int isempty(Stack s) {
  return s.top<0;
}

// Retrun the top element of stack s.
int top(Stack s) {
  return s.data[s.top];
}

// Push element e to stack s.
void push(Stack *s, int e) {
  s->data[++s->top] = e;
}

// Pop the top element from stack s.
int pop(Stack *s) {
  return s->data[s->top--];
}

// Check whether e is in stack s.
int find(Stack s, int e) {
  int i;
  
  for (i=0; i<=s.top; i++) 
    if (s.data[i]==e) return 1;
  return 0; 
}

// Print all elements of a stack from top to bottom.
void print_stack(Stack s) {
  int i;
  
  for (i=0; i<=s.top; i++) printf(" %d", s.data[i]); // No trailing space is output for the last block.
  printf("\n");
}

int main(void) {
  Stack line[24], temp;
  int n;
  int i;
  char cmd1[5], cmd3[5];
  int cmd2, cmd4;
  int loc_a, loc_b, elem, step=0;
  
  scanf("%d", &n); // Input the number of blocks.
  for (i=0; i<n; i++) { // Initial blocks of line[0] to line[n-1], using stack structure.
    initial_stack(&line[i]); // Initial stack i.
    push(&line[i], i); // Place block i into stack i.
  }
  
  initial_stack(&temp); // Set temporary stack to empty.
  
  scanf("%s", &cmd1); // Get the first command word.
  while (strcmp(cmd1, "quit")) { // Not "quit", perform the move or pile steps.
    scanf("%d %s %d\n", &cmd2, &cmd3, &cmd4); // Input the rest word of the command.
    
    for (i=0; i<n; i++) {
      if (find(line[i], cmd2)) loc_a = i; // Find the line location of element a.
      if (find(line[i], cmd4)) loc_b = i; // Find the line location of element b.
    }
    
    if (loc_a!=loc_b) { // if a equals to b or a and b are in the same stack, ignore the command.
      if (!strcmp(cmd1, "move")) { // "Move" command.
        if (!strcmp(cmd3, "onto")) { // "Move a (cmd2) onto b (cmd4)" command.
          // Place the elements on top of b to its initial location.
          while ((elem = pop(&line[loc_b]))!=cmd4) push(&line[elem], elem); 
          push(&line[loc_b], elem); // Restore element b. 
          // Place the elements on top of a to its initial location.
          while ((elem = pop(&line[loc_a]))!=cmd2) push(&line[elem], elem);
          push(&line[loc_b], elem); // Move a onto the top of b.           
        }
        else if (!strcmp(cmd3, "over")) { // "Move a over b" command.
          // Place the elements on top of a to its initial location.
          while ((elem = pop(&line[loc_a]))!=cmd2) push(&line[elem], elem);
          push(&line[loc_b], elem); // Move a to the top of the stack containing element b.     
        }
      }
      
      if (!strcmp(cmd1, "pile")) { // "Pile" command.
        if (!strcmp(cmd3, "onto")) { // "Pile a onto b" command.
          // Place the elements on top of b to its initial location.
          while ((elem = pop(&line[loc_b]))!=cmd4) push(&line[elem], elem); 
          push(&line[loc_b], elem); // Restore element b.
          // Push the elements on top of a to the temporary stack.
          while ((elem = pop(&line[loc_a]))!=cmd2) push(&temp, elem);
          push(&temp, elem); // Push a to the temporary stack.
          // Dump the elements in the temporary stack on the top of block b.
          while (!isempty(temp)) push(&line[loc_b], pop(&temp));           
        }
        else if (!strcmp(cmd3, "over")) { // "Pile a over b" command.
          // Push the elements on top of a to the temporary stack.
          while ((elem = pop(&line[loc_a]))!=cmd2) push(&temp, elem);
          push(&temp, elem); // Push a to the temporary stack.
          // Dump the elements in the temporary stack on the top of block b.
          while (!isempty(temp)) push(&line[loc_b], pop(&temp));      
        }
      }
    }
    scanf("%s", &cmd1); // Get the first word of the next command.
  }
  
  // Output the final result.
  for (i=0; i<n; i++) {
    printf(" %d:", i); // Output stack i. 
    print_stack(line[i]); // Output the blocks in stack i.
  }
  return 0;
} 
