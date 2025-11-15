#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

// Orthodox Canonical Form
DiamondTrap::DiamondTrap(void)
    : ClapTrap("DefaultDiamondTrap"), ScavTrap(), FragTrap(),
      name("DefaultDiamondTrap") {
    std::cout << "Default DiamondTrap constructor called\n";
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 30;
}

DiamondTrap::DiamondTrap(DiamondTrap const &other)
    : ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name) {
    std::cout << "DiamondTrap copy constructor called\n";
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other) {
    std::cout << "DiamondTrap copy asignment operator called\n";
    if (this != &other) {
        ClapTrap::operator=(other);
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
        name = other.name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap(void) {
    std::cout << "DiamondTrap destructor called\n";
}

// Other methods
DiamondTrap::DiamondTrap(std::string const &name)
    : ClapTrap(name + "_clap_name", 100, 30, 50), ScavTrap(name),
      FragTrap(name), name(name) {
    std::cout << "DiamondTrap named constructor called\n";
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 30;
}

void DiamondTrap::attack(const std::string &target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << "My DiamondTrap name is: " << name << '\n';
    std::cout << "My ClapTrap name is: " << ClapTrap::name << '\n';
}
