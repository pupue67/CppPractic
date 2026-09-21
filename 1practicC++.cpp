#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

class BankAccount
{
private:
    string owner;
    double balance;

public:


    BankAccount(string owner, double balance)
    {
        this->owner = owner;

        if (balance >= 0)
        {
            this->balance = balance;
        }
        else
        {
            this->balance = 0;
        }
    }


  
    BankAccount(const BankAccount& other)
    {
        owner = other.owner;
        balance = 0;
    }


    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance = balance + amount;
        }
        else
        {
            cout << "Нельзя внести отрицательную сумму \n";
        }
    }


  
    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            cout << "Нельзя снять отрицательную сумму \n";
        }
        else if (amount > balance)
        {
            cout << "Недостаточно денег \n";
        }
        else
        {
            balance = balance - amount;
        }
    }


   
    double getBalance() const
    {
        return balance;
    }



    string getOwner() const
    {
        return owner;
    }


   
    void print() const
    {
        cout << "Владелец: " << owner << "\n";
        cout << "Баланс: " << balance << "\n";
    }
};


int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    BankAccount account1("Иван", 10000);

    cout << "Первый счёт: \n";
    account1.print();


    account1.deposit(5000);

    cout << endl;
    cout << "После пополнения: \n";
    account1.print();


    account1.withdraw(3000);

    cout << endl;
    cout << "После снятия:  \n";
    account1.print();


   
    BankAccount account2 = account1;

    cout << endl;
    cout << "Копия счёта:   \n";
    account2.print();


    return 0;
}