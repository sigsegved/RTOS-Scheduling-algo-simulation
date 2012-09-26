#ifndef HELPER_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define HELPER_H


typedef struct task_node {
        int task_id;
        int period;
        int wcet;
}task;

typedef struct taskset { 
        task *task_arr;
        int N;
}task_set;

task_set read_input();
void print_task_arr(task *,int);

#endif

