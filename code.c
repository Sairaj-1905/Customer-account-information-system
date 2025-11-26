#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "customer_data.txt"

typedef struct {
    int id;
    char name[50];
    char email[50];
    char phone[20];
    double balance;
} Customer;

void addCustomer();
void displayCustomers();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;

    while (1) {
        printf("\n==============================\n");
        printf(" CUSTOMER ACCOUNT SYSTEM \n");
        printf("==============================\n");
        printf("1. Add Customer\n");
        printf("2. Display All Customers\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addCustomer();
            break;
        case 2:
            displayCustomers();
            break;
        case 3:
            printf("Exiting program...\n");
            
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}

void addCustomer() {
    Customer c;
    FILE *fp = fopen(FILE_NAME, "a");

    if (!fp) {
        printf("Error opening file.\n");
        return;
    }

    printf("\nEnter Customer ID: ");
    scanf("%d", &c.id);

    printf("Enter Name: ");
    getchar(); 
    fgets(c.name, 50, stdin);
    c.name[strcspn(c.name, "\n")] = 0;

    printf("Enter Email: ");
    fgets(c.email, 50, stdin);
    c.email[strcspn(c.email, "\n")] = 0;

    printf("Enter Phone: ");
    fgets(c.phone, 20, stdin);
    c.phone[strcspn(c.phone, "\n")] = 0;

    printf("Enter Balance: ");
    scanf("%lf", &c.balance);

    fprintf(fp, "%d,%s,%s,%s,%.2lf\n", c.id, c.name, c.email, c.phone, c.balance);

    fclose(fp);

    printf("\nCustomer added successfully!\n");
}

void displayCustomers() {
    Customer c;
    FILE *fp = fopen(FILE_NAME, "r");

    if (!fp) {
        printf("No customers found or file not accessible.\n");
        return;
    }

    printf("\n==============================\n");
    printf("    CUSTOMER LIST\n");
    printf("==============================\n");

    while (fscanf(fp, "%d,%49[^,],%49[^,],%19[^,],%lf",
                  &c.id, c.name, c.email, c.phone, &c.balance) != EOF) {

        printf("\nID: %d\nName: %s\nEmail: %s\nPhone: %s\nBalance: %.2lf\n",
               c.id, c.name, c.email, c.phone, c.balance);
    }

    fclose(fp);
}
