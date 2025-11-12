#include "ClapTrap.hpp"

int main(void) {

    ClapTrap clapTrap;

    clapTrap = ClapTrap("Mech 1");
    clapTrap.attack("Zombie");
    clapTrap.beRepaired(2);
    clapTrap.takeDamage(1);
    clapTrap.takeDamage(3);
    clapTrap.takeDamage(9);
    clapTrap.takeDamage(100);
    return 0;
}
