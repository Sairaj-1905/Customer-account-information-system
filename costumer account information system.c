#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Customer {
    int id;
    char name[50];
    char email[50];
    float balance;
};


void addCustomer();
void viewCustomers();
void searchCustomer();
void updateCustomer();
void deleteCustomer();

int main() {
    int choice;

    while (1) {
        printf("\n=== Customer Account Information System ===\n");
        printf("1. Add Customer\n");
        printf("2. View All Customers\n");
        printf("3. Search Customer\n");
        printf("4. Update Customer\n");
        printf("5. Delete Customer\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCustomer();
                break;
            case 2:
                viewCustomers();
                break;
            case 3:
                searchCustomer();
                break;
            case 4:
                updateCustomer();
                break;
            case 5:
                deleteCustomer();
                break;
            case 6:
                printf("👋 Exiting... Goodbye!\n");
                exit(0);
            default:
                printf("❌ Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


void addCustomer() {
    FILE *fp;
    struct Customer c;

    fp = fopen("customers.dat", "ab+");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Customer ID: ");
    scanf("%d", &c.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", c.name);
    printf("Enter Email: ");
    scanf(" %[^\n]", c.email);
    printf("Enter Account Balance: ");
    scanf("%f", &c.balance);

    fwrite(&c, sizeof(struct Customer), 1, fp);
    fclose(fp);

    printf("✅ Customer added successfully!\n");
}

void viewCustomers() {
    FILE *fp;
    struct Customer c;

    fp = fopen("customers.dat", "rb");
    if (fp == NULL) {
        printf("No customer data found.\n");
        return;
    }

    printf("\n--- Customer List ---\n");
    while (fread(&c, sizeof(struct Customer), 1, fp)) {
        printf("ID: %d | Name: %s | Email: %s | Balance: %.2f\n",
               c.id, c.name, c.email, c.balance);
    }
    fclose(fp);
}


void searchCustomer() {
    FILE *fp;
    struct Customer c;
    int id, found = 0;

    fp = fopen("customers.dat", "rb");
    if (fp == NULL) {
        printf("No customer data found.\n");
        return;
    }

    printf("Enter Customer ID to search: ");
    scanf("%d", &id);

    while (fread(&c, sizeof(struct Customer), 1, fp)) {
        if (c.id == id) {
            printf("\n✅ Customer Found:\n");
            printf("ID: %d\nName: %s\nEmail: %s\nBalance: %.2f\n",
                   c.id, c.name, c.email, c.balance);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("❌ Customer not found.\n");

    fclose(fp);
}

void updateCustomer() {
    FILE *fp, *temp;
    struct Customer c;
    int id, found = 0;

    fp = fopen("customers.dat", "rb");
    temp = fopen("temp.dat", "wb");

    if (fp == NULL || temp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter Customer ID to update: ");
    scanf("%d", &id);

    while (fread(&c, sizeof(struct Customer), 1, fp)) {
        if (c.id == id) {
            printf("Enter new Name: ");
            scanf(" %[^\n]", c.name);
            printf("Enter new Email: ");
            scanf(" %[^\n]", c.email);
            printf("Enter new Balance: ");
            scanf("%f", &c.balance);
            found = 1;
        }
        fwrite(&c, sizeof(struct Customer), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove("customers.dat");
    rename("temp.dat", "customers.dat");

    if (found)
        printf("✅ Customer updated successfully!\n");
    else
        printf("❌ Customer not found.\n");
}

void deleteCustomer() {
    FILE *fp, *temp;
    struct Customer c;
    int id, found = 0;

    fp = fopen("customers.dat", "rb");
    temp = fopen("temp.dat", "wb");

    if (fp == NULL || temp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter Customer ID to delete: ");
    scanf("%d", &id);

    while (fread(&c, sizeof(struct Customer), 1, fp)) {
        if (c.id != id) {
            fwrite(&c, sizeof(struct Customer), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("customers.dat");
    rename("temp.dat", "customers.dat");

    if (found)
        printf("✅ Customer deleted successfully!\n");
    else
        printf("❌ Customer not found.\n");
}
