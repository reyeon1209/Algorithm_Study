#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Number
{
public:
	void followUp(int N)
	{
		int tmp = 10;	// 자릿수
		int cnt = 1;	// 더해지는 수
		int total = 0;	// 총 자릿수
		
		// 1~9까지는 1자리, 10~99까지는 2자리, 100~999까지는 3자리...

		for (int i = 1; i <= N; i++)
		{
			if (i == tmp)	// i가 자릿수가 바뀌면
			{
				tmp *= 10;	// 다음 자릿수 카운트할 tmp * 10
				cnt++;	// 더해지는 수 +1
			}

			total += cnt;
		}

		printf("%d\n", total);
	}
};

int main()
{
	Number n;
	int N;

	scanf("%d", &N);

	n.followUp(N);


	return 0;
}
