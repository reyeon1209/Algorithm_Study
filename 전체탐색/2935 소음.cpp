#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{
	char A[101], B[101], C[101];
	char cal;
	int lenA, lenB;

	scanf("%s", A);
	getchar();
	scanf("%c", &cal);
	getchar();
	scanf("%s", B);
	getchar();

	lenA = strlen(A), lenB = strlen(B);

	if (cal == '+')
	{
		if (lenA >= lenB)
		{
			strcpy(C, A);
			C[lenA-lenB] += 1;
		}

		else
		{
			strcpy(C, B);
			C[lenB-lenA] += 1;
		}

		printf("%s\n", C);
	}

	else
	{
		printf("1");
		for (int i = 0; i < lenA+lenB-2; i++)
			printf("0");
		printf("\n");
	}


	return 0;
}
