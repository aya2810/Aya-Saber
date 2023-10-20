#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_USERS 30
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

typedef union {
    int flag;
    char active[2];
} Flag;

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    Flag activeFlag;
} User;

User users[MAX_USERS];
int numUsers = 0;

void registerUser() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int active;

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    printf("Enter 1 for active or 0 for inactive: ");
    scanf("%s", &active);

    if (numUsers >= MAX_USERS) {
        printf("Cannot register more users.\n");
        return;
    }

    strcpy(users[numUsers].username, username);
    strcpy(users[numUsers].password, password);
    users[numUsers].activeFlag.flag = active;
    numUsers++;

    printf("Register is succeded.\n");
}


int loginUser() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    int loggedIn = 0;

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            if (users[i].activeFlag.flag){
                printf("Login is succeded.\n");
                loggedIn = 1;
            }else{
                printf("User is inactive. \n");
            }
            break;
        }
    }
    if (!loggedIn){
        printf("Login is failed.\n");
    }
}

int main() {
    int choice;

    do {
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (loginUser()) {

                }
                break;
            case 3:
                printf("exit\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}