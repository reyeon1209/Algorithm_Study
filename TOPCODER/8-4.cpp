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

		map <string, long long> jobTime;	// ����ڸ��� �۾��� �ʿ��� �� �ð�
		for (int i = 0; i < N; i++)
			jobTime[user[i]] += duration[i];

		vector <bool> done(N);	// �۾� �����ߴ��� ����
		vector <int> ans;	// �۾� ó�� ����
		while (ans.size() < N)
		{
			string next;
			for (int i = 0; i < N; i++)
			{
				if ((!done[i]) && ((next.empty()) || (jobTime[user[i]] < jobTime[next])))
					// �������� ���� �۾��̰� next�� ����ְų� �۾� �ð��� �� ª�� ���� ������
					next = user[i];	// next�� �۾� �ð� �� ª�� ������ ����
			}

			for (int i = 0; i < N; i++)
			{
				if (user[i] == next)
				{
					done[i] = true;	// �۾� �����ߴٰ� ����
					ans.push_back(i);	// �۾� ó�� ������ �߰�
				}
			}
		}

		return ans;

	}
};