//By 3 Idiots
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Book
{
    int bookId;
    char title[100];
    char author[100];
    int availability;
};

struct User
{
    int userId;
    char username[100];
    char password[100];
    int fine;
};

void showWelcomeDashboard()
{
    printf("\t\t\t\t\t\t\t   **************************************\n");
    printf("\t\t\t\t\t\t\t   *          LibraSysManager           *\n");
    printf("\t\t\t\t\t\t\t   **************************************\n");
    printf("\t\t\t\t\t\t\t   *                                    *\n");
    printf("\t\t\t\t\t\t\t   *      Welcome to the Library!       *\n");
    printf("\t\t\t\t\t\t\t   *                                    *\n");
    printf("\t\t\t\t\t\t\t   **************************************\n\n");
    printf("\t\t\t\t\t\t\t   Books are keys to wisdom's treasure; \n\t\t\t\t\t\t\t   open them and unlock your mind.\n\n\t\t\t\t\t\t\t\t\t\t  --Unknown\n\n");
    printf("\t\t\t\t\t\t\t   **************************************\n\n\n");
}

void registerUser();
int loginUser();
void addBook();
void deleteBook();
void displayBooks();
void borrowBook();
void returnBook();
void searchBooks();
void calculateFine(int userId);

struct Book books[100];
int bookCount = 0;
struct User users[100];
int userCount = 0;

int main()
{
    showWelcomeDashboard();

    int choice;
    int loggedInUserId = -1;

    while (1)
    {
        printf("\t\t\t\t\t\t\t\t   Library Management System\n\n");
        printf("\t\t\t\t\t\t\t\t   1. Register\n");
        printf("\t\t\t\t\t\t\t\t   2. Login\n");
        printf("\t\t\t\t\t\t\t\t   3. Add Book\n");
        printf("\t\t\t\t\t\t\t\t   4. Delete Book\n");
        printf("\t\t\t\t\t\t\t\t   5. Display Books\n");
        printf("\t\t\t\t\t\t\t\t   6. Borrow Book\n");
        printf("\t\t\t\t\t\t\t\t   7. Return Book\n");
        printf("\t\t\t\t\t\t\t\t   8. Search Books\n");
        printf("\t\t\t\t\t\t\t\t   9. Calculate Fine\n");
        printf("\t\t\t\t\t\t\t\t   10. Exit\n\n");
        printf("\t\t\t\t\t\t\t\t   Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            registerUser();
            break;
        case 2:
            loggedInUserId = loginUser();
            if (loggedInUserId == -1)
            {
                printf("\n\t\t\t\t\t\t\t\t   Invalid username or password. Please try again.\n\n");
            }
            else
            {
                printf("\n\t\t\t\t\t\t\t\t   Login successful.\n\n");
            }
            break;
        case 3:
            if (loggedInUserId != -1)
            {
                addBook();
            }
            else
            {
                printf("\t\t\t\t\t\t\t\t   Please login first.\n\n");
            }
            break;
        case 4:
            if (loggedInUserId != -1)
            {
                deleteBook();
            }
            else
            {
                printf("\t\t\t\t\t\t\t\t   Please login first.\n\n");
            }
            break;
        case 5:
            displayBooks();
            break;
        case 6:
            if (loggedInUserId != -1)
            {
                borrowBook();
            }
            else
            {
                printf("\t\t\t\t\t\t\t\t   Please login first.\n\n");
            }
            break;
        case 7:
            if (loggedInUserId != -1)
            {
                returnBook();
            }
            else
            {
                printf("\t\t\t\t\t\t\t\t   Please login first.\n\n");
            }
            break;
        case 8:
            searchBooks();
            break;
        case 9:
            if (loggedInUserId != -1)
            {
                calculateFine(loggedInUserId);
            }
            else
            {
                printf("\t\t\t\t\t\t\t\t   Please login first.\n\n");
            }
            break;
        case 10:
            printf("\n\t\t\t\t\t\t\t\t   Exiting... Goodbye!\n\n");
            exit(0);
        default:
            printf("\t\t\t\t\t\t\t\t   Invalid choice. Please try again.\n\n");
        }
    }

    return 0;
}

void registerUser()
{
    struct User newUser;

    printf("\n\t\t\t\t\t\t\t\t   Enter username: ");
    scanf("%s", newUser.username);
    printf("\t\t\t\t\t\t\t\t   Enter password: ");
    scanf("%s", newUser.password);

    newUser.userId = userCount + 1;
    newUser.fine = 0;

    users[userCount] = newUser;
    userCount++;

    printf("\t\t\t\t\t\t\t\t   Registration successful. Your User ID is %d.\n\n", newUser.userId);
}

int loginUser()
{
    char username[100];
    char password[100];

    printf("\n\t\t\t\t\t\t\t\t   Enter username: ");
    scanf("%s", username);
    printf("\t\t\t\t\t\t\t\t   Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++)
    {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0)
        {
            return users[i].userId;
        }
    }

    return -1;
}

