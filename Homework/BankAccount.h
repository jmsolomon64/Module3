#include <string>
class BankAccount {
   public:
    BankAccount();
    BankAccount(std::string newName, double chBalance, double sBalance);
    void SetName(std::string newName);
    std::string GetName();
    void SetChkBalance(double balance);
    double GetChkBalance();
    void SetSavBalance(double balance);
    double GetSavBalance();
    void DepositChecking(double amt);
    void DepositSavings(double amt);
    void WithdrawChecking(double amt);
    void WithdrawSavings(double amt);
    void TransferToChecking(double amt);
   
   private:
    std::string customerName;
    double savingsBalance;
    double checkingBalance;
};