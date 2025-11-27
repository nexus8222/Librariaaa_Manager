#ifndef LIBRARY_H
#define LIBRARY_H

using namespace std;
#include <string>
#include <vector>
#include "Item.h"
#include "User.h"

class Library {
private:
    vector<Item*> items;   // Vector of pointers for polymorphism
    vector<User> users;    // Vector of User objects

    int nextItemId;
    int nextUserId;
    std::string illustrator;
    int Volume;

public:
    // Constructor
    Library();

    // Destructor
    ~Library();

    // Add items
    int addBook(const std::string& title, const std::string& author, int pages);
    int addMagazine(const std::string& title, int issue, const std::string& month);
    int addComic(const std::string& title,const int Volume,const std::string illustrator,const std::string& universe);

    // Add user
    int addUser(const std::string& name);

    // Borrow / return
    void borrowItem(int userId, int itemId);
    void returnItem(int userId, int itemId);

    // RemoveItem
    void removeItem(int itemId);

    // Display
    void showAllItems() const;
    void showAllUsers() const;
};

#endif
