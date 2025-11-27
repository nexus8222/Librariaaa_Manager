#include "Library.h"
#include "Book.h"
#include "Magazine.h"
#include "Comic.h"
#include <iostream>
#include <fstream>

// ---------------- Constructor ----------------
Library::Library()
{
    nextItemId = 1;
    nextUserId = 1;
}

// ---------------- Destructor ----------------
Library::~Library()
{
    // Delete all dynamically allocated Item objects
    for (auto item : items)
    {
        delete item;
    }
    items.clear();
    users.clear();
}

// ---------------- Add Book ----------------
int Library::addBook(const std::string &title, const std::string &author, int pages)
{
    Item *book = new Book(nextItemId, title, author, pages);
    items.push_back(book);

    std::ofstream file("library_data.txt", std::ios::app);
    if (!file)
    {
        std::cerr << "Error opening file\n";
    }
    else
    {
        book->saveToFile(file);
    }
    return nextItemId++;
}

// ---------------- Add Magazine ----------------
int Library::addMagazine(const std::string &title, int issue, const std::string &month)
{
    Item *mag = new Magazine(nextItemId, title, issue, month);
    items.push_back(mag);
    std::ofstream file("library_data.txt", std::ios::app);
    if (!file)
    {
        std::cerr << "Error opening file\n";
    }
    else
    {
        mag->saveToFile(file);
    }
    return nextItemId++;
}

// ---------------- Add Comic ----------------
int Library::addComic(const std::string &title, int Volume, std::string illustrator, const std::string &universe)
{
    int defaultVolume = 1;

    Item *comic = new Comic(nextItemId, title, Volume, illustrator, universe);
    items.push_back(comic);
    std::ofstream file("library_data.txt", std::ios::app);
    if (!file)
    {
        std::cerr << "Error opening file\n";
    }
    else
    {
        comic->saveToFile(file);
    }
    return nextItemId++;
}

// ---------------- Add User ----------------
int Library::addUser(const std::string &name)
{
    users.emplace_back(nextUserId, name); // Calls User constructor
    return nextUserId++;
}

// ---------------- Borrow Item ----------------
void Library::borrowItem(int userId, int itemId)
{
    for (auto &user : users)
    {
        if (user.getId() == userId)
        {
            user.borrowItem(itemId);
            return;
        }
    }
}

// Remove Item
void Library::removeItem(int itemId)
{
    for (size_t i = 0; i < items.size(); ++i)
    {
        if (items[i]->getIId() == itemId)
        {
            // Delete object from heap
            delete items[i];

            // Remove pointer from vector
            items.erase(items.begin() + i);

            // Now rewrite the entire file
            std::ofstream file("library_data.txt", std::ios::trunc);

            if (!file)
            {
                std::cerr << "Error opening file for rewrite\n";
            }
            else
            {
                
                for (auto item : items)
                {
                    item->saveToFile(file);
                }
            }

            // std::cout << "Item removed successfully!\n";
            return;
        }
    }

    std::cout << "Item not found!\n";
}


// ---------------- Return Item ----------------
void Library::returnItem(int userId, int itemId)
{
    for (auto &user : users)
    {
        if (user.getId() == userId)
        {
            user.returnItem(itemId);
            return;
        }
    }
}

// ---------------- Display All Items ----------------
void Library::showAllItems() const
{
    for (auto item : items)
    {
        item->display(); // Polymorphic call
        std::cout << std::endl;
    }
}

// ---------------- Display All Users ----------------
void Library::showAllUsers() const
{
    for (const auto &user : users)
    {
        user.display();
        std::cout << std::endl;
    }
}
