//============================================================================
// Name        : Tetris.cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Tetris...
//============================================================================
#ifndef TETRIS_CPP_
#define TETRIS_CPP_
#include "util.h"
#include <iostream>
#include<vector>
#include<algorithm>
//#include<cstdlib>
#include<ctime>
#include<string>
//#include<sys/wait.h>
//#include<stdlib.h>
//#include<stdio.h>
#include<unistd.h>
#include<sstream>
#include<cmath>      
using namespace std;


void SetCanvasSize(int width, int height) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
    glMatrixMode( GL_MODELVIEW);
    glLoadIdentity();
}
int bx,by,si=240,menu=0,go=0,old=0,DISPLAY=1,allow=0;
int bonus,level=1;
int arrx[5],arry[5];
void Food(int)
{
   //x-axis
   for(int i=0;i<2;i++)
   {
   arrx[i]=76+(rand()%800)+4;
  // arrx[i]=((arrx[i]/15)*15);
  
   }
   //y-axis
    for(int i=0;i<2;i++)
   {
   
   arry[i]=76+(rand()%800)+4;
  // arry[i]=((arry[i]/15)*15);
   
   }
   bonus++;
	glutPostRedisplay();

    glutTimerFunc(50000.0 / FPS, Food, 0);

}

void B_Food(int)
{
   //x-axis
   
   bx=80+(rand()%870)+4;
   bx=((bx/15)*15);
  
   
   //y-axis
   
   by=80+(rand()%870)+4;
   by=((by/15)*15);
   	
    
	glutPostRedisplay();

    glutTimerFunc(100000.0 / FPS, Food, 0);
}



int h1=141,h2=148,ch=9;
int temp1=0,temp2=0;
int ARR[500][2]={{116,140},{100,140}};
double startx=320,starty=400;
int temp3=0,temp4=0;
int score=1,sizee=3;
void Display(){
   

     glClearColor(0/*Red Component*/, 0.0/*Green Component*/,
            0.0/*Blue Component*/, 0 /*Alpha component*/);// Red==Green==Blue==1 --> White Colour
    glClear(GL_COLOR_BUFFER_BIT);   //Update the colors  
    
    string scr= to_string(score);
    string lvl= to_string(level);
    
    if(allow==1)
    {
    DrawSquare( 000 , 000 ,1000,colors[DARK_GREEN]);
    DrawSquare( 35 , 55 ,900,colors[OLIVE]);
    DrawSquare( 75 , 97.5, 820,colors[BLACK]);  
  DrawString( 81, 70.5, "Level :"+lvl, colors[MISTY_ROSE]);
  DrawString( 756, 70.5, "SCORE ="+scr, colors[MISTY_ROSE]); 
  DrawString( 81, 927, "PROGRESS", colors[MISTY_ROSE]); 
  }  
     
    if(ch==0)
    {
     h1-=15;
     if(h1<=79)
     h1=893;   
    }
    
    else if(ch==1)
    {
     h1+=15;
     if(h1>=893)
      h1=79;
    }
     
    else if(ch==2)
    {
     h2+=15;
     if(h2>=922)
      h2=97;
    }
     
    else if(ch==3)
    {
     h2-=15;
          if(h2<=97)
      h2=922;
    } 
    
    temp1=h1-5;
    temp2=h2-5;
   
	
    
    
  for(int i=0;i<=sizee;i++)
  {
    temp3=ARR[i][0];
    temp4=ARR[i][1];
    ARR[i][0]=temp1;
    ARR[i][1]=temp2;
    temp1=temp3;
    temp2=temp4; 
   }
   
    for(int i=0;i<=sizee;i++)
  {
     DrawSquare( ARR[i][0] , ARR[i][1], 13,colors[RED]);
  }  
    
  
 
DrawCircle(h1 , h2 , 10 , colors[5]); 

//food making circles!!
if(go==1)
{
for(int i=0;i<2;i++)
{
  if(i==0)
 DrawCircle(arrx[i], arry[i] , 7.5 , colors[KHAKI]); 
  else if(i==1)
 DrawCircle(arrx[i] , arry[i] , 7.5 , colors[WHITE]); 
} 
}
 
//food end; 


//collison check
int chk=15;
for(int i=0;i<2;i++)
{
if (h1 >= arrx[i] -chk && h1 <= arrx[i] + chk && h2 >= arry[i] - chk && h2 <= arry[i] + chk)
 {
    arrx[i]=80+(rand()%870);
  // arrx[i]=(arrx[i]/15)*15;
   
    arry[i]=80+(rand()%870);
   //arry[i]=(arry[i]/15)*15;
   
   if(i==0)
 DrawCircle(arrx[i], arry[i] , 7.5 , colors[KHAKI]); 
 DrawCircle(arrx[i] , arry[i] , 7.5 , colors[WHITE]); 
  
  score+=5; 
  sizee++; 
  si+=25;
 }
} 
/*bonus food

if(bonus>2)
{
 DrawCircle(bx, by , 10 , colors[TEAL]);
}  

//bonus food collision

 if (h1 >= bx -chk && h1 <= bx + chk && h2 >= by - chk && h2 <= by + chk)
 {
 score+=15;
 bx=1000000;
 by=1000000;
} 

*/

/*head collison

 for(int i=0;i<=sizee;i++)
 {
   if(h1==ARR[i][0]-h1||h2==ARR[i][1]-h2)
   {
    ch=9;
   }
  }  
*/


//progress lines
DrawLine(240, 934, 500,934 , 230, colors[WHITE]);
DrawLine(240, 934, si,934 , 230, colors[TEAL]);


//CHECK
if(si>=500)
{

 si=240;
 level+=1;
 chk+=10;
 
} 

//menu
if(menu==1)
{
   DrawSquare( 190 , 260,560 ,colors[SNOW]);
   
  DrawString( 290, 660, "PRESS P TO RESUME THE GAME", colors[BLACK]);
  DrawString( 290, 460, "PRESS E TO EXIT THE GAME ", colors[BLACK]);
  DrawString( 290, 560, "PRESS R TO RETURN TO MENU ", colors[BLACK]);
  DrawString( 200, 280, "THIS GAME IS MADE BY ABDULLAH ATTIQUE ", colors[SIENNA]); 
   
}

//display
if(DISPLAY==1)
{
 DrawSquare( 0 , 00,1000 ,colors[SNOW]);
 
  DrawString( 250,900,"WELCOME TO THE SNAKE GAME", colors[BLACK]);
  DrawString( 110, 550, "PRESS 0 TO EXIT THE GAME ", colors[BLACK]);
  DrawString( 110, 650, "PRESS 1 TO START THE GAME", colors[BLACK]);
  DrawString( 200, 50, "THIS GAME IS MADE BY ABDULLAH ATTIQUE ", colors[SIENNA]);
  
 } 
   glutSwapBuffers(); 
}




