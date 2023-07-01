#include "Library.h"

void encrypt(char a[], int k)
{
    int i, n = strlen(a);
    for (i = 0; i < strlen(a); ++i)
        a[i] += k;
    for (i = 0; i < n / 2; ++i)
        swap(a[i], a[n - i - 1]);
}
void decrypt(char a[], int k)
{
    int i, n = strlen(a);
    for (i = 0; i < strlen(a); ++i)
        a[i] -= k;
    for (i = 0; i < n / 2; ++i)
        swap(a[i], a[n - i - 1]);
}
void encrypt(int& a, int k)
{
    a -= (k * 946);
}
void decrypt(int& a, int k)
{
    a += (k * 946);
}

//CHUC NANG 1
void createNewAcc(fstream& fa, fstream& fu, user newUser) 
{
    char temp[10];
    encrypt(newUser.lik.username, key);
    fa << newUser.lik.username << '\n';
    encrypt(newUser.lik.password, key);
    fa << newUser.lik.password << '\n';

    fu << endl << newUser.lik.username << '\n';
    encrypt(newUser.name, key);
    fu << newUser.name << '\n';

    encrypt(newUser.dob.dd, key);
    fu << newUser.dob.dd << ' ';
    encrypt(newUser.dob.mm, key);
    fu << newUser.dob.mm << ' ';
    encrypt(newUser.dob.yyyy, key);
    fu << newUser.dob.yyyy << '\n';

    encrypt(newUser.id, key);
    fu << newUser.id << '\n';
    encrypt(newUser.address, key);
    fu << newUser.address << '\n';

    fu << newUser.gender << '\n';
    fu << newUser.status << '\n';
    fu << newUser.role;
}
user createNewUser(fstream& fa)
{
    user u;
    int n, choice;
    char temp[100], temp2[100];
    bool check(true);
    do
    {
        cout << "Nhap username\t\t: ";
        cin.getline(temp, 100);
        n = strlen(temp) + 1;
        u.lik.username = new char[n];
        strcpy(u.lik.username, temp);
        if (alreadyExistedUsername(fa, u.lik.username))
        {
            system("cls");
            cout << "Username da ton tai! Moi nhap lai.\n";
            continue;
        }
        bool c = false;
        do
        {   
            if (c) 
                cout << "Mat khau khong khop. Xin moi nhap lai.\n";
            cout << "Nhap password\t\t: ";
            cin.getline(temp, 100);
            cout << "Nhap lai password\t: ";
            cin.getline(temp2, 100);
            c = true;
        } while (strcmp(temp, temp2) != 0);
        n = strlen(temp) + 1;
        u.lik.password = new char[n];
        strcpy(u.lik.password, temp);
        check = false;
        cout << "Nhap ho ten\t\t: ";
        cin.getline(temp, 100);
        n = strlen(temp) + 1;
        u.name = new char[n];
        strcpy(u.name, temp);
        cout << "Nhap ngay thang nam sinh: ";
        cin >> u.dob.dd >> u.dob.mm >> u.dob.yyyy;
        cout << "Nhap CMND\t\t: ";
        cin.ignore();
        cin.getline(u.id, 15);
        cout << "Nhap dia chi\t\t: ";
        cin.getline(temp, 100);
        n = strlen(temp) + 1;
        u.address = new char[n];
        strcpy(u.address, temp);
        cout << "Nhap gioi tinh: \n\t1. Nam\n\t2. Nu\n\t3. Khac\n";
        cin >> u.gender;
        u.status = 1;
        cout << "Nhap chuc vu: \n\t1. Quan ly\n\t2. Chuyen vien\n";
        cin >> u.role;  
        check = false;
    } while (check);
    return u;
}
bool alreadyExistedUsername(fstream& fa, char username[])
{
    char temp[100];
    encrypt(username, key);
    fa.seekg(ios::beg);
    while (!fa.eof())
    {
        fa.getline(temp, 100);
        if (strcmp(temp, username) == 0) {
            //decrypt(username, key);
            fa.seekg(ios::end);
            return true;
        }
        fa.getline(temp, 100);
    }
    decrypt(username, key);
    fa.seekg(ios::end);
    return false;
}
void writeNewUserInfo(fstream& ftemp, user newInfo)
{
    encrypt(newInfo.lik.username, key);
    ftemp << newInfo.lik.username << '\n';
    encrypt(newInfo.name, key);
    ftemp << newInfo.name << '\n';

    encrypt(newInfo.dob.dd, key);
    ftemp << newInfo.dob.dd << ' ';
    encrypt(newInfo.dob.mm, key);
    ftemp << newInfo.dob.mm << ' ';
    encrypt(newInfo.dob.yyyy, key);
    ftemp << newInfo.dob.yyyy << '\n';

    encrypt(newInfo.id, key);
    ftemp << newInfo.id << '\n';
    encrypt(newInfo.address, key);
    ftemp << newInfo.address << '\n';

    ftemp << newInfo.gender << '\n';
    ftemp << newInfo.status << '\n';
    ftemp << newInfo.role << endl;
}
void writeUserInfo(fstream& ftemp, user newInfo)
{
    ftemp << endl << newInfo.lik.username << '\n';
    ftemp << newInfo.name << '\n';

    ftemp << newInfo.dob.dd << ' ';
    ftemp << newInfo.dob.mm << ' ';
    ftemp << newInfo.dob.yyyy << '\n';

    ftemp << newInfo.id << '\n';
    ftemp << newInfo.address << '\n';

    ftemp << newInfo.gender << '\n';
    ftemp << newInfo.status << '\n';
    ftemp << newInfo.role << endl;
}


