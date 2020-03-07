#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool visited[50] = {false};

class HamiltonPath
{
public :
	vector <string> roads;

	int countPaths(vector <string> roads)
	{
		int group = 0;	// 반드시 방문해야 하는 도시는 그룹으로 묶어서
		int free = 0;	// 자유롭게 이동할 수 있는 도시
		int connect[50] = {0};	// 각 도시에 몇 개의 "Y"가 있는지

		long long sum = 1;	// 경로의 수

		this->roads = roads;	//

		for (int i = 0; i < roads.size(); i++)
		{
			int y = 0;	// "Y"의 수
			for (int j = 0; j < roads[i].size(); j++)
			{
				if (roads[i].substr(j, 1) == "Y")
					if (++y > 2)	// "Y" 3개 이상이라면
						return 0;	// 가능한 경로 없음
			}
			connect[i] = y;	// i 도시에 "Y"의 수(y) 저장
		}

		for (int i = 0; i < roads.size(); i++)
		{
			if (connect[i] == 0)	// "Y"룰 포함하지 않는 열이면
			{
				visited[i] = true;	// 통과
				free++;	// 자유롭게 이동할 수 있는 도시
			}

			else if ((connect[i] == 1) && (!visited[i]))
			// "Y" 1개만 포함하고 아직 통과하지 않았다면
			{
				group++;	// 그룹 도시
				dfs(i);
			}
		}

		for (int i = 0; i < roads.size(); i++)
			if (!visited[i])	// 통과 경로 수를 센 뒤 통과하지 못한 도시가 있다면
				return 0;	// circle 있어서 가능한 경로 없음

		for (int i = 0; i < group+free; i++)
			sum = sum * (i+1) % 1000000007;	// (C+I)!

		for (int i = 0; i < group; i++)
			sum = sum * 2 % 1000000007;	// 양쪽 끝을 교체한 조합


		return (int)sum;
	}

	void dfs(int city)	// city에 연결된 도시들을 통과했다고 바꿈
	{
		visited[city] = true;

		for (int i = 0; i < roads[city].size(); i++)
			if ((roads[city].substr(i, 1) == "Y") && (!visited[i]))
				dfs(i);
	}
};