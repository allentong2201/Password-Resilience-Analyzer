#include <stdio.h>
#include <string.h>

int hasLowercase(char *password) {
  for (int i=0; password[i] != '\0'; i++) { 
    if (password[i] >= 'a' && password[i] <= 'z') { //checks if character is a lowercase latter
      return 1;
    }
  }
  return 0;
}

int hasUppercase(char *password) {
  for (int i=0; password[i] != '\0'; i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') { //checks if character is a uppercase letter
      return 1; 
    }
  }
  return 0;
}

int hasDigit(char *password) {
  for (int i=0; password[i] != '\0'; i++) {
    if (password[i] >= '0' && password[i] <= '9') { //checks if character is a number
      return 1;
    }
  }
  return 0;
}

int hasSpecialChar(char *password) {
  for (int i=0; password[i] != '\0'; i++) {
    if ((password[i] >= 'a' && password[i] <= 'z') ||
        (password[i] >= 'A' && password[i] <= 'Z') ||
        (password[i] >= '0' && password[i] <= '9') ||
        (password[i] == ' ')) {
      continue;
    }
    else { 
      return 1; //returns true if character is a special character
    }
  }
  return 0;
}

int evaluateStrength(char *password) {
  int strengthScore = 0;

  //checks if password meets each strength criterion
  if (hasLowercase(password)) {
    strengthScore++;
  }

  if (hasUppercase(password)) {
    strengthScore++;
  }

  if (hasDigit(password)) {
    strengthScore++;
  }

  if (hasSpecialChar(password)) {
    strengthScore++;
  }

  if (strlen(password) >= 12) {
    strengthScore++;
  }

return strengthScore;
}

int main() {
  char password[500], choice;
  int length;
  char *strength = NULL;

  while (1) { //continuously displays main menu until user chooses to exit
    printf("\nPassword Resilience Analyzer\n");
    printf("1. Test a new password\n");
    printf("2. View strength of the last tested password\n");
    printf("3. Exit\n");

    printf("Enter your choice: ");
    scanf(" %c", &choice); //stores the user choice as a string instead of a integer to prevent errors if user enters a non-integer character

    if (choice == '1') {
      printf("Enter the password: ");
      scanf("%s", password);

      length = strlen(password);
      if (length >= 8) { //determines password strength only if password has 8 or more characters
        int score = evaluateStrength(password);

        if (score <= 2) {
          strength = "Weak";
        }
	      else if (score <= 4) {
          strength = "Moderate";
        }
	      else {
          strength = "Strong";
        }
        printf("Password Strength: %s\n", strength);
      }
      else { //displays an error message if password has less than 8 characters
        printf("Error: Password should be at least 8 characters long.\n");
      }
    }
    else if (choice == '2') {
      if (strength == NULL) { //if user selects choice 2 without entering a password yet, displays an error message
        printf("Error: You have not entered a password yet.\n");
      }
      else {
        printf("Last tested password strength: %s\n", strength);
      }
    }
    else if (choice == '3') {
      printf("Exiting...\n");
      return 0;
    }
    else { //if user enters anything other than 1, 2, or 3 as a choice, displays an error message
      printf("Error: Invalid choice... please select another choice.\n");
    }
  }
  return 0;
}


