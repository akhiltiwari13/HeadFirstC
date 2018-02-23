#include<stdio.h>
#include<string.h>
#include"./required_data.h"

void find(int (*match)(char * str))
{
  printf("\n" );
  puts("-------------------------");
  puts("Search Results:");
  puts("-------------------------");

  for(int i=0; i<num; i++)
  {
    if((*match)(dates[i]))
    printf("%s\n",dates[i] );
  }
  printf("\n" );
  printf("\n" );
};

int match_bieber(char * str){
return strstr(str, "bieber");
};

int match_chess_and_work_out(char * str){
return (strstr(str, "working out")&& strstr(str, "chess"));
};

int match_books_and_theater(char * str){
return (strstr(str, "books")&&strstr(str, "theater"));
};

int match_sports_or_working_out(char * str){
return (strstr(str, "working out")||strstr(str, "sports"));
};