user getUserInfo(fstream& fu)
{
    user kq;
    int n;
    char temp[100];

    fu.ignore();
    fu.getline(temp, 100);
    //decrypt(temp, key);
    n = strlen(temp) + 1;
    kq.lik.username = new char[n];
    kq.lik.password = new char[10];
    strcpy(kq.lik.username, temp);

    fu.getline(temp, 100);
    //decrypt(temp, key);
    n = strlen(temp) + 1;
    kq.name = new char[n];
    strcpy(kq.name, temp);

    fu >> kq.dob.dd >> kq.dob.mm >> kq.dob.yyyy;
    //decrypt(kq.dob.dd, key);    
    //decrypt(kq.dob.dd, key);
    //decrypt(kq.dob.dd, key);

    fu.ignore();
    fu.getline(kq.id, 15);
    //decrypt(kq.id, key);

    fu.getline(temp, 100);
    //decrypt(temp, key);
    n = strlen(temp) + 1;
    kq.address = new char[n];
    strcpy(kq.address, temp);

    fu >> kq.gender >> kq.status >> kq.role;
    return kq;
}
void deleteUserTempMem(user& u)
{
    delete[]u.lik.username;
    delete[]u.lik.password;
    delete[]u.name;
    delete[]u.address;
}
void printUserInfo(user u)
{
    char temp[100];
    strcpy(temp, u.lik.username);
    decrypt(temp, key);
    cout << "Username\t: " << temp << '\n';

    strcpy(temp, u.name);
    decrypt(temp, key);
    cout << "Ho ten\t\t: " << temp << endl;

    decrypt(u.dob.dd, key);
    decrypt(u.dob.mm, key);
    decrypt(u.dob.yyyy, key);
    cout << "Ngay sinh\t: " << u.dob.dd << '/' << u.dob.mm << '/' << u.dob.yyyy << endl;

    decrypt(u.id, key);
    cout << "CMND\t\t: " << u.id << endl;

    strcpy(temp, u.address);
    decrypt(temp, key);
    cout << "Dia chi\t\t: " << temp << endl;

    cout << "Gioi tinh\t: ";
    if (u.gender == 1) cout << "Nam\n";
    if (u.gender == 2) cout << "Nu\n";
    if (u.gender == 3) cout << "Khac\n";
    cout << "Tinh trang\t: ";
    if (u.status) cout << "Da kich hoat\n";
    else cout << "Da bi khoa\n";
    cout << "Chuc vu\t\t: ";
    if (u.role == 0) cout << "ADMIN\n";
    else if (u.role == 1) cout << "Quan ly\n";
    else cout << "Chuyen vien\n";
}
user findUsername(fstream& fu, char username[])
{
    encrypt(username, key);
    while (!fu.eof())
    {
        user temp = getUserInfo(fu);
        if (strcmp(username, temp.lik.username) == 0) return temp;
    }
}

