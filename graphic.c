/************************************************************************************/
/*Name        : Vrajang Parikh                                                      */
/*Course Code : ICS4U1                                                              */
/*Date        : December 11, 2019                                                   */
/*Assignment  : ISU                                                                 */
/*File name   : search.c                                                            */
/*Description : methods in this file will handle graphics for the project. It will  */
/*              display main menu, search menu, end screen and animate atom diagram */
/************************************************************************************/

#include <graphics.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <windowsx.h>
#include <mmsystem.h>
#include <dos.h>
#define PI 3.1415926535897932384626433832795


/****************************************************************************/
/* play_sound will play the sound of button clicked by calling the .wav file*/
/****************************************************************************/

void play_sound()
{
  PlaySound("D:\\C\\Periodic Table\\button-3.wav",NULL,SND_SYNC | SND_LOOP | SND_FILENAME);
}

/**********************************************************************************/
/* introduction will display introduction screen at the beginning of the program  */
/**********************************************************************************/
void introduction()
{
	int gd = DETECT,gm;
	initgraph(&gd, &gm, "C:\\TC\\BGI");	   // setting up graphics 
	
	// i - identation of word "PERIODIC"
	// j - identation of word "Table"
	int i = 30;
	int j = 130;
	
	//background
	setfillstyle(1, 9);
	bar(0, 0,800,800);
	
	// font size and colour
	setbkcolor(9);
	setcolor(10);
	settextstyle(10, HORIZ_DIR, 9);
	
	// using delay function for animation
	outtextxy(i,50,"P");
	delay(100);
	outtextxy(i + 70,50 ,"E");
	delay(100);
	outtextxy(i + 140,50 ,"R");
	delay(100);
	outtextxy(i + 210,50 ,"I");
	delay(100);
	outtextxy(i+ 280,50 ,"O");
	delay(100);
	outtextxy(i+ 350,50 ,"D");
	delay(100);
	outtextxy(i+ 420,50 ,"I");
	delay(100);
	outtextxy(i + 490,50 ,"C");
	delay(100);
	outtextxy(j,150 ,"T");
	delay(100);
	outtextxy(j+ 70,150 ,"A");
	delay(100);
	outtextxy(j+ 140,150 ,"B");
	delay(100);
	outtextxy(j+ 210,150 ,"L");
	delay(100);
	outtextxy(j+ 280,150 ,"E");
	delay(100);	   

	// displaying creators 
	settextstyle(3,0,1);
	outtextxy(130,450, "BY:Vrajang Parikh");

	//  calling image 
	readimagefile("intro.gif",210,235,410,435);
	getch();
	closegraph();	 // closing the console
}

/*********************************************************************/
/*table() will display picture of periodic table on screen           */
/*********************************************************************/
void table()
{	 
    initwindow(1000,562,"Periodic table"); // setting up window
	readimagefile("table.jpg", 0, 0, 1000, 562); // calling image
} 

