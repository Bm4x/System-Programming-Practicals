/* sigdemo3.c
 *	purpose:   show answers to signal questions
 *	question1: does the handler stay in effect after a signal arrives?
 *  Whatever was typed before the signal arrived is forgoten can cleared, and onced the signal arrives the 
 *  signal handler for the signal sent is executed.
 *
 *	question2: what if a signalX arrives while handling signalX?
 *  When signalX arrives while handling SignalX, the handler is cleared and repeats the signal handler for sigX.
 *
 *  question3: what if a signalX arrives while handling signalY?
 *  
 *
 *  question4: what happens to read() when a signal arrives?
 *
 *
 */

#include	<stdio.h>
#include	<signal.h>
#include <string.h>
#include <unistd.h>

#define	INPUTLEN	100

int main(int ac, char *av[])
{
	void	signalhandler(int);
	char	input[INPUTLEN];
	int	nchars;

	signal(SIGINT,  signalhandler );		/* set handler */
	signal(SIGQUIT, signalhandler );		/* set handler */

	do {
		printf("\nType a message\n");
		nchars = read(0, input, (INPUTLEN-1));
		if ( nchars == -1 )
			perror("read returned an error");
		else {
			input[nchars] = '\0';
			printf("You typed: %s", input);
		}
	} 
	while( strncmp( input , "quit" , 4 ) != 0 );
}

// this handles SIGINT (2) and SIGQUIT (3)
// checks using if statements
void signalhandler(int s){
  if(s == SIGINT){
	    printf(" Received signal %d .. waiting\n", s );
	    sleep(2);
	    printf("  Leaving inthandler \n");
    }
  if(s == SIGQUIT){
  	  printf(" Received signal %d .. waiting\n", s );
	    sleep(3);
	    printf("  Leaving quithandler \n");
    }
}

