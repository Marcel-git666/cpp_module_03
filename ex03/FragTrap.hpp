#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class FragTrap : public virtual ClapTrap {

  public:
    // Orthodox Canonical Form
    FragTrap(void);
    FragTrap(FragTrap const &other);
    FragTrap &operator=(FragTrap const &other);
    ~FragTrap(void);

    // Other methods
    FragTrap(std::string const &name);
    void highFivesGuys();
};
#endif
