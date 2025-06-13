#include "hopcroft.hpp"
#include <set>
#include <stack>

double getOutputTorque(int motor_id, int gear_id) {
    Motor *motor = Motor::motors[motor_id];
    Gear *gear = Gear::gears[gear_id];

    double torque = motor->getTorque();
    double efficiency = gear->getEfficiency();
    double ratio = gear->getRatio();

    return torque * efficiency * ratio;
}

bool isValidMatch(int motor_id, int gear_id, double required_torque) {
    Motor *motor = Motor::motors[motor_id];
    Gear *gear = Gear::gears[gear_id];

    bool valid_diameter = gear->getDiameter() <= motor->getDiameter();
    bool valid_torque = getOutputTorque(motor_id, gear_id) >= required_torque;

    return valid_diameter && valid_torque;
}

vector<pair<int, int>> maximum_matching(double required_torque) {
    int n = Motor::getNumberOfMotors(), m = Gear::getNumberOfGears();
    vector<vector<int>> edges(n + m);
    set<int> matched, unmatched;
    for (int i = 0; i < n; i++) {
        unmatched.insert(i);
        for (int j = 0; j < m; j++) {
            if (isValidMatch(i, j, required_torque)) {
                edges[i].push_back(n + j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int v : edges[i]) {
            if (edges[v].empty()) {
                matched.insert(i);
                unmatched.erase(i);
                edges[v].push_back(i);
                break;
            }
        }
    }
    while (!unmatched.empty()) {
        int st = *unmatched.begin(), found = 0;
        vector<int> parent(n + m, 0);
        stack<int> pending({st});
        parent[st] = -1;
        while (!pending.empty()) {
            int current = pending.top();
            pending.pop();
            for (int neighbor : edges[current]) {
                if (!parent[neighbor]) {
                    parent[neighbor] = current;
                    if (neighbor > n && edges[neighbor].empty()) {
                        found = neighbor;
                        break;
                    } else {
                        pending.push(neighbor);
                    }
                }
            }
            if (found) {
                break;
            }
        }
        if (!found) {
            break;
        }
        while (found != st) {
            if (found >= n) {
                edges[found] = {parent[found]};
            }
            found = parent[found];
        }
        unmatched.erase(st);
        matched.insert(st);
    }
    vector<pair<int, int>> valid_matching;
    for (int i = n; i < n + m; i++) {
        if (!edges[i].empty()) {
            valid_matching.push_back({edges[i][0], i - n});
        }
    }
    return valid_matching;
}
