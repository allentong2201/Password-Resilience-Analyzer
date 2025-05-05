#include <stdio.h>
#include <string.h>

int hasLowercase(char *password) {
  int i;
  for (i=0; password[i] != '\0'; i++) { //iterates through each character in the password string
    if (password[i] >= 'a' && password[i] <= 'z') { //checks if the current character is a lowercase latter
      return 1; //returns true if it is a lowercase
    }
  }
  return 0; //returns false if there's no lowercase letter in the password
}

int hasUppercase(char *password) {
  int i;
  for (i=0; password[i] != '\0'; i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') { //checks if the current character is a uppercase letter
      return 1; //returns true if yes
    }
  }
  return 0; //returns false if no uppercase letter is found
}

int hasDigit(char *password) {
  int i;
  for (i=0; password[i] != '\0'; i++) {
    if (password[i] >= '0' && password[i] <= '9') { //checks if current character is a number
      return 1; //returns true if yes
    }
  }
  return 0; //otherwise returns false if no number is found in the password
}

int hasSpecialChar(char *password) {
  int i;
  for (i=0; password[i] != '\0'; i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      continue;
    }
    else if (password[i] >= 'A' && password[i] <= 'Z') {
      continue;
    }
    else if (password[i] >= '0' && password[i] <= '9') {
      continue;
    }
    else if (password[i] == ' ') {
      continue;
    }
    else { //if current character is not a lowercase or uppercase letter, not a number, and not a space, it is a special character
      return 1; //returns true if current character is a special character
    }
  }
  return 0; //returns false if no special character is found
}

int evaluateStrength(char *password) {
  int strengthScore = 0; //initializes the password strength score as 0

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
  char password[500], *strength, choice;
  int length;
  while (choice != '3') { //continuously displays main menu until user chooses to exit
    printf("\nPassword Resilience Analyzer\n");
    printf("1. Test a new password\n");
    printf("2. View strength of the last tested password\n");
    printf("3. Exit\n");

    printf("Enter your choice: ");
    scanf("%s", &choice); //stores the user choice as a string instead of a integer to prevent errors if user enters a non-integer character

    if (choice == '1') {
      printf("Enter the password: ");
      scanf("%s", &password);

      length = strlen(password);
      if (length >= 8) { //determines password strength only if password has 8 or more characters
        if (evaluateStrength(password) >= 0 && evaluateStrength(password) <= 2) {
          strength = "Weak";
          printf("Password Strength: %s\n", strength);
        }
	else if (evaluateStrength(password) >=3 && evaluateStrength(password) <= 4) {
          strength = "Moderate";
          printf("Password Strength: %s\n", strength);
        }
	else if (evaluateStrength(password) == 5) {
          strength = "Strong";
          printf("Password Strength: %s\n", strength);
        }
      }
      else if (length < 8) { //displays an error message if password has less than 8 characters
        printf("Error: Password should be at least 8 characters long.\n");
      }
    }
    else if (choice == '2') {
      if (strength == '\0') { //if user selects choice 2 without entering a password yet, displays an error message
        printf("Error: You have not entered a password yet.\n");
      }
      else {
        printf("Last tested password strength: %s\n", strength);
      }
    }
    else if (choice == '3') {
      printf("Exiting...\n");
    }
    else { //if user enters anything other than 1, 2, or 3 as a choice, displays an error message
      printf("Error: Invalid choice.\n");
    }
  }
  return 0;
}


