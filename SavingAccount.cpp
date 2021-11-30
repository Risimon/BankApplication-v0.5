#include "SavingAccount.h"
SavingAccount::SavingAccount(int id, int balance, InhaString name, float rate) : m_rate{ rate }, Account(id, balance * (rate/100), name) {}

SavingAccount::~SavingAccount(){}

void SavingAccount::deposit(int money)
{
	m_balance += money + money * (m_rate / 100);
}
