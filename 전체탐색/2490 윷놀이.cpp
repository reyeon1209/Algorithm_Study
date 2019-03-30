#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class YutNori
{
public:
	void choose(vector <int> Y)
	{
		int cnt = 0;

		for (int i = 0; i < Y.size(); i++)
		{
			if (Y[i] == 1)
				cnt++;
		
			if (i % 4 == 3)
			{
				switch (cnt)
				{
				case 0: cout << 'D' << endl;	break;
				case 1: cout << 'C' << endl;	break;
				case 2: cout << 'B' << endl;	break;
				case 3: cout << 'A' << endl;	break;
				case 4: cout << 'E' << endl;	break;
				}

				cnt = 0;
			}
		}
	}
};

int main()
{
	int n;
	YutNori y;
	vector <int> v;
	v.reserve(12);

	for (int i = 0; i < 12; i++)
		cin >> v[i];

	y.choose(v);


	return 0;
}
