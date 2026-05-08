/* hello1.c
 *	purpose	 show the minimal calls needed to use curses
 *	outline  initialize, draw stuff, wait for input, quit
 */

#include	<stdio.h>
#include	<curses.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
	initscr() ;		/* turn on curses	*/

  char *message;
  int tracker;

  if(argc > 1){
      tracker = 1;
} else {
      message = "Hello, World";
      tracker = 0;
  }

  int col = (COLS - strlen(message)) / 2;
  int row = LINES / 2;

				/* send requests	*/
	clear();			/* clear screen	*/

  for(int i = 0; i < 10; i++){

	    move(row,col);			/* centres to middle of screen	*/
      int tempCol = col;
      if(tracker == 1) { 
          for(int i = 1; i < sizeof(argc); i++) {
              addstr(argv[i]);
              if(i + 1 < sizeof(argc)){
                  addstr(" "); 
              }
          }
    } else {
	        addstr(message);		/* add a string	*/
    }
	    refresh();		/* update the screen	*/
      sleep(1);
      clear();
      refresh();
      sleep(1);
  }

	endwin();		/* turn off curses	*/
}
