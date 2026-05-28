/*

Library Book Management System
TEMB 1202 Computing II — Group A Evening

*/
#include <stdio.h> //standard input and output
#include <stdlib.h> //
#include <string.h> //for managing strings

/* Constants */
#define MAX_BOOKS 100
#define MAX_MEMBERS 50
#define HIGH_DEMAND_THRESHOLD 5
#define LOAN_PERIOD_DAYS 14
#define FINE_PER_DAY 500.0f

/* Book record */
typedef struct {
int id;
char isbn[20];
char title[80];
char author[50];
char genre[30];
int year;
int totalCopies;
int availableCopies;
int borrowCount;
int isHighDemand;
} Book;

/* Member / borrower record */
typedef struct {int memberId;
char name[50];
int borrowedBookId; /* -1 = none */
char borrowDate[12];
char dueDate[12];
float unpaidFine;
int totalBorrows;
} Member;
Book library[MAX_BOOKS];
Member members[MAX_MEMBERS];
int bookCount = 0;
int memberCount = 0;

/* Forward declarations */
int authenticate();
void displayMenu();
void addBook();
void searchBook();
void updateBook();
void deleteBook();
void borrowBook();
void returnBook();
void displayAllBooks();
void generateReport();
void registerMember();
void payFine();
int findBookById(int id);
int findMemberById(int id);
int computeOverdueDays(const char *dueDate);
void clearBuffer();


//main entry point

int main(){

    if (!authenticate()) return 1;
int choice;
do {
displayMenu();
printf("Enter choice: "); scanf("%d", &choice); clearBuffer();
switch (choice) {case 1: addBook(); break;
case 2: searchBook(); break;
case 3: updateBook(); break;
case 4: deleteBook(); break;
case 5: borrowBook(); break;
case 6: returnBook(); break;
case 7: displayAllBooks(); break;
case 8: generateReport(); break;
case 9: registerMember(); break;
case 10: payFine(); break;
case 0: printf("Goodbye!\n"); break;
default: printf("[!] Invalid option. Pick something valid\n");
}
} while (choice != 0);
return 0;
}

//authentication function with 3 attempts

int authenticate() {
char user[30], pass[30];
const char *VALID_USER = "admin"; // Hardcoded credentials for demo
const char *VALID_PASS = "lib2026"; //password
int attempts = 0;
while (attempts < 3) {
printf("\n============================================\n");
printf(" LIBRARY BOOK MANAGEMENT SYSTEM v1.0 \n");
printf("============================================\n");
printf("Username : "); scanf("%29s", user);
printf("Password : "); scanf("%29s", pass); clearBuffer();
if (strcmp(user, VALID_USER) == 0 &&
strcmp(pass, VALID_PASS) == 0) {
printf("[OK] Welcome, Librarian %s!\n", user);
return 1;
}
attempts++;
printf("[X] Wrong credentials. %d attempt(s) left.\n", 3 - attempts);
}
printf("[X] Access denied. Contact administrator.\n");
return 0;
}

//display main menu

void displayMenu() {
printf("\n.............................................\n");
printf(" MAIN MENU \n");
printf("...............................................\n");
printf(" 1. Add Book\n");
printf(" 2. Search Book\n");
printf(" 3. Update Book\n");
printf(" 4. Delete Book\n");
printf(" 5. Borrow Book\n");
printf(" 6. Return Book\n");
printf(" 7. Display All Books\n");
printf(" 8. Library Summary Report\n");
printf(" 9. Register Member\n");
printf(" 10. Pay Fine\n");
printf(" 0. Exit\n");
printf("--------------------------------------------\n");
}

//add new book to library

