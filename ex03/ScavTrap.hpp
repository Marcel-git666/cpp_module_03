#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public virtual ClapTrap {

  public:
    // Orthodox Canonical Form
    ScavTrap(void);
    ScavTrap(ScavTrap const &other);
    ScavTrap &operator=(ScavTrap const &other);
    ~ScavTrap(void);

    // Other methods
    ScavTrap(std::string const &name);
    void guardGate();
    void attack(const std::string &target);
};
#endif
