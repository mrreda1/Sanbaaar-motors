#ifndef _MOTOR
#define _MOTOR

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Motor {
  private:
    inline static int number_of_motors = 0;

    int id;
    string name;
    double torque, diameter, cost;

  public:
    inline static vector<Motor *> motors;
    Motor(string name, double diameter, double torque, double cost) {
        this->id = number_of_motors++;
        this->name = name;
        this->diameter = diameter;
        this->torque = torque;
        this->cost = cost;
        motors.push_back(this);
    }
    string getName() {
        return name;
    }
    double getTorque() {
        return torque;
    }
    double getDiameter() {
        return diameter;
    }
    double getCost() {
        return cost;
    }
    void printInfo() {
        cout << "Name: " << this->getName() << "\n";
        cout << "Diameter: " << this->getDiameter() << " mm\n";
        cout << "Torque: " << this->getTorque() << " mNm\n";
        cout << "Cost: " << this->getCost() << " $\n";
    }

    static int getNumberOfMotors() {
        return number_of_motors;
    }
    static void addMotor(string name, double diameter, double torque,
                         double cost) {
        new Motor(name, diameter, torque, cost);
    }
};

void addInitialMotors();

#endif
