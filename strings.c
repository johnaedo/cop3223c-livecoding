#include <stdio.h>
#include <string.h>
#include "utils.h"

#define MAX_STRING 50

#ifdef DEBUG
void print_debug(char *message) {
    printf("%s\n", message);
}
#endif


void get_position(char * position_id, char * position) {
    #if DEBUG == 5
    printf("Debug level is 5\n");
    #endif

    #ifdef DEBUG
    print_debug("In get_position()");
    #endif
    if (strcmp(position_id, "0110") == 0) {
        strcpy(position, "Junior Accountant");
    } else if (strcmp(position_id, "1100") == 0) {
        strcpy(position, "Associate Accountant");
    } else if (strcmp(position_id, "1110") == 0) {
        strcpy(position, "Senior Accountant");
    } else {
        strcpy(position, "TEMP");
    }
}

int main(void){
   char firstName[MAX_STRING] = "John";
   char lastName[MAX_STRING] = "Aedo";
   char empid[MAX_STRING] = "0110 0758 PAYROLL";
   char fullName[100];

   char position[MAX_STRING];
   char position_id[MAX_STRING];
   char individual_id[MAX_STRING];
   char dept[MAX_STRING];
   char tmp[MAX_STRING];

    #ifdef DEBUG
    print_debug("Done Initializing Data");
    #endif


   strcat(firstName, " ");
   printf("[%s]\n", firstName);
   strcat(fullName, firstName);
   printf("[%s]\n", fullName);
   strcat(fullName, lastName);
   printf("[%s]\n", fullName);
   strcpy(tmp, empid);
   char *myPtr = strtok(tmp, " ");
   int i = 0;
   while(myPtr != NULL) {
        #ifdef DEBUG
        print_debug("In Tokenizing Loop");
        #endif

        switch(i) {
            case 0:
                strcpy(position_id, myPtr);
                get_position(position_id, position);
                break;
            case 1:
                strcpy(individual_id, myPtr);
                break;
            case 2:
                strcpy(dept, myPtr);
        }
        myPtr = strtok(NULL, " ");
        i++;
   }
   printf("Employee Record\n");
   printf("===============\n");
   printf("Full Name: %s (%s)\n", fullName, individual_id);
   printf("Position: %s\n", position);
   printf("Department:  %s\n", dept);
   printf("Max Age: %d\n", max_age);

   char action[MAX_STRING];
   printf("Enter an action: ");
   fgets(action, MAX_STRING, stdin);
   printf("Confirmed: %s", action);
   int new_salary = 0;
   char promotion_code[MAX_STRING];
   printf("Enter new salary and promotion code: ");
   scanf("%d %s", &new_salary, promotion_code);
   printf("Confirmed new salary: %d\n", new_salary);
   printf("Confirmed promotion code: %s\n", promotion_code);

   

}