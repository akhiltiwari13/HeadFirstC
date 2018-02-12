#include<stdio.h>
#include"./testheaderfiles/testheader.h"

float total= 0;
const short tax_percent= 6;
short number_of_items= 0;
float get_tax_multiplier()
{
	return (1+ (tax_percent/100));
}

float calculate_cost_with_tax(float commodity_cost)
{
	number_of_items++;
	float taxed_cost= (commodity_cost * get_tax_multiplier());
	total = total + taxed_cost;
	return taxed_cost;
}

void main()
{
	float commodity_cost;
	testfunction();
	printf("enter the prices of the commodities \n");
	while(scanf("%f", &commodity_cost) == 1)
		printf("the cost of the current commodity inclusive of taxes is= %f\n", calculate_cost_with_tax(commodity_cost));
	printf("the total number of items are %d\n", number_of_items);
	printf("the total cost is= %f", total);
}

// moving the definition of the testfunction to a header file which has been included here.
