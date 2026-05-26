TEMB 1202: COMPUTING II
LIBRARY BOOK MANAGEMENT SYSTEM

GROUP A EVENING
NAMES	REGISTRATION NUMBER
OREM ABRAHAM	25/U/BIE/01415/PE
JUUKO MORRIS	25/U/BIE/01375/PE
OKOT CLEMENT	25/U/BIE/05306/PE
SANYU DORCUS	25/U/BIE/01420/PE
EDYABI BRIAN	25/U/BIE/05291/PE
BUYONDO EMMANUEL	25/U/BIO/04517/PD

Introduction and Project Scope
•	Automated Solution: Replaces manual library record-keeping to minimize lost books and tracking errors.
•	Implementation: Built as a complete, modular console application in C (ISO C99 standard).
•	System Capacity: Manages a dataset of up to 100 book entries and 50 registered borrower records.
Problem Statement & Objectives
•	Core Problem: Manual systems lead to uncollected fines, unknown resource availability, and tracking inefficiencies
•	Key System Objectives:
•	Authenticate librarian access at system startup.
•	Perform robust Add, Search, Update, and Delete operations.
•	Seamlessly handle borrow and return transaction loops.
System Architecture (3 Layer Design)
•	User Interface Layer: Displays clean menus and formatted terminal tables (main(), displayMenu()).
•	Business Logic Layer: Enforces library policy rules and handles fine calculations (borrowBook(), returnBook()).
•	Data Management Layer: Handles modifications directly within fixed memory data blocks (addBook(), deleteBook()).
Structural Data Structures













Application Capabilities 
•	Authentication: Grants access via a secure three-attempt login gateway (admin/lib2026).
•	Inventory Control: Comprehensive duplicate checks for IDs and ISBNs during registration.
•	Flexible Querying: Supports multi-mode lookups by exact book ID, title keyword, or author name.
Validation & Business Rules 
•	BR-1 & BR-2: Checks copy availability; returns explicit "All copies borrowed" prompt if empty
•	BR-3: Applies late penalties of 500 UGX per day on overdue returns
•	BR-4: Completely freezes account borrowing privileges if a user has unpaid fines.
•	Automatically tags books as [HIGH DEMAND] when total lifetime borrows reach 5.
Analytical Summary Reporting 
•	Real-time Evaluation: Loops sequentially through active arrays to compile real-time operations.
•	Metrics Generated: 
•	Total inventory and active out-on-loan books.
•	Cumulative outstanding revenue from overdue items.
•	Live high demand analysis pinpointing the most borrowed resource.
Testing Framework & Success Metrics
•	Boundary Testing: Verified system responses for input errors like duplicate records or over-limit deletes.
•	Functional Checks: Validated correct fine accumulation tracking and borrow-blocking limits.
•	Status: Passed 100% of the structured testing protocols.
Summary of Project Achievements
•	Outcome: Fulfills all programmatic requirements assigned for the Computing II course.
•	Curriculum Integration: Demonstrates safe file/buffer processing, multi-struct linking, and pointer logic in C.
•	Future Extensions: Data storage persistence across sessions and multiple simultaneous book loans.