/*************************************************************/
/* main_menu will display 5 options and take user            */
/* input on that option using buttons.Return: option number  */
/* options: 1- search elements                        	 	 */
/*	        2- add information                       	     */
/*	        3- access information entered earlier         	 */
/*	        4- quit                                   		 */
/*          5- User manual                            		 */
/*************************************************************/
int main_menu()
{
	// setting up graphics 
	int gd = DETECT,gm;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	
	// mouse coordinates
	int mousex, mousey;
	
	// default value of option
	int option = 1; 
					
	// display title		
	setfillstyle(1, 9);
	bar(0, 0,800,800);
	setfillstyle(1,10);
	bar(15, 20,650,40);
	setbkcolor(9);
	settextstyle(8, HORIZ_DIR, 14);
	outtextxy( 400,50 ,"PERIODIC TABLE");
	
	// displaying buttons
	setfillstyle(1,12);
	bar(150,200, 450,230);	  
	setbkcolor(12);
	settextstyle(10, HORIZ_DIR, 3);
	outtextxy( 257,205 ,"Explore");
		
	setfillstyle(5,12);
	bar(150,250, 450,280);
	setbkcolor(12);
	settextstyle(10, HORIZ_DIR, 3);
	outtextxy( 195,255 ,"Add information");	
	   	   	   
	setfillstyle(1,12);
	bar(150,300, 450,330);
	setbkcolor(12);
	settextstyle(10, HORIZ_DIR, 3);
	outtextxy( 160,305 ,"Access user database");
	
	setfillstyle(1,12);
	bar(150,350, 450,380);
	setbkcolor(12);
	settextstyle(10, HORIZ_DIR, 3);
	outtextxy( 270,355 ,"Quit");
	
	setfillstyle(1,12);
	bar(150,400, 450,430);
	setbkcolor(12);
	settextstyle(10, HORIZ_DIR, 3);
	outtextxy( 230,405 ,"User manual");
	
	// infinite loop 
	// only end if buttton is pressed
	while(3>1)
	{
		// getting mouse click and coordiantes
		getmouseclick (WM_LBUTTONDBLCLK, mousex,mousey);
		
		// if mosue clicks are inside button areas loop is break
		// playing the sound when button is presssed
		
		if(	WM_LBUTTONDOWN  && mousex >= 150 && mousex <=450 && mousey >= 400 && mousey <= 430  )
		{
			play_sound();
			option = 5;
			break;
		}
		if(	WM_LBUTTONDOWN  && mousex >= 150 && mousex <=450 && mousey >= 350 && mousey <= 380 )
		{
		    play_sound();
			option = 4;
			break;
		}
		
		if(	WM_LBUTTONDOWN  && mousex >= 150 && mousex <=450 && mousey >= 300 && mousey <= 330  )
		{
			play_sound();
			option = 3;
			break;
		}
		
		if(	WM_LBUTTONDOWN  && mousex >= 150 && mousex <=450 && mousey >= 250 && mousey <= 280 )
		{
			play_sound();
			option = 2;
			break;
		}
		
		if(	WM_LBUTTONDOWN  && mousex >= 150 && mousex <=450 && mousey >= 200 && mousey <= 230  )
		{
			play_sound();
			option = 1;
			break;
		}
		
	}

	closegraph(); 	// closing graphic console
	return option;   // returning option
}
/************************************************************/
/* search_menu will display 4 options and take user         */
/* input on that option using buttons Return: option number */
/* options: 1-  search by atomic number              	    */
/*	        2-  search by atomic weight                 */
/*	        3-  search by name              	    */
/*	        4-  search by symbol                   	    */
/************************************************************/
int search_menu()
{

	// setting up graphics 	   
	int gd = DETECT,gm;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	
	// mouse coordinates
	int mousex, mousey;
	
	// default value of option
	int option = 1;
	
	
   	// background	 	 
	setfillstyle(1, 9);
	bar(0, 0,800,800);
	
	// green bar 
	setfillstyle(1,10);
	bar(15, 20,650,40);
	
	// title
	setbkcolor(9);
	settextstyle(8, HORIZ_DIR, 14);
	outtextxy( 400,50 ,"PERIODIC TABLE");
	
	// displaying buttons	
	setfillstyle(1,12);
	bar(100,200, 520,240);
	setbkcolor(12);
	settextstyle(10, HORIZ_DIR, 3);
	outtextxy( 138,208 ,"Search by Atomic Number");
		
	setfillstyle(5,12);
	bar(100,250, 520,290);
	setbkcolor(12);
	settextstyle(10, HORIZ_DIR, 3);
	outtextxy( 138,258 ,"Search by Atomic weight");
		
	setfillstyle(1,12);
	bar(100,300, 520,340);
	setbkcolor(12);
	settextstyle(10, HORIZ_DIR, 3);
	outtextxy( 200,308 ,"Search by Name");
	
	setfillstyle(1,12);
	bar(100,350, 520,390);
	setbkcolor(12);
	settextstyle(10, HORIZ_DIR, 3);
	outtextxy( 195,358 ,"Search by Symbol");
	
	// infinite loop 
	// only end if button is pressed	  
	while(3>1)
	{
    	// getting mouse click and coordiantes
		getmouseclick (WM_LBUTTONDBLCLK, mousex,mousey);
		
		// if mosue clicks are inside button areas loop is break
		// playing sound when button is pressed
		if(	WM_LBUTTONDOWN  && mousex >= 100 && mousex <=520 && mousey >= 350 && mousey <= 390 )
		{
			play_sound();
			option = 4;
			break;
		}
		
		if(	WM_LBUTTONDOWN  && mousex >= 100 && mousex <=520 && mousey >= 300 && mousey <= 340  )
		{   
		    play_sound();
			option = 3;
			break;
		}
		
		if(	WM_LBUTTONDOWN  && mousex >= 100 && mousex <=520 && mousey >= 250 && mousey <= 290 )
		{
			play_sound();
			option = 2;
			break;
		}
		
		if(	WM_LBUTTONDOWN  && mousex >= 100 && mousex <=520 && mousey >= 200 && mousey <= 240  )
		{
			play_sound();
			option = 1;
			break;
		}
	}

	closegraph();   //closing graphic console
	return option;  // returning values 
}


