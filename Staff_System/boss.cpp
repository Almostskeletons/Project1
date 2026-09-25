#include <iostream>
using namespace std;
#include <string>
#include "boss.h"
boss::boss(int number, string Name, int Job) :staff(number, Name, Job)
{
	this->duty = "管理公司";
}
