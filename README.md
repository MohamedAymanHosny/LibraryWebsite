<h1 align="center">Library Management System in C++</h1>


## Project Description
This project implements a **Library Management System** in C++ that provides functionalities for managing books and user operations. The system supports both admin and user roles with distinct privileges, following Object-Oriented Programming (OOP) principles.

---

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

## How to Run

1. Clone the repository:
   ```bash
   git clone https://github.com/MohamedAymanHosny/LibraryWebsite.git



