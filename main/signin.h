//
// Created by MiaKim on 09/06/2025.
//

#ifndef SIGNIN_H
#define SIGNIN_H

using namespace std;

struct LoginInfo {
    bool success;
    string id;
    string email;
    string name;
    string store;
};


void loginMenu();

#endif //SIGNIN_H
