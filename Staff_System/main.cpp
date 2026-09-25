#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include "staff.h"
#include "boss.h"
#include "manager.h"
#include "worker.h"
#include "SYSTEM_CONTROL.h"

int main()
{
	System sys;
	sys.instruction();
	int choice = 0;

	while (true)
	{
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "退出系统" << endl;
			return 0;
		case 2:
			cout << "现在开始添加员工" << endl;
			sys.add();
			break;
		case 3:
			cout << "开始显示员工" << endl;
			sys.present();
			break;
		case 4:
			cout << "开始删除员工" << endl;
			sys.Delete();
			break;
		case 5:
			cout << "开始给员工排序" << endl;
			sys.Sort();
			break;
		}
	}
}