void addBook()
{
    struct Book newBook;

    printf("\n\t\t\t\t\t\t\t\t   Enter Book Title: ");
    scanf(" %[^\n]", newBook.title);
    printf("\t\t\t\t\t\t\t\t   Enter Author: ");
    scanf(" %[^\n]", newBook.author);
    printf("\t\t\t\t\t\t\t\t   Enter Availability (1 for available, 0 for not available):");
    scanf("%d", &newBook.availability);

    newBook.bookId = bookCount + 1;

    books[bookCount] = newBook;
    bookCount++;

    printf("\t\t\t\t\t\t\t\t   Book added successfully. Book ID is %d.\n\n", newBook.bookId);
}

void deleteBook()
{
    int bookId;

    printf("\n\t\t\t\t\t\t\t\t   Enter Book ID: ");
    scanf("%d", &bookId);

    int index = -1;

    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].bookId == bookId)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        for (int i = index; i < bookCount - 1; i++)
        {
            books[i] = books[i + 1];
        }
        bookCount--;

        printf("\t\t\t\t\t\t\t\t   Book deleted successfully.\n\n");
    }
    else
    {
        printf("\t\t\t\t\t\t\t\t   Book not found.\n\n");
    }
}

void displayBooks()
{
    printf("\n\t\t\t\t\t\t\t\t   --- Available Books ---\n");
    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].availability == 1)
        {
            printf("\t\t\t\t\t\t\t\t   Book ID: %d\n", books[i].bookId);
            printf("\t\t\t\t\t\t\t\t   Title: %s\n", books[i].title);
            printf("\t\t\t\t\t\t\t\t   Author: %s\n", books[i].author);
            printf("\t\t\t\t\t\t\t\t   Availability: %s\n", books[i].availability == 1 ? "Available" : "Not Available");
            printf("\t\t\t\t\t\t\t\t   -----------------------\n");
        }
    }
}

void borrowBook()
{
    int bookId;

    printf("\n\t\t\t\t\t\t\t\t   Enter Book ID to borrow: ");
    scanf("%d", &bookId);

    int index = -1;

    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].bookId == bookId)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        if (books[index].availability == 1)
        {
            books[index].availability = 0;
            printf("\t\t\t\t\t\t\t\t   Book borrowed successfully.\n\n");
        }
        else
        {
            printf("\t\t\t\t\t\t\t\t   Book not available for borrowing.\n\n");
        }
    }
    else
    {
        printf("\t\t\t\t\t\t\t\t   Book not found.\n\n");
    }
}

void returnBook()
{
    int bookId;

    printf("\n\t\t\t\t\t\t\t\t   Enter Book ID to return: ");
    scanf("%d", &bookId);

    int index = -1;

    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].bookId == bookId)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        if (books[index].availability == 0)
        {
            books[index].availability = 1;
            printf("\t\t\t\t\t\t\t\t   Book returned successfully.\n\n");
        }
        else
        {
            printf("\t\t\t\t\t\t\t\t   Invalid operation. Book is already available.\n\n");
        }
    }
    else
    {
        printf("\t\t\t\t\t\t\t\t   Book not found.\n\n");
    }
}

void searchBooks()
{
    char searchQuery[100];

    printf("\n\t\t\t\t\t\t\t\t   Enter Search Query: ");
    scanf(" %[^\n]", searchQuery);

    printf("\t\t\t\t\t\t\t\t   --- Search Results ---\n");
    for (int i = 0; i < bookCount; i++)
    {
        if (strstr(books[i].title, searchQuery) != NULL || strstr(books[i].author, searchQuery) != NULL)
        {
            printf("\t\t\t\t\t\t\t\t   Book ID: %d\n", books[i].bookId);
            printf("\t\t\t\t\t\t\t\t   Title: %s\n", books[i].title);
            printf("\t\t\t\t\t\t\t\t   Author: %s\n", books[i].author);
            printf("\t\t\t\t\t\t\t\t   Availability: %s\n", books[i].availability == 1 ? "Available" : "Not Available");
            printf("\t\t\t\t\t\t\t\t   -----------------------\n");
        }
    }
}

void calculateFine(int userId)
{
    int days;
    int finePerDay = 5;

    printf("\n\t\t\t\t\t\t\t\t   Enter the number of days the book is overdue: ");
    scanf("%d", &days);

    if (days > 0)
    {
        int index = -1;

        for (int i = 0; i < userCount; i++)
        {
            if (users[i].userId == userId)
            {
                index = i;
                break;
            }
        }

        if (index != -1)
        {
            int fine = days * finePerDay;
            users[index].fine += fine;

            printf("\t\t\t\t\t\t\t\t   Fine calculated successfully. Total fine for User ID %d is %d BDT.\n\n", userId, users[index].fine);
        }
        else
        {
            printf("\t\t\t\t\t\t\t\t   User not found.\n\n");
        }
    }
    else
    {
        printf("\t\t\t\t\t\t\t\t   Invalid number of days.\n\n");
    }
}
