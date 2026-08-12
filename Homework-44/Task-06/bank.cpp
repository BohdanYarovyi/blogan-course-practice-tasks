#include <iostream>

const double MIN_DEPOSIT_LIMIT = 0.01;

const double MAX_DEPOSIT_LIMIT = 10'000.00;

const double MIN_WITHDRAW_LIMIT = 0.01;

const double MAX_WITHDRAW_LIMIT = 1'000.00;

static int accounts_count;

static double total_balance;

void create_account() {
	std::cout << "Enter initial balance: ";
	double initial_balance;
	std::cin >> initial_balance;

	if (initial_balance < 0) {
		std::cout << "Uncorrect data: initial balance cannot be negative" << std::endl;
		return;
	}

	total_balance += initial_balance;
	accounts_count++;
	std::cout << "Was created an account with initial balance: " << initial_balance << std::endl;
}

bool deposit(double money) {
	if (money < MIN_DEPOSIT_LIMIT || money > MAX_DEPOSIT_LIMIT) {
		std::cout << "Failed to deposit money: Deposit must be between "
		          << MIN_DEPOSIT_LIMIT << " and " << MAX_DEPOSIT_LIMIT << std::endl;
		return false;
	}

	total_balance += money;
	std::cout << "Success: On your account was depositted " << money << " dollars." << std::endl;
	return true;
}

bool withdraw(double money) {
	if (money < MIN_WITHDRAW_LIMIT || money > MAX_WITHDRAW_LIMIT) {
		std::cout << "Failed to withdraw money: Amount of withdraw money must be between "
		          << MIN_WITHDRAW_LIMIT << " and " << MAX_WITHDRAW_LIMIT << std::endl;
		return false;
	}

	if (money > total_balance) {
		std::cout << "Failed to withdraw money: Not enough money on account" << std::endl;
		return false;
	}

	total_balance -= money;
	std::cout << "Success: From your account was withdrawed " << money << " dollars." << std::endl;
	return true;
}

void show_accounts_count() {
	std::cout << "Registred accounts in the bank: " << accounts_count << std::endl;
}

void show_total_balance() {
	std::cout << "Total balance: " << total_balance << std::endl;
}
