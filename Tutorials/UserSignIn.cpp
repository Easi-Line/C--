#include <iostream>
#include <fstream>
using namespace std;

int main() {
    system("cls");

    //File based user sign-in simulation.
    string username, password, storedUsername, storedPassword;

    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    ofstream outfile("userInfo.txt");
    outfile <<"Username: " << username <<"\n" <<"Password: " << password << "\n";
    cout << "Account created successfully!\n";

    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    ifstream infile("userInfo.txt");
    infile.close();

    (username == storedUsername && password == storedPassword) ? 
        cout << "Sign-in successful!\n" : 
        cout << "Invalid username or password.\n";

    return 0;
}