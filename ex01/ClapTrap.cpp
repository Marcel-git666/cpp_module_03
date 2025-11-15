#include "ClapTrap.hpp"
#include <iostream>

// Orthodox Canonical Form
ClapTrap::ClapTrap(void)
    : name("DefaultClapTrap"), hitPoints(10), attackDamage(0),
      energyPoints(10) {
    std::cout << "Default ClapTrap constructor called\n";
}
ClapTrap::ClapTrap(ClapTrap const &other)
    : name(other.name), hitPoints(other.hitPoints),
      attackDamage(other.attackDamage), energyPoints(other.energyPoints) {
    std::cout << "ClapTrap copy constructor called\n";
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other) {
    std::cout << "ClapTrap copy asignment operator called\n";
    if (this != &other) {
        name = other.name;
        attackDamage = other.attackDamage;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
    }
    return *this;
}

ClapTrap::~ClapTrap(void) { std::cout << "ClapTrap destructor called\n"; }

// protected ctor

ClapTrap::ClapTrap(std::string const &name, unsigned int hp, unsigned int ad,
                   unsigned int ep)
    : name(name), hitPoints(hp), attackDamage(ad), energyPoints(ep) {
    std::cout << "ClapTrap protected constructor called\n";
}

// Other methods
ClapTrap::ClapTrap(std::string const &name)
    : name(name), hitPoints(10), attackDamage(0), energyPoints(10) {
    std::cout << "ClapTrap named constructor called\n";
}

void ClapTrap::attack(const std::string &target) {
    if (hitPoints > 0 && energyPoints > 0) {
        std::cout << "ClapTrap " << name << " attacks " << target
                  << ", causing " << attackDamage << " points of damage!\n";
        energyPoints--;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints == 0) {
        std::cout << "ClapTrap " << name << " is already disabled!\n";
        return;
    }
    if (hitPoints > amount) {
        std::cout << "ClapTrap " << name << " has taken " << amount
                  << " points of damage!\n";
        hitPoints -= amount;
    } else {
        std::cout << "ClapTrap " << name << " has taken " << amount
                  << " points of damage and is now at 0 HP!\n";
        hitPoints = 0;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (hitPoints > 0 && energyPoints > 0) {
        std::cout << "ClapTrap " << name << " has been repaired for " << amount
                  << " hit points!\n";
        hitPoints += amount;
        energyPoints--;
    }
}
