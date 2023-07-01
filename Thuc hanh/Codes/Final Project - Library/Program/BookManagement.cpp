#include "Library.h"

//CHUC NANG 3
book_info getBookInfo(fstream& filein)
{
    book_info book;
    book.isbn = new char[20];
    book.book_name = new char[100];
    book.author = new char[50];
    book.publisher = new char[50];
    book.category = new char[50];
    filein.getline(book.isbn, 20, ',');
    filein.getline(book.book_name, 100, ',');
    filein.getline(book.author, 50, ',');
    filein.getline(book.publisher, 50, ',');
    filein >> book.publication_year;
    filein.ignore();
    filein.getline(book.category, 50, ',');
    filein >> book.price;
    filein.ignore();
    filein >> book.quantity;
    filein.ignore();
    return book;
}
void deleteBookInfoTempMem(book_info& b)
{
    delete[]b.isbn;
    delete[]b.book_name;
    delete[]b.author;
    delete[]b.publisher;
    delete[]b.category;
}
int quantityOfAllBooks(fstream& f)
{
    char k;
    int i = 1;
    do {
        f.seekg(-i, SEEK_END);
        f >> k;
        i++;
    } while (k != ',');
    f.seekg(-(i - 2), SEEK_END);
    int n;
    f >> n;
    f.seekg(SEEK_SET);
    return n;
}

void printBookInfo(book_info b)
{
    cout << b.isbn << '\t' << b.book_name << "\t" << b.author << '\t' << b.publisher << '\t'
        << b.publication_year << '\t' << b.category << '\t'
        << b.price << "\t\t" << b.quantity << endl;
}
void printBookInfoToFile(fstream& f, book_info newOne) {
    f << newOne.isbn << "," << newOne.book_name << ","
        << newOne.author << "," << newOne.publisher << ","
        << newOne.publication_year << "," << newOne.category << ","
        << newOne.price << "," << newOne.quantity << endl;
}
void printBookList()
{
    fstream f;
    f.open("book.csv", ios::in);
    if (f.fail()) cout << "Khong the mo file quan ly sach.\n";
    else
    {
        int n = quantityOfAllBooks(f);
        cout << "Ma sach\t\tTen sach\t\tTac gia\t\tNXB\tNamXB\tThe loai\tGia sach\tSo luong\n\n";
        for (int i = 0; i < n; ++i)
        {
            book_info book = getBookInfo(f);
            printBookInfo(book);
            deleteBookInfoTempMem(book);
        }
        f.close();
        cout << endl;
    }
}
book_info newBook()
{
    book_info book;
    book.isbn = new char[20];
    cout << "Nhap ID sach: ";
    cin.getline(book.isbn, 20);
    book.book_name = new char[100];
    cout << "Nhap ten sach: ";
    cin.getline(book.book_name, 100);
    book.author = new char[50];
    cout << "Nhap ten tac gia: ";
    cin.getline(book.author, 50);
    book.publisher = new char[50];
    cout << "Nhap ten nha xuat ban: ";
    cin.getline(book.publisher, 50);
    cout << "Nhap nam xuat ban: ";
    cin >> book.publication_year;
    book.category = new char[50];
    cout << "Nhap the loai sach: ";
    cin.ignore();
    cin.getline(book.category, 50);
    cout << "Nhap gia sach: ";
    cin >> book.price;
    cout << "Nhap so luong sach: ";
    cin >> book.quantity;
    return book;
}
bool alreadyExistedBookISBN(fstream& f, book_info book)
{
    int n = quantityOfAllBooks(f);
    for (int i = 0; i < n; ++i)
    {
        book_info temp = getBookInfo(f);
        if (_stricmp(book.isbn, temp.isbn) == 0)
        {
            return true;
        }
    }
    return false;
}
bool alreadyExistedBookName(fstream& f, book_info book)
{
    int n = quantityOfAllBooks(f);
    for (int i = 0; i < n; ++i)
    {
        book_info temp = getBookInfo(f);
        if (_stricmp(book.book_name, temp.book_name) == 0)
        {
            return true;
        }
    }
    return false;
}

