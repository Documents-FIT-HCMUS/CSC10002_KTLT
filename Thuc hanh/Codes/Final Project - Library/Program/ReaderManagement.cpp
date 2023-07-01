#include "Library.h"

//CHUC NANG 2
reader inputReaderInfo(int t)
{
    reader ri;
    int n;
    char temp[100];
    ri.reader_id = t + 1;
    cin.ignore();
    cout << "Nhap ten doc gia\t: ";
    cin.getline(temp, 100);
    n = strlen(temp) + 1;
    ri.name = new char[n];
    //strcpy(ri.name, temp);
    strcpy(ri.name, temp);
    cout << "Nhap so CMND\t: ";
    cin >> ri.id;
    cout << "Nhap ngay sinh\t: ";
    cin >> ri.dob.dd;
    cout << "Nhap thang sinh\t: ";
    cin >> ri.dob.mm;
    cout << "Nhap nam sinh\t: ";
    cin >> ri.dob.yyyy;
    cout << "Nhap gioi tinh (1 Nam, 2 Nu, 3 Khac)\n";
    cin >> ri.gender;
    cout << "Nhap email\t: ";
    cin.ignore();
    cin.getline(temp, 100);
    n = strlen(temp) + 1;
    ri.email = new char[n];
    strcpy(ri.email, temp);
    //strcpy_s(ri.email, sizeof(char) * strlen(temp), temp);
    cout << "Nhap dia chi\t: ";
    cin.getline(temp, 100);
    n = strlen(temp) + 1;
    ri.address = new char[n];
    strcpy(ri.address, temp);
    //strcpy_s(ri.address, sizeof(temp) * strlen(temp), temp);
    cout << "Nhap ngay dang ki\t: ";
    cin >> ri.sign_in_day.dd;
    cout << "Nhap thang dang ki\t: ";
    cin >> ri.sign_in_day.mm;
    cout << "Nhap nam dang ki\t: ";
    cin >> ri.sign_in_day.yyyy;
    return ri;
}
void _delete(reader& ri) {
    delete[]ri.name;
    delete[]ri.address;
    delete[]ri.email;
    ri.name = nullptr;
    ri.address = nullptr;
    ri.email = nullptr;
}
void printOneReader(reader ri) {
    cout << ri.name << '\t';
    cout << ri.reader_id << '\t';
    cout << ri.id << '\t';
    cout << ri.dob.dd << '/';
    cout << ri.dob.mm << '/';
    cout << ri.dob.yyyy << '\t';
    cout << ri.gender << '\t';
    cout << ri.email << '\t';
    cout << ri.address << '\t';
    cout << ri.sign_in_day.dd << '/';
    cout << ri.sign_in_day.mm << '/';
    cout << ri.sign_in_day.yyyy << '\n';
}
void printReader(fstream& fu) {
    fu.open(rif, ios_base::in);
    int n;
    fu >> n;
    fu.ignore(8);
    reader ri;
    for (int i = 0; i < n; i++) {
        ri = reader_list(fu);
        printOneReader(ri);
        _delete(ri);
    }
    fu.close();
}
void writeReaderInfo(fstream& fu, reader ri)
{
    //fu.open(rif, ios::out | ios::app);
    fu << ri.name << ',';
    fu << ri.reader_id << ',';
    fu << ri.id << ',';
    fu << ri.dob.dd << '/';
    fu << ri.dob.mm << '/';
    fu << ri.dob.yyyy << ',';
    fu << ri.gender << ',';
    fu << ri.email << ',';
    fu << ri.address << ',';
    fu << ri.sign_in_day.dd << '/';
    fu << ri.sign_in_day.mm << '/';
    fu << ri.sign_in_day.yyyy << '\n';
    //fu.close();
}
void addNewReaderInfo(fstream& filein) {
    fstream file_temp;
    filein.open(rif, ios_base::in);
    file_temp.open("temp.txt", ios_base::out | ios_base::app);
    int n;
    filein >> n;
    file_temp << n + 1 << ",,,,,,,\n";
    reader ri;
    filein.ignore(8);
    for (int i = 0; i < n; i++) {
        ri = reader_list(filein);
        writeReaderInfo(file_temp, ri);
        _delete(ri);
    }
    reader newReader;
    newReader = inputReaderInfo(n);
    writeReaderInfo(file_temp, newReader);
    file_temp.close();
    filein.close();
    remove(rif);
    rename("temp.txt", rif);
}
reader reader_list(fstream& filein) {

    reader ri;
    ri.name = new char[100];
    ri.email = new char[100];
    ri.address = new char[100];
    filein.getline(ri.name, 100, ',');
    filein >> ri.reader_id;
    filein.ignore();
    filein >> ri.id;
    filein.ignore();
    filein >> ri.dob.dd;
    filein.ignore();
    filein >> ri.dob.mm;
    filein.ignore();
    filein >> ri.dob.yyyy;
    filein.ignore();
    filein >> ri.gender;
    filein.ignore();
    filein.getline(ri.email, 100, ',');
    filein.getline(ri.address, 100, ',');
    filein >> ri.sign_in_day.dd;
    filein.ignore();
    filein >> ri.sign_in_day.mm;
    filein.ignore();
    filein >> ri.sign_in_day.yyyy;
    filein.ignore();
    return ri;
}
void editReaderInfo(fstream& filein, int id, char* name) {
    fstream file_temp;
    filein.open(rif, ios_base::in);
    file_temp.open("temp.txt", ios_base::out);
    int n;
    filein >> n;
    file_temp << n;
    file_temp << ",,,,,,,\n";
    filein.ignore(8);
    reader new_ri;
    bool check = true;
    for (int i = 0; i < n; i++) {
        reader ri = reader_list(filein);
        if (strcmp(ri.name, name) == 0 && id == ri.id) {
            ri.reader_id--;
            new_ri = inputReaderInfo(ri.reader_id);
            writeReaderInfo(file_temp, new_ri);
            _delete(new_ri);
            check = false;
        }
        else
            writeReaderInfo(file_temp, ri);
        _delete(ri);
    }
    if (check) {
        cout << "Doc gia khong co trong danh sach ";
    }
    file_temp.close();
    filein.close();
    remove(rif);
    rename("temp.txt", rif);
}
void removeReader(fstream& filein, int id, char* name) {
    fstream file_temp;
    filein.open(rif, ios_base::in);
    file_temp.open("temp.txt", ios_base::out | ios_base::app);
    int n;
    filein >> n;
    file_temp << n - 1 << ",,,,,,,\n";
    /*cout << "Nhap ten doc gia can xoa: ";
    cin.getline(temp, 100);
    cout << "Nhap CMND: ";
    cin >> cmnd;*/
    reader ri;
    filein.ignore(8);
    bool check = true;
    for (int i = 0; i < n; i++) {
        ri = reader_list(filein);
        if (strcmp(ri.name, name) == 0 && id == ri.id) {
            check = false;
            continue;
        }
        else
            writeReaderInfo(file_temp, ri);
        _delete(ri);
    }
    if (check) {
        cout << "Doc gia khong co trong danh sach ";
    }
    file_temp.close();
    filein.close();
    remove(rif);
    rename("temp.txt", rif);
}
reader findReaderID(fstream& filein, int id) {
    int n;
    filein >> n;
    filein.ignore(8);
    for (int i = 0; i < n; i++) {
        reader ri = reader_list(filein);
        if (id == ri.id) {
            return ri;
        }
        _delete(ri);
    }
    reader rii;
    rii.id = -1;
    return rii;
}
reader findReaderName(fstream& filein, char* name) {
    int n;
    filein >> n;
    filein.ignore(8);
    bool b = true;
    for (int i = 0; i < n; i++) {
        reader ri = reader_list(filein);
        if (strcmp(name, ri.name) == 0) {
            printOneReader(ri);
            b = false;
        }
        _delete(ri);
    }
    reader rii;
    rii.id = -2;
    if (b)
        rii.id = -1;
    return rii;
}
reader findReaderByReaderID(fstream& filein, int id) {
    int n;
    filein >> n;
    filein.ignore(8);
    for (int i = 0; i < n; i++) {
        reader ri = reader_list(filein);
        if (id == ri.reader_id) {
            return ri;
        }
        _delete(ri);
    }
    reader rii;
    rii.id = -1;
    return rii;
}
