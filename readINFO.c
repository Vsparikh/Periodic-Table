/************************************************************************************/
/*Name        : Vrajang Parikh                                                      */
/*Course Code : ICS4U1                                                              */
/*Date        : December 11, 2018                                                   */
/*Assignment  : ISU                                                                 */
/*File name   : readINFO.c                                                          */
/*Description : method in this file will take atomic number and display information */
/*              about the element for that atomic number                            */
/************************************************************************************/
#include<stdio.h>
#include<stdlib.h>

/******************************************************************/
/* display_info will take atomic number as an integer and retrieve*/
/* information about the element with that atomic number. It will */
/* also indent the data and display that on screen                */
/******************************************************************/
void display_info( int atomicNum)
{
	system("cls");
	system("color F1");
	
	int blank = 0; /*number of blank lines*/
	FILE *fp1;     /*object for file*/
	char ch;
	char c;
	//opening file  
	fp1 = fopen("Database.txt", "r");
	
	if (fp1 == NULL) 
	{
		printf("\n\n\n\t\t\tError! Database.txt has been removed from the project");
		getchar();
	}
	else 
	{
	
		// retrieving information and display it
		while ((ch = fgetc(fp1)) != EOF)
		{
			if (ch  == '\n')
			{
				if ((ch = fgetc(fp1))  ==  '\n')
				{
					fseek(fp1, -1, 1);
					blank++;
				}
				if (blank == (atomicNum - 1))
				{
					printf("\n");
				}
			}
			if (blank == (atomicNum - 1))
			{
				printf ("%c", ch);
			}
		}
	}
}

