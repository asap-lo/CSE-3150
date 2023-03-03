#ifndef _EC_ACCOUNTS_H
#define _EC_ACCOUNTS_H

// Created by Y. Wu, Feb 17, 2023
// Implement a simple bank account: it has account number, account holder's name. Then you would like to store accounts in some container. What do you need for that?
// Assume account numbers are distinct

#include <string>

class ECAccount
{
public:
  ECAccount(int accNum, const std::string &accName);
  int GetAccountNum() const { return accountNum; }
  // ECAccount(const ECAccount &rhs) = delete;
  // YW: should we return a copy or a reference?
  std::string GetHolderName() const { return name; }   


  // what else do we need?
  bool operator<(const ECAccount &other) const { return accountNum < other.accountNum; }

private:
  std::string name;
  int accountNum;       // what should the account number type be?
};

#endif
