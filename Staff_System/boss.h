#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "staff.h"

class boss :public staff
{
public:
	boss(int number, string Name, int Job);
};