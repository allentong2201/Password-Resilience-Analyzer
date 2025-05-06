# Password-Resilience-Analyzer

## Overview

**Password Resilience Analyzer** is a command-line C program developed as a final project for the **SFWRENG 2XC3** course. It evaluates the strength and resilience of user-provided passwords against common attack strategies, providing helpful feedback to improve password security.

## Objective

The goal of this project is to:
- Implement modular, testable code using user-defined functions
- Highlight password weaknesses based on common security criteria
- Encourage the creation of secure passwords

## Features

### Main Menu
- Navigate the program through a clear, text-based interface
- Options:
  - Test a new password
  - View strength of the last tested password
  - Exit the program

### Password Input
- Prompts the user for password input
- Validates that the password is at least 8 characters long

### Strength Tests
The password is evaluated based on five criteria:
1. Contains lowercase letters
2. Contains uppercase letters
3. Includes numeric digits
4. Includes special characters (`!@#$%^&*()`)
5. Is 12 or more characters long

Each criterion met adds one point to a strength score (0–5).

### Password Strength Score
- 0–2: Weak
- 3–4: Moderate
- 5: Strong

### Modular Design
Functions implemented:
- `hasLowercase()`
- `hasUppercase()`
- `hasDigit()`
- `hasSpecialChar()`
- `evaluateStrength()`

## Example Usage

```bash
$ ./password_analyzer

Password Resilience Analyzer
1. Test a new password
2. View strength of the last tested password
3. Exit
Enter your choice: 1
Enter a password: myP@ssword123!
Password Strength: Strong
```