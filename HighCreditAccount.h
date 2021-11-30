#ifndef HIGHCREDITACCOUNT_H
#define HIGHCREDITACCOUNT_H
#include "SavingAccount.h"

class HighCreditAccount : public SavingAccount
{
	short m_rating;
public:
	HighCreditAccount(int id, int balance, InhaString name, float rate, short rating);
	virtual ~HighCreditAccount();
	virtual void deposit(int) override;
};

#endif