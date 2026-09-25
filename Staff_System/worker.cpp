#include <iostream>
using namespace std;
#include <string>
#include "worker.h"

worker::worker(int number, string Name, int Job) :staff(number, Name, Job)
{
	this->duty = "完成经理给的任务";
}
