Minitalk :

New function that we will use in this project is :

signal();

	-When we recieve a signal this function called a signal handler for this signal
	(signal is a message from the operating system to a program indicating that some event has occured)

	- Prototype : sighandler_t signal(int signum, sighandler_t handler);

sigemptyset();

	-This function is used to empty a signal set "takes a pointer to a set of signals as an argument and 	empties this set by adding no signal to it"
	(Signal set is a tool that helps you manage how a process interacts with signals)

	- Prototype : int sigemptyset(sigset_t *set);

sigaddset();
	
	-This function allows you to add a signal to signal set (takes two arguments: a pointer to a set of 	signals and the number of the signal to add to the set)
	
	- Prototype : int sigaddset(sigset_t *set, int signum);

	EXAMPLE : (sigemptyset & sigaddset)

	#include <signal.h>

	int main(void)
	{
    		sigset_t signal_set;

    		// Initialize an empty signal set
    		sigemptyset(&signal_set);

    		// Add SIGINT to the signal set
    		sigaddset(&signal_set, SIGINT);
	}

sigaction();
	
	-This function used to specify the action to be taken when a specific signal is received by a process.
	
	- Prototype : int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
	
	-(The "signum" specifies the signal for which the action is being specified)
	
	-(The "*act" argument is a pointer to a struct sigaction that specifies the action to be taken when the 	signal is received)
	
	-(The oldact argument is a pointer to a struct sigaction that is used to retrieve the previous action 	for 	the specified signal)

kill();

	- This function is a system call that sends a signal to a process.
	-Prototype : int kill(pid_t pid, int sig);
	(the pid argument is to select which process youre sending to the signal, and the sig is the type of the 	signal)

getpid();

	-This function return the id of the process.
	- Prototype : pid_t getpid(void);

pause();
	-This function causes the calling process to sleep until a signal is received. The process remains blocked 	until a signal handler is executed or the signal is ignored
	- Prototype : int pause(void);
sleep();

	-This function causes the process to sleep for a specified num of seconds.
	- Prototype : unsigned int sleep(unsigned int seconds);
	
usleep();
	
	-This function is like sleep() but the diff is usleep() causes the process to sleep specified num of 	microseconds.
	- Prototype : int usleep(useconds_t usec);
exit();

	- This function in the C standard library that terminates the calling process immediately.
	- Prototype : void exit(int status);

	(status : A value of 0 indicates successful termination, while non-zero values indicate an error)

Understand each one of them then start coding.
