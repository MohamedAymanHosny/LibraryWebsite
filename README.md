<h1 align="center">Library Management System in C++</h1>

## Project Description
This project implements a simple **Library Management System** using C++. The system includes functionalities for managing books and users, both from an admin's perspective and a regular user's perspective. It leverages object-oriented principles such as **inheritance**, **encapsulation**, and **polymorphism** to manage library operations.

## Features

1. **Admin Functions**:
   - **Add Book**: The admin can add new books to the library.
   - **Update Book**: The admin can update book details (name and copies available).
   - **Delete Book**: The admin can remove a book from the library.

2. **User Functions**:
   - **Signup and Login**: Users can sign up and log in to the system.
   - **Buy Book**: A user can buy a book from the library if copies are available.
   - **Borrow Book**: Users can borrow a book if there are enough copies in the library.

3. **Book Management**:
   - Each book has an ID, name, and number of copies available.
   - Admins have the authority to manage the books in the library, while users can only view, borrow, or buy books.

## Key Classes

- **Book**: Represents a book in the library, with attributes like `name`, `id`, and `copies`.
- **Person**: A base class for both `User` and `Admin`, managing login credentials.
- **User**: Inherits from `Person` and allows users to buy and borrow books.
- **Admin**: Inherits from `Person` and has permissions to manage (add, update, delete) books.
- **Library**: Manages the collection of books and users and handles the overall library operations.

## Concepts Applied

- **Object-Oriented Programming (OOP)**: Inheritance, encapsulation, and aggregation.
- **Data Structures**: Utilizes vectors for storing lists of books and users.
- **Composition and Aggregation**:
  - The `Library` class has a **composition** relationship with `Admin`, meaning the library cannot exist without an admin.
  - The `User` class has an **aggregation** relationship with `Book`, allowing users to interact with books without owning them directly.

## How to Run

1. Clone the repository.
2. Compile the code using a C++ compiler (e.g., `g++`).
3. Run the program to interact with the library system.

