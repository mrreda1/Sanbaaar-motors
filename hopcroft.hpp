#ifndef _HOPKROFT
#define _HOPKROFT

#include "gear.hpp"
#include "motor.hpp"

double getOutputTorque(int motor_id, int gear_id);
vector<pair<int, int>> maximum_matching(double required_torque);
bool isValidMatch(int motor_id, int gear_id, double required_torque);

#endif
