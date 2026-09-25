#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "staff.h"

class worker :public staff
{
public:
	worker(int number, string Name, int Job);
};