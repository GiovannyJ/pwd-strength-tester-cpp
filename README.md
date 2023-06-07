# password-strength-tester-cpp
 Password Strength Tester made in C++

# What is a Secure Password?
 A secure password contains the following
 - A length of at least 12 characters
 - A combination of Uppercase and Lowercase letters
 - Numbers and special characters (!, ?, $, etc.)
 - Not predictable (ex: password123, Password123?, etc.)

# What This code does
 This code checks to see if the input password is resistent to brute force or guessing attacks. It does this by first checking the base metrics of the password to see if it matches all the criteria of a strong password, then it checks to see if the password input is commonly used by comparing it to a shorted version of the rockyou.txt (list of leaked database passwords) called rockyou-25.txt.

 
## Adding a password list
 add the password list to the directory and use its file name as the second argument when you are running the executable of the code

# How To Run
1. git clone github.com/GiovannyJ/pwd-strength-tester-cpp
2. cd pwd-strength-tester-cpp
3. g++ -o pwdtester pwdtester.cpp
4. ./pwdtester PASSWORD (OPTIONAL: FILENAME)