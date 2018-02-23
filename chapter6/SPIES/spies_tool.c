#include <stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
    char * question;
    struct node * no;
    struct node * yes;
}node;

int yes_no(char * question)
{
  char answer[3];
  printf("%s:\n", question);
  fgets(3,answer, stdin);
  return answer[0]=='y';
}

node* create(char *question)
{
  node * n= malloc(sizeof(node));
  n->question=question;
  n->no=NULL;
  n->yes=NULL;
  return n;
}

void release(node *n)
{
  if (n) {
        if(n->no)
        release(n->no);
        if(n->yes)
        release(n->yes);
        if(n->question)
        free(n->question);
        free(n);
  }
}

int int main() {
  // no need to copy entire program
  // I got the flaw that caused the memory leak
  // the question of one node was being changed without actuall free the memory taken up by the previous strdup function.
  return 0;
}
