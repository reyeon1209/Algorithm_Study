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
			int dist = distance(X[i], Y[i], x1, y1);	// 원의 중심 사이의 거리
			
			if (dist < (R[i] * R[i]))	// 원의 중심 사이의 거리가 원의 반지름보다 작다면
				isInside[i] = !isInside[i];	// 원의 내부에 있다
		}
		
		for (int i = 0; i < X.size(); i++)
		{
			int dist = distance(X[i], Y[i], x2, y2);	// 원의 중심 사이의 거리
			
			if (dist < (R[i] * R[i]))	// 원의 중심 사이의 거리가 원의 반지름보다 작다면
				isInside[i] = !isInside[i];
				// 출발지와 목적지가 같은 원의 내부이거나 출발지와 목적지가 모두 원의 외부일 경우
				// false가 되어 cnt 계산 X
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