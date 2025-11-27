# Library Management System (C++ OOP Project)

A fully object-oriented Library Management System built using modern C++.  
This project demonstrates Inheritance, Polymorphism, Dynamic Memory Handling, File Persistence, Deep Copying, Exception Handling, and STL vector usage. I just completed my learning of C++ and just for handon practice i surfed Chat gpt and as him to give me a massive project that covers all of the fundamental concepts of C++ and i got this. So yes you can trust on me this one is developed by me, not by Android!

---

## Features

### 1. Complete Item System (Polymorphism)
Supports multiple library item types:
- Book  
- Magazine  
- Comic  

All derive from the abstract base class `Item` defined using pure virtual function:
- `display()`
- `saveToFile(std::ostream&) const=0`

### 2. User Management
- Add users  
- Add items
- Borrow items  
- Return items  
- Delete items
- Deep copy constructor  
- Proper destructor to free dynamic memory

User class includes:
- `id`
- `name`
- Dynamic array of borrowed item IDs

### 3. Vector-Based Storage
The system uses STL vectors:
- `std::vector<Item*> items`
- `std::vector<User> users`

No manual resizing required.  
Automatic growth and memory management.

### 4. File Persistence
The project supports full save/load functionality.

#### Saving:
Data is written in the format:
```bash
TYPE|id|title|field1|field2
```


#### Loading(to be added):
At program startup:
- File is read line-by-line
- Type identified
- Correct derived object created dynamically (Book/Magazine/Comic)
- Object pushed into the vector

### 5. Memory Safety
- Every dynamically allocated item is deleted in the destructor
- Deep copy ensures users do not share pointer addresses
- No memory leaks

### 6. Project Demonstrates
- Encapsulation  
- Inheritance  
- Runtime Polymorphism  
- Virtual destructor usage  
- Operator overloading (optional but supported)  
- Exception handling  
- File I/O  
- Using STL containers  
- Dynamic arrays

---

## Project Structure
```bash
library_project/
│
├── include/
│ ├── Item.h
│ ├── Book.h
│ ├── Magazine.h
│ ├── Comic.h
│ ├── User.h
│ └── Library.h
│
├── src/
│ ├── Item.cpp
│ ├── Book.cpp
│ ├── Magazine.cpp
│ ├── Comic.cpp
│ ├── User.cpp
│ ├── Library.cpp
│ └── main.cpp
│
└── library_data.txt
```




---

## Build Instructions

### Compile:

```bash
g++ src/main.cpp src/User.cpp src/Library.cpp src/Book.cpp src/Magazine.cpp src/Comic.cpp src/Item.cpp -I include -o library_app
```


### Run:

```bash
./library_app
```


---

## What This Project Teaches

By building this, you learn:

- Designing class hierarchies  
- Working with abstract classes and virtual functions  
- Using vectors to store heterogeneous objects  
- Handling dynamic memory safely  
- Implementing deep copying  
- Real-world file persistence  
- Clean OOP architecture  
- Separation of interface and implementation  
- Polymorphic object creation at runtime  

---

## Future Enhancements 

- Add sorting (by title, ID, type)  
- Use function pointers or `std::function` for menu actions  
- Implement custom exceptions  
- Add admin login  
- Add custom password storage encryption algorithm
- Add due dates and fine calculation  
- Switch to JSON or CSV format  

---

## Author
Developed by Sahil Rana as an Understanding project for learning in depth C++ and  object-oriented design principles.

---

