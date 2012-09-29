#ifndef HELPER_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <iostream>
#include <vector>

#define HELPER_H

using namespace std;


typedef struct task_node {
        int task_id;
        int period;
        int wcet;
	int arrival_time;
	int deadline;
	int state;
	int ceu;
	int slacktime;
}task;

void read_input(vector<task> &);
void print_task_vec(vector<task> &);
bool comparebyperiod(const task&,const task&);
bool comparebydeadline(const task&,const task&);
bool comparebyslacktime(const task&,const task&);

#endif

