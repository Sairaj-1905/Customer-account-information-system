# Customer Account Information System (C Program)

## 📌 Abstract
This project is a simple **Customer Account Information System** written in the C programming language.  
It allows users to add customer details and display stored customer records.  
All data is stored in a text file (`customer_data.txt`) to ensure persistence.

---

## ⭐ Features
- Add customer information
- View all saved customers
- Text-file–based data storage
- Simple menu-driven interface
- Persistent storage across sessions

---

## 🛠 Technical Requirements
- GCC Compiler or any C compiler
- 1 KB of disk space for data file
- Operating System: Windows / Linux / macOS
- Text editor or IDE (VS Code, Code::Blocks, Dev-C++, etc.)

---

## 📌 Functional Requirements
### User Should Be Able To:
1. Add new customer account information:
   - ID  
   - Name  
   - Email  
   - Phone  
   - Account balance  

2. Display all stored customer records.

3. Exit the system safely.

### System Should:
- Store data in a permanent text file (`customer_data.txt`)
- Display records in readable format
- Validate menu choices

---

## ▶ How to Run the Program

### **Using GCC**
```sh
gcc customer_account_system.c -o customer
./customer
1️⃣ Program Menu Screen
====================================
   CUSTOMER ACCOUNT INFORMATION SYSTEM
====================================
1. Add Customer
2. Display All Customers
3. Search Customer by ID
4. Exit
Enter your choice: 1

2️⃣ Add Customer – Input Screen
--- Add Customer ---

Enter Customer ID: 101
Enter Customer Name: John Doe
Enter Phone Number: 555-0199
Enter Account Balance: 2500.50

Customer added successfully!

3️⃣ Add Customer – Second Example
--- Add Customer ---

Enter Customer ID: 102
Enter Customer Name: Ana Lee
Enter Phone Number: 555-8821
Enter Account Balance: 320.00

Customer added successfully!

4️⃣ Display Customers – Output Screen
--- Customer List ---
ID         Name                 Phone           Balance
-------------------------------------------------------------
101        John Doe             555-0199        2500.50
102        Ana Lee              555-8821        320.00

5️⃣ Search Customer – Input + Output
Enter Customer ID to search: 101

Customer Found:
ID: 101
Name: John Doe
Phone: 555-0199
Balance: 2500.50

6️⃣ Search – Not Found Example
Enter Customer ID to search: 999

Customer with ID 999 not found.

