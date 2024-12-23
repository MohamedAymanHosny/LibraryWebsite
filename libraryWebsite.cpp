#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
private:
    string name;
    int id;
    int copies;

public:
    Book(string n, int i, int c) : name(n), id(i), copies(c) {}

    int getId() const { return id; }
    int getCopies() const { return copies; }
    void setCopies(int newCopies) { copies = newCopies; }
    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Copies: " << copies << endl;
    }
};

class Person {
protected:
    string username;
    string password;

public:
    Person(string u, string p) : username(u), password(p) {}
    string getUsername() const { return username; }
    virtual bool login(string user, string pass) {
        return (username == user && password == pass);
    }
};

class User : public Person {
public:
    User(string u, string p) : Person(u, p) {}

    void buyBooks(vector<Book>& books);
    void borrowBooks(vector<Book>& books);
};

class Admin : public Person
{
public:
    Admin(string u, string p) : Person(u, p) {}

    void addBook(vector<Book> &books, string name, int id, int copies)
    {
        
        for (const Book &book : books)
        {
            if (book.getId() == id)
            {
                cout << "A book with ID " << id << " already exists. Please try adding a book with a different ID." << endl;
                return;
            }
        }

        books.push_back(Book(name, id, copies));
        cout << "Book added successfully." << endl;
    }

    void updateBook(vector<Book> &books, int id, string newName, int newCopies)
    {
        for (Book &book : books)
        {
            if (book.getId() == id)
            {
                book = Book(newName, id, newCopies);
                cout << "Book updated successfully." << endl;
                return;
            }
        }
        cout << "Book not found." << endl;
    }

    void deleteBook(vector<Book> &books, int id)
    {
        for (int i = 0; i < books.size(); ++i)
        {
            if (books[i].getId() == id)
            {
                books.erase(books.begin() + i);
                cout << "Book deleted successfully." << endl;
                return;
            }
        }
        cout << "Book not found." << endl;
    }
};

class Library {
private:
    vector<Book> books;
    vector<User> users;
    vector<Admin> admins;

public:
    void adminSignUp(string username, string password) {
        admins.push_back(Admin(username, password));
        cout << "Admin signup successful for username: " << username << endl;
    }

    Admin* loginAdmin(string username, string password) {
        for (Admin& admin : admins) {
            if (admin.login(username, password)) {
                cout << "Admin login successful!" << endl;
                return &admin;
            }
        }
        cout << "Invalid admin username or password." << endl;
        return nullptr;
    }

    void userSignUp(string username, string password) {
        users.push_back(User(username, password));
        cout << "User signup successful for username: " << username << endl;
    }

    User* loginUser(string username, string password) {
        for (User& user : users) {
            if (user.login(username, password)) {
                cout << "User login successful!" << endl;
                return &user;
            }
        }
        cout << "Invalid username or password." << endl;
        return nullptr;
    }

    vector<Book>& getBooks() { return books; }

    void displayBooks() const {
        if (books.empty()) {
            cout << "No books in the library" << endl;
            return;
        }
        for (const Book& book : books) {
            book.display();
        }
    }
};

void User::buyBooks(vector<Book>& books) {
    int n;
    cout << "How many books do you want to buy? ";
    cin >> n;

    while (n--) {
        int id, quantity;
        cout << "Enter book ID to buy: ";
        cin >> id;
        cout << "Enter quantity to buy: ";
        cin >> quantity;

        bool found = false;  
        for (Book& book : books) {
            if (book.getId() == id) {
                found = true;  
                if (book.getCopies() >= quantity) {
                    book.setCopies(book.getCopies() - quantity);
                    cout << "You successfully bought " << quantity << " copies of the book!" << endl;
                } else {
                    cout << "Only " << book.getCopies() << " copies are available. Unable to buy " << quantity << " copies." << endl;
                }
                break;
            }
        }

        if (!found) {
            cout << "Book not found." << endl;
        }
    }
}

void User::borrowBooks(vector<Book>& books) {
    int n;
    cout << "How many books do you want to borrow? ";
    cin >> n;

    while (n--) {
        int id, quantity;
        cout << "Enter book ID to borrow: ";
        cin >> id;
        cout << "Enter quantity to borrow: ";
        cin >> quantity;

        bool found = false;  
        for (Book& book : books) {
            if (book.getId() == id) {
                found = true;  
                if (book.getCopies() >= quantity) {
                    book.setCopies(book.getCopies() - quantity);
                    cout << "You successfully borrowed " << quantity << " copies of the book!" << endl;
                } else {
                    cout << "Only " << book.getCopies() << " copies are available. Unable to borrow " << quantity << " copies." << endl;
                }
                break;
            }
        }

        if (!found) {
            cout << "Book not found." << endl;
        }
    }
}

int main() {
    Library library;

    while (true) {
        cout << "\n--- Library Management System ---" << endl;
        cout << "1. Admin Signup\n2. Admin Login\n3. User Signup\n4. User Login\n5. Display Books\n6. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            string username, password;
            cout << "Enter admin username: ";
            cin >> username;
            cout << "Enter admin password: ";
            cin >> password;
            library.adminSignUp(username, password);
        } else if (choice == 2) {
            string username, password;
            cout << "Enter admin username: ";
            cin >> username;
            cout << "Enter admin password: ";
            cin >> password;

            Admin* admin = library.loginAdmin(username, password);
            if (admin) {
                while (true) {
                    cout << "\n--- Admin Panel ---" << endl;
                    cout << "1. Add Book\n2. Update Book\n3. Delete Book\n4. Logout" << endl;
                    cout << "Enter your choice: ";
                    int adminChoice;
                    cin >> adminChoice;

                    if (adminChoice == 1) {
                        string name;
                        int id, copies;
                        cin.ignore(); 
                        cout << "Enter book name: ";
                        getline(cin, name);
                        cout << "Enter book ID: ";
                        cin >> id;
                        cout << "Enter number of copies: ";
                        cin >> copies;
                        admin->addBook(library.getBooks(), name, id, copies);
                    } else if (adminChoice == 2) {
                        int id, copies;
                        string name;
                        cin.ignore(); 
                        cout << "Enter book ID to update: ";
                        cin >> id;
                        cin.ignore();
                        cout << "Enter new book name: ";
                        getline(cin, name);
                        cout << "Enter new number of copies: ";
                        cin >> copies;
                        admin->updateBook(library.getBooks(), id, name, copies);
                    } else if (adminChoice == 3) {
                        int id;
                        cout << "Enter book ID to delete: ";
                        cin >> id;
                        admin->deleteBook(library.getBooks(), id);
                    } else if (adminChoice == 4) {
                        break;
                    }
                }
            }
        } else if (choice == 3) {
            string username, password;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            library.userSignUp(username, password);
        } else if (choice == 4) {
            string username, password;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            User* user = library.loginUser(username, password);
            if (user) {
                while (true) {
                    cout << "\n--- User Panel ---" << endl;
                    cout << "1. Buy Books\n2. Borrow Books\n3. Logout" << endl;
                    cout << "Enter your choice: ";
                    int userChoice;
                    cin >> userChoice;

                    if (userChoice == 1) {
                        user->buyBooks(library.getBooks());
                    } else if (userChoice == 2) {
                        user->borrowBooks(library.getBooks());
                    } else if (userChoice == 3) {
                        break;
                    }
                }
            }
        } else if (choice == 5) {
            library.displayBooks();
        } else if (choice == 6) {
            cout << "Exiting the system. Goodbye!" << endl;
            break;
        }
    }

    return 0;
}
