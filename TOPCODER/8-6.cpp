#include <algorithm>
#include <cmath>
using namespace std;

class AutoLoan
{
public:
	double interestRate(double price, double monthlyPayment, int loanTerm)
	{
		double balance;	// 결과
		double high = 100, low = 0, mid = 50;	// 연간 금리 0~100

		while (((1e-9) < (high-low)) && ((1e-9) < (high-low)/high))
		// 절대오차와 상대오차가 오차범위 안에 들어가면 while문 탈출 
		{
			balance = price;
			mid = (high+low)/2;

			for (int j = 0; j < loanTerm; j++)
				balance = balance + (balance * mid / 1200) - monthlyPayment;

			if (balance > 0)
				high = mid;	// 앞쪽 탐색
			else
				low = mid;	// 뒤쪽 탐색
		}

		return mid;
	}
};