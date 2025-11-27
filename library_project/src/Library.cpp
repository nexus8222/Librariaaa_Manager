#include "Library.h"
#include "Book.h"
#include "Magazine.h"
#include "Comic.h"
#include <string>


#include <iostream>

// ---------------- Constructor ----------------

Library::Library() {
    itemCapacity = 5;
    userCapacity = 5;

    items = new Item*[itemCapacity];
    users = new User[userCapacity];

    itemCount = 0;
    userCount = 0;

    nextItemId = 1;
    nextUserId = 1;
}

// ---------------- Destructor ----------------

Library::~Library() {
    for (int i = 0; i < itemCount; i++)
        delete items[i];

    delete[] items;
    delete[] users;
}

// ---------------- Expand Items ----------------

void Library::expandItems() {
    itemCapacity *= 2;
    Item** newArr = new Item*[itemCapacity];

    for (int i = 0; i < itemCount; i++)
        newArr[i] = items[i];

    delete[] items;
    items = newArr;
}

// ---------------- Expand Users ----------------

void Library::expandUsers() {
    userCapacity *= 2;
    User* newArr = new User[userCapacity];

    for (int i = 0; i < userCount; i++)
        newArr[i] = users[i];   // uses User deep copy

    delete[] users;
    users = newArr;
}

// ---------------- Add Book ----------------

int Library::addBook(std::string title, std::string author, int pages) {
    if (itemCount == itemCapacity) expandItems();

    items[itemCount] = new Book(nextItemId, title, author, pages);
    itemCount++;

    return nextItemId++;
}

// ---------------- Add Magazine ----------------

int Library::addMagazine(std::string title, int issue, std::string month) {
    if (itemCount == itemCapacity) expandItems();

    items[itemCount] = new Magazine(nextItemId, title, issue, month);
    itemCount++;

    return nextItemId++;
}

// ---------------- Add Comic ----------------

int Library::addComic(std::string title, std::string universe) {
    if (itemCount == itemCapacity) expandItems();

    // Using default values for Volume and Illustrator
    int defaultVolume = 1;
    std::string defaultIllustrator = "Unknown";

    // Create new Comic object
    items[itemCount] = new Comic(nextItemId, title, defaultVolume, defaultIllustrator, universe);

    itemCount++;

    return nextItemId++;
}

// ---------------- Add User ----------------

int Library::addUser(std::string name) {
    if (userCount == userCapacity) expandUsers();

    users[userCount] = User(nextUserId, name); // calls constructor
    userCount++;

    return nextUserId++;
}

// ---------------- Borrow Item ----------------

void Library::borrowItem(int userId, int itemId) {
    for (int i = 0; i < userCount; i++) {
        if (users[i].getId() == userId) {
            users[i].borrowItem(itemId);
            return;
        }
    }
}

// ---------------- Return Item ----------------

void Library::returnItem(int userId, int itemId) {
    for (int i = 0; i < userCount; i++) {
        if (users[i].getId() == userId) {
            users[i].returnItem(itemId);
            return;
        }
    }
}

// ---------------- Display All Items ----------------

void Library::showAllItems() {
    for (int i = 0; i < itemCount; i++)
        items[i]->display();
}

// ---------------- Display All Users ----------------

void Library::showAllUsers() {
    for (int i = 0; i < userCount; i++)
        users[i].display();
}
