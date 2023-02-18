#include <stdio.h>
#include <stdlib.h>

#if 0
enum{
	STATE_RUNNING = 1,
	STATE_CANCELED,
	STATE_OVER
};
#endif

#define STATE_RUNNING 		1
#define STATE_CANCELED 		2	
#define STATE_OVER			3

struct job_st{
	int id;
	int state;
	time_t start, end;
};

int main()
{

	struct job_st job;
	/*
	 获取job的state
	 */

	switch(job.state){
		case STATE_RUNNING:
			//do something
			break;
		case STATE_CANCELED:
			//do something
			break;
		case STATE_OVER:
			//do something
			break;
		default:
			//
	};

	return 0;
}
