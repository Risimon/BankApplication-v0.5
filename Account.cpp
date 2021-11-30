#include "Account.h";
Account::Account(int id, int balance, InhaString name) : m_accId{ id }, m_balance{ balance }, m_cusName{ name }{}
Account::Account(const Account& cp) : m_accId{ cp.m_accId }, m_balance{ cp.m_balance }, m_cusName{ cp.m_cusName }{}
Account::Account() = default;
Account::~Account() {}
int Account::getAccId() const {
    return m_accId;
}
void Account::deposit(int money) {
    if (money > 0)
        m_balance += money;
}
int Account::withdraw(int money) {
    if ((money < 0) || (money > m_balance))
        return -1;
    m_balance -= money;
    return money;
}
void Account::showAccInfo() const {
    cout << "Account ID: " << m_accId << endl;
    cout << "Name: " << m_cusName << endl;
    cout << "Balance: " << m_balance << endl << endl;
}
int Account::getBalance()const {
    return m_balance;
}