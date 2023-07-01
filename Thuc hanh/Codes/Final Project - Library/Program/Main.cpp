#include "Library.h"

int main() 
{
    fstream fa, fu;
    int menu(-1), menu1(-1), menu2;
    int i, n;
    char username[100], password[100];
    bool check;
    user currentUser;

    //DANG NHAP
    
    do
    {
        i = 0;
        check = true;
        cout << " --- DANG NHAP --- \n";
        cout << "Username\t: ";
        cin >> username;
        cout << "Password\t: ";
        cin >> password;
        fa.open(uaf, ios::in);
        if (logIn(fa, username, password)) cout << "Dang nhap thanh cong!\n";
        else
        {
            check = false;
            cout << "Sai username hoac password!!!\n";
            cout << "Ban co muon nhap lai khong?\n\t1. Co\n\t2. Khong\n"; //choose to re-enter the password
            cin >> i;
        }
        fa.close();
        if (i == 2) break; //if not, exit the loop
        if (check) system("pause");
        system("cls");
    } while (check == false);

    if (!check)
    {
        cout << "Thoat khoi chuong trinh.\n";
        return 0; //if wrong account, exit the program
    }

    cout << "Thong tin nguoi dang nhap hien tai:\n";
    fu.open(uif, ios::in);
    currentUser = findUsername(fu, username);
    printUserInfo(currentUser);
    fu.close();
    n = strlen(password) + 1;
    currentUser.lik.password = new char[n];
    strcpy(currentUser.lik.password, password);
    encrypt(currentUser.lik.password, key);
    cout << endl;

    //CHON CHUC NANG CHINH
    
    do
    {
        //if (menu < 0) menu = mainFunc();
        menu = mainFunc();
        if (menu == 0)
        {
            system("cls");
            cout << "Ban da dang xuat.\n";
            break;
        }
        system("cls");
        menu1 = subFunc(currentUser.role, menu);
        if (menu1 == 0)
        {
            system("cls");
            continue;
        }
        mainMenu(menu, menu1, currentUser);
        system("pause");
        system("cls");
    } while (true);
    
    
    /*
    fa.open(uaf, ios::in);
    currentUser = createNewUser(fa);
    fa.close();

    fa.open(uaf, ios::out);
    fu.open(uif, ios::out);
    createNewAcc(fa, fu, currentUser);
    fa.close();
    fu.close();*/
    
    
    cout << "\PROJECT COMPLETED." << endl;

    return 1;
}

