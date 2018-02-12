typedef struct island{
  char * name;
  char * opens;
  char * closes;
  struct island* next;
}island;

void display(island * node);
island* create(char * name);
void free_memory(island * node);
void append(island * node, island * start);
