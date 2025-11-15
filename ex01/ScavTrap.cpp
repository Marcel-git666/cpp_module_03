#include "ScavTrap.hpp"
#include <iostream>

// Orthodox Canonical Form
ScavTrap::ScavTrap(void) : ClapTrap("DefaultScavTrap") {
    hitPoints = 100;
    attackDamage = 20;
    energyPoints = 50;
    std::cout << "Default ScavTrap constructor called\n";
}

ScavTrap::ScavTrap(ScavTrap const &other) : ClapTrap(other) {
    std::cout << "ScavTrap copy constructor called\n";
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other) {
    std::cout << "ScavTrap copy asignment operator called\n";
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap(void) { std::cout << "ScavTrap destructor called\n"; }

// Other methods
ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name, 100, 20, 50) {
    std::cout << "ScavTrap named constructor called\n";
}

void ScavTrap::attack(const std::string &target) {
    if (hitPoints > 0 && energyPoints > 0) {
        std::cout << "ScavTrap " << name << " attacks " << target
                  << ", causing " << attackDamage << " points of damage!\n";
        energyPoints--;
    }
}

void ScavTrap::guardGate() {
    if (hitPoints > 0 && energyPoints > 0) {
        std::cout << "ScavTrap " << name << " is now in GateKeeper mode.\n";
        energyPoints--;
    }
}
