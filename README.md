# Employee Management System

A simple console-based Employee Management System written in C. The application allows users to manage employee records through a text-based interface and stores data in a binary file.

## Overview

This project was created as a desktop console application for managing employee information. It demonstrates fundamental programming concepts such as:

* Structures
* File handling
* User authentication
* CRUD operations (Create, Read, Update, Delete)
* Console-based user interfaces
* Basic data persistence

Employee records are stored in a binary file (`EMP.DAT`), allowing data to persist between application sessions.

---

## Features

### Authentication System

* Login screen
* Password masking
* Limited login attempts

### Employee Management

* Add new employees
* View all employees
* Edit selected employee information
* Delete employee records

### Data Storage

* Binary file storage
* Persistent employee database
* Automatic file creation if database does not exist

---

## Technologies

* C
* Windows API
* Standard C Library
* File Operations
* Console Application Development

---

## Project Structure

```text
employee-management-system/
│
├── EmployeeManagementSystem/
│   └── EmployeeManagementSystem.c
│
├── EmployeeManagementSystem.sln
├── .gitignore
└── README.md
```

---

## Screenshots

### Login Screen

<img width="948" height="381" alt="Zrzut ekranu 2026-06-05 004758" src="https://github.com/user-attachments/assets/3d675b09-eb35-4bc0-9df1-2ef8f99ba17f" />

---

### Main Menu

<img width="1058" height="453" alt="Zrzut ekranu 2026-06-05 004835" src="https://github.com/user-attachments/assets/342dbd96-eb67-4093-a87e-9daeecdd8216" />

---

### Employee List

<img width="886" height="417" alt="Zrzut ekranu 2026-06-05 004920" src="https://github.com/user-attachments/assets/df2d9bda-0002-4275-a7e6-d0be2e3f8cd2" />

---

### Edit Employee

<img width="749" height="568" alt="Zrzut ekranu 2026-06-05 005031" src="https://github.com/user-attachments/assets/c48fa0e7-5cbb-49fe-be60-8f36a2c6f6bb" />

---

## How It Works

1. User logs into the system.
2. Main menu is displayed.
3. Employee records can be:

   * Added
   * Modified
   * Listed
   * Removed
4. Data is stored in a binary database file (`EMP.DAT`).

---

## Default Login Credentials

```text
Username: 111
Password: 111
```

---

## Learning Outcomes

This project helped develop practical experience with:

* C programming
* Working with structures
* Binary file operations
* Console user interface design
* Data management systems
* Basic software architecture

---

## Future Improvements

Potential enhancements include:

* Data validation
* Search functionality
* Sorting employee records
* Multiple user accounts
* Password encryption
* Improved user interface
* Database integration

---

## Author

Waldemar Wilk

Personal portfolio project created in C as an Employee Management System demonstrating file handling, CRUD operations, and console application development.
