#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

class BatchSystem
{
public :
	vector <int> schedule(vector <int> duration, vector <string> user)
	{
		int N = duration.size();

		map <string, long long> jobTime;	// 사용자마다 작업에 필요한 총 시간
		for (int i = 0; i < N; i++)
			jobTime[user[i]] += duration[i];

		vector <bool> done(N);	// 작업 수행했는지 여부
		vector <int> ans;	// 작업 처리 순서
		while (ans.size() < N)
		{
			string next;
			for (int i = 0; i < N; i++)
			{
				if ((!done[i]) && ((next.empty()) || (jobTime[user[i]] < jobTime[next])))
					// 수행하지 않은 작업이고 next가 비어있거나 작업 시간이 더 짧은 것이 있으면
					next = user[i];	// next를 작업 시간 더 짧은 것으로 변경
			}

			for (int i = 0; i < N; i++)
			{
				if (user[i] == next)
				{
					done[i] = true;	// 작업 수행했다고 변경
					ans.push_back(i);	// 작업 처리 순서에 추가
				}
			}
		}

		return ans;

	}
};