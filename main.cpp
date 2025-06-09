#include <iostream>
#include "ui.h"
#include "signup/signup.h"
#include "admin/adminmenu.h"


using namespace std;

int main() {
    //Program START
    // displayWelcome();
    //signup
    // SignupManager signup;
    // signup.registerUser();



    cout << "[Admin Mode Activated]\n" << endl;
    runAdminPanel();  // admin 메뉴 진입

    return 0;
}
