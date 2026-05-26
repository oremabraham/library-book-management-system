{\rtf1\ansi\ansicpg1252
{\fonttbl
{\f1\fnil\fcharset0\fprq0 Aptos Display;}
{\f2\fnil\fcharset0\fprq0 Aptos;}
{\f3\fnil\fcharset0\fprq0 Arial;}
}
{\colortbl;
\red0\green0\blue0;
\red0\green0\blue255;
}
{\stylesheet
{\s1\li360\fi-360\kerning24\fs56\lang1033\level1 heading 1;}
{\s2\li1080\fi-360\kerning24\fs48\lang1033\level2 heading 2;}
{\s3\li1800\fi-360\kerning24\fs40\lang1033\level3 heading 3;}
{\s4\li2520\fi-360\kerning24\lang1033\level4 heading 4;}
{\s5\li3240\fi-360\kerning24\lang1033\level5 heading 5;}
{\s6\li3960\fi-360\kerning24\lang1033\level6 heading 6;}
{\s7\li4680\fi-360\kerning24\lang1033\level7 heading 7;}
{\s8\li5400\fi-360\kerning24\lang1033\level8 heading 8;}
{\s9\li6120\fi-360\kerning24\lang1033\level9 heading 9;}
}
\pard\plain\ltrpar\s1\li360\fi-360\kerning24\fs56\lang1033\li0\fi0\qc {\f1\fs120\cf1 TEMB 1202: COMPUTING II\line }{\f1\fs64\cf1 LIBRARY BOOK MANAGEMENT SYSTEM}{\f1\fs120\cf1{\bcp47{\*\langtag en-UG}\lang0}\par 
}\pard\plain\ltrpar\s2\li1080\fi-360\kerning24\fs48\lang1033\li0\fi0\qc {\f2\cf1 GROUP A EVENING}{\f2\cf1{\bcp47{\*\langtag en-UG}\lang0}\par 
}\pard\plain\ltrpar\s1\li360\fi-360\kerning24\fs56\lang1033\li0\fi0 {\f1\fs88\cf1 Introduction and Project Scope}{\f1\fs88\cf1{\bcp47{\*\langtag en-UG}\lang0}\par 
}\pard\plain\ltrpar\s2\li1080\fi-360\kerning24\fs48\lang1033\li360 {\pntext\pard\plain\f3\fs56 \'95\tab}{\*\pn\pnlvlblt\pnf3\pnfs56{\pntxtb \'95}}{\b\f2\fs56\cf1 Automated Solution:}{\f2\fs56\cf1  Replaces manual library record-keeping to minimize lost books and tracking errors.\par 
}\pard\plain\ltrpar\s2\li1080\fi-360\kerning24\fs48\lang1033\li360 {\pntext\pard\plain\f3\fs56 \'95\tab}{\*\pn\pnlvlblt\pnf3\pnfs56{\pntxtb \'95}}{\b\f2\fs56\cf1 Implementation:}{\f2\fs56\cf1  Built as a complete, modular console application in C (ISO C99 standard).\par 
}\pard\plain\ltrpar\s2\li1080\fi-360\kerning24\fs48\lang1033\li360 {\pntext\pard\plain\f3\fs56 \'95\tab}{\*\pn\pnlvlblt\pnf3\pnfs56{\pntxtb \'95}}{\f2\fs56\cf1 System Capacity: Manages a dataset of up to 100 book entries and 50 registered borrower records.}{\f2\fs56\cf1{\bcp47{\*\langtag en-UG}\lang0}\par 
}\pard\plain\ltrpar\s1\li360\fi-360\kerning24\fs56\lang1033\li0\fi0 {\f1\fs88\cf1 Problem Statement & Objectives}{\f1\fs88\cf1{\bcp47{\*\langtag en-UG}\lang0}\par 
}\pard\plain\ltrpar\s2\li1080\fi-360\kerning24\fs48\lang1033\li360 {\pntext\pard\plain\f3\fs56 \'95\tab}{\*\pn\pnlvlblt\pnf3\pnfs56{\pntxtb \'95}}{\b\f2\fs56\cf1 Core Problem:}{\f2\fs56\cf1  Manual systems lead to uncollected fines, unknown resource availability, and tracking inefficiencies\par 
}\pard\plain\ltrpar\s2\li1080\fi-360\kerning24\fs48\lang1033\li360 {\pntext\pard\plain\f3\fs56 \'95\tab}{\*\pn\pnlvlblt\pnf3\pnfs56{\pntxtb \'95}}{\b\f2\fs56\cf1 Key System Objectives:\par 
}\pard\plain\ltrpar\s3\li1800\fi-360\kerning24\fs40\lang1033\li1080 {\pntext\pard\plain\f3\fs48 \'95\tab}{\*\pn\pnlvlblt\pnf3\pnfs48{\pntxtb \'95}}{\f2\fs48\cf1 Authenticate librarian access at system startup.\par 
}\pard\plain\ltrpar\s3\li1800\fi-360\kerning24\fs40\lang1033\li1080 {\pntext\pard\plain\f3\fs48 \'95\tab}{\*\pn\pnlvlblt\pnf3\pnfs48{\pntxtb \'95}}{\f2\fs48\cf1 Perform robust Add, Search, Update, and Delete operations.\par 
}\pard\plain\ltrpar\s3\li1800\fi-360\kerning24\fs40\lang1033\li1080 {\pntext\pard\plain\f3\fs48 \'95\tab}{\*\pn\pnlvlblt\pnf3\pnfs48{\pntxtb \'95}}{\f2\fs48\cf1 Seamlessly handle borrow and return transaction loops.}{\f2\fs48\cf1{\bcp47{\*\langtag en-UG}\lang0}\par 
}\pard\plain\ltrpar\s1\li360\fi-360\kerning24\fs56\lang1033\li0\fi0 {\f1\fs88\cf1 System Architecture (3 Layer Design)}{\f1\fs88\cf1{\bcp47{\*\langtag en-UG}\lang0}\par 
}\pard\plain\ltrpar\s2\li1080\fi-360\kerning24\fs48\lang1033\li360 {\pntext\pard\plain\f3\fs56 \'95\tab}{\*\pn\pnlvlblt\pnf3\pnfs56{\pntxtb \'95}}{\b\f2\fs56\cf1 User Interface Layer:}{\f2\fs56\cf1  Displays clean menus and formatted terminal tables (main(), }{\f2\fs56\cf1 displayMenu}{\f2\fs56\cf1 ()).\par 
}\pard\plain\ltrpar\s2\li1080\fi-360\kerning24\fs48\lang1033\li360 {\pntext\pard\plain\f3\fs56 \'95\tab}{\*\pn\pnlvlblt\pnf3\pnfs56{\pntxtb \'95}}{\b\f2\fs56\cf1 Business Logic Layer:}{\f2\fs56\cf1  Enforces library policy rules and handles fine calculations (}{\f2\fs56\cf1 borrowBook}{\f2\fs56\cf1 (), }{\f2\fs56\cf1 returnBook}{\f2\fs56\cf1 ()).\par 
}\pard\plain\ltrpar\s2\li1080\fi-360\kerning24\fs48\lang1033\li360 {\pntext\pard\plain\f3\fs56 \'95\tab}{\*\pn\pnlvlblt\pnf3\pnfs56{\pntxtb \'95}}{\b\f2\fs56\cf1 Data Management Layer:}{\f2\fs56\cf1  Handles modifications directly within fixed memory data blocks (}{\f2\fs56\cf1 addBook}{\f2\fs56\cf1 (), }{\f2\fs56\cf1 deleteBook}{\f2\fs56\cf1 ()).}{\f2\fs56\cf1{\bcp47{\*\langtag en-UG}\lang0}\par 
}\pard\plain\ltrpar\s1\li360\fi-360\kerning24\fs56\lang1033\li0\fi0 {\f1\fs88\cf1 Structural Data Structures}{\f1\fs88\cf1{\bcp47{\*\langtag en-UG}\lang0}\par 
}\pard\plain\ltrpar\s1\li360\fi-360\kerning24\fs56\lang1033\li0\fi0 {\f1\fs88\cf1 Application Capabilities }{\f1\fs88\cf1{\bcp47{\*\langtag en-UG}\lang0}\par 
}\pard\plain\ltrpar\s2\li1080\fi-360\kerning24\fs48\lang1033\li360 {\pntext\pard\plain\f3\fs56 \'95\tab}{\*\pn\pnlvlblt\pnf3\pnfs56{\pntxtb \'95}}{\b\f2\fs56\cf1 Authentication:}{\f2\fs56\cf1  Grants access via a secure three-attempt login gateway (admin/lib2026).\par 
}\pard\plain\ltrpar\s2\li1080\fi-360\kerning24\fs48\lang1033\li360 {\pntext\pard\plain\f3\fs56 \'95\tab}{\*\pn\pnlvlblt\pnf3\pnfs56{\pntxtb \'95}}{\b\f2\fs56\cf1 Inventory Control:}{\f2\fs56\cf1  Comprehensive duplicate checks for IDs and ISBNs during registration.\par 
}\pard\plain\ltrpar\s2\li1080\fi-360\kerning24\fs48\lang1033\li360 {\pntext\pard\plain\f3\fs56 \'95\tab}{\*\pn\pnlvlblt\pnf3\pnfs56{\pntxtb \'95}}{\b\f2\fs56\cf1 Flexible Querying:}{\f2\fs56\cf1  Supports multi-mode lookups by exact book ID, title keyword, or author name.}{\f2\fs56\cf1{\bcp47{\*\langtag en-UG}\lang0}\par 
}\pard\plain\ltrpar\s1\li360\fi-360\kerning24\fs56\lang1033\li0\fi0 {\f1\fs88\cf1 Validation & Business Rules }{\f1\fs88\cf1{\bcp47{\*\langtag en-UG}\lang0}\par 
}\pard\plain\ltrpar\s2\li1080\fi-360\kerning24\fs48\lang1033\li360 {\pntext\pard\plain\f3\fs56 \'95\tab}{\*\pn\pnlvlblt\pnf3\pnfs56{\pntxtb \'95}}{\b\f2\fs56\cf1 BR-1 & BR-2:}{\f2\fs56\cf1  Checks copy availability; returns explicit "All copies borrowed" prompt if empty\par 
}\pard\plain\ltrpar\s2\li1080\fi-360\kerning24\fs48\lang1033\li360 {\pntext\pard\plain\f3\fs56 \'95\tab}{\*\pn\pnlvlblt\pnf3\pnfs56{\pntxtb \'95}}{\b\f2\fs56\cf1 BR-3:}{\f2\fs56\cf1  Applies late penalties of }{\b\f2\fs56\cf1 500 UGX per day}{\f2\fs56\cf1  on overdue returns\par 
}\pard\plain\ltrpar\s2\li1080\fi-360\kerning24\fs48\lang1033\li360 {\pntext\pard\plain\f3\fs56 \'95\tab}{\*\pn\pnlvlblt\pnf3\pnfs56{\pntxtb \'95}}{\b\f2\fs56\cf1 BR-4:}{\f2\fs56\cf1  Completely freezes account borrowing privileges if a user has unpaid fines.\par 
}\pard\plain\ltrpar\s2\li1080\fi-360\kerning24\fs48\lang1033\li360 {\pntext\pard\plain\f3\fs56 \'95\tab}{\*\pn\pnlvlblt\pnf3\pnfs56{\pntxtb \'95}}{\f2\fs56\cf1 Automatically tags books as [HIGH DEMAND] when total lifetime borrows reach 5.}{\f2\fs56\cf1{\bcp47{\*\langtag en-UG}\lang0}\par 
}\pard\plain\ltrpar\s1\li360\fi-360\kerning24\fs56\lang1033\li0\fi0 {\f1\fs88\cf1 Analytical Summary Reporting }{\f1\fs88\cf1{\bcp47{\*\langtag en-UG}\lang0}\par 
}\pard\plain\ltrpar\s2\li1080\fi-360\kerning24\fs48\lang1033\li360 {\pntext\pard\plain\f3\fs56 \'95\tab}{\*\pn\pnlvlblt\pnf3\pnfs56{\pntxtb \'95}}{\b\f2\fs56\cf1 Real-time Evaluation:}{\f2\fs56\cf1  Loops sequentially through active arrays to compile real-time operations.\par 
}\pard\plain\ltrpar\s2\li1080\fi-360\kerning24\fs48\lang1033\li360 {\pntext\pard\plain\f3\fs56 \'95\tab}{\*\pn\pnlvlblt\pnf3\pnfs56{\pntxtb \'95}}{\b\f2\fs56\cf1 Metrics Generated:}{\f2\fs56\cf1  \par 
}\pard\plain\ltrpar\s3\li1800\fi-360\kerning24\fs40\lang1033\li1080 {\pntext\pard\plain\f3\fs48 \'95\tab}{\*\pn\pnlvlblt\pnf3\pnfs48{\pntxtb \'95}}{\f2\fs48\cf1 Total inventory and active out-on-loan books.\par 
}\pard\plain\ltrpar\s3\li1800\fi-360\kerning24\fs40\lang1033\li1080 {\pntext\pard\plain\f3\fs48 \'95\tab}{\*\pn\pnlvlblt\pnf3\pnfs48{\pntxtb \'95}}{\f2\fs48\cf1 Cumulative outstanding revenue from overdue items.\par 
}\pard\plain\ltrpar\s3\li1800\fi-360\kerning24\fs40\lang1033\li1080 {\pntext\pard\plain\f3\fs48 \'95\tab}{\*\pn\pnlvlblt\pnf3\pnfs48{\pntxtb \'95}}{\f2\fs48\cf1 Live high demand analysis pinpointing the most borrowed resource.\par 
}\pard\plain\ltrpar\s1\li360\fi-360\kerning24\fs56\lang1033\li0\fi0 {\f1\fs88\cf1 Testing Framework & Success Metrics}{\f1\fs88\cf1{\bcp47{\*\langtag en-UG}\lang0}\par 
}\pard\plain\ltrpar\s2\li1080\fi-360\kerning24\fs48\lang1033\li360 {\pntext\pard\plain\f3\fs56 \'95\tab}{\*\pn\pnlvlblt\pnf3\pnfs56{\pntxtb \'95}}{\b\f2\fs56\cf1 Boundary Testing:}{\f2\fs56\cf1  Verified system responses for input errors like duplicate records or over-limit deletes.\par 
}\pard\plain\ltrpar\s2\li1080\fi-360\kerning24\fs48\lang1033\li360 {\pntext\pard\plain\f3\fs56 \'95\tab}{\*\pn\pnlvlblt\pnf3\pnfs56{\pntxtb \'95}}{\b\f2\fs56\cf1 Functional Checks:}{\f2\fs56\cf1  Validated correct fine accumulation tracking and borrow-blocking limits.\par 
}\pard\plain\ltrpar\s2\li1080\fi-360\kerning24\fs48\lang1033\li360 {\pntext\pard\plain\f3\fs56 \'95\tab}{\*\pn\pnlvlblt\pnf3\pnfs56{\pntxtb \'95}}{\b\f2\fs56\cf1 Status:}{\f2\fs56\cf1  Passed 100% of the structured testing protocols.}{\f2\fs56\cf1{\bcp47{\*\langtag en-UG}\lang0}\par 
}\pard\plain\ltrpar\s1\li360\fi-360\kerning24\fs56\lang1033\li0\fi0 {\f1\fs88\cf1 Summary of Project Achievements}{\f1\fs88\cf1{\bcp47{\*\langtag en-UG}\lang0}\par 
}\pard\plain\ltrpar\s2\li1080\fi-360\kerning24\fs48\lang1033\li360 {\pntext\pard\plain\f3\fs56 \'95\tab}{\*\pn\pnlvlblt\pnf3\pnfs56{\pntxtb \'95}}{\b\f2\fs56\cf1 Outcome:}{\f2\fs56\cf1  Fulfills all programmatic requirements assigned for the Computing II course.\par 
}\pard\plain\ltrpar\s2\li1080\fi-360\kerning24\fs48\lang1033\li360 {\pntext\pard\plain\f3\fs56 \'95\tab}{\*\pn\pnlvlblt\pnf3\pnfs56{\pntxtb \'95}}{\b\f2\fs56\cf1 Curriculum Integration:}{\f2\fs56\cf1  Demonstrates safe file/buffer processing, multi-struct linking, and pointer logic in C.\par 
}\pard\plain\ltrpar\s2\li1080\fi-360\kerning24\fs48\lang1033\li360 {\pntext\pard\plain\f3\fs56 \'95\tab}{\*\pn\pnlvlblt\pnf3\pnfs56{\pntxtb \'95}}{\b\f2\fs56\cf1 Future Extensions:}{\f2\fs56\cf1  Data storage persistence across sessions and multiple simultaneous book loans.}{\f2\fs56\cf1{\bcp47{\*\langtag en-UG}\lang0}\par 
}
}