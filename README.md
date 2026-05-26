# library-book-management-system
A system to be used by a librarian to manage the library business electronically.
# TEMB 1202: Computing II — Library Book Management System

## Project Overview
This project is a complete, menu-driven C console application designed to automate library operations, enforce business rules, and generate summary metrics. It was developed for the **Group A Evening** assignment in the Department of Biomedical and Mechatronics Engineering at **Kyambogo University**.

### 🎓 Course & Submission Details
* **Course Code:** TEMB 1202 — Computing II
* **Institution:** Kyambogo University
* **Department:** Biomedical and Mechatronics Engineering
* **Implementation Language:** C (ISO C99 standard)
* **Project Files:** `main.c` (Source Code) 

---

## 🛠️ System Features & Business Rules Implemented
The application fulfills all criteria requested in the project brief by managing up to 100 books and 50 members under strict validation checks:

1. **Authentication:** Secure startup login portal (3 attempts allowed).
2. **Book & Member CRUD:** Operations to add, search, update, and delete entries safely.
3. **BR-1 & BR-2 (Availability Safeguards):** Blocks borrow actions if zero copies remain and outputs an explicit availability error.
4. **BR-3 (Late Fine Calculator):** Accumulates a late fee of **500 UGX per day** for overdue materials.
5. **BR-4 (Unpaid Fine Block):** Freezes accounts from borrowing additional items if they hold a pending fine balance.
6. **BR-5 (High Demand Tagging):** Flags books automatically with a `[HIGH DEMAND]` indicator if checked out 5 or more times.
7. **Library Reporting:** Automatically calculates active loans, collective fine balances, and identifies the most popular book.

---

## 🚀 Compilation and Execution Instructions

To compile and run this console program locally, use any standard C99 compiler (such as GCC).

### 1. Compile the Source Code
Open your terminal or command prompt in this project directory and run:
```bash
gcc -o library library.c -Wall -std=c99
```

### 2. Launch the Program
Execute the compiled binary file:
* **Windows:**
  ```cmd
  library.exe
  ```
* **Linux / macOS:**
  ```bash
  ./library
  ```

### 🔑 Demo Login Credentials
Access to the librarian dashboard requires the following admin credentials:
* **Username:** `admin`
* **Password:** `lib2026`

