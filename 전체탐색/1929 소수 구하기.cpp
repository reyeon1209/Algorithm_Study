#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Prime
{
public:
	void primeNumber(int M, int N)
	{
		vector<bool> prime(N+1, true);	// 소수인지 여부 저장할 vector
		prime[0] = false, prime[1] = false;	// 0, 1은 소수가 아니므로

		for (int i = 2; i <= N; i++)
		{
			if (i*i > 1000000)	// 범위 초과
				break;

			for (int j = i*i; j <= N; j+=i)	// i의 배수
				prime[j] = false;
		}

		for (int i = M; i <= N; i++)
			if (prime[i])
				printf("%d\n", i);
	}
};

int main()
{
	Prime p;
	int M, N;

	cin >> M >> N;

	p.primeNumber(M, N);

	return 0;
}