void addBook() {
if (bookCount >= MAX_BOOKS) {
printf("[!] Catalogue full.\n"); return;
}
Book b;
printf("\n--- Add New Book ---\n");
printf("Book ID : "); scanf("%d", &b.id); clearBuffer();
for (int i = 0; i < bookCount; i++) {
if (library[i].id == b.id) {
printf("[!] ID %d already exists.\n", b.id); return;
}
}
printf("ISBN : "); fgets(b.isbn, 20, stdin); b.isbn[strcspn(b.isbn,"\n")]='\0';
printf("Title : "); fgets(b.title, 80, stdin); b.title[strcspn(b.title,"\n")]='\0';
printf("Author : "); fgets(b.author,50, stdin); b.author[strcspn(b.author,"\n")]='\0';
printf("Genre : "); fgets(b.genre, 30, stdin); b.genre[strcspn(b.genre,"\n")]='\0';
printf("Year : "); scanf("%d", &b.year);
printf("Copies : "); scanf("%d", &b.totalCopies); clearBuffer();
if (b.totalCopies <= 0) { printf("[!] Copies must be > 0.\n"); return; }
b.availableCopies = b.totalCopies;
b.borrowCount = 0;
b.isHighDemand = 0;
library[bookCount++] = b;
printf("[+] '%s' added. Copies: %d\n", b.title, b.totalCopies);
}

//search for book by id, title or author

void searchBook() {
printf("\nSearch by: 1) ID 2) Title 3) Author: ");
int opt; scanf("%d", &opt); clearBuffer();
if (opt == 1) {
int id; printf("Book ID: "); scanf("%d", &id); clearBuffer();
int idx = findBookById(id);
if (idx == -1) { printf("[!] Not found.\n"); return; }
Book *b = &library[idx];
printf("\nID: %d | Title: %s | Author: %s\n", b->id, b->title, b->author);
printf("ISBN: %s | Genre: %s | Year: %d\n", b->isbn, b->genre, b->year);
printf("Copies: %d / %d available | Borrows: %d | %s\n",
b->availableCopies, b->totalCopies, b->borrowCount,
b->isHighDemand ? "[HIGH DEMAND]" : "");
} else {
char key[80];
printf("Keyword: "); fgets(key, 80, stdin); key[strcspn(key,"\n")]='\0';
int found = 0;
for (int i = 0; i < bookCount; i++) {
int match = (opt == 2)
? (strstr(library[i].title, key) != NULL)
: (strstr(library[i].author, key) != NULL);
if (match) {
printf(" [%d] %s by %s (%d avail)\n",
library[i].id, library[i].title,
library[i].author, library[i].availableCopies);
found = 1;
}
}
if (!found) printf("[!] No match for '%s'.\n", key);
}
}

//update book record (title, author, add copies)

void updateBook() {
int id; printf("\nBook ID to update: "); scanf("%d",&id); clearBuffer();
int idx = findBookById(id);
if (idx == -1) { printf("[!] Not found.\n"); return; }
Book *b = &library[idx];
printf("Current Title: %s\nNew Title (Enter to keep): ", b->title);
char tmp[80]; fgets(tmp, 80, stdin);
if (tmp[0] != '\n') { tmp[strcspn(tmp,"\n")]='\0'; strcpy(b->title, tmp); }
printf("Current Author: %s\nNew Author (Enter to keep): ", b->author);
fgets(tmp, 50, stdin);
if (tmp[0] != '\n') { tmp[strcspn(tmp,"\n")]='\0'; strcpy(b->author, tmp); }
printf("Current Copies: %d\nAdd more copies (0 to skip): ");
int extra; scanf("%d", &extra); clearBuffer();
if (extra > 0) { b->totalCopies += extra; b->availableCopies += extra; }
printf("[+] Book record updated.\n");
}

//update book record (title, author, add copies)

void deleteBook() {
int id; printf("\nBook ID to delete: "); scanf("%d",&id); clearBuffer();
int idx = findBookById(id);
if (idx == -1) { printf("[!] Not found.\n"); return; }
if (library[idx].availableCopies < library[idx].totalCopies) {
printf("[!] Cannot delete: some copies are currently borrowed.\n"); return;
}
printf("Delete '%s'? (y/n): ", library[idx].title);
char c; scanf(" %c", &c); clearBuffer();
if (c != 'y' && c != 'Y') { printf("[-] Cancelled.\n"); return; }
for (int i = idx; i < bookCount - 1; i++) library[i] = library[i+1];
bookCount--;
printf("[+] Book deleted.\n");
}

