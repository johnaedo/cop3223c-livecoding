#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    int id;
    char title[100];
    char authorFirstName[100];
    char authorLastName[100];
    char publisher[100];
    float price;
};

typedef struct book book_t;


book_t *book1;
book_t *book2;

void printBook(book_t *myBook) {
    printf("Author: %s %s\n", myBook->authorFirstName, myBook->authorLastName);
    printf("Title: %s\n", myBook->title);
    printf("Publisher: %s\n", myBook->publisher);
    printf("Price: %f\n", myBook->price);
    printf("ID: %d\n", myBook->id);   
}

book_t * createBook(int id, char authorFirstName[100], char authorLastName[100], char title[100], char publisher[100], float price) {
    book_t *tmpBook;
    tmpBook = malloc(sizeof(book_t));
    strcpy(tmpBook->authorFirstName, authorFirstName);
    strcpy(tmpBook->authorLastName, authorLastName);
    strcpy(tmpBook->title, title);
    strcpy(tmpBook->publisher, publisher);
    tmpBook->id = id;
    tmpBook->price = price;
    return tmpBook;
}

int main(void) {
    book1 = createBook(100, "Arthur C.", "Clarke", "Foundation", "Random House", 17.99);
    book2 = createBook(101, "Orson Scott", "Card", "Ender's Game", "Baen", 22.99);
    printBook(book1);
    printBook(book2);    
}
