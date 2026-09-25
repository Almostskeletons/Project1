#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "staff.h"

class manager :public staff
{
public:
	manager(int number, string Name, int Job);
};