/******************************************************************************/
/* fillelectron will draw electrons in an orbit. It will take spped,          */
/* x and y coordinates of orbit, radius and number of electrons to be drawn   */
/******************************************************************************/
void fillelectron(double a,int x,int y,int radius, int number)
{
	double i, angle=2*PI/number;	/*angle to equally divide electrons*/
	
	for(i=PI+a;i<=3*PI+a;i= i+angle)	/*Loop to fill electrons evenly around the ring*/
	{
		fillellipse(x+radius*sin(i),y+radius*cos(i),5,5);	/*Intense SOH CAH TOA math for coordinates*/
	}	 	 
}

/**************************************************************************/
/* animateAtom will display rotating atom on screen until 'c' is pressed  */
/**************************************************************************/
void animateAtom(int element)
{
	
	int gd = DETECT,gm;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	setbkcolor(15);
	
	int x,y, orbit, radius=25, speed = 1, e = element;
	double a=0;		/*animation variable*/
	x=getmaxx()/2;
	y=getmaxy()/2;
	
	if(element<=2)		/*Determine orbits in atom*/
		orbit=1;
	else if(element<=10)
		orbit=2;
	else if(element<=28)
		orbit=3;
	else if(element<=60)
		orbit=4;
	else if(element<=110)
		orbit=5;
	else if(element<=182)
		orbit=6;
		
		speed = 2*orbit;
	do	/*Animation loop*/
	{
		cleardevice();
		setcolor(RED);
		setfillstyle(1,4);
		
		fillellipse(x, y, 25, 25);	/*nucleus*/
		setfillstyle(1,0);
		e = element;				/*e is set back to element because it is changed*/
	
		setcolor(BLACK);
		for (radius = 50; radius <= 25*(orbit+1); radius = radius + 25)	/*Loop for drawing energy shells*/
		{		
			setfillstyle(1,1);
			circle(x, y, radius);	/*energy shell*/
			
			if(radius!= 25*(orbit+1) )	/*filling in electrons in full levels*/
			{
				fillelectron(a*speed,x,y,radius, (2*pow(((radius-25)/25),2)) );
				e = e - 2*pow(((radius-25)/25),2);
			}
			else						/*filling in valence electrons*/
				fillelectron(a,x,y,radius,e);
			speed=speed-2;	  	  	  /*change speed (inch of 0.5 makes everything move at same speed)*/		   	   	   	   
		}
		/*delay(100);	---->  use instead of speed if it is automated loop*/
		speed= 2*orbit;	   	   /*used for different speed of rotation*/
		a= a+0.01 ;		/*change to move greater or lesser dist on each input*/
		
		
		settextstyle(9, HORIZ_DIR, 12);
	    outtextxy( x - 75,getmaxy()-35 ,"Press c to quit ");
	}
	while(getch()!='c' && getch() !='C');/*runs while something besides 'c' is pressed*/
	
	closegraph(); // closing the console
}

/********************************************************************/
/* tab will take an integer and put that number of \t on the screen */
/********************************************************************/
void tab(int n)
{
    printf("\n");
	int i =0;
    for( i =0; i<n;i++)
    {
        printf("\t");
    }
}

/********************************************************************/
/* line will take an integer and put that number of \n on the scree */
/********************************************************************/
void line(int n)
{
	int i =0;

    for( i =0; i<n;i++)
    {
         printf("\n");
    }

}

/*******************************************************************/
/* display_end_screen will display thank you message on the screen */
/*******************************************************************/
void display_end_screen()
{
	// displaying end screen in normal console
    system("cls");
	system ("color 3F");   
    line(5);
    tab(4);
    printf("Thank you for Using the application");
    getchar();
}

/**************************************************************/
/* end will display thank you image on the screen             */
/**************************************************************/
void end()
{
	 initwindow(600,320,"Periodic table");
	 readimagefile("END.jpg",0,0,600,320);
	 getch();
	 closegraph();
}


