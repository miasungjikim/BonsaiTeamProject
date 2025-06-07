#include "signup.h"
#include <iostream>
#include <fstream>

using namespace std;

// ----- User class method definitions -----

User::User(const string& fname, const string& lname, const string& mail, const string& pass) {
    first_name = fname;
    last_name = lname;
    email = mail;
    password = pass;
    user_id = "";  // 기본값
}

void User::setUserId(int id_num) {
    user_id = "U" + to_string(id_num);
}

string User::getUserId() const {
    return user_id;
}

string User::getFirstName() const {
    return first_name;
}

string User::getLastName() const {
    return last_name;
}

string User::getPassword() const {
    return password;
}
void SignupManager::registerUser() {
    string fname, lname, email, password, confirm_password;
    string role, admin_key;

    cout << "\n----- Sign Up -----\n";
    cout << "First name: ";
    cin >> fname;
    cout << "Last name: ";
    cin >> lname;
    cout << "Email: ";
    cin >> email;
    cout << "Create password: ";
    cin >> password;
    cout << "Confirm password: ";
    cin >> confirm_password;

    if (password != confirm_password) {
        cout << "Passwords do not match.\n";
        return;
    }

    cout << "Sign up as (user/admin): ";
    cin >> role;

    if (role == "admin") {
        cout << "Enter admin key: ";
        cin >> admin_key;
        if (admin_key != "admin1234") {
            cout << "Wrong admin key.\n";
            return;
        }
    }

    // 포인터로 User 객체 생성
    User* new_user = new User(fname, lname, email, password);

    // 간단한 user ID 만들기 (U 뒤에 랜덤 숫자 예시)
    new_user->setUserId(1000);  // 나중에 자동 증가로 바꿔도 됨

    // 저장할 파일명
    string filename;
    if (role == "admin") {
        filename = "admins.txt";
    } else {
        filename = "users.txt";
    }

    // 파일 저장 (간단하게 덮어쓰기 아닌 이어쓰기)
    ofstream file(filename, std::ios::app);
    if (file.is_open()) {
        file << new_user->getUserId() << ","
             << new_user->getFirstName() << ","
             << new_user->getLastName() << ","
             << email << ","
             << new_user->getPassword() << "\n";
        file.close();
        cout << "Sign up successful! ID: " << new_user->getUserId() << endl;
    } else {
        cout << "File error.\n";
    }

    delete new_user;  // 동적 메모리 해제
}
