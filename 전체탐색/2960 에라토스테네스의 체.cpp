#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Prime
{
public:
	void Eratos(int N, int K)
	{
		int cnt = 0;
		vector<bool> prime(N+1, true);
		prime[0] = false, prime[1] = false;

		for (int i = 2; i <= N; i++)
		{
			for (int j = i; j <= N; j+=i)
			{
				if (prime[j])
				{
					prime[j] = false;
					cnt++;

					if (cnt == K)
					{
						cout << j << endl;
						return ;
					}
				}
			}
		}
	}
};

int main()
{
	Prime p;
	int N, K;

	cin >> N >> K;

	p.Eratos(N, K);

	return 0;
}
