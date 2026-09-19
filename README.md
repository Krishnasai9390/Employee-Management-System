# Employee-Management-System# Employee Management System

A console-based **Employee Management System developed in C** using linked lists, file handling, dynamic memory allocation, and string manipulation.

## 📌 Project Overview

The Employee Management System is a menu-driven C application that allows users to manage employee information.

Employee details such as employee number, name, location, band, role, and skills are stored and managed using a **singly linked list**. The employee data is also stored permanently in a text file named `empdata.txt`.

## ✨ Features

* Add a new employee
* Search for employees
* Update employee information
* Delete an employee
* Display all employees
* Shift an employee to a different location
* Store employee data in a text file
* Automatically maintain employees in ascending order of employee number
* Generate timestamped output files for search and display operations
* Dynamic memory allocation for employee records

## 🛠️ Technologies and Concepts Used

* **C Programming**
* **Structures**
* **Singly Linked Lists**
* **Dynamic Memory Allocation**
* **File Handling**
* **String Manipulation**
* **Pointers**
* **Searching**
* **Insertion and Deletion**
* **Tokenization using `strtok()`**
* **Time and Date Handling**

## 📂 Project Structure

```text
Employee-Management-System/
│
├── employee.c
├── empdata.txt
├── README.md
└── .gitignore
```

### `employee.c`

Contains the complete source code for the Employee Management System.

### `empdata.txt`

Stores employee information used by the application.

### `README.md`

Project documentation and instructions.

### `.gitignore`

Specifies files that should not be tracked by Git, such as compiled executable files.

## 👨‍💻 Employee Information

Each employee record contains:

| Field           | Description                            |
| --------------- | -------------------------------------- |
| Employee Number | Unique employee identification number  |
| Name            | Employee name                          |
| Location        | Current employee location              |
| Band            | Employee band                          |
| Role            | Employee role                          |
| Skills          | Employee technical/professional skills |

## 📋 Application Menu

When the application starts, the following menu is displayed:

```text
1. Add Employee
2. Search Employee
3. Update Employee
4. Delete Employee
5. Show All Employees
6. Shift Employee Location
7. Exit
```

## 🔹 Add Employee

Allows the user to add a new employee by entering:

```text
Employee Number
Name
Location
Band
Role
Skills
```

The employee is inserted into the linked list while maintaining ascending order based on employee number.

## 🔎 Search Employee

The search functionality allows employees to be searched using one or more values.

The search can match against:

* Employee number
* Name
* Location
* Band
* Role
* Skills

The search results are written to a timestamped output file.

Example:

```text
search_143025_19092026.txt
```

## ✏️ Update Employee

The user can update the following employee details:

```text
1. Location
2. Band
3. Role
4. Skills
```

The employee number is used to locate the employee record.

## 🗑️ Delete Employee

The user can delete an employee by providing the employee number.

Before deletion, the application asks for confirmation:

```text
Are you sure you want to delete? (Y/N):
```

## 📄 Show All Employees

Displays all employee records and generates a timestamped output file containing the employee information and total employee count.

## 📍 Shift Employee Location

This feature allows the user to change an employee's current location.

The user provides:

```text
Employee Number
New Location
```

## 💾 File Handling

The application uses `empdata.txt` to store employee information.

Employee records are loaded when the program starts and saved whenever employee information is added, updated, deleted, or modified.

Example employee data format:

```text
101 Rahul Bangalore A1 Developer C,Python,Linux
102 Priya Chennai A2 Tester Java,SQL,Testing
103 Arun Hyderabad A1 Developer C++,Linux,Git
```

> **Note:** The current implementation reads employee fields as whitespace-separated values, so names, locations, roles, and skills should not contain spaces unless the input format is changed.

## 🔗 Data Structure

The project uses a **singly linked list**.

Each employee node contains employee information and a pointer to the next employee:

```c
struct employee {
    int empno;
    char name[50];
    char location[50];
    char band[20];
    char role[50];
    char skills[100];
    struct employee *next;
};
```

The linked list allows employee records to be dynamically created and removed during program execution.

## 🧠 Memory Management

Employee records are dynamically allocated using:

```c
malloc()
```

and released using:

```c
free()
```

This allows the application to manage employee records dynamically during runtime.

## ⚙️ How to Compile

Make sure GCC is installed on your system.

Open a terminal in the project directory and run:

```bash
gcc employee.c -o employee
```

## ▶️ How to Run

### Windows

```bash
employee.exe
```

### Linux/macOS

```bash
./employee
```

Make sure `empdata.txt` is present in the same directory as the executable.

## 🔄 Program Flow

```text
Start
  │
  ▼
Load employee data
  │
  ▼
Display menu
  │
  ├── Add Employee
  │
  ├── Search Employee
  │
  ├── Update Employee
  │
  ├── Delete Employee
  │
  ├── Show All Employees
  │
  ├── Shift Employee Location
  │
  └── Exit
        │
        ▼
     Free Memory
        │
        ▼
       End
```

## 📚 Key C Concepts Demonstrated

This project demonstrates practical usage of:

* Structures
* Pointers
* Pointer-based linked lists
* Dynamic memory allocation
* `malloc()` and `free()`
* File operations using `fopen()`, `fclose()`, `fscanf()`, and `fprintf()`
* String functions
* `strtok()`
* `strcmp()` and `strcasecmp()`
* Searching linked lists
* Insertion into linked lists
* Deletion from linked lists
* Memory management
* Date and time functions

## 🚀 Future Improvements

The project can be extended with:

* Input validation improvements
* Support for employee names and roles containing spaces
* Separate source files such as `.c` and `.h`
* Better error handling
* Employee sorting by different fields
* Login/authentication
* Database integration
* GUI or web-based interface
* Unit testing
* Makefile/CMake build system

## 👤 Author

**Krishna Sai**

## 📄 License

This project is intended for educational and learning purposes.
