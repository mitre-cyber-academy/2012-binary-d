Binary Exploit Challenge:
Flag: MCA-225D4AFD

Description of challenge:
Participants are provided with a Linux binary. If run, the program displays one of an assortment of messages from the Youtube video ‘Official Ojai Valley Taxidermy TV Commercial’ to standard output and refuses to be killed by SIGINT (control C). When the user attempts to kill the program in this fashion, the message ‘Nope! Chuck Testa’ is displayed on standard output. The program can still be terminated using kill -9 or SIGKILL.

When looking at the binary via object dump (or something similar), many calls to sigaction can be seen, coupled with the function catch_alarm. This latter function is a handler for signals sent by the system. A great number of signals are bound to this function using sigaction. When the handler itself is examined, there is a comparison to a given signal. If the numeric value of this signal (SIGXCPU) is sent using the kill command (or a like signal generation program), the program will print out the flag on standard out. In the worst case, a user can send all of the signals available via kill to get the flag.

Programs needed:
gcc 
kill
make
some assembly debugging tool

Files included:

Generation:
  • chuckTesta.c
    o This is the source file which includes the obfuscated flag and a few garbage functions
  • Makefile
    o This is the tool used to make the executable binary
Challenge:
  • binaryAux.bin
    o This is the challenge binary itself, compiled on Ubuntu 10.04 x86_64
