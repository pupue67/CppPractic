#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;



class Robot
{
private:
    int id;
    string name;
    double power;

public:
    Robot(int id, string name, double power) : id(id), name(name), power(power)
    {
    }

    void info()
    {
        cout << "ID: " << id << "\n";
        cout << "Название: " << name << "\n";
    }

    void state()
    {
        cout << "Уровень заряда: " << power << "%\n";
    }

    virtual void task() = 0;

    virtual ~Robot() = default;
};


class Movable
{
public:
    virtual void move() = 0;

    virtual ~Movable() = default;
};



class DataTransmitter
{
public:
    virtual void transmit() = 0;

    virtual ~DataTransmitter() = default;
};


class ScoutRobot : public Robot, public Movable, public DataTransmitter
{
public:
    ScoutRobot(int id, string name, double power) : Robot(id, name, power)
    {
    }

    void move() override
    {
        cout << "Робот-разведчик перемещается по территории\n";
    }

    void transmit() override
    {
        cout << "Робот-разведчик передаёт данные о территории оператору\n";
    }

    void task() override
    {
        cout << "Робот-разведчик исследует территорию\n";
    }
};


class ResearchRobot : public Robot, public Movable, public DataTransmitter
{
public:
    ResearchRobot(int id, string name, double power) : Robot(id, name, power)
    {
    }

    void move() override
    {
        cout << "Робот-исследователь осторожно перемещается к образцам\n";
    }

    void transmit() override
    {
        cout << "Робот-исследователь передаёт результаты исследования оператору\n";
    }

    void task() override
    {
        cout << "Робот-исследователь анализирует образцы\n";
    }
};


class AnalysisRobot : public Robot, public DataTransmitter
{
public:
    AnalysisRobot(int id, string name, double power) : Robot(id, name, power)
    {
    }

    void transmit() override
    {
        cout << "Робот-аналитик передаёт результаты обработки данных оператору\n";
    }

    void task() override
    {
        cout << "Робот-аналитик обрабатывает полученные данные\n";
    }
};



class SecurityRobot : public Robot, public Movable, public DataTransmitter
{
private:
    int protectionLevel;

public:
    SecurityRobot(int id, string name, double power, int protectionLevel) : Robot(id, name, power), protectionLevel(protectionLevel)
    {
    }

    void move() override
    {
        cout << "Робот-охранник патрулирует территорию\n";
    }

    void transmit() override
    {
        cout << "Робот-охранник передаёт данные о безопасности оператору\n";
    }

    void task() override
    {
        cout << "Робот-охранник защищает территорию\n";
        cout << "Уровень защиты: " << protectionLevel << "\n";
    }
};



void moveRobot(Movable& robot)
{
    robot.move();
}



void sendData(DataTransmitter& robot)
{
    robot.transmit();
}


int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    ScoutRobot scout(1, "Разведчик-1", 90);
    ResearchRobot research(2, "Исследователь-1", 75);
    AnalysisRobot analysis(3, "Аналитик-1", 60);
    SecurityRobot security(4, "Охранник-1", 85, 5);


    Robot* robots[4] = { &scout, &research, &analysis, &security };

    cout << "Информация о роботах\n\n";

    for (int i = 0; i < 4; i++)
    {
        robots[i]->info();
        robots[i]->state();
        robots[i]->task();
        cout << " \n";
    }


    cout << "\nПеремещение\n";

    moveRobot(scout);
    moveRobot(research);
    moveRobot(security);


    cout << "\nПередача данных\n";

    sendData(scout);
    sendData(research);
    sendData(analysis);
    sendData(security);

    return 0;
}