void NonPrintableKeys(int key, int x, int y) {

     

    if (key == GLUT_KEY_LEFT )   {
	
	if(ch==1)
	{
	}
	else
	ch=0;    
      
    } else if (key == GLUT_KEY_RIGHT )
     {
          if(ch==0)
          {
          }
          else
          ch=1;
    
    } else if (key == GLUT_KEY_UP)
     {    
       if(ch==3)
       {
       }
       else
       ch=2;
    }
    else if (key == GLUT_KEY_DOWN)   
     {
    if(ch==2)
    {
    }
    else
    ch=3;		
    }
    
    
     glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
    if (key == KEY_ESC)
    {
      old=ch;
      ch=9;
      menu=1; 
      go=0;  
    }
    if (key == 'E' || key=='e')
    {
        exit(1); 
    	
    }
    
    else if  (key == 'P' || key=='p')
    {  
       old=ch;
       menu=0;
       go=1; 
    }
    
    if (key == '1' )
    {
     allow=1;
     go=1;
     ch=1;
     DISPLAY=100;
    } 
    
     if (key == '0' )
    {
    exit(0);
    }
    
     if (key == 'R' || key=='r')
    {
     allow=0;
     go=0;
     ch=9;
     DISPLAY=1;
    } 
     
    glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */

void Timer(int m) {


	glutPostRedisplay();

    glutTimerFunc(1000.0 / FPS, Timer, 0);
}

/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {
    int width = 1000, height = 1000; // i have set my window size to be 800 x 600
    InitRandomizer(); // seed the random number generator...
    glutInit(&argc, argv); // initialize the graphics library...

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
    glutInitWindowPosition(50, 50); // set the initial position of our window
    glutInitWindowSize(width, height); // set the size of our window
    glutCreateWindow("PF's Snake Game"); // set the title of our game window
    SetCanvasSize(width, height); // set the number of pixels...

// Register your functions to the library,
// you are telling the library names of function to call for different tasks.
//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
    glutDisplayFunc(Display); // tell library which function to call for drawing Canvas.
    glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
    glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
    glutTimerFunc(5.0 / FPS, Timer, 0);
      glutTimerFunc(5.0 / FPS, Food, 0);

// now handle the control to library and it will call our registered functions when
// it deems necessary...
    glutMainLoop();
    return 1;
}
#endif /* Snake Game */

