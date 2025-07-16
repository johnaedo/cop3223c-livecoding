#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct contact {
    char firstName[50];
    char lastName[50];
    char email[100];
    char phone[12];
} contact_t;

contact_t * CreateEntry(char firstName[], char lastName[], char email[], char phone[]) {
    contact_t *newEntry = malloc(sizeof(contact_t));
    if (newEntry == NULL) {
        perror("Memory allocation error.\n");
        exit(-1);
    }
    strcpy(newEntry->firstName, firstName);
    strcpy(newEntry->lastName, lastName);
    strcpy(newEntry->email, email);
    strcpy(newEntry->phone, phone);
    return newEntry;
}

int main(int argc, char *argv[]) {
    // CALLOC
    srand(time(0));
    int array_length = atoi(argv[1]);
    int *randoms;
    randoms = calloc(array_length, sizeof(int));
    if (randoms == NULL) {
        perror("Memory allocation failure.\n");
        exit(-1);
    }
    for (int i = 0; i < array_length; i++) {
        randoms[i] = (rand() % 20) + 1;
    }
    for (int i = 0; i < array_length; i++) {
        printf("%d\n", randoms[i]);
    }
    
    // MALLOC
    // myContact ==> [212 bytes...]
    // CreateEntry ==> [212 bytes...]
    // 
    contact_t *myContact;
    myContact = CreateEntry("John", "Aedo", "john.aedo@ucf.edu", "407-823-????");
    printf("Full Name: %s %s\n", myContact->firstName, myContact->lastName);

    // REALLOC
    randoms = realloc(randoms, sizeof(int) * 1);
    for (int i = 0; i < 3
        ; i++) {
        printf("%d\n", randoms[i]);
    }
    // FREE
    free(myContact);
    if (myContact == NULL) {
        printf("Yep, free makes it a NULL pointer\n");
    } else {
        printf("After free, it still has a value: %p\n", myContact);
        if (!strcmp(myContact->firstName, "")) {
            printf("firstname has a value\n");
        }
        printf("First Name: %s\n", myContact->firstName);
    }
    free(randoms);

       

}