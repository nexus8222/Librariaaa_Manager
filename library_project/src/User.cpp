#include "User.h"
#include <iostream>

// Constructor

User::User()
    : id(0), name(""), borrowedCount(0), capacity(5)
{
    borrowedItemIds = new int[capacity];
}

User::User(int id, std::string name)
    : id(id), name(name), borrowedCount(0), capacity(5)
{
    borrowedItemIds = new int[capacity];   // allocates array of 5
}

// Deep copy constructor
User::User(const User& other)
    : id(other.id), name(other.name), borrowedCount(other.borrowedCount), capacity(other.capacity)
{
    borrowedItemIds = new int[capacity];
    for (int i = 0; i < borrowedCount; i++) {
        borrowedItemIds[i] = other.borrowedItemIds[i];
    }
}

// Destructor
User::~User() {
    delete[] borrowedItemIds;
}


// Add borrowed item
void User::borrowItem(int itemId) {

    // Expand array if full
    if (borrowedCount == capacity) {
        capacity *= 2;
        int* temp = new int[capacity];

        for (int i = 0; i < borrowedCount; i++)
            temp[i] = borrowedItemIds[i];

        delete[] borrowedItemIds;
        borrowedItemIds = temp;
    }

    borrowedItemIds[borrowedCount++] = itemId;

    std::cout << "+) Borrowed item with ID: " << itemId << std::endl;
}


// Return an item
void User::returnItem(int itemId) {
    int index = -1;

    // Find item
    for (int i = 0; i < borrowedCount; i++) {
        if (borrowedItemIds[i] == itemId) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        std::cout << "!) This item is not borrowed!\n";
        return;
    }

    // Shift left to remove
    for (int i = index; i < borrowedCount - 1; i++) {
        borrowedItemIds[i] = borrowedItemIds[i + 1];
    }

    borrowedCount--;

    std::cout << "-) Returned item with ID: " << itemId << std::endl;
}



void User::display() const {
    std::cout << "\n=== User Info ===\n";
    std::cout << "ID: " << id << "\nName: " << name;
    std::cout << "\nBorrowed items: ";

    if (borrowedCount == 0) {
        std::cout << "None\n";
        return;
    }

    for (int i = 0; i < borrowedCount; i++) {
        std::cout << borrowedItemIds[i] << " ";
    }
    
    std::cout << "\n";
}
