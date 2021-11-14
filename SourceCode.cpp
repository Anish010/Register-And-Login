//Login and register
#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <string>

using namespace std;

bool exist(string username)
{
    ifstream duplicate;
    duplicate.open(username + ".txt");
    if (duplicate.is_open())
    {
        return true;
    }
    return false;
}

void Register(string username, string password)
{
    bool valid = exist(username);
    if (valid == false)
    {
        fstream user;
        user.open(username + ".txt", ios::out); //write a file
        if (user.is_open())
        {
            user << username << endl;
            user << password << endl;
            user.close();
        }
        cout << endl
             << "You are registered successfully."
             << endl;
    }
    else
        cout << "Username is already taken. Try Again!!" << endl;
}

bool LogIn()
{
    string username, password, u, p;
    cout << "Enter username : ";
    cin >> username;
    cout << "\nEnter password : ";
    cin >> password;

    ifstream user(username + ".txt");
    getline(user, u);
    getline(user, p);

    if (u == username && p == password)
    {
        return true;
    }
    else
        return false;
}

int main()
{
    int ch;
    cout << "Press 1 for Register Id.";
    cout << "\nPress 2 for Login Id." << endl;
    cout << endl
         << "Enter your choice : ";
    cin >> ch;
    cout << endl;

    fstream user;
    if (ch == 1)
    {
        string username, password;
        cout << "Create a username : ";
        cin >> username;
        cout << "Create a password (Password should be of minimum 8 digits) : ";
        cin >> password;
        cout << endl;

        if (password.length() >= 8 && username.size() != 0)
        {
            Register(username, password);
            main();
        }
        else if (username.size() == 0)
        {
            cout << "\nEnter username." << endl;
            main();
        }
        else
        {
            cout << "\nInvalid password.\nPassword should be of minimum 8 digits.\nTry Again!!" << endl;
            main();
        }
    }
    if (ch == 2)
    {
        bool check = LogIn();
        if (check == true)
        {
            cout << "You are successfully logged in." << endl;
        }
        else
        {
            cout << "Wrong username or password.\nTry Again!!." << endl;
            main();
        }
    }
}