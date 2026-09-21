#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Employee
{
protected:
    string name;
    double salary;
    int id;

    static int employeeCount;

public:
    Employee(string name, double salary)
    {
        this->name = name;
        this->salary = salary;

        employeeCount++;
        id = employeeCount;
    }

    
    Employee(const Employee& other)
    {
        name = other.name;
        salary = other.salary;

        employeeCount++;
        id = employeeCount;
    }

    virtual double CalculateSalary()
    {
        return salary;
    }

    virtual void Work()
    {
        cout << name << " работает" << endl;
    }

    virtual void Print() const
    {
        cout << "ID: " << id << endl;
        cout << "Имя: " << name << endl;
        cout << "Базовая зарплата: " << salary << " рублей" << endl;
    }

    static int getEmployeeCount()
    {
        return employeeCount;
    }

    virtual ~Employee() = default;
};


int Employee::employeeCount = 0;


class Developer : public Employee
{
private:
    string programmingLanguage;

public:
    Developer(string name, double salary, string programmingLanguage)
        : Employee(name, salary)
    {
        this->programmingLanguage = programmingLanguage;
    }

    double CalculateSalary() override
    {
        return salary * 1.20;
    }

    void Work() override
    {
        cout << name
             << " пишет программу на "
             << programmingLanguage
             << endl;
    }

    void Print() const override
    {
        cout << "ID: " << id << endl;
        cout << "Имя: " << name << endl;
        cout << "Должность: разработчик" << endl;
        cout << "Язык программирования: " << programmingLanguage << endl;
        cout << "Базовая зарплата: " << salary << " рублей" << endl;
    }
};

class Tester : public Employee
{
private:
    int bugsFound;

public:
    Tester(string name, double salary, int bugsFound)
        : Employee(name, salary)
    {
        this->bugsFound = bugsFound;
    }

    double CalculateSalary() override
    {
        if (bugsFound <= 10)
        {
            return salary * 1.05;
        }
        else if (bugsFound <= 30)
        {
            return salary * 1.10;
        }
        else
        {
            return salary * 1.15;
        }
    }

    void Work() override
    {
        cout << name
             << " тестирует программу и ищет ошибки"
             << endl;
    }

    void Print() const override
    {
        cout << "ID: " << id << endl;
        cout << "Имя: " << name << endl;
        cout << "Должность: тестировщик" << endl;
        cout << "Найдено ошибок: " << bugsFound << endl;
        cout << "Базовая зарплата: " << salary << " рублей" << endl;
    }
};


class Analyst : public Employee
{
private:
    int projects;

public:
    Analyst(string name, double salary, int projects)
        : Employee(name, salary)
    {
        this->projects = projects;
    }

    double CalculateSalary() override
    {
        if (projects > 5)
        {
            return salary * 1.25;
        }
        else
        {
            return salary * 1.10;
        }
    }

    void Work() override
    {
        cout << name
             << " занимается анализом проектов"
             << endl;
    }

    void Print() const override
    {
        cout << "ID: " << id << endl;
        cout << "Имя: " << name << endl;
        cout << "Должность: аналитик" << endl;
        cout << "Количество проектов: " << projects << endl;
        cout << "Базовая зарплата: " << salary << " рублей" << endl;
    }
};


int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    Employee* employees[5];

    employees[0] =
        new Developer("Николай", 100000, "C++");

    employees[1] =
        new Developer("Алексей", 90000, "C#");

    employees[2] =
        new Tester("Иван", 70000, 8);

    employees[3] =
        new Tester("Анна", 75000, 35);

    employees[4] =
        new Analyst("Олег", 85000, 7);


    for (int i = 0; i < 5; i++)
    {
        cout << "Сотрудник №" << i + 1 << endl;

        employees[i]->Print();

        employees[i]->Work();

        cout << "Итоговая зарплата: "
             << employees[i]->CalculateSalary()
             << " рублей"
             << endl;

    }


    cout << endl;

    cout << "Всего создано сотрудников: "
         << Employee::getEmployeeCount()
         << endl;


    for (int i = 0; i < 5; i++)
    {
        delete employees[i];
    }

    return 0;
}