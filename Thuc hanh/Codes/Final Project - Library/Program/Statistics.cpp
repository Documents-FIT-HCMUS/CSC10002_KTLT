#include "Library.h"

//CHUC NANG 6
int totalBook()
{
    fstream f;
    int total = 0;
    f.open("book.csv", ios::in);
    int n = quantityOfAllBooks(f);
    for (int i = 0; i < n; ++i)
    {
        book_info temp = getBookInfo(f);
        total += temp.quantity;
        deleteBookInfoTempMem(temp);
    }
    f.close();
    return total;
}
int totalBookByCategory()
{
    fstream f;
    f.open("book.csv", ios::in);
    int n = quantityOfAllBooks(f);
    int total = 0;
    char temp[100];
    cout << "Nhap the loai sach can thong ke: ";
    cin.getline(temp, 100);
    for (int i = 0; i < n; ++i)
    {
        book_info bf = getBookInfo(f);
        if (_stricmp(bf.category, temp) == 0)
            total += bf.quantity;
        deleteBookInfoTempMem(bf);
    }
    f.close();
    return total;
}
int numberOfReader()
{
    fstream f;
    int n;
    f.open(rif, ios::in);
    f >> n;
    f.close();
    return n;
}
int numberOfReaderByGender(short int gender)
{
    fstream f;
    int n;
    int total = 0;
    f.open(rif, ios::in);
    f >> n;
    f.ignore(8);
    for (int i = 0; i < n; i++)
    {
        reader ri = reader_list(f);
        if (ri.gender == gender)
            total++;
        _delete(ri);
    }
    f.close();
    return total;
}
void expired(fstream& filein, fstream& fileReader) {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    date current;
    current.yyyy = 1900 + ltm->tm_year;
    current.mm = 1 + ltm->tm_mon;
    current.dd = ltm->tm_mday;
    int n;
    filein >> n;
    form f;
    reader r;
    for (int i = 0; i < n; i++) {
        f = getform(filein);
        if (f.expected_return_day.yyyy <= current.yyyy)
            if (f.expected_return_day.mm <= current.mm)
                if (f.expected_return_day.dd < current.dd) {
                    r = findReaderByReaderID(fileReader, f.reader_id);
                    if (r.id != -1) {
                        printOneReader(r);
                        _delete(r);
                    }
                    fileReader.clear();
                    fileReader.seekg(ios_base::beg);
                }
        removeFormTempMem(f);
    }
}
int borrowedBook(fstream& filein) {
    int n, total = 0;
    filein >> n;
    form f;
    for (int i = 0; i < n; i++) {
        f = getform(filein);
        total += f.quantity;
        removeFormTempMem(f);
    }
    return total;
}