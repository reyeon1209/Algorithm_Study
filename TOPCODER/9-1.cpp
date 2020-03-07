#include <algorithm>
#include <queue>
using namespace std;

class BinaryFlips
{
public :
	int minimalMoves(int A, int B, int K)
	{
		if (A == 0)
			return 0;	// ������ �ʿ䰡 ���� ���
		if (A + B < K)
			return -1;	// ������ �� ���� ���

		int array[A + B + 1];

		for (int i = 0; i <= A + B; i++)
			array[i] = -1;

		queue<int> q;
		q.push(A);
		array[A] = 0;

		while (!q.empty())
		{
			int i = q.front();	// i�� 0�� ��
			q.pop();
			for (int j = max(0, K - (A + B - i)); j <= min(i, K); j++)
			{
				int nextzero = i + (K - 2 * j);	// ���� ������ 0�� ��
				if (array[nextzero] == -1)
				{
					if (nextzero == 0)
						return array[i]+1;
					array[nextzero] = array[i] + 1;
					q.push(nextzero);
				}
			}
		}

		return -1;
	}
};