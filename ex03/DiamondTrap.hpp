#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#include <string>

class DiamondTrap : public ScavTrap, public FragTrap {

  private:
    std::string name;

  public:
    // Orthodox Canonical Form
    DiamondTrap(void);
    DiamondTrap(DiamondTrap const &other);
    DiamondTrap &operator=(DiamondTrap const &other);
    ~DiamondTrap(void);

    // Other methods
    DiamondTrap(std::string const &name);
    void attack(const std::string &target);
    void whoAmI();
};
#endif
