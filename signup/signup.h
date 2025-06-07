//
// Created by MiaKim on 07/06/2025. (OOP)


#ifndef SIGNUP_H
#define SIGNUP_H

#include <iostream>
using namespace std;

class User {
private:
    string user_id;
    string first_name;
    string last_name;
    string email;
    string password;

public:User(const string& fname, const string& lname, const string& mail, const string& pass ); //constructor
    void setUserId(int id_num) ; //Setter
    string getUserId() const; // Getter
    string getFirstName() const;
    string getLastName() const;
    string getPassword() const;
};

class SignupManager {
public:
    void registerUser();
};




#endif //SIGNUP_H
