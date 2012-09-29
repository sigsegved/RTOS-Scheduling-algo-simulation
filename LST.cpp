#include "LST.h"

#define READY 1

void LST_Scheduler(vector<task> &task_vec,int sim_time) { 
	/*t=0
	one time sorty by period (assign priority
	for each process set arrival.time = 0
	do
	for each proces update the deadline
	curr_priority = highest_priority;
	pick the task with curr_priority
	execute for 1 unit of time. 
	update the arrival time of each process.
	if curr_task is done curr_priority--;
	loop
	*/
	sort(task_vec.begin(),task_vec.end(),comparebyslacktime);
	print_task_vec(task_vec);
	int i,time = 0;
	int  n = task_vec.size();
	int curr_process;
	while (time < sim_time) {
		cout<<"TIME "<<time<<endl;
		curr_process = 0;
		if(curr_process > -1) {

			if(task_vec[curr_process].ceu < task_vec[curr_process].wcet) {
				task_vec[curr_process].ceu++;
				task_vec[curr_process].slacktime = (task_vec[curr_process].deadline - time) - (task_vec[curr_process].wcet - task_vec[curr_process].ceu);
				cout<<"\tEXECUTING TASK "<<task_vec[curr_process].task_id<<endl;

			}
			if (task_vec[curr_process].ceu == task_vec[curr_process].wcet) {
				cout<<"\tTASK COMPLETED "<<task_vec[curr_process].task_id<<endl;
				task_vec[curr_process].arrival_time += task_vec[curr_process].period;
				task_vec[curr_process].deadline = task_vec[curr_process].arrival_time + task_vec[curr_process].period;
				task_vec[curr_process].state = READY;
				sort(task_vec.begin(),task_vec.end(),comparebyperiod);
				task_vec[curr_process].ceu = 0;
				task_vec[curr_process].slacktime = (task_vec[curr_process].deadline - time) - (task_vec[curr_process].wcet - task_vec[curr_process].ceu);
				
	
			}
		}
		for(i=0;i<n;i++) {
			if(task_vec[i].deadline < time) {
				cout<<"\tTASK "<<i+1<<" missed deadline"<<endl;
				task_vec[i].arrival_time += task_vec[i].period;
				task_vec[i].deadline = task_vec[i].arrival_time + task_vec[i].period;
				task_vec[i].state = READY;
				sort(task_vec.begin(),task_vec.end(),comparebyperiod);
				task_vec[i].ceu = 0;
				task_vec[curr_process].slacktime = (task_vec[curr_process].deadline - time) - (task_vec[curr_process].wcet - task_vec[curr_process].ceu);

			}
		}
		time++;
		sort(task_vec.begin(),task_vec.end(),comparebyslacktime);
		//print_task_vec(task_vec);
	}
	print_task_vec(task_vec);

}