void addBook()
{
    fstream f, file_temp;
    cout << "NHAP THONG TIN SACH CAN THEM:\n";
    book_info newOne = newBook();
    bool check(false);
    f.open("book.csv", ios::in);
    if (f.fail()) cout << "Khong the mo file quan ly sach.\n";
    else
    {
        int n = quantityOfAllBooks(f);
        file_temp.open("temp.txt", ios_base::out);
        if (alreadyExistedBookISBN(f, newOne))
        {
            f.seekg(ios::beg);
            for (int i = 0; i < n; i++)
            {
                book_info bf = getBookInfo(f);
                if (strcmp(bf.isbn, newOne.isbn) == 0)
                {
                    bf.quantity += newOne.quantity;
                    printBookInfoToFile(file_temp, bf);
                }
                else
                    printBookInfoToFile(file_temp, bf);
            }
        }
        else
        {
            f.seekg(ios::beg);
            for (int i = 0; i < n; ++i)
            {
                book_info bf = getBookInfo(f);
                printBookInfoToFile(file_temp, bf);
            }

            file_temp << newOne.isbn << "," << newOne.book_name << ","
                << newOne.author << "," << newOne.publisher << ","
                << newOne.publication_year << "," << newOne.category << ","
                << newOne.price << "," << newOne.quantity << endl;

            n++;
        }
        file_temp << ",,,,,,," << n;
        file_temp.close();
        f.close();
        remove("book.csv");
        rename("temp.txt", "book.csv");
    }
}
void editBookInfo()
{
    fstream fi, fo;
    book_info b;
    b.isbn = new char[50];
    cout << "Nhap ID sach can chinh sua thong tin: ";
    cin.getline(b.isbn, 50);

    fi.open("book.csv", ios::in);
    if (alreadyExistedBookISBN(fi, b) == false)
    {
        cout << "Khong ton tai sach co ID nhu tren.\n";
        fi.close();
        return;
    }
    else
    {
        fo.open("temp.txt", ios::out);
        cout << "Nhap thong tin sach moi:\n";
        book_info newOne = newBook();
        int n = quantityOfAllBooks(fi);

        for (int i = 0; i < n; ++i)
        {
            book_info bf = getBookInfo(fi);
            if (strcmp(bf.isbn, b.isbn) == 0)
            {
                printBookInfoToFile(fo, newOne);
            }
            else
                printBookInfoToFile(fo, bf);
        }
        fo << ",,,,,,," << n;
    }
    fo.close();
    fi.close();
    remove("book.csv");
    rename("temp.txt", "book.csv");
}
void deleteBookInfo()
{
    fstream fi, fo;
    book_info b;
    b.isbn = new char[50];
    cout << "Nhap ID sach can xoa thong tin: ";
    cin.getline(b.isbn, 50);

    fi.open("book.csv", ios::in);
    if (alreadyExistedBookISBN(fi, b) == false)
    {
        cout << "Khong ton tai sach co ID nhu tren.\n";
        fi.close();
        return;
    }
    else
    {
        fo.open("temp.txt", ios::out);
        int n = quantityOfAllBooks(fi);

        for (int i = 0; i < n; ++i)
        {
            book_info bf = getBookInfo(fi);
            if (strcmp(bf.isbn, b.isbn) == 0)
            {

            }
            else
                printBookInfoToFile(fo, bf);
        }
        n--;
        fo << ",,,,,,," << n;
    }
    fo.close();
    fi.close();
    remove("book.csv");
    rename("temp.txt", "book.csv");
}
void findBookISBN()
{
    fstream f;
    f.open("book.csv", ios::in);
    book_info b;
    b.isbn = new char[50];
    cout << "Nhap ID sach can tim thong tin: ";
    cin.getline(b.isbn, 50);
    if (alreadyExistedBookISBN(f, b))
    {
        cout << "\nMa sach\t\tTen sach\t\tTac gia\t\tNXB\tNamXB\tThe loai\tGia sach\tSo luong\n";
        printBookInfo(findBookISBN(f, b));
    }
    else cout << "Khong ton tai sach co ID nhu tren.\n";
    delete[]b.isbn;
    f.close();
}
book_info findBookISBN(fstream& f, book_info b)
{
    f.seekg(ios::beg);
    int n = quantityOfAllBooks(f);

    for (int i = 0; i < n; ++i)
    {
        book_info bf = getBookInfo(f);
        if (strcmp(bf.isbn, b.isbn) == 0)
            return bf;
    }
}
void findBookName()
{
    fstream f;
    f.open("book.csv", ios::in);
    book_info b;
    b.book_name = new char[100];
    cout << "Nhap ten sach can tim thong tin: ";
    cin.getline(b.book_name, 100);
    if (alreadyExistedBookName(f, b))
    {
        cout << "\nMa sach\t\tTen sach\t\tTac gia\t\tNXB\tNamXB\tThe loai\tGia sach\tSo luong\n";
        printBookInfo(findBookName(f, b));
    }
    else cout << "Khong ton tai sach co ten nhu tren.\n";
    delete[]b.book_name;
    f.close();
}
book_info findBookName(fstream& f, book_info b)
{
    f.seekg(ios::beg);
    int n = quantityOfAllBooks(f);

    for (int i = 0; i < n; ++i)
    {
        book_info bf = getBookInfo(f);
        if (_stricmp(bf.book_name, b.book_name) == 0)
            return bf;
    }
}