#include <iostream>
#include "User.h"
#include "Library.h"

int main() {

    std::cout << "\n===== ADDING ITEMS =====\n";
    Library lib;
    // Test Books
    int b1 = lib.addBook("The Alchemist", "Paulo Coelho", 208);
    int b2 = lib.addBook("Clean Code", "Robert C. Martin", 464);

    // Test Magazines
    int m1 = lib.addMagazine("National Geographic", 310,"December");
    int m2 = lib.addMagazine("Time Magazine", 122,"August");

    // Test Comics
    int c1 = lib.addComic("Spider-Man",2, "JK miCHeal", "Marvel");
    int c2 = lib.addComic("Batman",1,"Augusta Gein",  "DC");

    std::cout << "\n===== SHOW ALL ITEMS =====\n";
    lib.showAllItems();


    std::cout << "\n===== ADDING USERS =====\n";
    int u1 = lib.addUser("Alice");
    int u2 = lib.addUser("Bob");

    lib.showAllUsers();


    std::cout << "\n===== BORROW ITEMS =====\n";
    lib.borrowItem(u1, b1);   // Alice borrows The Alchemist
    lib.borrowItem(u1, c1);   // Alice borrows Spider-Man
    lib.borrowItem(u2, m1);   // Bob borrows National Geographic

    lib.showAllUsers();


    std::cout << "\n===== RETURN ITEMS =====\n";
    lib.returnItem(u1, c1);    // Alice returns Spider-Man
    lib.returnItem(u2, m1);    // Bob returns National Geographic

    lib.showAllUsers();


    std::cout << "\n===== TEST USER DEEP COPY =====\n";
    User temp(10, "Temporary User");
    temp.borrowItem(111);
    temp.borrowItem(222);

    User copy = temp; // deep copy test

    std::cout << "\nOriginal User:\n";
    temp.display();

    std::cout << "\nCopied User:\n";
    copy.display();

    std::cout << "\nModify original user to check deep copy:\n";
    temp.borrowItem(999);

    std::cout << "\nOriginal User After Modification:\n";
    temp.display();

    std::cout << "\nCopied User Should NOT Have 999:\n";
    copy.display();


    // Item Removing

    // lib.removeItem(1);
    // lib.removeItem(2);
    // lib.removeItem(3);
    lib.removeItem(4);
    // lib.removeItem(5);
    lib.removeItem(6);
    // lib.showAllItems();
   
    std::cout << "\n===== ALL TESTS COMPLETED SUCCESSFULLY =====\n";

    return 0;
}
