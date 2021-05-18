class Account {
public:
Account(double initial_balance) { balance = initial_balance; } //与1相同
double GetBalance(); //在类中声明
double Deposit( double Amount );
double Withdraw( double Amount );
private:
double balance;
};
inline double Account::GetBalance() { return balance; } //在类外定义时添加inline关键字
inline double Account::Deposit( double Amount ) { return ( balance += Amount ); }
inline double Account::Withdraw( double Amount ) { return ( balance -= Amount ); }