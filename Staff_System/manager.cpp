#include <iostream>
using namespace std;
#include <string>
#include "manager.h"

manager::manager(int number, string Name, int Job) :staff(number, Name, Job)
{
	this->duty = "完成老板给的任务";
}
