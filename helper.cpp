#include "helper.hpp"

bool comparebyslacktime(const task &a, const task &b) {
	if(a.slacktime < b.slacktime) {
		return true;
	}
	return false;
}

bool comparebyperiod(const task &a, const task &b) {
	if(a.period < b.period) {
		return true;
	}
	return false;
}

bool comparebydeadline(const task &a, const task &b) {
	if(a.deadline < b.deadline) {
		return true;
	}
	return false;
}
void read_input(vector<task> &task_vector) {
	char input[1024], *tok;
	int N,counter,task_id,period,wcet,index;
	memset(input,0,1024);
	fgets(input,1024,stdin) ;
	N = atoi(input);
	index = N;
	while ( index>0) {
		task t;
		memset(input,0,1024);
		fgets(input,1024,stdin);
		tok =  strtok(input,",");
		counter  = 0;
		do {
			if (counter == 0)
				task_id = atoi(tok);
			if (counter == 2)
				period = atoi(tok);
			if (counter == 1)
				wcet = atoi(tok);
			if (counter > 2){
				cout<<"FORMAT ERROR IN INPUT FILE\n";
				exit(-1);
			}
			counter++;
			tok  = strtok(NULL,",");
		}while (tok);
		if(counter<2){
			cout<<"FORMAT ERROR IN INPUT FILE\n";
			exit(-1);
		}
		t.task_id = task_id;
		t.period = period;
		t.wcet = wcet;
		t.arrival_time = 0;
		t.deadline = t.arrival_time  + t.period;
		t.ceu = 0;
		t.slacktime = (t.deadline - 0) - ( t.wcet - t.ceu);
		task_vector.push_back(t);
		index--;
	}

}

void print_task_vec(vector<task> &v) {

	int n = v.size();
	int i;

	cout<<"----------------------------------\n";

	cout<<"Task\tPeriod\tWCET\tatime\tdead\tslack\n";

	for (i=0;i<n;i++) { 
		cout<<v[i].task_id<<"\t"<<v[i].period<<"\t"<<v[i].wcet<<"\t"<<v[i].arrival_time<<"\t"<<v[i].deadline<<"\t"<<v[i].slacktime<<endl;
	}
	cout<<"----------------------------------\n";
}
