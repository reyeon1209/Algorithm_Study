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
				corp++;	// corp : 회사의 수

		int prices[50][999];	// 각 월에 따른 회사들의 주가
		double max = 0, profit = 0;	// 최대 증가율, 이윤
		double proportion[50] = {0};	// 1달러 당 이율
		bool buy[50] = {false};	// 주식을 사야하는지 여부

		// 각 월에 따른 회사들의 주가를 처리하기 쉽게 숫자 배열(prices)로
		// 함수들은 아래 설명 참고
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

		// 반복문을 역으로 돌려 거슬러 올라가며 각 월까지의 최대 증가율과 주식을 사야하는지 저장
		for (int i = month-2; i >= 0; i--)
		{
			for (int j = 0; j < corp; j++)
			{
				double p = 1.0 * prices[month-1][j] / prices[i][j] - 1;	// 증가율
				if ((p > 0) && (p > max))	// 증가율이 max(최대 증가율)보다 클 경우
				{
					buy[i] = true;	// 주식을 사야한다(true)
					max = p;	// 최대 증가율 갱신
					proportion[i] = p;	// 1달러 당 이율 저장
				}
			}
		}

		// 처음부터 시작해서 사야 하는 달이 오면 모든 자금 투자
		for (int i = 0; i < month; i++)
		{
			if (buy[i])	// 주식을 사야할 경우
			{
				profit += money * proportion[i];	// 이익 계산
				money = 0;	// 투자금을 사용했으므로 0으로 초기화
			}
			money += monthlyContribution;	// 1달이 지나면 매 월 사용할 monthlyContrubution달러 추가
		}


		return (int)floor(profit);	// 이익 반올림
	}
};