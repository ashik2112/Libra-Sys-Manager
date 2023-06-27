//By 3 Idiots
#include<stdio.h>

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

int main()
{
    showWelcomeDashboard();
    int choice;

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
    }
    return 0;
}
