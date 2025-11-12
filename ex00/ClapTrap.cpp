#include "ClapTrap.hpp"

// Orthodox Canonical Form
ClapTrap::ClapTrap(void);
ClapTrap::ClapTrap(ClapTrap const &other);
ClapTrap::ClapTrap &operator=(ClapTrap const &other);
ClapTrap::~ClapTrap(void);

// Other methods
ClapTrap(std::string name);
void attack(const std::string &target);
void takeDamage(unsigned int amount);
void beRepaired(unsigned int amount);
