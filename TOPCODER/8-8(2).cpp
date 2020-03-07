#include <algorithm>
#include <vector>
using namespace std;

class CirclesCountry
{ 
public:
	int leastBorders(vector <int> X, vector <int> Y, vector <int> R, int x1, int y1, int x2, int y2)
	{
		int cnt = 0;
		
		for (int i = 0; i < X.size(); i++)
		{
			if (inside(X[i], Y[i], x1, y1, R[i]) != inside(X[i], Y[i], x2, y2, R[i]))
			// 출발지와 목적지가 원의 외부와 내부에 각각 있다면
				cnt++;
		}
		
		return cnt;
	}

	bool inside(int x1, int y1, int x2, int y2, int r)
	{
		return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= r * r;
		// 원의 중심 사이의 거리가 원의 반지름 보다 작다면 내부에 있다.
	}
};