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
