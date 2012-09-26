#include "helper.h"

task_set read_input() {
	char input[1024], *tok;
	int N,counter,task_id,period,wcet,index;
	task_set tset;
	memset(input,0,1024);
	fgets(input,1024,stdin) ;
	N = atoi(input);
	task *task_arr = (task *) malloc(sizeof(task)*N);
	tset.task_arr = task_arr;
	tset.N = N;
	index = N;
	while ( index>0) {
		memset(input,0,1024);
		fgets(input,1024,stdin);
		tok =  strtok(input,",");
		counter  = 0;
		do {
			if (counter == 0)
				task_id = atoi(tok);
			if (counter == 1)
				period = atoi(tok);
			if (counter == 2)
				wcet = atoi(tok);
			if (counter > 2){
				printf("FORMAT ERROR IN INPUT FILE\n");
				tset.task_arr = NULL;
				tset.N = -1;
				return tset;
			}
			counter++;
			tok  = strtok(NULL,",");
		}while (tok);
		task_arr->task_id = task_id;
		task_arr->period = period;
		task_arr->wcet = wcet;
		index--;
		task_arr++;
	}

	return tset;
}

void print_task_arr(task *task_arr,int N) {
	int i;
	for (i=0;i<N;i++) { 
		printf("%d \t %d \t %d\n",task_arr->task_id,task_arr->period,task_arr->wcet);
		task_arr++;
	}
}
