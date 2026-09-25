#include "SYSTEM_CONTROL.h"

System::~System()
{
	delete[] total_staff;
}

void System::get()
{
	int number;
	string name;
	int job;
	ifstream ifs("system.txt", ios::in);
	total_staff = new staff*[total_number];

	for (int i = 0;i < total_number;i++)
	{
		ifs >> number >> name >> job;
		switch (job)
		{
		case 1:
			total_staff[i] = new worker (number, name, job);
			break;
		case 2:
			total_staff[i] = new manager (number, name, job);
			break;
		case 3:
			total_staff[i] = new boss (number, name, job);
			break;
		}
	}
	ifs.close();
}

System::System()
{

	int number;
	string name;
	int job;

	ifstream ifs("system.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "目前文件没有创建" << endl;
		total_number = 0;
		total_staff = NULL;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件没有数据" << endl;
		total_number = 0;
		total_staff = NULL;
		ifs.close();
		return;
	}
	ifs.close();

	int index = 0;
	ifs.open("system.txt", ios::in);
	while (ifs >> number >> name >> job)
	{
		index++;
	}
	total_number = index;
	cout << "现在有" << index << "个人" << endl;
	ifs.close();
	get();

}
void System::instruction()
{
	cout << "\n================ 职工管理系统 ================\n";
	cout << "1. 退出管理程序\n";
	cout << "2. 增加职工信息\n";
	cout << "3. 显示职工信息\n";
	cout << "4. 删除离职职工\n";
	cout << ". 修改职工信息\n";
	cout << ".查找职工信息\n";
	cout << "5. 按照编号排序\n";
	cout << ". 清空所有文档\n";
	cout << "==============================================\n";
	cout << "请输入你的选择 (1-8): ";
}

void System::add()
{
	int a;
	cout << "请问你要输入多少个员工信息？" << endl;
	cin >> a;
	staff** new_staff = new staff * [total_number + a];
	if (a>0)
	{
      //"在属性二级指针赋值给新二级指针之后，在属性二级指针重新赋值之前要释放：属性二级指针"
	  //为何之前的属性指针赋值给新二级指针delete没有事呢，因为不是搬动房子也就是数组地址，而只是将房子里面的指针地址一个一个搬出来。
		for (int i = 0;i < total_number;i++)
		{
			new_staff[i] = total_staff[i];
		}

		if (total_staff != NULL)
		{
			delete[] total_staff;
			total_staff = NULL;
		}

		for (int j = total_number;j < total_number + a;j++)
		{
			cout << "输入职工编号信息：" << endl;
			int number;
			cin >> number;

			cout << "请输入姓名：" << endl;
			string name;
			cin >> name;

			cout << "请输入部门编号：" << endl;
			int job;
			cin >> job;

			switch (job)
			{
			case 1:
				new_staff[j] = new worker(number, name, job);
				break;
			case 2:
				new_staff[j] = new manager(number, name, job);
				break;
			case 3:
				new_staff[j] = new boss(number, name, job);
				break;
			}
		}

	}
	else
	{
		cout << "数量有误" << endl;
		delete[] new_staff;
		return;
	}

	total_number += a;
	total_staff = new_staff;//新二级指针赋值给属性二级指针之后，不需要delete，因为两者只是将数组地址赋值。改了一个另外一个也会改。而在栈区储存的new_staff指针8字节内存，随着大括号的结束也会消亡
	save();
	
}

void System::save()
{
	ofstream ofs("system.txt", ios::out | ios::trunc);
	for (int i = 0;i < total_number;i++)
	{
		ofs << total_staff[i]->num << " "
			<< total_staff[i]->name << " "
			<< total_staff[i]->job << endl;
	}
	ofs.close();
	cout << "已经完成填写" << endl;
}

void System::present()
{
	for (int i = 0;i < total_number;i++)
	{
		cout << "编号：" << total_staff[i]->num << endl;
		cout << "姓名：" << total_staff[i]->name << endl;
		cout << "岗位：" << total_staff[i]->job << endl;
		cout << "职责：" << total_staff[i]->duty << endl;
	}
	cout << "--------------显示完毕！--------------------" << endl;
}

void System::Delete()
{
	cout << "请输入你要删除的成员编号：" << endl;
	int a;
	cin >> a;
	bool condition = false;
	for (int i = 0;i < total_number-1;i++)
	{
		if (condition || a == total_staff[i]->num)
		{
			condition = true;
			delete total_staff[i];//通过第二层房子储存的门牌号delete第一层房子
			total_staff[i] = total_staff[i + 1];

		}
	}

	if (condition)
	{
		total_staff[total_number - 1] = NULL;//为何不直接delete而是留在这里继续占用内存：没有第二层单个房子的独立房产证，第三层房子储存的只是第二层房子的地址8字节
		total_number -= 1;
		cout << "已经删除完毕！";
		save();
	}
	else
	{
		cout << "并没有找到相应员工信息！";
	}
}

void System::Sort()
{
	for (int i = 0;i < total_number - 1;i++)
	{
		for (int j = 0;j < total_number - 1 - i;j++)
		{
			if (total_staff[j]->num > total_staff[j + 1]->num)
			{
				staff* temp = total_staff[j];
				total_staff[j] = total_staff[j + 1];
				total_staff[j + 1] = temp;
			}
		}
	}
	save();
	cout << "排序完毕！" << endl;
}

