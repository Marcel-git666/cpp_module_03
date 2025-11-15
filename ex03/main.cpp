#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void) {

    std::cout << "\n--- 1. Testing Construction & Core Functions ---\n"
              << std::endl;

    std::cout << "Creating DiamondTrap 'Sparkle'..." << std::endl;
    DiamondTrap dt("Sparkle");
    std::cout << std::endl;

    // --- 2. TEST whoAmI() ---
    std::cout << "--- Testing whoAmI() ---\n";
    dt.whoAmI();
    std::cout << std::endl;

    std::cout << "--- Testing inherited & overridden functions ---\n";

    std::cout << "Calling attack(): ";
    dt.attack("a poor peasant");

    std::cout << "Calling guardGate(): ";
    dt.guardGate();

    std::cout << "Calling highFivesGuys(): ";
    dt.highFivesGuys();
    std::cout << std::endl;

    std::cout << "--- Testing Stats (HP=100, EP=50, AD=30) ---\n";
    std::cout << "'Sparkle' has 100 HP, 50 EP, 30 AD.\n";

    dt.takeDamage(30);
    dt.beRepaired(10);
    dt.takeDamage(90);

    std::cout << "\nAttempting actions at 0 HP:" << std::endl;
    dt.beRepaired(10);
    dt.attack("the air");
    std::cout << std::endl;

    // --- 5. TEST ORTODOXNÍ KANONICKÉ FORMY (OCF) ---
    std::cout << "\n--- 5. Testing OCF ---\n";

    // Test Kopírovacího konstruktoru
    std::cout << "--- Testing Copy Constructor ---\n";
    DiamondTrap copy = dt;

    std::cout << "\n--- Checking copy's 'whoAmI()' (should be 'Sparkle') ---\n";
    copy.whoAmI();
    std::cout << std::endl;

    // Test Operátoru přiřazení
    std::cout << "--- Testing Assignment Operator ---\n";
    DiamondTrap assign("Assign-Me");
    std::cout << "--- Before assignment, 'Assign-Me' says: ---\n";
    assign.whoAmI();

    assign = dt; // Volá se operator=

    std::cout << "\n--- After assignment, 'Assign-Me' says: ---\n";
    assign.whoAmI();
    std::cout << std::endl;

    // --- 6. TEST DESTRUKCE ---
    std::cout << "\n--- 6. Testing Destruction ---\n";
    std::cout
        << "main() is ending. Destructors will be called in reverse order.\n";
    std::cout << "(Diamond -> Frag -> Scav -> Clap)\n" << std::endl;

    return 0;
}
