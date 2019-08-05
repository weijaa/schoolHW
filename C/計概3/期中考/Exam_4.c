#include <stdio.h>
#include <string.h>

struct Customer_t
{
  char name[10];
  int next;
};

/*******Fix start*******/
// 使用typedef定義結構為Customer
// 生成全域變數陣列database，並初始化數值
// Use typedef to define structure as Customer.
// Declear a global variable array "database", and initialize it.

/*******Fix end*******/


int findName (Customer db[], char tName[])
{
  /*******Fix start*******/

  /*******Fix end*******/
}

int removeNext (Customer db[], int current)
{
  /*******Fix start*******/

  /*******Fix end*******/
}

int main ()
{
  int iPrev = findName (database, "Terry");
  printf ("Previous is %d \n", iPrev);

  int NumBeRemoved = removeNext(database, 3);
  printf ("The removed data number is %d", NumBeRemoved);
  return 0;
}
