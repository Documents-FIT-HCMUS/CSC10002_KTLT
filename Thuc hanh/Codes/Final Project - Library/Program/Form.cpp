#include "Library.h"

//CHUC NANG 4 VA 5
void printForm(form f)
{
    cout << "Ma doc gia: " << f.reader_id << endl;
    cout << "Ngay muon: " << f.borrow_day.dd << "/" << f.borrow_day.mm << "/" << f.borrow_day.yyyy << endl;
    cout << "Ngay tra du kien: " << f.expected_return_day.dd << "/" <<
        f.expected_return_day.mm << "/" << f.expected_return_day.yyyy << endl;
    if (f.return_day.dd > 0 && f.return_day.mm > 0 && f.return_day.yyyy > 0)
    {
        cout << "Ngay tra: " << f.return_day.dd << "/" << f.return_day.mm << "/"
            << f.return_day.yyyy << endl;
    }
    cout << "So sach muon: " << f.quantity << endl;
    cout << "ID sach muon: \n";
    for (int i = 0; i < f.quantity; ++i)
    {
        cout << "\t" << f.isbn_list[i] << endl;
    }
}
form borrowForm()
{
    form f;
    int i;
    cout << "Nhap ma doc gia: ";
    cin >> f.reader_id;
    cout << "Nhap ngay thang nam muon: ";
    cin >> f.borrow_day.dd >> f.borrow_day.mm >> f.borrow_day.yyyy;
    cout << "Nhap ngay thang nam tra du kien: ";
    cin >> f.expected_return_day.dd >> f.expected_return_day.mm >> f.expected_return_day.yyyy;
    f.return_day.dd = f.return_day.mm = f.return_day.yyyy = -1;
    cout << "Nhap so luong sach muon: ";
    cin >> f.quantity;
    cin.ignore();
    char temp[100];
    f.isbn_list = new char* [f.quantity];
    for (i = 0; i < f.quantity; i++) {
        cout << "Nhap id sach thu " << i + 1 << ": ";
        cin.getline(temp, 100);
        size_t n = strlen(temp);
        f.isbn_list[i] = new char[n + 1];
        strcpy(f.isbn_list[i], temp);
    }
    return f;
}
form getReturnForm(int check) {
    form f;
    fstream filein;
    filein.open("rform.txt", ios_base::in);
    int n;
    filein >> n;
    for (int i = 0; i < n; i++) {
        f = getform(filein);
        if (f.reader_id == check)
            return f;
        removeFormTempMem(f);
    }
    filein.close();
    f.reader_id = -1;
    return f;
}
void returnForm(form& f)
{
    cout << "Ma doc gia: " << f.reader_id << endl;
    cout << "Ngay muon: " << f.borrow_day.dd << "/" << f.borrow_day.mm << "/" << f.borrow_day.yyyy << endl;
    cout << "Ngay tra du kien: " << f.expected_return_day.dd << "/" <<
        f.expected_return_day.mm << "/" << f.expected_return_day.yyyy << endl;
    cout << "Ngay tra: ";
    cin >> f.return_day.dd >> f.return_day.mm >> f.return_day.yyyy;
    cout << "So sach muon: " << f.quantity << endl;
    cout << "ID sach muon: \n";
    for (int i = 0; i < f.quantity; ++i)
    {
        cout << "\t" << f.isbn_list[i] << endl;
    }
}
void removeFormTempMem(form& f) {
    for (int i = 0; i < f.quantity; i++)
        delete[] f.isbn_list[i];
    delete[]f.isbn_list;
}
void writeForm(fstream& fo, form f) {
    fo << f.reader_id << endl;
    fo << f.borrow_day.dd << "/" << f.borrow_day.mm << "/" << f.borrow_day.yyyy << endl;
    fo << f.expected_return_day.dd << "/" <<
        f.expected_return_day.mm << "/" << f.expected_return_day.yyyy << endl;
    fo << f.return_day.dd << "/" << f.return_day.mm << "/" << f.return_day.yyyy << endl;
    fo << f.quantity << endl;
    for (int i = 0; i < f.quantity; ++i)
    {
        fo << f.isbn_list[i] << ",";
    }
    fo << "\n";
}
void printReturnFormToFile(form f)
{
    fstream fi, fileTemp;
    fi.open("rform.txt", ios_base::in);
    fileTemp.open("temp.txt", ios_base::out);
    int n;
    fi >> n;
    form ftemp;
    fileTemp << n << endl;
    for (int i = 0; i < n; i++) {
        ftemp = getform(fi);
        if (ftemp.reader_id == f.reader_id)
            writeForm(fileTemp, f);
        else
            writeForm(fileTemp, ftemp);
        removeFormTempMem(ftemp);
    }
    fi.close();
    fileTemp.close();
    remove("rform.txt");
    rename("temp.txt", "rform.txt");
}
void printBorrowFormToFile(form f)
{
    fstream fi, fileTemp;
    fi.open("rform.txt", ios_base::in);
    fileTemp.open("temp.txt", ios_base::out);
    int n;
    fi >> n;
    form ftemp;
    fileTemp << n + 1 << endl;
    for (int i = 0; i < n; i++) {
        ftemp = getform(fi);
        writeForm(fileTemp, ftemp);
        removeFormTempMem(ftemp);
    }
    writeForm(fileTemp, f);
    removeFormTempMem(f);
    fi.close();
    fileTemp.close();
    remove("rform.txt");
    rename("temp.txt", "rform.txt");
}
form getform(fstream& filein) {
    form f;
    char temp[50];
    filein >> f.reader_id;
    filein >> f.borrow_day.dd;
    filein.ignore();
    filein >> f.borrow_day.mm;
    filein.ignore();
    filein >> f.borrow_day.yyyy;
    filein >> f.expected_return_day.dd;
    filein.ignore();
    filein >> f.expected_return_day.mm;
    filein.ignore();
    filein >> f.expected_return_day.yyyy;
    filein >> f.return_day.dd;
    filein.ignore();
    filein >> f.return_day.mm;
    filein.ignore();
    filein >> f.return_day.yyyy;
    filein >> f.quantity;
    filein.ignore();
    int n;
    f.isbn_list = new char* [f.quantity];
    for (int i = 0; i < f.quantity; ++i)
    {
        filein.getline(temp, 50, ',');
        n = strlen(temp) + 1;
        f.isbn_list[i] = new char[n];
        strcpy(f.isbn_list[i], temp);
    }
    return f;
}
int ReadersStatisticsByGender(fstream& filein, short int gender) {
    int n;
    int total = 0;
    filein >> n;
    filein.ignore(8);
    for (int i = 0; i < n; i++) {
        reader ri = reader_list(filein);
        if (gender == ri.gender) {
            total++;
        }
        _delete(ri);
    }
    return total;
}