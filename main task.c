#include <stdio.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 30
#define MAX_PASSWORD_LENGTH 20

typedef enum {
  ACTIVE,
  INACTIVE
} UserStatus;

typedef struct User {
  char username[MAX_USERNAME_LENGTH];
  char password[MAX_PASSWORD_LENGTH];
  UserStatus status;
} User;

User users[100]; // Array to store user data
int numUsers = 0; // Number of registered users

void registerNewUser() {
  User newUser;

  printf("Enter username: ");
  scanf("%s", newUser.username);

  printf("Enter password: ");
  scanf("%s", newUser.password);

  printf("Enter user status (1 for active, 0 for inactive): ");
  scanf("%d", &newUser.status);

  // Check if username already exists
  for (int i = 0; i < numUsers; i++) {
    if (strcmp(users[i].username, newUser.username) == 0) {
      printf("Username already exists. Please try a different one.\n");
      return;
    }
  }

  // Add new user to the users array
  users[numUsers] = newUser;
  numUsers++;

  printf("Registration successful!\n");
}

void loginUser() {
  char username[MAX_USERNAME_LENGTH];
  char password[MAX_PASSWORD_LENGTH];

  printf("Enter username: ");
  scanf("%s", username);

  printf("Enter password: ");
  scanf("%s", password);

  // Find the user with the given username and password
  int foundUserIndex = -1;
  for (int i = 0; i < numUsers; i++) {
    if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
      if (users[i].status == ACTIVE) {
        foundUserIndex = i;
        break;
      } else {
        printf("User is inactive. Please contact the administrator to activate your account.\n");
        return;
      }
    }
  }

  if (foundUserIndex == -1) {
    printf("Invalid username or password. Please try again.\n");
  } else {
    printf("Login successful!\nWelcome, %s!\n", users[foundUserIndex].username);
  }
}

int main() {
  int choice;

  while (1) {
    printf("\n1. Register\n2. Login\n3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        registerNewUser();
        break;
      case 2:
        loginUser();
        break;
      case 3:
        printf("Exiting...\n");
        return 0;
      default:
        printf("Invalid choice. Please enter a number between 1 and 3.\n");
    }
  }

  return 0;
}
