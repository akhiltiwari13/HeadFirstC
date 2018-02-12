/* Program to display the face value of the card entered by the user 
 * author: @akhil
 */

#include<stdio.h>
#include<stdlib.h>

int main ()
{
	int value=0;
	char cardName[3];
	int count= 0;
	for(;cardName[0]!= 'x' | cardName[0]!= 'X';)
	{	printf("Please Enter your cards name\n");
		scanf("%2s", cardName);
		/*if( cardName[0] == 'K' || cardName[0]== 'k' || cardName[0]== 'Q' || cardName[0]=='q' || cardName[0]=='j' || cardName[0]=='J')
		  {
		  value = 10;	
		  }
		  else	 if(cardName[0]=='A' || cardName[0]=='a')
		  value= 11;
		  else
		  value = atoi(cardName);
		  printf("The face value of the card %s is %i\n", cardName, value);*/

		//whenever we need to do multiple manipulations on a single varaible using a switch-case statement is a better alternative than series of if elses.
		switch (cardName[0]){
			case 'j':
			case 'J':
			case 'q':
			case 'Q':
			case 'k':	
			case 'K':
				value=10;
				break;
			case 'a':
			case 'A':
				value=11;
				break;
			case 'x':
			case 'X': 
				printf("You chose to exit \n");
				printf("The value of the count is %d", count);
				return 0;
			default: value= atoi(cardName);
				 if(value<=1 || value>=11){
					 printf("incorrect value.\n");
					 continue;}
		}
		printf("The face value of the card is %i \n", value);
		if (value>=3 && value<= 6)
		{	printf("This is a low value card \n");
			printf("The count has gone up \n");
			count++;
		}
		else
		{
			printf("This is a high value card \n");
			printf("The count has gone down... \n");
			count--;
		}
	}
	return 0;

}
