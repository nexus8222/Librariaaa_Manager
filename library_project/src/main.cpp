#include <iostream>
#include "User.h"

int main() {

    // Create a user
    User u1(1, "Alice");

    std::cout << "\n--- Testing borrowItem() ---\n";
    u1.borrowItem(101);
    u1.borrowItem(202);
    u1.borrowItem(303);

    u1.display();

    std::cout << "\n--- Testing returnItem() ---\n";
    u1.returnItem(202);
    u1.display();

    std::cout << "\n--- Testing deep copy constructor ---\n";
    User u2 = u1;     // copy u1 → u2

    u2.display();

    std::cout << "\n--- Modifying u1 to check deep copy ---\n";
    u1.borrowItem(999);

    std::cout << "\nU1:\n";
    u1.display();

    std::cout << "\nU2 (should NOT have 999):\n";
    u2.display();

    std::cout << "\n(If the program ends without crash ⇒ destructor works)\n";
    
    return 0;
}
