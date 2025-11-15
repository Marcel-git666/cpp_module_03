
#include "FragTrap.hpp"
#include <iostream>

int main(void) {

    // --- 1. CONSTRUCTOR/DESTRUCTOR CHAINING TEST ---
    std::cout << "\n--- 1. FRAGTRAP CHAINING TEST ---\n" << std::endl;
    {
        std::cout << "Creating FragTrap 'f1'..." << std::endl;
        FragTrap f1("F1");
        std::cout << "\n...Scope is about to end." << std::endl;
    }
    std::cout << "\n--- CHAINING TEST FINISHED ---\n" << std::endl;

    // --- 2. ORTHODOX CANONICAL FORM (OCF) TEST ---
    std::cout << "\n--- 2. FRAGTRAP OCF TEST ---\n" << std::endl;

    std::cout << "Creating 'original'..." << std::endl;
    FragTrap original("Original");
    std::cout << std::endl;

    std::cout << "Testing Copy Constructor (FragTrap copy = original;)..."
              << std::endl;
    FragTrap copy = original;
    std::cout << "Copy's name should be 'Original'." << std::endl;
    copy.attack("TestTarget");
    std::cout << std::endl;

    std::cout << "Creating 'assignTarget'..." << std::endl;
    FragTrap assignTarget("AssignTarget");
    std::cout << std::endl;

    std::cout << "Testing Assignment Operator (assignTarget = original;)..."
              << std::endl;
    assignTarget = original;
    std::cout << "AssignTarget's name should now be 'Original'." << std::endl;
    assignTarget.attack("AnotherTarget");
    std::cout << std::endl;

    std::cout << "--- OCF TEST FINISHED ---\n" << std::endl;

    // --- 3. BASIC FUNCTIONALITY TEST ---
    std::cout << "\n--- 3. FUNCTIONALITY TEST (using 'Original') ---\n"
              << std::endl;

    std::cout << "'Original' (100 HP, 100 EP, 30 AD) testing functions:\n";
    original.attack("Zombie");
    original.takeDamage(30);
    original.beRepaired(10);
    original.highFivesGuys();
    std::cout << "--- FUNCTIONALITY TEST FINISHED ---\n" << std::endl;

    // --- 4. ZERO HP (EXHAUSTION) TEST ---
    std::cout << "\n--- 4. ZERO HP TEST (using 'copy') ---\n" << std::endl;
    std::cout << "'Copy' taking 1000 damage..." << std::endl;
    copy.takeDamage(1000);

    std::cout << "\nAttempting actions at 0 HP..." << std::endl;
    copy.attack("Zombie");
    copy.beRepaired(50);
    copy.highFivesGuys();
    copy.takeDamage(10);
    std::cout << "--- ZERO HP TEST FINISHED ---\n" << std::endl;

    // --- 5. ZERO ENERGY (EXHAUSTION) TEST ---
    std::cout << "\n--- 5. ZERO ENERGY TEST ---\n" << std::endl;
    FragTrap energetic("Energetic");
    std::cout << "FragTrap 'Energetic' has 100 energy. Attempting 101 actions "
                 "(attacks)...\n";

    for (int i = 0; i < 101; i++) {
        std::cout << "Action #" << (i + 1) << ": ";
        energetic.attack("LoopTarget");
    }

    std::cout << "\nFinal attempt to use energy (repair):" << std::endl;
    energetic.beRepaired(10);
    std::cout << "--- ZERO ENERGY TEST FINISHED ---\n" << std::endl;

    std::cout
        << "\n--- MAIN() IS ENDING (remaining objects will be destroyed) ---\n"
        << std::endl;
    return 0;
}
