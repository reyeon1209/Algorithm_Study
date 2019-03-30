#include <iostream>
#include <algorithm>
using namespace std;

bool prime[1000000];	// 소수 여부 저장할 배열

class Goldbach
{
public:
	void primeNumber()	// 소수 여부 판별 함수
	{
		prime[0] = false, prime[1] = false;

		for (int i = 2; i <= 1000000; i++)
			prime[i] = true;	// true로 초기화

		for (int i = 2; i*i <= 1000000; i++)
			for (int j = i*i; j <= 1000000; j+=i)	// i의 배수
				prime[j] = false;
	}

	void goldbachConjecture(int N)
	{
		for (int i = 3; i <= N/2+1; i+=2)	// 3부터 주어진 수의 절반까지
		{
			if ((prime[i]) && (prime[N-i]))	// 둘 다 소수이면
			{
				printf("%d = %d + %d\n", N, i, N-i);	
				return ;
			}
		}

		printf("Goldbach's conjecture is wrong.\n");	// 소수+소수가 없으면 
	}
};

int main()
{
	Goldbach g;
	int N;
	g.primeNumber();

	while (1)
	{
		scanf("%d", &N);
		if (N == 0)
			return 0;
		g.goldbachConjecture(N);
	}

	return 0;
}
