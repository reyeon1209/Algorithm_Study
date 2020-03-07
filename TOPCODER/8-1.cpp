#include <iostream>
#include <algorithm>
using namespace std;

class ColorfulBoxesAndBalls
{
public:
	int getMaximum(int numRed, int numBlue, int onlyRed, int onlyBlue, int bothColors)
	{
		int ans = INT_MIN;	// ������ ������ ���� �� �־ INT_MIN���� �ʱ�ȭ
		int change = min(numRed, numBlue);	// �� �� �� �� ���� ���� �� ����ŭ�� ���ڿ� ���� �� ����

		// 0(���� �� ���ڿ� ���� ����) ~ change(���ڿ� ���� ���� �ٸ��� ����)
		for (int i = 0; i <= change; i++)
		{
			int myscore = (numRed-i)*onlyRed + (numBlue-i)*onlyBlue + 2*i*bothColors;	// �׸� ����

			ans = max(ans, myscore);	// ���� ���ؼ� �ִ� ���� ����
		}

		return ans;
	}
};

int main()
{
	ColorfulBoxesAndBalls c;

	int numRed, numBlue;
	int onlyRed, onlyBlue, bothColors;
	int returns;

	cin >> numRed >> numBlue;
	cin >> onlyRed >> onlyBlue >> bothColors;

	returns = c.getMaximum(numRed, numBlue, onlyRed, onlyBlue, bothColors);

	cout << returns << endl;


	return 0;
}