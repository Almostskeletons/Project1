#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include "staff.h"
#include "boss.h"
#include "manager.h"
#include "worker.h"

class System
{
public:

	~System();

	void get();

	System();

	void instruction();

	void add();

	void save();

	void present();

	void Delete();

	void Sort();

private:
	int total_number;
	staff** total_staff;
};
















	