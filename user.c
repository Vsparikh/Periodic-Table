/************************************************************************************/
/*Name        : Vrajang Parikh                                                      */
/*Course Code : ICS4U1                                                              */
/*Date        : December 11, 2018                                                   */
/*Assignment  : ISU                                                                 */
/*File name   : user.c                                                              */
/*Description : method in this file will handle option 2 and 3 in main menu.It will */
/*              take user input and write in the file and retrieve user information */
/*              from file and display it			               	    */
/************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

/***********************************************************/
/* take_input will take user input unless ~ is pressed.    */
/* It will also write that input in a file named user.txt  */
/***********************************************************/
void take_input()
{
	FILE *fp;
	fp = fopen("user.txt", "a");  // opening file
	system("color F1");
	system ("cls");
	
	// displaying instruction
	line(5);
	tab(4);
	printf("Prese enter to add the information {press ~ to end}");
	getchar();
	getchar();
	system("cls");
	
	// input
	char c = getchar();
	while (c  != '~')
	{
		// writing in the file
		if (c == '\n')
			fprintf(fp, "\n");
		else if (c == '\t')
			fprintf(fp, "\t");
		else
			fprintf(fp, "%c", c);
		c = getchar(); 
	}
	
	fclose(fp); // closing file
}
/************************************************************************/
/* print_user_input will print previously entered information on screen */
/************************************************************************/
void print_user_input()
{
	system("color F1");
	system ("cls");
	FILE *fp;
	fp = fopen("user.txt", "r");  // opening file
	char c = '0';
	if (fp == NULL)
	{
		printf("\n\n\n\t\t\tError! user.txt has been removed from the project");
		getchar();
	}
	else
	{
		// printing from file
		while ( c != EOF)
		{
			c = fgetc(fp);
			printf("%c", c);
		}
		fclose(fp); // closing file
	}
}

