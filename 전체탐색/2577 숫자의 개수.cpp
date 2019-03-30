#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Number
{
public:
	void num(int total)
	{
		vector<int> cnt(10, 0);

		while (total > 0)
		{
			cnt.at(total % 10) += 1;
			total /= 10;
		}

		for (int i = 0; i < cnt.size(); i++)
			printf("%d\n", cnt.at(i));
	}
};

int main()
{
	int A, B, C;
	Number n;

	scanf("%d %d %d", &A, &B, &C);

	n.num(A*B*C);


	return 0;
}
