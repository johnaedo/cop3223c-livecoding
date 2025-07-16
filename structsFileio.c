#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typedef struct {
    int id;
    char title[100];
    char authorFirstName[100];
    char authorLastName[100];
    char publisher[100];
    double price;
} book_t;

typedef enum {
    FALSE,
    TRUE
} BOOL;

BOOL hasPublisher(char *publisher) {
    if (strlen(publisher) == 0) {
        return FALSE;
    } else {
        return TRUE;
    }    
}

void printBook(book_t* myBook) {
    printf("Author: %s %s\n", myBook->authorFirstName, myBook->authorLastName);
    printf("Title: %s\n", myBook->title);
    if (hasPublisher(myBook->publisher)) {
        printf("Publisher: %s\n", myBook->publisher);
    }
    else {
        printf("Publisher: Unknown\n");
    };
    printf("Price: %f\n", myBook->price);
    printf("ID: %d\n", myBook->id);
}

book_t* createBook(int id, char authorFirstName[100], char authorLastName[100], char title[100], char publisher[100], float price) {
    book_t* tmpBook;
    tmpBook = malloc(sizeof(book_t));
    strcpy(tmpBook->authorFirstName, authorFirstName);
    strcpy(tmpBook->authorLastName, authorLastName);
    strcpy(tmpBook->title, title);
    strcpy(tmpBook->publisher, publisher);
    tmpBook->id = id;
    tmpBook->price = price;
    return tmpBook;
}

double costAverage(int max, ...) {
    va_list argList;
    double sum = 0.0;
    va_start(argList, max);
    for (int i = 0; i < max; i++) {
        sum += va_arg(argList, double);
    }
    va_end(argList);
    return sum / max;
}

void saveBook(FILE* fp, book_t* myBook) {
    fprintf(fp, "%d,%s,%s,%s,%s,%0.2f\n", myBook->id, myBook->authorFirstName, myBook->authorLastName, myBook->title, myBook->publisher, myBook->price);
}

int main(void) {
    book_t* book1;
    book_t* book2;
    book_t* book3;
    book_t* book4;
    book_t* book5;
    book_t* book6;
    FILE* fp = fopen("bookdb.txt", "w");
    book1 = createBook(100, "Arthur C.", "Clarke", "Foundation", "Random House", 17.99);
    book2 = createBook(101, "Orson Scott", "Card", "Ender's Game", "Baen", 22.99);
    book3 = createBook(102, "H.G.", "Wells", "The Time Machine", "", 12.99);
    book4 = createBook(103, "H.G.", "Wells", "20,000 Leagues Under the Sea", "", 25.99);
    book5 = createBook(104, "H.G.", "Wells", "The Time Machine II: The Timening", "", 10.99);
    book6 = createBook(105, "H.G.", "Wells", "The Time Machine III: The Revenge of the Morlocks", "", 10.99);
    printf("Average price of books in catalog: %0.2lf\n", costAverage(6, 
        book1->price, 
        book2->price, 
        book3->price,
        book4->price,
        book5->price,
        book6->price));
    printBook(book1);
    printBook(book2);
    printBook(book3);
    saveBook(fp, book1);
    saveBook(fp, book2);
    saveBook(fp, book3);
    free(book1);
    free(book2);
    free(book3);
    fclose(fp);
}
