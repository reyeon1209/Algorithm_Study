#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

int main()
{
	vector<int> set(21, 0);	// x의 범위가 1~20이니까 크기가 21인 vector를 생성
	int M, x;
	char option[7];
	
	scanf("%d", &M);

	for (int i = 0; i < M; i++)
	{
		scanf("%s", &option);

		switch(option[0])
		{
		case 'a':
			if (option[1] == 'd')
			{
				scanf("%d", &x);
				set.at(x) = 1;	// x번째 원소를 1로 바꿈 (1 : 있다)
				break;
			}

			else
			{
				for (int j = 0; j < set.size(); j++)
					set.at(j) = 1;	// 모든 원소를 1로 바꿈
				break;
			}

		case 'r':
			scanf("%d", &x);
			set.at(x) = 0;	// x번째 원소를 0으로 바꿈 (0 : 없다)
			break;

		case 'c':
			scanf("%d", &x);
			printf("%d\n", set.at(x));	// 있다면 1, 없다면 0 출력됨
			break;

		case 't':
			scanf("%d", &x);
			set.at(x) ? (set.at(x) = 0) : (set.at(x) = 1);	// 있으면 0(제거), 없으면 1(추가)
			break;

		case 'e':
			for (int j = 0; j < set.size(); j++)
				set.at(j) = 0;	// 모든 원소를 0으로 바꿈 (공집합)
			break;
		}
	}
	

	return 0;
}
