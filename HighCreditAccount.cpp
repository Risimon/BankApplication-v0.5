#include "HighCreditAccount.h"
HighCreditAccount::HighCreditAccount(int id, int balance, InhaString name, float rate, short rating) : SavingAccount(id, balance, name, rate), m_rating{ rating }{}

HighCreditAccount::~HighCreditAccount(){}

void HighCreditAccount::deposit(int money)
{
	SavingAccount::deposit(money);
	if (m_rating == 1)
		m_balance += money * 0.07;
	else if (m_rating == 2)
		m_balance += money * 0.04;
	else if (m_rating == 3)
		m_balance += money * 0.02;
}
