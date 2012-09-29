#include "helper.hpp"
#include "RMS.h"
#include "EDF.h"

int main() {
	vector<task> task_vec;
	int n=100;
	read_input(task_vec);
	print_task_vec(task_vec);
	//RMS_Scheduler(task_vec,n);
	EDF_Scheduler(task_vec,n);

}
