#include "FragTrap.hpp"
#include <iostream>

// Orthodox Canonical Form
FragTrap::FragTrap(void) : ClapTrap("DefaultFragTrap", 100, 30, 100) {
    std::cout << "Default FragTrap constructor called\n";
}

FragTrap::FragTrap(FragTrap const &other) : ClapTrap(other) {
    std::cout << "FragTrap copy constructor called\n";
}

FragTrap &FragTrap::operator=(FragTrap const &other) {
    std::cout << "FragTrap copy asignment operator called\n";
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

FragTrap::~FragTrap(void) { std::cout << "FragTrap destructor called\n"; }

// Other methods
FragTrap::FragTrap(std::string const &name) : ClapTrap(name, 100, 30, 100) {
    std::cout << "FragTrap named constructor called\n";
}

void FragTrap::highFivesGuys() {
    if (hitPoints > 0 && energyPoints > 0) {
        std::cout << "FragTrap " << name << " would like a high five.\n";
        energyPoints--;
    }
}
