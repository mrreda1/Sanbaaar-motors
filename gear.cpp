#include "gear.hpp"

void addInitialGears() {
    Gear::addGear("Planetary Gearhead GP 42", 42, 1296, 0.64, 220); // 830
    Gear::addGear("Planetary Gearhead GP 22", 22, 6561 / 16.0, 0.49, 160); // 200
    Gear::addGear("SPUR Gearhead GS 24", 24, 199, 0.53, 120);    // 105.47
    Gear::addGear("Planetary Gearhead GP 13", 13, 67, 0.75, 80); // 50
    Gear::addGear("Planetary Gearhead GP 16", 16, 729 / 25.0, 0.81, 70); // 23
    Gear::addGear("GB 12 Worm Gear", 12, 30, 0.65, 50);                  // 19.5
    Gear::addGear("Planetary Gearhead GP 22", 22, 57 / 13.0, 0.9, 20);   // 4
}