//borrow book (with rules: availability, fines, one book at a time, high demand flag)

void borrowBook() {
int memberId, bookId;
printf("\n--- Borrow Book ---\n");
printf("Member ID : "); scanf("%d", &memberId);
printf("Book ID : "); scanf("%d", &bookId); clearBuffer();
int mIdx = findMemberById(memberId);
int bIdx = findBookById(bookId);
if (mIdx == -1) { printf("[!] Member not found.\n"); return; }
if (bIdx == -1) { printf("[!] Book not found.\n"); return; }
Member *m = &members[mIdx];
Book *b = &library[bIdx];
/* BR-4 */
if (m->unpaidFine > 0.0f) {
printf("[X] Borrow blocked: outstanding fine of %.2f UGX. Please pay first.\n",
m->unpaidFine);
return;
}
/* BR-1 & BR-2 */
if (b->availableCopies <= 0) {
printf("[X] UNAVAILABLE: All %d copy/copies of '%s' are currently borrowed.\n",
b->totalCopies, b->title);
return;
}
if (m->borrowedBookId != -1) {
printf("[!] Member already has a book on loan (ID %d).\n",
m->borrowedBookId);
return;
}

// Proceed with borrowing

m->borrowedBookId = bookId;

// For simplicity, we set fixed dates. In a real system, we'd calculate these based on the current date.

strcpy(m->borrowDate, "22/05/2026");
strcpy(m->dueDate, "05/06/2026");
b->availableCopies--;
b->borrowCount++;
m->totalBorrows++;
/* BR-5 */
if (!b->isHighDemand && b->borrowCount >= HIGH_DEMAND_THRESHOLD) {
b->isHighDemand = 1;
printf("[*] '%s' is now flagged as HIGH DEMAND.\n", b->title);
}
printf("[+] '%s' borrowed by %s. Due: %s\n",
b->title, m->name, m->dueDate);
}

//return book (with fine calculation for late returns)

void returnBook() {
int memberId;
printf("\n--- Return Book ---\n");
printf("Member ID : "); scanf("%d", &memberId); clearBuffer();
int mIdx = findMemberById(memberId);
if (mIdx == -1) { printf("[!] Member not found.\n"); return; }
Member *m = &members[mIdx];
if (m->borrowedBookId == -1) {
printf("[!] No book currently on loan for this member.\n"); return;
}
int bIdx = findBookById(m->borrowedBookId);
Book *b = (bIdx != -1) ? &library[bIdx] : NULL;
/* BR-3: Fine calculation */
int overdue = computeOverdueDays(m->dueDate);
if (overdue > 0) {
float fine = overdue * FINE_PER_DAY;
m->unpaidFine += fine;
printf("[!] LATE: %d day(s) overdue. Fine charged: %.2f UGX\n",
overdue, fine);
printf(" Total outstanding: %.2f UGX (pay to borrow again)\n",
m->unpaidFine);
} else {
printf("[+] Returned on time. No fine applied.\n");
}
if (b) b->availableCopies++;
m->borrowedBookId = -1;
printf("[+] '%s' returned successfully.\n", b ? b->title : "Book");
}


//display all books in library with details and high demand status

void displayAllBooks() {
if (bookCount == 0) { printf("[!] No books in catalogue.\n"); return; }
printf("\n%-4s %-28s %-20s %6s %6s %s\n",
"ID","Title","Author","Avail","Total","Status");
printf("------------------------------------------------------------------\n");
for (int i = 0; i < bookCount; i++) {
Book *b = &library[i];
printf("%-4d %-28s %-20s %6d %6d %s\n",
b->id, b->title, b->author,
b->availableCopies, b->totalCopies,
b->isHighDemand ? "[HIGH DEMAND]" : "");
}
}

//generate summary report with total books, borrows, fines, and most borrowed book

