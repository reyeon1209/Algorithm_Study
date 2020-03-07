#include <algorithm>
#include <vector>
using namespace std;

class CirclesCountry
{ 
public:
	int leastBorders(vector <int> X, vector <int> Y, vector <int> R, int x1, int y1, int x2, int y2)
	{
		bool isInside[50] = {false};
		
		for (int i = 0; i < X.size(); i++)
		{
			int dist = distance(X[i], Y[i], x1, y1);	// ���� �߽� ������ �Ÿ�
			
			if (dist < (R[i] * R[i]))	// ���� �߽� ������ �Ÿ��� ���� ���������� �۴ٸ�
				isInside[i] = !isInside[i];	// ���� ���ο� �ִ�
		}
		
		for (int i = 0; i < X.size(); i++)
		{
			int dist = distance(X[i], Y[i], x2, y2);	// ���� �߽� ������ �Ÿ�
			
			if (dist < (R[i] * R[i]))	// ���� �߽� ������ �Ÿ��� ���� ���������� �۴ٸ�
				isInside[i] = !isInside[i];
				// ������� �������� ���� ���� �����̰ų� ������� �������� ��� ���� �ܺ��� ���
				// false�� �Ǿ� cnt ��� X
		}

		int cnt = 0;
		for (int i = 0; i < X.size(); i++)
		{
			if (isInside[i])
				cnt++;
		}
		
		return cnt;
	}

	int distance(int x1, int y1, int x2, int y2)
	{
		return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	}
};