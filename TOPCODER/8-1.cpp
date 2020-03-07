#include <iostream>
#include <algorithm>
using namespace std;

class ColorfulBoxesAndBalls
{
public:
	int getMaximum(int numRed, int numBlue, int onlyRed, int onlyBlue, int bothColors)
	{
		int ans = INT_MIN;	// 점수가 음수가 나올 수 있어서 INT_MIN으로 초기화
		int change = min(numRed, numBlue);	// 두 공 중 더 적은 수의 공 색만큼만 상자와 공의 색 변경

		// 0(같은 색 상자에 공을 넣음) ~ change(상자와 공의 색을 다르게 변경)
		for (int i = 0; i <= change; i++)
		{
			int myscore = (numRed-i)*onlyRed + (numBlue-i)*onlyBlue + 2*i*bothColors;	// 그림 참고

			ans = max(ans, myscore);	// 점수 비교해서 최대 점수 선택
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