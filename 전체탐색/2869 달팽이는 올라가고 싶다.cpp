#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Snail
{
public:
	void climbTree(int a, int b, int v)
	{
		int day = 1;

		day += (v - a) / (a - b);

		if (v > (a-b)*(day-1)+a)
			day++;

		cout << day << endl;
	}
};

int main()
{
	Snail s;
	int a, b, v;

	cin >> a >> b >> v;

	s.climbTree(a, b, v);

	return 0;
}
