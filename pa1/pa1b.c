/* Programming Assignment 1: Exercise B
 *
 * Now we will expand the program of Exercise A to call Fork () multiple times.
 * Run the program below and answer the following questions:
 *
 * 1. Can you explain the order of what gets printed based on the code?
 *	  The parent process first prints. Then child process prints in order from the first to the last.
 * 2. Why do you think the first child executes before the second child?
 *	  Because the first child executes the print statement before the second child.
 * 3. Move the two print statements executed by the parent to just after
 * where it says HERE.  How can you print the pid of the first child?
 *	  Create a new variable pid1 wich stores the pid of the first child.
 */

#include <stdio.h>
#include "aux.h"
#include "umix.h"

void Main ()
{
	int pid = 0;
	int pid1 = 0;

	if ((pid1 = Fork ()) == 0) {

		/* first child executes here */
		Printf ("I am the first child, my pid is %d\n", Getpid ());
		Exit ();
	}

	if ((pid = Fork ()) == 0) {

		/* second child executes here */
		Printf ("I am the second child, my pid is %d\n", Getpid ());
		Exit ();
	}

	/* HERE */
	Printf ("I am the parent, my pid is %d\n", Getpid ());
	Printf ("I just created a child process whose pid is %d\n", pid1);
	Printf ("I (the parent) just created a second child process whose pid is %d\n", pid);
}
