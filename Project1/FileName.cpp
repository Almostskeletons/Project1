#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
#include <string>

int main() {
	srand((unsigned int)time(0));
	int num = 100 + rand() % 100;
	cout << "请你猜数字范围100-199" << endl;
	int a=0;
	while (true)
	{
		cin >> a;
		if (a == num)
		{
			cout << "你猜对了！" << endl;
			break;
		}
		
		string str = a > num ? "这个字太大了":"这个数字太小了";
		cout << str << endl;
	}

	
	
	return 0;
}