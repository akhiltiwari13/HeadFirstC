#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"./island_node.h"

void display(island * node)
{
  island * local= node;
  printf("\n--------------------------------\n" );
  while(local != NULL ){
    printf("Island Name:-%s\n",local->name );
    printf("Island Opens:-%s\n",local->opens);
    printf("Island Closes:-%s\n",local->closes);
    if(local->next!=NULL)printf("Next Island Linked:-%s\n",(local->next)->name);
    printf("--------------------------------\n" );
    local=local->next;
  }
}

island* create(char * name)
{
  char * local_name= strdup(name);
  island* local_island= malloc(sizeof(island));
  local_island->name=local_name;
  local_island->opens="7:00";
  local_island->closes="21:00";
  local_island->next=NULL;
  return local_island;
}

void free_memory(island* start)
{
  island* current = start;
  island * next;
  for(;current != NULL; current=next)
  {
    next=current->next;
    free(current->name);
    free(current);
  }
}

void append(island * node, island * start)
{
  island * lstart=start;
  while(start->next !=NULL)
  start=start->next;
  start->next=node;

}
