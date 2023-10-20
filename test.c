#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a user
struct User {
    char username[50];
    char password[50];
};


union UserData {
    int flag; 
   
};


void registerUser(struct User *users, union UserData *userData, int *userCount) {
    if (*userCount >= 10) {
        printf("User limit reached. Cannot register more users.\n");
        return;
    }

    printf("Enter a username: ");
    scanf("%s", users[*userCount].username);

    printf("Enter a password: ");
    scanf("%s", users[*userCount].password);

    int userFlag;
    printf("Set user flag (1 for active, 0 for inactive): ");
    scanf("%d", &userFlag);

    userData[*userCount].flag = userFlag;

    printf("User registered successfully.\n");
    (*userCount)++;
}

// Function to log in a user
int loginUser(struct User *users, union UserData *userData, int userCount) {
    char username[50];
    char password[50];

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            if (userData[i].flag == 1) {
                printf("Login successful. Welcome, %s!\n", username);
                return 1;
            } else {
                printf("Login failed. User is inactive.\n");
                return 0;
            }
        }
    }

    printf("Login failed. Invalid username or password.\n");
    return 0;
}

int main() {
    struct User users[10]; // Store up to 10 users
    union UserData userData[10]; // User-specific data including flag
    int userCount = 0;

    int option;
    int loggedIn = 0;

    while (1)
    {
        printf("1. Register\n2. Login\n3. Quit\nEnter your choice: ");
        scanf("%d", &option);
        if (option == 1)
        {
            if (register_User())
            {
             
            }
        }
        else if (choice == 2)
        {
            if (loginUser())
            {
                loggedIn = 1;
            }
        }
        else if (3)
        {
            printf("see you later!\n");
            return 0;
        }
        else
        {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}