#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Money
{
public:
	void change(int total)
	{
		int money = 1000 - total;
		int cnt = 0;

		if (money >= 500)
		{
			cnt += money / 500;
			money %= 500;
		}

		if (money >= 100)
		{
			cnt += money / 100;
			money %= 100;
		}

		if (money >= 50)
		{
			cnt += money / 50;
			money %= 50;
		}

		if (money >= 10)
		{
			cnt += money / 10;
			money %= 10;
		}

		if (money >= 5)
		{
			cnt += money / 5;
			money %= 5;
		}

		if (money >= 1)
		{
			cnt += money / 1;
			money %= 1;
		}

		if (money == 0)
		{
			cout << cnt << endl;
			return ;
		}
	}
};

int main()
{
	Money m;
	int pay;

	cin >> pay;

	m.change(pay);


	return 0;
}
