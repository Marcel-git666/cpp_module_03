#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
  private:
    std::string name;
    unsigned int hitPoints;
    unsigned int attackDamage;
    unsigned int energyPoints;

  public:
    // Orthodox Canonical Form
    ClapTrap(void);
    ClapTrap(ClapTrap const &other);
    ClapTrap &operator=(ClapTrap const &other);
    ~ClapTrap(void);

    // Other methods
    ClapTrap(std::string const &name);
    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};
#endif
