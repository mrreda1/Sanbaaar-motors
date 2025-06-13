#include "motor.hpp"

void addInitialMotors() {
    Motor::addMotor("EC Frameless DT 50", 50, 322, 350);
    Motor::addMotor("ECX FLAT 42", 42, 221, 300);
    Motor::addMotor("ECX FLAT 32", 32, 94.4, 265);
    Motor::addMotor("ECX PRIME 22", 22, 66, 200);
    Motor::addMotor("A-max 22", 22, 6.18, 170);
    Motor::addMotor("A-max 16", 16, 2.11, 140);
    Motor::addMotor("A-max 19", 19, 1.35, 90);
}
