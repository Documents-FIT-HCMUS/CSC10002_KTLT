#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include <ctime>
#define uaf "user_acc_file.txt"
#define uif "user_info_file.txt"
#define rif "reader_info_file.txt"
#define _CRT_SECURE_NO_WARNINGS
#define key 100
using namespace std;

struct log_in_key {
    char* username;
    char* password;
};
struct date {
    int dd, mm, yyyy;
};
struct user {
    log_in_key lik;
    char* name;
    date dob;
    char id[15];
    char* address;
    short int gender;
    bool status;
    short int role;
};
struct reader {
    int reader_id;//ma doc gia
    char* name;
    int id;//cmnd
    date dob;
    short int gender;
    char* email;
    char* address;
    date sign_in_day;
};
struct book_info {
    char* isbn;
    char* book_name;
    char* author;
    char* publisher;
    int publication_year;//nam xuat ban
    char* category;
    int price;
    int quantity;
};
struct form {
    int reader_id;
    date borrow_day;//ngay muon
    date expected_return_day;
    date return_day;
    int quantity;
    char** isbn_list;
};

void encrypt(char[], int); //for string
void decrypt(char[], int);
void encrypt(int&, int); //for number
void decrypt(int&, int);

bool logIn(fstream&, char*, char*);

void changePassword(fstream&, char[], char[], char[]);
void createNewAcc(fstream&, fstream&, user);
user createNewUser(fstream&);
void writeNewUserInfo(fstream&, user);
void writeUserInfo(fstream&, user); //without encrypting
user getUserInfo(fstream&);
void deleteUserTempMem(user&);
void printUserInfo(user);
bool alreadyExistedUsername(fstream&, char[]);
user findUsername(fstream&, char[]);

void editUserInfo(user&);
void editUserInfo(fstream&, user);

void printReader(fstream&);
void printOneReader(reader);
reader inputReaderInfo(int);
void _delete(reader&);
void writeReaderInfo(fstream&, reader);
void addNewReaderInfo(fstream&);
reader reader_list(fstream&);
void editReaderInfo(fstream&,int,char*);
void removeReader(fstream&,int,char*);
reader findReaderID(fstream&,int id);
reader findReaderName(fstream&,char* name);
reader findReaderByReaderID(fstream&, int);

//CHUC NANG 3
book_info getBookInfo(fstream&);
void printBookInfo(book_info);
int quantityOfAllBooks(fstream&);

void printBookList();
void deleteBookInfoTempMem(book_info&);
bool alreadyExistedBookISBN(fstream&, book_info);
bool alreadyExistedBookName(fstream&, book_info);
void addBook();
book_info newBook();
void editBookInfo();
void deleteBookInfo();
void findBookISBN();
book_info findBookISBN(fstream&, book_info);
void findBookName();
book_info findBookName(fstream&, book_info);

//CHUC NANG 4 + 5
void printForm(form f);
form borrowForm();
form getReturnForm(int);
void returnForm(form&);
void removeFormTempMem(form&);
void writeForm(fstream&, form);
void printReturnFormToFile(form);
void printBorrowFormToFile(form);
form getform(fstream&);
int ReadersStatisticsByGender(fstream&, short int);
int borrowedBook(fstream&);
void expired(fstream&, fstream&);

//CHUC NANG 6
int totalBook();
int totalBookByCategory();
int numberOfReader();
int numberOfReaderByGender(short int);

//MENU
void mainMenu(int, int, user&);
int mainFunc();
int subFunc(short int, int);
