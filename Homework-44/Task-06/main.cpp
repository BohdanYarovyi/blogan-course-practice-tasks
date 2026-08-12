#include <iostream>

/*
    Створіть програму, яка керує банківськими аккаунтами, використовуючи функції та глобальні змінні.

    Список глобальних констант:

    int accountsCount; -> загальна кількість аккаунтів
    double totalBalance; -> загальний баланс всіх аккаунтів

    Список функцій:

    void CreateAccount() -> просить у користувача ввести початковий баланс нового аккаунту. Після
        введення кількість аккаунтів і загальний баланс збільшується.

    bool Deposit(double money) -> додає указанy суму грошей до загального балансу.

    bool Withdraw(double money) -> віднімає указанy суму грошей від загального балансу.

    УВАГА: замітьте, що обидві функції повертають тип bool. Діло в тому, що ці операції можуть не спрацювати
    (наприклад сума грошей не коректна, або балансу не хватає, щоб зняти гроші). Врахуйте це.

    void ShowAccountsCount() - виводить на екран кількість створених аккаунтів.
    void ShowTotalBalance() - виводить на екран загальний баланс всіх аккаунтів.

    Створіть файл Bank.cpp. Розмістіть ці змінні і функції в ньому. А у функції main із файлу Main.cpp,
    ви будете користуватися цими функціями. Для цього не забудьте їх оголосити.

    У функції main у вас будуть реалізовані свої функції:

    void ShowMenu() - виводить меню із наступних пунктів:
        1 - показати загальний баланс,
        2 - показати кількість аккаунтів,
        3 - створити новий аккаунт
        4 - покласти гроші на рахунок
        5 - зняти гроші з рахунку
        0 - вихід із програми

    int EnterMenuItem() - функція, яка просить у користувача вибрати пункт меню і повертає це значення.

    У самій функції main має спочатку появитися меню, далі користувач вводить пункт меню. Після цього
    ви аналізуєте цей пункт (завдяки if або switch) і викликаєте відповідну функцію в залежності від
    пункту. Після завершення чергової операції меню має появлятися знову. Іншими словами всі ці алгоритми
    мають знаходитися в циклі, який завершиться лише тоді, коли користувач захоче вийти із програми (вибравши
    пункт 0).
 */

void create_account();

bool deposit(double money);

bool withdraw(double money);

void show_accounts_count();

void show_total_balance();

void show_menu() {
	std::cout << "Chose one of the following menu item: " 	<< std::endl;
	std::cout << " 1 - show total balance" 					<< std::endl;
	std::cout << " 2 - show amount of accounts" 			<< std::endl;
	std::cout << " 3 - create new account" 					<< std::endl;
	std::cout << " 4 - deposit" 							<< std::endl;
	std::cout << " 5 - withdraw" 							<< std::endl;
	std::cout << " 6 - exit program" 						<< std::endl;
}

int enter_menu_item() {
	std::cout << ">> ";
	int menu_item;
	std::cin >> menu_item;

	return menu_item;
}

int main() {
	int menu_item;
	while (true) {
		show_menu();
		menu_item = enter_menu_item();

		switch (menu_item) {
			case 1: {
			    show_total_balance();
			    break;
		    }
			case 2: {
			    show_accounts_count();
			    break;
		    }
			case 3: {
			    create_account();
			    break;
		    }
		    case 4: {
			    std::cout << "Enter amount of dollars to deposit: ";
			    double money;
			    std::cin >> money;
			    deposit(money);
			    break;
		    }
			case 5: {
		    	std::cout << "Enter amount of dollars to withdraw: ";
			    double money;
	    		std::cin >> money;
				withdraw(money);
			    break;
		    }
			case 6: {
    			return 0;
			}
		    default: {
			    std::cout << "Such option doesn't exist: " << menu_item << std::endl;
			}
	    }
	    std::cout << std::endl;
	}

	return  0;
}
