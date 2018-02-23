#include<stdio.h>
#include"./island_node.h"

int main()
{
  island * i1= create("Mauritius");
  island * i2= create("Andaman");
  island * i3= create("Nicobar");
  island * i4= create("Lakshadweep");

  append(i2,i1);
  append(i3,i1);
  append(i4,i1);

  display(i1);

  free_memory(i1);
}
