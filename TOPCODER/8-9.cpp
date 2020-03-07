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
		int group = 0;	// �ݵ�� �湮�ؾ� �ϴ� ���ô� �׷����� ���
		int free = 0;	// �����Ӱ� �̵��� �� �ִ� ����
		int connect[50] = {0};	// �� ���ÿ� �� ���� "Y"�� �ִ���

		long long sum = 1;	// ����� ��

		this->roads = roads;	//

		for (int i = 0; i < roads.size(); i++)
		{
			int y = 0;	// "Y"�� ��
			for (int j = 0; j < roads[i].size(); j++)
			{
				if (roads[i].substr(j, 1) == "Y")
					if (++y > 2)	// "Y" 3�� �̻��̶��
						return 0;	// ������ ��� ����
			}
			connect[i] = y;	// i ���ÿ� "Y"�� ��(y) ����
		}

		for (int i = 0; i < roads.size(); i++)
		{
			if (connect[i] == 0)	// "Y"�� �������� �ʴ� ���̸�
			{
				visited[i] = true;	// ���
				free++;	// �����Ӱ� �̵��� �� �ִ� ����
			}

			else if ((connect[i] == 1) && (!visited[i]))
			// "Y" 1���� �����ϰ� ���� ������� �ʾҴٸ�
			{
				group++;	// �׷� ����
				dfs(i);
			}
		}

		for (int i = 0; i < roads.size(); i++)
			if (!visited[i])	// ��� ��� ���� �� �� ������� ���� ���ð� �ִٸ�
				return 0;	// circle �־ ������ ��� ����

		for (int i = 0; i < group+free; i++)
			sum = sum * (i+1) % 1000000007;	// (C+I)!

		for (int i = 0; i < group; i++)
			sum = sum * 2 % 1000000007;	// ���� ���� ��ü�� ����


		return (int)sum;
	}

	void dfs(int city)	// city�� ����� ���õ��� ����ߴٰ� �ٲ�
	{
		visited[city] = true;

		for (int i = 0; i < roads[city].size(); i++)
			if ((roads[city].substr(i, 1) == "Y") && (!visited[i]))
				dfs(i);
	}
};