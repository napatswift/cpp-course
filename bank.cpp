#include <iostream>
using namespace std;

class BankAccount {
	private:
		string name_;
		double balance_;
	public:
		BankAccount(string name, double balance = 0):
			name_(name), balance_(balance) {}
		void Deposit(double amount){
			balance_ += amount;
		}
		void Withdraw(double amount){
			balance_ -= amount;
		}

		double GetBalance() const{
			return balance_;
		}

		string GetName() const{
			return name_;
		}

};

class Bank{
	private:
		string name;
		BankAccount **accounts;
		int act_size;
	public:
		Bank(string name){
			this->name = name;
			accounts = new BankAccount* [10];
			act_size = 0;
		}
		void OpenAccount(BankAccount *act){
			if(act_size < 10){
				accounts[act_size] = act;
				act_size++;
			}
		}
		void Transfer(int from, int to, double amount){
			accounts[from]->Withdraw(amount);
			accounts[to]->Deposit(amount);
		}
};

int main() {
	Bank *ku_bank = new Bank("KU Bank");

	BankAccount *usa = new BankAccount("Usa", 500);
	ku_bank->OpenAccount(usa);

	BankAccount *chakrit = new BankAccount("Chakrit", 1000);
	ku_bank->OpenAccount(chakrit);

	ku_bank->Transfer(0, 1, 100);
	cout << usa->GetBalance() << " : " << chakrit->GetBalance();


}
