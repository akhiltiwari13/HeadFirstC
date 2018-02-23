#include<stdio.h>
// including the header file here was giving the error for multiple declaration of the num and dates variables.
//#include"./required_data.h"

// The fuction declaration needs to be extracted out of the header file and pasted here.
int match_bieber(char * str);
int match_chess_and_work_out(char * str);
int match_books_and_theater(char * str);
int match_sports_or_working_out(char * str);

void find(int (*match)(char * str));

void main()
{
  find(&match_bieber);
  find(&match_chess_and_work_out);
  find(&match_books_and_theater);
  find(&match_sports_or_working_out);
}
