#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void) {

    // --- 1. CONSTRUCTOR/DESTRUCTOR CHAINING TEST ---
    // This demonstrates that the base class (ClapTrap) is constructed
    // before the derived class (ScavTrap), and destruction
    // happens in the reverse order.
    std::cout << "\n--- 1. CONSTRUCTOR/DESTRUCTOR CHAINING TEST ---\n"
              << std::endl;
    {
        std::cout << "Creating ScavTrap 's1'..." << std::endl;
        ScavTrap s1("S1");
        std::cout << "\nCreating ClapTrap 'c1'..." << std::endl;
        ClapTrap c1("C1");
        std::cout << "\n...Scope is about to end." << std::endl;
    } // Destructors for s1 and c1 are called HERE
    std::cout << "\n--- CHAINING TEST FINISHED ---\n" << std::endl;

    // --- 2. ORTHODOX CANONICAL FORM (OCF) TEST ---
    std::cout << "\n--- 2. ORTHODOX CANONICAL FORM (OCF) TEST ---\n"
              << std::endl;

    std::cout << "Creating 'original'..." << std::endl;
    ScavTrap original("Original");
    std::cout << std::endl;

    // Test Copy Constructor
    std::cout << "Testing Copy Constructor (ScavTrap copy = original;)..."
              << std::endl;
    ScavTrap copy = original;
    std::cout << "Copy's name should be 'Original'." << std::endl;
    copy.attack(
        "TestTarget"); // Just to verify 'copy' is alive and has the name
    std::cout << std::endl;

    // Test Assignment Operator
    std::cout << "Creating 'assignTarget'..." << std::endl;
    ScavTrap assignTarget("AssignTarget");
    std::cout << std::endl;

    std::cout << "Testing Assignment Operator (assignTarget = original;)..."
              << std::endl;
    assignTarget = original; // operator= is called here
    std::cout << "AssignTarget's name should now be 'Original'." << std::endl;
    assignTarget.attack("AnotherTarget"); // Verification
    std::cout << std::endl;

    std::cout << "--- OCF TEST FINISHED ---\n" << std::endl;

    // --- 3. BASIC FUNCTIONALITY TEST ---
    // Using 'original', which has full stats
    std::cout << "\n--- 3. FUNCTIONALITY TEST (using 'Original') ---\n"
              << std::endl;
    std::cout << "'Original' (100 HP, 50 EP, 20 AD) testing functions:\n";
    original.attack("Zombie"); // Should deal 20 dmg, cost 1 EP
    original.takeDamage(30);   // Should now have 70 HP
    original.beRepaired(10);   // Should now have 80 HP, cost 1 EP
    original.guardGate();      // Should print its message, cost 1 EP
    std::cout << "--- FUNCTIONALITY TEST FINISHED ---\n" << std::endl;

    // --- 4. ZERO HP (EXHAUSTION) TEST ---
    // Using 'copy', which currently has 100 HP
    std::cout << "\n--- 4. ZERO HP TEST (using 'copy') ---\n" << std::endl;
    std::cout << "'Copy' taking 1000 damage..." << std::endl;
    copy.takeDamage(1000); // This will set its HP to 0

    std::cout << "\nAttempting actions at 0 HP..." << std::endl;
    copy.attack("Zombie"); // Should fail
    copy.beRepaired(50);   // Should fail
    copy.guardGate();      // Should fail
    copy.takeDamage(10);   // Should print "is already disabled!"
    std::cout << "--- ZERO HP TEST FINISHED ---\n" << std::endl;

    // --- 5. ZERO ENERGY (EXHAUSTION) TEST ---
    // A new ScavTrap has 50 energy points.
    std::cout << "\n--- 5. ZERO ENERGY TEST ---\n" << std::endl;
    ScavTrap energetic("Energetic");
    std::cout << "ScavTrap 'Energetic' has 50 energy. Attempting 51 actions "
                 "(attacks)...\n";

    for (int i = 0; i < 51; i++) {
        // Printing just for clarity
        std::cout << "Action #" << (i + 1) << ": ";
        energetic.attack("LoopTarget");
        // The 51st attack (i=50) should fail silently (energyPoints > 0 check
        // fails)
    }

    std::cout << "\nFinal attempt to use energy (repair):" << std::endl;
    energetic.beRepaired(10); // Should also fail due to 0 energy
    std::cout << "--- ZERO ENERGY TEST FINISHED ---\n" << std::endl;

    std::cout
        << "\n--- MAIN() IS ENDING (remaining objects will be destroyed) ---\n"
        << std::endl;
    return 0;
    // Destructors for:
    // energetic, assignTarget, copy, original
    // will be called here in reverse order of their creation.
}
