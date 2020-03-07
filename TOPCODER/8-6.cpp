#include <algorithm>
#include <cmath>
using namespace std;

class AutoLoan
{
public:
	double interestRate(double price, double monthlyPayment, int loanTerm)
	{
		double balance;	// ���
		double high = 100, low = 0, mid = 50;	// ���� �ݸ� 0~100

		while (((1e-9) < (high-low)) && ((1e-9) < (high-low)/high))
		// ��������� �������� �������� �ȿ� ���� while�� Ż�� 
		{
			balance = price;
			mid = (high+low)/2;

			for (int j = 0; j < loanTerm; j++)
				balance = balance + (balance * mid / 1200) - monthlyPayment;

			if (balance > 0)
				high = mid;	// ���� Ž��
			else
				low = mid;	// ���� Ž��
		}

		return mid;
	}
};