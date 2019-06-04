/************************************************************************************/
/*Name        : Fenil Patel,Jinesh Patel,Vrajang Parikh                             */
/*Course Code : ICS4U1                                                              */
/*Date        : December 11, 2019                                                   */
/*Assignment  : ISU                                                                 */
/*File name   : search.c                                                            */
/*Description : methods in this file will take user input{element properties}       */
/*              and identify element based on that property                         */
/************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*****************************************************************/
/* search_atomic_number will take user input about atomic number */
/* and return the number as an integer value                     */
/*****************************************************************/
int search_atomic_number()
{
	system("cls");
	system ("color 3F");
	int n = 1;
	do
	{
		system("cls");
	    system ("color 3F");
		line(5);
		tab(4);
		printf("Please enter the Atomic Number: ");
		scanf("%d", &n);
	}
	while (n < 0 || n > 118);
	return n;
}

/*********************************************************************/
/* search_atomic_weight will take user input for atomic weight       */
/* It will take that weight and find corresponding atomic number     */
/* for that element and return the atomic number as an integer value */
/*********************************************************************/
int Search_atomic_weight()
{
	system("cls");
	system ("color 3F");
	// open file
	FILE *fp;
	fp = fopen("mass.txt", "r");  // opening file
	float input = 0;   // inputted mass
	float in;		   // temp value for inputted mass
	
	// array with mass of all 118 elements
	float weight[118] = {0};
	
	// variablel saves temporary mass of element
	float temp = 0.0;
	// index of weight array
	int i = 0;
	int atomic_num = 1;
	
	// use to find nearest value to user inputted value
	float sub_value ;
	// take user input
	
	do
	{
		system("cls");
		line(5);
		tab(4);
		printf("Please enter the Atomic Weight: ");
		scanf("%f", &input);
	}
	while (input < 0);
	
	in = input;
	
	
	if (fp == NULL)
	{
		printf("\n\n\n\t\t\tError! mass.txt has been removed from the project");
		getchar();
	}
	else
	{
	
		// save masses of each element in array
		while (!feof(fp))
		{
			fscanf(fp, "%f", &temp);
			// while there is new line character
			// do not save the value
			while ((fgetc(fp) != '\n') && (!feof(fp)))
			{
				/* do nothing */
			}
			weight[i] = temp;
			i++;
		}
		// close the file
	    fclose(fp);
	}
	
	// diffrence between input value and value in database
	sub_value = abs(weight[0] - in);
	// find smallest value of sub_value
	// one with the smallest value is that element
	
	for (int j = 0; j < 118; j++)
	{
		if (abs(weight[j] - in) < sub_value)
		{
			// determine atomic number of the element based on index number of weight array
			sub_value = abs(weight[j] - in);
			atomic_num = j + 1;
		}
	}

	return atomic_num;
}

/*****************************************************************/
/* search_name will take user input as name of element           */
/* and return the atomic number as an integer value              */
/*****************************************************************/
int search_name()
{
	system("cls");
	system("color 3F");
	
	FILE *fp;
	fp = fopen("name.txt", "r");  // opening file
	
	char name[30]; // name of element
	char temp[30]; // element found from file
	
	// atomic number
	int i = 0;
	
	if (fp == NULL)
	{
		printf("\n\n\n\t\t\tError! name.txt has been removed from the project");
		getchar();
	}
	else
	{
		// take input
		line(5);
		tab(4);
		printf("Please enter the name: ");
		fgets(name, sizeof(name), stdin);
		// compare inputted name with name in file
		
		while (fgets(temp, sizeof(temp), fp) != "\0")
		{
			i++; // increase atomic number
			if (strcmpi(temp, name) == 0)
			{
				// if they are same, stop the loop
				break;
			}
		}

		fclose(fp); // close the file
	} 
	// return value of atomic number
	return i;
}

/*****************************************************************/
/* search_symbol will take user input as symbol of element       */
/* and return the atomic number as an integer value              */
/*****************************************************************/
int search_symbol()
{
	system("cls");
	system("color 3F");
	FILE *fp;
	fp = fopen("symbol.txt", "r");  // opening file
	char name[30] = {" "};  // symbol for element
	char temp[30];  // symbol for element from file
	// atomic number
	int i = 0;
	
	if (fp == NULL)
	{
		printf("\n\n\n\t\t\tError! name.txt has been removed from the project");
		getchar();
	}
	else
	{
	
		// take input number
		line(5);
		tab(4);
		printf("Please enter the symbol: ");
		fgets(name, sizeof(name), stdin);
		
		// loop through file
		while (fgets(temp, sizeof(temp), fp) != "\0")
		{
			i++; // increase atomic number
			if (strcmpi(temp, name) == 0)
			{
				//if both symbol are equal
				break;
			}
		}
		
		fclose(fp); // close the file
	}
	return i;   // return value of atomic number
}

