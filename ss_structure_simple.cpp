#include<iostream>
#include<conio.h>

using namespace std;

struct book{
    int bookID;
    char title[20];
    float price;
};

book input();
void display(book);

int main() {
    // clrscr();
    book b;
    b = input();
    display(b);
    return 0;
    getch();
}

book input() {
    book b1;
    cout << "Enter book ID, title, price: " << endl;
    cin >> b1.bookID;
    cin.getline(b1.title,sizeof(b1.title));
    //cin >> b1.title;
    cin >> b1.price;
    return(b1);
}

void display (book b) {
    cout << "Book ID: " << b.bookID << " Book Title: " << b.title << " Book Price: " << b.price << endl;
}


