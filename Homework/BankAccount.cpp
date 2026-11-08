#include "./BankAccount.h"
#include <cstring>
#include <iostream>
#include <ostream>
#include <string>

BankAccount::BankAccount() {}

BankAccount::BankAccount(std::string newName, double chBalance, double sBalance) {
    this->customerName = newName;
    this->checkingBalance = chBalance;
    this->savingsBalance = sBalance;
}

void BankAccount::SetName(std::string newName) {
    this->customerName = newName;
}

std::string BankAccount::GetName() {
    return this->customerName;
}

void BankAccount::SetChkBalance(double balance) {
    this->checkingBalance = balance;
}

double BankAccount::GetChkBalance() {
    return this->checkingBalance;
}

void BankAccount::SetSavBalance(double balance) {
    this->savingsBalance = balance;
}

double BankAccount::GetSavBalance() {
    return this->savingsBalance;
}

void BankAccount::DepositChecking(double amt) {
    this->checkingBalance += amt;
}

void BankAccount::DepositSavings(double amt) {
    this->savingsBalance += amt;
}

void BankAccount::WithdrawChecking(double amt) {
    this->checkingBalance -= amt;
}

void BankAccount::WithdrawSavings(double amt) {
    this->savingsBalance -= amt;
}

void BankAccount::TransferToChecking(double amt) {
    this->savingsBalance -= amt;
    this->checkingBalance += amt;
}

int main() {
    BankAccount acc;
    acc.SetChkBalance(100);
    if(acc.GetChkBalance() != 100)
        std::cout << "Failed set checking" << std::endl;
    acc.SetSavBalance(100);
    if(acc.GetSavBalance() != 100)
        std::cout << "Failed set saving" << std::endl;
    acc.DepositChecking(50);
    if(acc.GetChkBalance() != 150)
        std::cout << "Failed deposit checking" << std::endl;
    acc.DepositSavings(50);
    if(acc.GetSavBalance() != 150)
        std::cout << "Failed deposit saving" << std::endl;
    acc.WithdrawChecking(50);
    if(acc.GetChkBalance() != 100)
        std::cout << "Failed deposit checking" << std::endl;
    acc.WithdrawSavings(50);
    if(acc.GetSavBalance() != 100)
        std::cout << "Failed deposit saving" << std::endl;
    acc.TransferToChecking(50);
    if(acc.GetChkBalance() != 150 && acc.GetSavBalance() != 50)
        std::cout << "Failed transfer to checking" << std::endl;
}