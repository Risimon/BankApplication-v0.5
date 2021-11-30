#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H
#include "Account.h";

class SavingAccount : public Account
{
protected:
	float m_rate;
public:
	SavingAccount(int id, int balance, InhaString name, float rate);
	virtual ~SavingAccount();
	virtual void deposit(int) override;
};

#endif