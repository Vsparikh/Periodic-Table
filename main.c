/************************************************************************************/
/*Name        : Fenil Patel,Jinesh Patel,Vrajang Parikh                             */
/*Course Code : ICS4U1                                                              */
/*Date        : December 11, 2019                                                   */
/*Assignment  : ISU                                                                 */
/*File name   : main.c                                                              */
/*Description : All the functions from other files are invoked in this              */
/*              file to execute project                                             */
/************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// including files
#include "graphic.c"
#include "search.c"
#include "user.c"
#include "readINFO.c"
int main()
{
	int opt = 4; // option selected by user
	
	/* 1- search elements
	*  2- add information
	*  3- access informaiton entered earlier
	*  4- quit
	*  5- User manual
	*/
	
	introduction(); // invoking introduction()
	table(); // drawing table
	do
	{
		opt =  main_menu(); // invoking main menu to get option
		// if user wants to search elements
		if (opt == 1)
		{
			int type = search_menu(); // different options for search
			/*
			* 1- atomic number
			* 2- atomic weight
			* 3- name
			* 4- symbol
			*/
			int atom_num = 1; // atomic number
			if (type == 1)
			{
				// get atomic number
				atom_num = search_atomic_number();
			}
			else if (type == 2)
			{
				//search_atomic_weight converts mass into atomic number
				atom_num = Search_atomic_weight();
			}
			else if (type == 3)
			{
				// convert name into atomic number
				atom_num = search_name();
			}
			else if (type == 4)
			{
				// convert symbol into atomic number
				atom_num = search_symbol();
			}
			// display information based on atomic number
			display_info(atom_num);
			// display atom diagram
			animateAtom(atom_num);
		}
		else if (opt == 2)
		{
			// take information from user and save into file
			take_input();
		}
		else if (opt == 3)
		{
			// retrieve earlier information saved in user database
			print_user_input();
		}
		else if (opt == 5)
		{
			// open web browser to display user manual
			system("START https://docs.google.com/document/d/1ckGt8uxXy6FD3YmkzuRfVF9SHlF0Leew5E1wC5KUt3M/edit?usp=sharing");
		}
	}
	while (opt != 4); // run until user decides to quit
	
	// display end screens
	end();
	display_end_screen();
	return 0;
}

