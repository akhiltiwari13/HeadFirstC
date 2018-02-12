#include<stdio.h>

typedef enum relationship_future{ DUMP, SECOND_CHANCE, MARRIAGE, MURDER}relationship_future;

typedef struct relationship_partner{
  char * name;
  relationship_future future;

}relationship_partner;

void dump(relationship_partner  partner)
{
  printf("Dear %s,\n", partner.name);
  puts("I am DUMPING your pathetic ass");
};

void second_chance(relationship_partner  partner)
{
  printf("Dear %s,\n", partner.name);
  puts("I giving you a SECOND_CHANCE chance");
};

void marriage(relationship_partner  partner)
{
  printf("Dear %s,\n", partner.name);
  puts("I am WEDDING your pathetic ass");
};

void murder(relationship_partner  partner)
{
  printf("Dear %s,\n", partner.name);
  puts("I am KILLING your pathetic ass");
};

int main()
{
  relationship_partner p1= {"matt", MURDER };
  relationship_partner p2= {"stefan", MARRIAGE };
  relationship_partner p3= {"damon", MARRIAGE };
  relationship_partner p4= {"ric", MURDER };
  relationship_partner p5= {"jeremy", SECOND_CHANCE };
  relationship_partner p6= {"elena", DUMP };
  relationship_partner p7= {"klaus", MURDER };

  relationship_partner arr[]= {p1, p2, p3, p4, p5, p6, p7};

  void (* rel_outcome[])(relationship_partner)={&dump, &second_chance, &marriage, &murder};

  for(int i=0; i<7; i++)
  (*rel_outcome[arr[i].future])(arr[i]);

  return 0;
}