bool logIn(fstream& fa, char* username, char* password) 
{
    char temp[100], temp2[100];
    encrypt(username, key);
    encrypt(password, key);
    while (!fa.eof())
    {
        fa.getline(temp, 100);
        fa.getline(temp2, 100);
        if (strcmp(temp, username) == 0) 
        {
            if (strcmp(temp2, password) == 0)
            {
                decrypt(username, key);
                decrypt(password, key);
                return true;
            }
            else
            {
                decrypt(username, key);
                decrypt(password, key);
                return false;
            }
        }
    }
    decrypt(username, key);
    decrypt(password, key);
    return false;
}

void changePassword(fstream& fa, char username[], char password[], char newPassword[])
{
    char temp[100];
    char temp2[100];
    fstream ftemp;
    encrypt(newPassword, key);
    fa.open(uaf, ios::in);
    ftemp.open("temp.txt", ios::out);
    while (!fa.eof())
    {
        fa.getline(temp, 100);
        fa.getline(temp2, 100);
        if (strcmp(temp, username) == 0)
        {
            ftemp << temp << endl;
            strcpy(temp2, newPassword);
            ftemp << temp2 << endl;
        }
        else
        {
            if (strlen(temp) == 0 || strlen(temp2) == 0) break;
            ftemp << temp << endl << temp2 << endl;
        }
    }
    ftemp.close();
    fa.close();
    remove(uaf);
    rename("temp.txt", uaf);
}
void editUserInfo(user& current)
{
    int choice, n;
    char temp[100];
    cout << "1. Thay doi ho ten\n2. Thay doi ngay thang nam sinh\n3. Thay doi CMND\n4. Thay doi dia chi\n";
    cout << "5. Thay doi gioi tinh\n";
    cout << "Chon thong tin muon thay doi: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Nhap ho ten moi: ";
        cin.ignore();
        cin.getline(temp, 100);
        delete[]current.name;
        n = strlen(temp) + 1;
        current.name = new char[n];
        encrypt(temp, key);
        strcpy(current.name, temp);
        break;
    case 2:
        cout << "Nhap ngay thang nam sinh moi: ";
        cin >> current.dob.dd >> current.dob.mm >> current.dob.yyyy;
        encrypt(current.dob.dd, key);
        encrypt(current.dob.mm, key);
        encrypt(current.dob.yyyy, key);
        break;
    case 3:
        cout << "Nhap so CMND moi: ";
        cin.ignore();
        cin.getline(temp, 100);
        encrypt(temp, key);
        strcpy(current.id, temp);
        break;
    case 4:
        cout << "Nhap dia chi moi: ";
        cin.ignore();
        cin.getline(temp, 100);
        delete[]current.address;
        n = strlen(temp) + 1;        
        encrypt(temp, key);
        current.address = new char[n];
        strcpy(current.address, temp);
        break;
    case 5: 
        cout << "Nhap gioi tinh moi (1. Nam, 2. Nu, 3. Khac): ";
        cin >> current.gender;
        break;
    default:
        break;
    }
}
void editUserInfo(fstream& fu, user newInfo)
{
    user temp;
    fstream ftemp;
    fu.open(uif, ios::in);
    ftemp.open("temp.txt", ios::out | ios::app);
    while (!fu.eof())
    {
        temp = getUserInfo(fu);
        if (strlen(temp.lik.username) == 0)
        {
            deleteUserTempMem(temp);
            break;
        }
        else
        {
            if (strcmp(newInfo.lik.username, temp.lik.username) == 0)
                writeUserInfo(ftemp, newInfo);
            else
                writeUserInfo(ftemp, temp);
        }       
        deleteUserTempMem(temp);
    }
    ftemp.close();
    fu.close();
    remove(uif);
    rename("temp.txt", uif);
}
