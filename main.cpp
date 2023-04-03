#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct User {
    string username;
    string password;
};

vector<User> users;

bool isUsernameExists(string username) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].username == username) {
            return true;
        }
    }
    return false;
}

bool registerUser(string username, string password) {
    if (isUsernameExists(username)) {
        return false;
    }
    users.push_back(User{ username, password });
    return true;
}

bool loginUser(string username, string password) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].username == username && users[i].password == password) {
            return true;
        }
    }
    return false;
}

int main() {
    while (true) {
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            string username, password;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            if (registerUser(username, password)) {
                cout << "Registration successful!" << endl;
            }
            else {
                cout << "Username already exists!" << endl;
            }
        }
        else if (choice == 2) {
            string username, password;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            if (loginUser(username, password)) {
                cout << "Login successful!" << endl;
                // Add your logged in user code here
            }
            else {
                cout << "Invalid username or password!" << endl;
            }
        }
        else if (choice == 3) {
            break;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
