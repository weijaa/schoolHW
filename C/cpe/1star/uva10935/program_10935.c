// One-star problem
// Problem 10935 Throwing Cards Away I
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
  int cards[50]; // At most 50 cards in a deck.
  int n; // Number of the total cards.
  int count; // Number of cards in the deck.
  int thrown; // 1: throw the next card; -1: keep the card in the deck.
  int top; // The card on the top.
  int i; // Loop variable.
  
  while (1) {// Continue unitil 0 is input
    scanf("%d", &n); // Input the number of cars.
	if (n==0) break; // If 0 is input, stop the loop and terminate the program.
	for (i=0; i<n; i++) cards[i] = 1; // card[i]==1 means card i+1 is still in the deck.
	count = n; // At the beginning, there are n cards in the deck.
	thrown = 1; // The top of the card will be thrown away.
	top = 0; // The top of the deck is 1.
	printf("Discarded cards: "); // Output the message text.
	while (count>1) { // Continue the process, when there two or more cards in the deck.
	  if (cards[top]) { // If cards[top] is one, this card will be inspected.
	  	if (thrown) { // If this card will be thrown away.
	  	  thrown = 0; // The next card will be kept.
	  	  count--; // One card is thrown.
	  	  cards[top] = 0; // Mark the card is thrown away.
	  	  printf("%d, ", top+1); // The care number is 1 greater than the top index.
	    }
	    else { // The card is kept.
	      thrown = 1; // The next card will be thrown away.
		}
	  	top =  (top + 1) % n; // Check the next card.
	  }
	  else top =  (top + 1) % n; // Check the next card.		
	}
	for (i=0; i<n; i++) // Search for the remaining card.
	  if (cards[i]) {
	    printf("\nRemaining card: %d\n", i+1);
	    break;
      }
  }
  return 0;
}
