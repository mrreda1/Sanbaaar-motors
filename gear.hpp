#ifndef _GEAR
#define _GEAR

#include <string>
#include <vector>

using namespace std;

class Gear {
  private:
    inline static int number_of_gears = 0;

    int id;
    string name;
    double diameter, cost, ratio, efficiency;

    Gear(string name, double diameter, double ratio, double efficiency,
         double cost) {
        this->id = number_of_gears++;
        this->name = name;
        this->diameter = diameter;
        this->ratio = ratio;
        this->efficiency = efficiency;
        this->cost = cost;
        gears.push_back(this);
    }

  public:
    inline static vector<Gear *> gears;

    string getName() {
        return name;
    }
    double getDiameter() {
        return diameter;
    }
    double getCost() {
        return cost;
    }
    double getRatio() {
        return ratio;
    }
    double getEfficiency() {
        return efficiency;
    }
    static int getNumberOfGears() {
        return number_of_gears;
    }
    static void addGear(string name, double diameter, double ratio,
                        double efficiency, double cost) {
        new Gear(name, diameter, ratio, efficiency, cost);
    }
};

void addInitialGears();

#endif
