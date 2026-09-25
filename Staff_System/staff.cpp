#include <iostream>
using namespace std;
#include <string>
#include "staff.h"

staff::staff(int number, string Name, int Job)
{
	this->num = number;
	this->name = Name;
	this->job = Job;
}