void generateReport() {
printf("\n================================================\n");
printf(" LIBRARY SUMMARY REPORT \n");
printf("================================================\n");
printf("%-4s %-25s %7s %7s %9s\n",
"ID","Title","Borrows","Avail","Demand");
printf("------------------------------------------------\n");
int totalBorrows = 0;
float totalFines = 0.0f;
int topIdx = -1;
for (int i = 0; i < bookCount; i++) {
Book *b = &library[i];
printf("%-4d %-25s %7d %7d %9s\n",
    b->id, b->title, b->borrowCount,
b->availableCopies, b->isHighDemand ? "[HIGH]" : "Normal");
totalBorrows += b->borrowCount;
if (topIdx == -1 ||
b->borrowCount > library[topIdx].borrowCount)
topIdx = i;
}
for (int i = 0; i < memberCount; i++)
totalFines += members[i].unpaidFine;
printf("------------------------------------------------\n");
printf("TOTAL BOOKS : %d\n", bookCount);
printf("TOTAL BORROWS : %d\n", totalBorrows);
printf("TOTAL FINES : %.2f UGX\n", totalFines);
if (topIdx != -1 && library[topIdx].borrowCount > 0)
printf("MOST BORROWED : %s (%d borrows)\n",
library[topIdx].title, library[topIdx].borrowCount);
else
printf("MOST BORROWED : No borrows recorded yet.\n");
printf("================================================\n");
}

//register new member to library

void registerMember() {
if (memberCount >= MAX_MEMBERS) {
printf("[!] Member list full.\n"); return;
}
Member m;
printf("\n--- Register Member ---\n");
printf("Member ID : "); scanf("%d", &m.memberId); clearBuffer();
for (int i = 0; i < memberCount; i++) {
if (members[i].memberId == m.memberId) {
printf("[!] ID %d already registered.\n", m.memberId); return;
}
}
printf("Name : "); fgets(m.name, 50, stdin); m.name[strcspn(m.name,"\n")]='\0';
m.borrowedBookId = -1;
m.unpaidFine = 0.0f;
m.totalBorrows = 0;
strcpy(m.borrowDate, "");
strcpy(m.dueDate, "");
members[memberCount++] = m;
printf("[+] Member '%s' registered with ID %d.\n", m.name, m.memberId);
}


//pay fine for a member (full or partial payment)

void payFine() {
int memberId; printf("\nMember ID: "); scanf("%d",&memberId); clearBuffer();
int mIdx = findMemberById(memberId);
if (mIdx == -1) { printf("[!] Member not found.\n"); return; }
Member *m = &members[mIdx];
if (m->unpaidFine <= 0.0f) {
printf("[+] No outstanding fines for this member.\n"); return;
}
printf("Outstanding fine: %.2f UGX\n", m->unpaidFine);
printf("Amount paid : ");
float paid; scanf("%f", &paid); clearBuffer();
if (paid >= m->unpaidFine) {
float change = paid - m->unpaidFine;
m->unpaidFine = 0.0f;
printf("[+] Fine cleared. Change: %.2f UGX\n", change);
} else {
m->unpaidFine -= paid;
printf("[+] Partial payment. Remaining: %.2f UGX\n", m->unpaidFine);
}
}


//helper functions

int findBookById(int id) {
for (int i = 0; i < bookCount; i++)
if (library[i].id == id) return i;
return -1;
}
int findMemberById(int id) {
for (int i = 0; i < memberCount; i++)
if (members[i].memberId == id) return i;
return -1;
}
int computeOverdueDays(const char *dueDate) {
int dd, mm, yy;
if (sscanf(dueDate, "%d/%d/%d", &dd, &mm, &yy) != 3) return 0;
int dueAbs = yy*365 + mm*30 + dd;
int todAbs = 2026*365 + 5*30 + 22; /* today = 22/05/2026 */
int diff = todAbs - dueAbs;
return diff > 0 ? diff : 0;
}
void clearBuffer() { while (getchar() != '\n'); 

}
    
  
