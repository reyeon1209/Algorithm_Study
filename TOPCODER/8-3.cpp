#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

class StockHistory
{
public:
	int maximumEarnings(int initialInvestment, int monthlyContribution, vector <string> stockPrices)
	{
		int money = initialInvestment;
		int month = stockPrices.size();

		int corp = 1;
		char *s = (char *)stockPrices[0].c_str();
		while (*s++)
			if (*s == ' ')
				corp++;	// corp : ȸ���� ��

		int prices[50][999];	// �� ���� ���� ȸ����� �ְ�
		double max = 0, profit = 0;	// �ִ� ������, ����
		double proportion[50] = {0};	// 1�޷� �� ����
		bool buy[50] = {false};	// �ֽ��� ����ϴ��� ����

		// �� ���� ���� ȸ����� �ְ��� ó���ϱ� ���� ���� �迭(prices)��
		// �Լ����� �Ʒ� ���� ����
		for (int i = 0; i < month; i++)
		{
			string s = stockPrices[i];
			for (int j = 0; j < corp; j++)
			{
				int pos = s.find(" ");
				if (pos == string::npos)
					prices[i][j] = atoi(s.c_str());
				else
				{
					prices[i][j] = atoi(s.substr(0, pos).c_str());
					s = s.substr(pos+1, s.size());
				}
			}
		}

		// �ݺ����� ������ ���� �Ž��� �ö󰡸� �� �������� �ִ� �������� �ֽ��� ����ϴ��� ����
		for (int i = month-2; i >= 0; i--)
		{
			for (int j = 0; j < corp; j++)
			{
				double p = 1.0 * prices[month-1][j] / prices[i][j] - 1;	// ������
				if ((p > 0) && (p > max))	// �������� max(�ִ� ������)���� Ŭ ���
				{
					buy[i] = true;	// �ֽ��� ����Ѵ�(true)
					max = p;	// �ִ� ������ ����
					proportion[i] = p;	// 1�޷� �� ���� ����
				}
			}
		}

		// ó������ �����ؼ� ��� �ϴ� ���� ���� ��� �ڱ� ����
		for (int i = 0; i < month; i++)
		{
			if (buy[i])	// �ֽ��� ����� ���
			{
				profit += money * proportion[i];	// ���� ���
				money = 0;	// ���ڱ��� ��������Ƿ� 0���� �ʱ�ȭ
			}
			money += monthlyContribution;	// 1���� ������ �� �� ����� monthlyContrubution�޷� �߰�
		}


		return (int)floor(profit);	// ���� �ݿø�
	}
};