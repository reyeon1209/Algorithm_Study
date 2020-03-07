#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, M;
	int capacities[50];
	int bottles[50];
	int fromId[50];
	int toId[50];
	
	scanf("%d %d", &N, &M);
	
	for (int i = 0; i < N; i++)
		scanf("%d", &capacities[i]);

	for (int i = 0; i < N; i++)
		scanf("%d", &bottles[i]);

	for (int i = 0; i < M; i++)
		scanf("%d", &fromId[i]);

	for (int i = 0; i < M; i++)
		scanf("%d", &toId[i]);
	
	for (int i = 0; i < M; i++)
	{
		if (capacities[toId[i]] >= bottles[toId[i]]+bottles[fromId[i]])
		{
			bottles[toId[i]] += bottles[fromId[i]];
			bottles[fromId[i]] = 0;
		}

		else
		{
			bottles[fromId[i]] -= capacities[toId[i]] - bottles[toId[i]];
			bottles[toId[i]] = capacities[toId[i]];
		}
	}

	for (int i = 0; i < N; i++)
		printf("%d ", bottles[i]);
	printf("\n");


	return 0;
}
