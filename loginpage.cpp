#include <iostream>
#include <fstream>
#include <string>

// Structure to hold user information
struct User {
    std::string username;
    std::string password;
    std::string firstName;
    std::string lastName;
    std::string email;
    std::string mobileNumber;
};

// Function to handle new user registration
void registerUser() {
    User newUser;

    std::cout << "\n--- New User Registration ---\n";
    std::cout << "Enter username: ";
    std::cin >> newUser.username;
    std::cout << "Enter password: ";
    std::cin >> newUser.password;

    std::cout << "Enter first name: ";
    std::cin >> newUser.firstName;

    std::cout << "Enter last name: ";
    std::cin >> newUser.lastName;

    std::cout << "Enter email: ";
    std::cin >> newUser.email;
    
    std::cout << "Enter mobile number: ";
    std::cin >> newUser.mobileNumber;

    // Open the file in append mode to add new user records
    std::ofstream file("users.txt", std::ios::app);
    if (file.is_open()) {
        file << newUser.username << " "
             << newUser.password << " "
             << newUser.firstName << " "
             << newUser.lastName << " "
             << newUser.email << " "
             << newUser.mobileNumber << "\n";
        file.close();
        std::cout << "\nRegistration successful!\n";
    } else {
        std::cerr << "Error: Unable to open file for writing.\n";
    }
}

// Function to handle user login
void loginUser() {
    std::string username, password;
    std::cout << "\n--- User Login ---\n";
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    std::ifstream file("users.txt");
    bool loggedIn = false;
    User tempUser;

    if (file.is_open()) {
        while (file >> tempUser.username >> tempUser.password >> tempUser.firstName >> tempUser.lastName >> tempUser.email >> tempUser.mobileNumber) {
            if (tempUser.username == username && tempUser.password == password) {
                loggedIn = true;
                break;
            }
        }
        file.close();
    } else {
        std::cerr << "Error: Unable to open file for reading.\n";
        return;
    }

    if (loggedIn) {
        std::cout << "\nLogin successful! Welcome, " << tempUser.firstName << ".\n";
        // You can add more functionality here, like displaying full user info.
        std::cout << "Your details:\n";
        std::cout << "Username: " << tempUser.username << "\n";
        std::cout << "Full Name: " << tempUser.firstName << " " << tempUser.lastName << "\n";
        std::cout << "Email: " << tempUser.email << "\n";
        std::cout << "Mobile Number: " << tempUser.mobileNumber << "\n";
    } else {
        std::cout << "\nInvalid username or password. Please try again.\n";
    }
}

int main() {
    int choice;
    do {
        std::cout << "\n--- Main Menu ---\n";
        std::cout << "1. Register New Account\n";
        std::cout << "2. Login\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                std::cout << "Exiting program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 3);

    return 0;
}