#include <iostream>
#include <vector>

class BankAccount;

std::vector<BankAccount> UserAccounts;

class User {
private:
	std::string username;
	std::string password;
public:
	User(const std::string& username, const std::string& password) : username(username), password(password)
	{
		std::cout << "Username : " << username << std::endl;
		std::cout << "Password : " << password << std::endl;
	}
	void ChangePassword() {
		std::string old_pass,new_pass;
		std::cout << "Enter Old Password" << std::endl;
		std::cin >> old_pass;
		if (old_pass == password){
			std::cout << "Enter New Password" << std::endl;
			std::cin >> new_pass;
			password = new_pass;
		}
		else{
			std::cout << "Wrong Password!" << std::endl;
		}
	}

	friend class BankAccount;
};

class BankAccount {
private:
	User& user;
	int balance=0;
public:
	BankAccount(User& user) : user(user) 
	{
		UserAccounts.emplace_back(*this);
	}
	void Deposit(){
		int d_amount;
		std::cout << "Enter Amount to Deposit : " << std::endl;
		std::cin >> d_amount;
		balance += d_amount;
		std::cout << "New Balance : " << balance << std::endl;
	}
	void Withdraw() {
		int w_amount;
		std::cout << "Enter Amount to Withdraw : " << std::endl;
		std::cin >> w_amount;
		if (balance >= w_amount){
			balance -= w_amount;
			std::cout << "Amount Withdrawn : " << w_amount << std::endl;
			std::cout << "New Balance : " << balance << std::endl;
		}
	}

	void TransferFunds() {
		std::string other_user_username;
		std::cout << "Transfer To : " << std::endl;
		std::cin >> other_user_username;
		for (int i = 0; i < UserAccounts.size(); i++)
		{
			if (other_user_username == UserAccounts[i].user.username){
				int t_amount;
				std::cout << "User Found! " << std::endl;
				std::cout << "Enter Amount to Transfer" << std::endl;
				std::cin >> t_amount;
				if (balance >= t_amount) {
					balance -= t_amount;
					UserAccounts[i].balance += t_amount;
					std::cout << "Amount Transferred : " << t_amount << std::endl;
					std::cout << "Your Balance : " << balance << std::endl;
				}
				else {
					std::cout << "Wrong User! No User Found!" << std::endl;
				}

			}
		}
	}
};

int main() {
	User u1("Salman", "123");
	User u2("Shehrayar", "123");
	u1.ChangePassword();
	BankAccount B1 = u1;
	BankAccount B2 = u2;
	B1.Deposit();
	B1.Withdraw();
	B1.TransferFunds();

	std::cin.get();
}