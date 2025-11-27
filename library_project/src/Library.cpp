#include "Library.h"
#include "Book.h"
#include "Magazine.h"
#include "Comic.h"
#include <iostream>

// ---------------- Constructor ----------------
Library::Library() {
    nextItemId=1; 
    nextUserId=1; 
}

// ---------------- Destructor ----------------
Library::~Library() {
    // Delete all dynamically allocated Item objects
    for (auto item : items) {
        delete item;
    }
    items.clear();
    users.clear();
}

// ---------------- Add Book ----------------
int Library::addBook(const std::string& title, const std::string& author, int pages) {
    Item* book = new Book(nextItemId, title, author, pages);
    items.push_back(book);
    return nextItemId++;
}

// ---------------- Add Magazine ----------------
int Library::addMagazine(const std::string& title, int issue,const std::string& month) {
    Item* mag = new Magazine(nextItemId, title, issue, month);
    items.push_back(mag);
    return nextItemId++;
}

// ---------------- Add Comic ----------------
int Library::addComic(const std::string& title,int Volume,std::string illustrator, const std::string& universe) {
    int defaultVolume = 1;


    Item* comic = new Comic(nextItemId, title, Volume, illustrator, universe);
    items.push_back(comic);
    return nextItemId++;
}

// ---------------- Add User ----------------
int Library::addUser(const std::string& name) {
    users.emplace_back(nextUserId, name);  // Calls User constructor
    return nextUserId++;
}

// ---------------- Borrow Item ----------------
void Library::borrowItem(int userId, int itemId) {
    for (auto& user : users) {
        if (user.getId() == userId) {
            user.borrowItem(itemId);
            return;
        }
    }
}

// ---------------- Return Item ----------------
void Library::returnItem(int userId, int itemId) {
    for (auto& user : users) {
        if (user.getId() == userId) {
            user.returnItem(itemId);
            return;
        }
    }
}

// ---------------- Display All Items ----------------
void Library::showAllItems() const {
    for (auto item : items) {
        item->display();   // Polymorphic call
    }
}

// ---------------- Display All Users ----------------
void Library::showAllUsers() const {
    for (const auto& user : users) {
        user.display();
    }
}

