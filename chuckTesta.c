#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PREFERRED SIGINT

inline char fcn1(int val)
{
	return (val == SIGTSTP);
}

inline unsigned char fcn2(unsigned char toRot, unsigned char numToRot)
{
	unsigned char toRet;
	if(numToRot > 8)
	{
		toRet = toRot;
	}
	else
		toRot = toRot << numToRot | toRot >> (8 - numToRot);
	return toRot;
}
inline unsigned char fcn3(unsigned char toRot, unsigned char numToRot)
{
	unsigned char toRet;
	if(numToRot > 8)
	{
		toRet = toRot;
	}
	else
		toRot = toRot >> numToRot | toRot << (8 - numToRot);
	return toRot;
}
inline unsigned char fcn4(unsigned char tofcn4)
{
	return (255) - tofcn4;
}
inline void fcn5()
{
	int count, other;
	for(count = 0; count < 100; count += 3)
	{
		other = count % (count + 5);
		other /= count * (count * count * count);
	}
}

inline void fcn6(int x)
{
	x = (x * ((long) &x)) + (((long)&x) / 2) * 1337;
}

inline void fcn7(int y)
{
	y = ((long) &y) * (y + 7) * 7;
}

/*sigaction(SIGCHLD, &(struct sigaction){.sa_handler = SIG_IGN}, NULL);*/
void catch_alarm(int sig)
{
	char* chuck, *fl, temp;
	int count;
	unsigned int array[] = {841659538,
		1028719516, 909397802, 1754545167, 946600146, 266717345, 179636521,
		1573066716, 1494908293, 1803539398, 583497890, 2000205038, 332115872,
		831944984, 1826250297, 981620713, 1004099205, 159904560, 610855554,
		2126372486, 30679861, 3464572, 876187132, 1282339497, 1690478533,
		728574180, 1082381029, 1044530251, 1941339865, 1506061544, 461696694,
		635515755, 387297412, 1371094496, 242577274, 1333897558, 1637811842,
		422213795, 759480626, 985236487, 78269545, 1342978517, 837957877,
		410385418, 27439853, 516724526, 1392006131, 1031539058, 676629087,
		2002861685, 1010427896, 707308948, 2006326258, 1886615029, 1989648445,
		1549321143, 467705561, 924545826, 446367746, 261561778, 283123723,
		908064440, 897077533, 670421135, 131675289, 1139654808, 2004318694,
		1769487131, 1561868603, 616315672, 607239970, 1640138149, 1959294189,
		1445197848, 2050523567, 1986734043, 1961922374, 1295046050, 870789453,
		491067813, 1150424087, 1881217350, 1198376761, 1009266697, 1620348731,
		1040541558, 411104192, 2088054292, 1965087385, 857471939, 202132422,
		100727460, 1765536379, 1099209955, 771148595, 1897211668, 91381115,
		627983641, 1519215151, 1653249719};
	unsigned char chuckArr[] = {0xb0, 0xe2, 0x32, 0x4b, 0xec, 0xc4, 0x6d, 0x38, 
		0x81, 0xda, 0x26, 0x61, 0xe9, 0x6e, 0x5f, 0x42, 0x8d, 0x80, 0x8b, 0x00};
	unsigned char flagArr[] = {0x4a, 0x41, 0x46, 0x45, 0x6f, 0x65, 0x0a, 0x98,
		0x31, 0x17, 0xca, 0x74, 0x00};
	unsigned int array2[] = {
		0xab, 0xBCdeF, 1023020, 2030, 1, 3023, 255, 30, 102, 233, 100, 839,
		0x00, 32, 10, 40, 41,41,41,41,0x00};

	chuck = (char*) malloc(sizeof(char) * 20);
	fl = (char*) malloc(sizeof(char) * 13);
	fcn5();
	for(count = 0; count < 20; count ++)
		chuck[count] = chuckArr[count];
	for(count = 0; count < 13; count ++)
		fl[count] = flagArr[count];
	switch(sig)
	{

		case SIGXCPU:
			fcn7(chuckArr[3]);
			for(count = 0; count < 12; count ++)
			{
				temp = fl[count];
				fcn7(chuck[count]);
				if(count % 5 == 0)
					temp = fcn2(temp, count % 8);
				temp -= count * count * count;
				fcn5();
				temp += 3;
				fcn7(temp * chuck[count]);
				fl[count] = temp;
			}
			fcn5();
			fcn7(23504309 + 0xFF320);
			fcn6(fl[3] + 2);
			fcn6(array[23522 % 100] + array[2355250 % 100]);
			fcn5();
			fcn6(chuckArr[5]);
			printf("%s\n", fl);
			fcn5();
			fcn6(array[32 % 100] + array[580230 % 100]);
			break;
		default:
			
			fcn6(array[2305288 % 100]);
			fcn7(array[202003 % 100]);
			for(count = 0; count < 19; count ++)
			{
				fcn5();
				temp = chuck[count];
				fcn7(array2[count]);
				if(count % 2 == 0)
				{
					temp = fcn4(temp);
					fcn5();
				}
				temp = fcn3(temp, count % 8);
				fcn4(fl[count]);
				temp -= count + 1;
				fl[count] = temp + 3;
				chuck[count] = temp;
			}
			fcn5();
			printf("%s\n", chuck);
			fcn7(array[23 % 100]);
			fcn7(array[20202333 % 100]);
	}
	free(chuck);
	free(fl);
}

int main()
{
	char* chuck[] = {"Oh no! There's a bear in my bed!", "You probably thought that this deer was alive.",
		"And this coyote was alive.", "And this pheasant was alive.", "Look at that antelope driving a car!",
		"There's a leopard, sitting on an Impala, out on my deck.", "Did that rhino just order a drink?"};

	int flags[] = {SIGHUP , SIGINT , SIGQUIT , SIGILL , SIGABRT , SIGFPE ,
		SIGSEGV , SIGPIPE , SIGALRM , SIGTERM , SIGUSR1 , SIGUSR2 ,
		SIGCHLD , SIGCONT , SIGTSTP , SIGTTIN , SIGTTOU ,
		SIGBUS , SIGPOLL , SIGPROF , SIGSYS , SIGTRAP , SIGURG , 
		SIGVTALRM , SIGXCPU , SIGXFSZ};
	struct sigaction sa;
	int count;
	sa.sa_handler = SIG_IGN;
	sa.sa_handler = catch_alarm;
	for(count = 0; count < 26; count ++)
	{
		sa.sa_flags = flags[count];
		sigaction(flags[count], &sa, NULL);
	}
	while(1)
	{
		printf("%s\n", chuck[rand() % 7]);
		sleep(5);
	}
	return 0;
}
