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
}task;

void read_input(vector<task> &);
void print_task_vec(vector<task> &);
bool comparebyperiod(const task&,const task&);

#endif

