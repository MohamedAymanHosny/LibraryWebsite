<h1 align="center">Library Management System in C++</h1>

## Project Description
This project implements a simple **Library Management System** using C++. The system includes functionalities for managing books and users, both from an admin's perspective and a regular user's perspective. It leverages object-oriented principles such as **inheritance**, **encapsulation**, and **polymorphism** to manage library operations.

## Features

### Admin Functionalities:
1. **Add Book**: Admins can add new books to the library, ensuring unique book IDs.
2. **Update Book**: Admins can modify book details, such as name and number of copies.
3. **Delete Book**: Admins can remove books from the library.

### User Functionalities:
1. **Signup & Login**: Users can create accounts and log in to access the system.
2. **Buy Books**: Users can purchase books if sufficient copies are available.
3. **Borrow Books**: Users can borrow books within the library's stock limits.

### General Features:
- Display a list of available books with their details (ID, name, copies).
- Separate interfaces for admins and users.

---

## Key Classes

- **Book**: Represents each book with attributes: `name`, `id`, and `copies`.
- **Person**: A base class for handling credentials (`username`, `password`), extended by `Admin` and `User`.
- **User**: Enables book purchase and borrowing.
- **Admin**: Grants permission for full book management.
- **Library**: Manages the collections of books, users, and admins, serving as the core system.

---

## Applied Concepts

- **Object-Oriented Programming (OOP)**:
  - **Encapsulation**: Ensures secure handling of book and user data.
  - **Inheritance**: Admin and User classes inherit from the Person class.
  - **Polymorphism**: Overridden login behavior for different roles.
- **Data Structures**: Uses `std::vector` for dynamic storage of books and users.
- **Error Handling**: Prevents duplicate book IDs and handles invalid inputs gracefully.

---
## Diagram
![Library Management System Diagram](https://edrawcloudpublicus.s3.amazonaws.com/viewer/self/4593811/share/2024-9-11/1726071432/main.svg)

## How to Run

1. Clone the repository: Open (cmd or git), navigate to your destination folder using `cd path/to/destination/folder`
2. run `git clone https://github.com/MohamedAymanHosny/LibraryWebsite.git`.
3. Navigate to the project directory: Run `cd LibraryWebsite`.
4. Update the repository: Use `git pull origin main`.
5. Compile the code: Use a C++ compiler (e.g., `g++`).
6. Run the program to interact with the library system.
