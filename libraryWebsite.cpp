#include <iostream>
#include <vector>
using namespace std;

class Book
{
private:
    string name;
    int id;
    int copies;

public:
    Book(string n, int i, int c) : name(n), id(i), copies(c) {}

    int getId() const
    {
        return id;
    }
    int getCopies() const
    {
        return copies;
    }
    void setCopies(int newCopies)
    {
        copies = newCopies;
    }
    void display() const
    {
        cout << "ID: " << id << ", Name: " << name << ", Copies: " << copies << endl;
    }
};

class Person
{
protected:
    string username;
    string password;

public:
    Person(string u, string p) : username(u), password(p) {}
    string getUsername() const
    {
        return username;
    }
    virtual bool login(string user, string pass)
    {
        return (username == user and password == pass);
    }
};

class User : public Person
{
public:
    User(string u, string p) : Person(u, p) {}
    void buyBook(vector<Book> &books, int id);
    void borrowBook(vector<Book> &books, int id);
};

class Admin : public Person
{
public:
    Admin(string u, string p) : Person(u, p) {}
    void addBook(vector<Book> &books, string name, int id, int copies)
    {
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
class Library
{
private:
    vector<Book> books;
    vector<User> users;
    Admin admin;

public:
    Library(Admin a) : admin(a) {}

    vector<Book> &getBooks()
    {
        return books;
    }
    void signUp(string username, string password)
    {
        users.push_back(User(username, password));
        cout << "Signup successful for user: " << username << endl;
    }
    User *loginUser(string username, string password)
    {
        for (User &user : users)
        {
            if (user.login(username, password))
            {
                cout << "Login successful!" << endl;
                return &user;
            }
        }
        cout << "Invalid username or password." << endl;
        return nullptr;
    }
    void displayBooks() const
    {
        if (books.empty())
        {
            cout << "No books in the library" << endl;
            return;
        }
        for (const Book &book : books)
        {
            book.display();
        }
    }
    // Admin ==> Composition
    void adminAddBook(string name, int id, int copies)
    {
        admin.addBook(books, name, id, copies);
    }
    void adminUpdateBook(int id, string newName, int newCopies)
    {
        admin.updateBook(books, id, newName, newCopies);
    }
    void adminDeleteBook(int id)
    {
        admin.deleteBook(books, id);
    }
};
// User ==> Aggregation
void User::buyBook(vector<Book> &books, int id)
{
    for (Book &book : books)
    {
        if (book.getId() == id)
        {
            if (book.getCopies() > 0)
            {
                book.setCopies(book.getCopies() - 1);
                cout << "Book bought successfully!" << endl;
            }
            else
            {
                cout << "Book is out of stock!" << endl;
            }
            return;
        }
    }
    cout << "Book not found." << endl;
}
void User::borrowBook(vector<Book> &books, int id)
{
    for (Book &book : books)
    {
        if (book.getId() == id)
        {
            if (book.getCopies() > 0)
            {
                book.setCopies(book.getCopies() - 1);
                cout << "Book borrowed successfully!" << endl;
            }
            else
            {
                cout << "No copies available to borrow." << endl;
            }
            return;
        }
    }
    cout << "Book not found." << endl;
}
int main()
{
    Admin admin("admin", "admin123");
    Library library(admin);

    cout << "Admin adds books:" << endl;
    library.adminAddBook("C++ Programming", 1, 60);
    library.adminAddBook("Data Science", 2, 33);
    library.adminAddBook("Machine Learning", 3, 37);
    library.adminAddBook("Data Structure", 4, 12);
    library.displayBooks();

    cout << "\nAdmin updates book 1:" << endl;
    library.adminUpdateBook(1, "Advanced C++", 100);
    library.displayBooks();

    cout << "\nAdmin deletes book 2:" << endl;
    library.adminDeleteBook(2);
    library.displayBooks();

    cout << "\nUser sign up:" << endl;
    library.signUp("Mohamed", "password123#$");
    library.signUp("Omar", "passwordOmar927@");
    library.signUp("Ahmed", "passwordAhhhmed242*&");

    cout << "\nUser login:" << endl;
    User *Mohamed = library.loginUser("Mohamed", "password123#$");
    User *Omar = library.loginUser("Omar", "passwordOmar927");
    User *Ahmed = library.loginUser("Ahmed", "passwordAhhhmed242*&");

    if (Mohamed)
    {
        cout << "\nMohamed buys book 1:" << endl;
        Mohamed->buyBook(library.getBooks(), 1);
        library.displayBooks();
    }
    if (Ahmed)
    {
        cout << "\nAhmed buys book 4:" << endl;
        Ahmed->buyBook(library.getBooks(), 4);
        library.displayBooks();
    }

    if (Omar)
    {
        cout << "\nOmar borrows book 3:" << endl;
        Omar->borrowBook(library.getBooks(), 3);
        library.displayBooks();
    }

    /*cout << "\nTest invalid login:" << endl;
    User *invalidUser = library.loginUser("invalid_user", "wrong_password");
    if (!invalidUser)
    {
        cout << "Invalid login attempt failed as expected." << endl;
    }*/

    cout << "\nFinal state of the library:" << endl;
    library.displayBooks();

    return 0;
}
