#include "gear.hpp"
#include "hopcroft.hpp"
#include "motor.hpp"
#include <iostream>

using namespace std;

int readRequiredTorque();
void printValidMatching(vector<pair<int, int>> valid_matching);

int main() {
    addInitialMotors();
    addInitialGears();
    double required_torque = readRequiredTorque();
    vector<pair<int, int>> valid_matching = maximum_matching(required_torque);
    printValidMatching(valid_matching);
}

void printValidMatching(vector<pair<int, int>> valid_matching) {
    if (valid_matching.empty()) {
        cout << "\nThere are no valid matching.";
        return;
    }
    cout << "\nCurrently valid matching is " << valid_matching.size() << '\n';

    int counter = 1;
    for (auto [motor_id, gear_id] : valid_matching) {
        string motor_name = Motor::motors[motor_id]->getName();
        string gear_name = Gear::gears[gear_id]->getName();

        double motor_cost = Motor::motors[motor_id]->getCost();
        double gear_cost = Gear::gears[gear_id]->getCost();

        cout << '\n' << string(20, '-');
        cout << "\nMatch #" << counter++ << ":\n";
        cout << "Motor info:" << '\n';
        cout << "   Name: " << motor_name << '\n';
        cout << "   Cost: " << motor_cost << '$' << "\n\n";

        cout << "Gear info:" << '\n';
        cout << "   Name: " << gear_name << '\n';
        cout << "   Cost: " << gear_cost << '$' << "\n\n";

        cout << "Total Cost: " << motor_cost + gear_cost << '$' << "\n";
        cout << "Output Torque: " << getOutputTorque(motor_id, gear_id) << " mNm\n";
    }
}

int readRequiredTorque() {
    cout << "Enter Required Torque: ";

    double required_torque;
    cin >> required_torque;

    return required_torque;
}
