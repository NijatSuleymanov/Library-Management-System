#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
    Exercise: Library Management System

    In this exercise, we'll create a simple Library Management System 
    using object-oriented programming and inheritance in C++.
    This exercise simulates a real-world application in software engineering where 
    different types of library items are managed within a library system.

    Background:
    Imagine you are developing a library management software for a university. 
    The software needs to handle two types of items: Books and DVDs. 
    Both items have common properties such as title, author/director, and publication year, 
    but they also have some specific properties. 
    Books have an ISBN (International Standard Book Number) while DVDs have a runtime.

*/




/* Solution */
class  LibraryItem{
    public :
    // Initializer List Constructor
    LibraryItem(const string& title,const string& authorOrDirector,int publicationYear) 
    : title(title),authorOrDirector(authorOrDirector),publicationYear(publicationYear){}

    virtual void displayinfo(){
        cout << "Title: " << title << endl;
        cout << "Author/Director: " << authorOrDirector << endl;
        cout << "Publication Year: " << publicationYear << endl;
     }

    protected :

        string title;
        string authorOrDirector;
        int publicationYear;

};

class Book : public LibraryItem{
    public :
        Book(const string& title,const string& authorOrDirector,int publicationYear,const string& isbn)
         : LibraryItem(title,authorOrDirector,publicationYear),isbn(isbn){};

        void displayinfo() override {
         LibraryItem ::displayinfo();
         cout << "ISBN: " << isbn <<  endl;
        } 

    private :
        string isbn;

};

class DVD : public LibraryItem{
    public :
        DVD(const string& title,const string& authorOrDirector,int publicationYear,int runtime)
         : LibraryItem(title,authorOrDirector,publicationYear),runtime(runtime){};

        void displayinfo() override {
         LibraryItem ::displayinfo();
         cout << "Runtime: " << runtime << " minutes" << endl;
        } 

    private :
        int runtime;

};

class Library{
    private:
        vector<LibraryItem*>items;

    public:
        void addItem(LibraryItem* item){
            items.push_back(item);
        }

        void displayAllItems()const{
             for(LibraryItem* item : items){
                item->displayinfo();
                cout << "------------------------" << endl;
             }
        }


};

int main() {
     system("cls");
    /*      Example usage:     */
    Library library;

    Book book("The Great Gatsby", "F. Scott Fitzgerald", 1925, "978-3-16-148410-0");
    DVD  dvd("Inception", "Christopher Nolan", 2010, 148);

    library.addItem(&book);
    library.addItem(&dvd);

    library.displayAllItems();

    


    /* 
        [Sample Output]

        Title: The Great Gatsby
        Author/Director: F. Scott Fitzgerald
        Publication Year: 1925
        ISBN: 978-3-16-148410-0
        ------------------------
        Title: Inception
        Author/Director: Christopher Nolan
        Publication Year: 2010
        Runtime: 148 minutes
        ------------------------
    */

    return 0;
}