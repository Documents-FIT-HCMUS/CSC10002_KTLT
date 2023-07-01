#include "Library.h"

//MENU
int mainFunc()
{
    int menu;
    cout << "--- CHON NHOM CHUC NANG MUON THUC HIEN ---\n";
    cout << "0. Dang xuat (thoat khoi chuong trinh).\n";
    cout << "1. Su dung chuc nang he thong\n";
    cout << "2. Quan ly doc gia\n";
    cout << "3. Quan ly sach\n";
    cout << "4. Lap phieu muon sach\n";
    cout << "5. Lap phieu tra sach\n";
    cout << "6. Thong ke co ban\n";
    cout << "Nhap chuc nang: ";
    cin >> menu;
    return menu;
}
int subFunc(short int role, int mainFuncion)
{
    int menu(-1);
    switch (mainFuncion)
    {
    case 1:
        cout << "--- CHUC NANG HE THONG ---\n";
        cout << "0. Tro lai\n";
        cout << "1. Thay doi mat khau\n2. Cap nhat thong tin ca nhan\n";
        if (role == 0) cout << "3. Tao nguoi dung moi\n";
        cout << "Chon chuc nang: ";
        cin >> menu;
        break;
    case 2:
        cout << "--- QUAN LY DOC GIA ---\n";
        cout << "0. Tro lai\n";
        cout << "1. Xem danh sach doc gia\n2. Them doc gia\n3. Chinh sua thong tin doc gia\n";
        cout << "4. Tim kiem doc gia theo cmnd\n5. Tim kiem sach muon theo ho ten\n";
        if (role != 2) cout << "6. Xoa thong tin doc gia\n";
        cout << "Chon chuc nang: ";
        cin >> menu;
        break;
    case 3:
        cout << "--- QUAN LY SACH ---\n";
        cout << "0. Tro lai\n";
        cout << "1. Tim kiem sach theo ISBN\n2. Tim kiem sach theo ten sach\n";
        if (role != 2)
        {
            cout << "3. Xem danh sach cac sach trong thu vien.\n4. Them sach moi\n";
            cout << "5. Chinh sua thong tin sach\n6. Xoa sach\n";
        }
        cout << "Chon chuc nang: ";
        cin >> menu;
        break;
    case 4:
        //PLACEHOLDER
        break;
    case 5:
        //PLACEHOLDER
        break;
    case 6:
        cout << "--- THONG KE CO BAN ---\n";
        cout << "0. Tro lai\n";
        cout << "1. Thong ke so sach dang duoc muon\n2. Thong ke danh sach doc gia bi tre han\n";
        if (role != 2)
        {
            cout << "3. Thong ke so luong sach trong thu vien.\n4. Thong ke so luong sach theo the loai\n";
            cout << "5. Thong ke so luong doc gia\n6. Thong ke so luong doc gia theo gioi tinh\n";
        }
        cout << "Chon chuc nang: ";
        cin >> menu;
        break;
    default:
        break;
    }
    return menu;
}
void mainMenu(int mainFunc, int subFunc, user& currentUser)
{
    fstream fa, fu;
    form f;
    user u;
    char temp[100];
    int n;
    switch (mainFunc)
    {
    case 0:

    case 1:
    {
        if (subFunc == 1)
        {
            cin.ignore();
            cout << "--- THAY DOI MAT KHAU ---\n";
            do
            {
                cout << "Nhap mat khau cu\t: ";
                
                cin.getline(temp, 100);
                encrypt(temp, key);
                if (strcmp(currentUser.lik.password, temp) != 0)
                {
                    cout << "Sai mat khau! Moi nhap lai.\n";
                    continue;
                }
                else
                {
                    cout << "Nhap mat khau moi\t: ";
                    cin.getline(temp, 100);
                    changePassword(fa, currentUser.lik.username, currentUser.lik.password, temp);
                    break;
                }
            } while (true);
        }
        if (subFunc == 2)
        {
            cout << "--- THAY DOI THONG TIN CA NHAN ---\n";
            editUserInfo(currentUser);
            editUserInfo(fu, currentUser);
        }
        if (currentUser.role == 0 && subFunc == 3)
        {
            cout << "--- TAO TAI KHOAN MOI ---\n";
            fa.open(uaf, ios::in);
            cin.ignore();
            u = createNewUser(fa);
            fa.close();
            fa.open(uaf, ios::out | ios::app);
            fu.open(uif, ios::out | ios::app);
            createNewAcc(fa, fu, u);
            fa.close();
            fu.close();
        }
        if (currentUser.role != 0 && subFunc != 1 && subFunc != 2)
            cout << "Khong hop le!!!\n";
        break;
    }
    case 2:
        reader ri;
        switch (subFunc)
        {
        case 1:
            cout << "--- DANH SACH DOC GIA ---\n\n";
            printReader(fu);
            break;
        case 2:
            addNewReaderInfo(fa);
            break;
        case 3:
            cin.ignore();
            cout << "Nhap ten: ";
            cin.getline(temp, 100);
            cout << "Nhap CMND: ";
            cin >> n;
            editReaderInfo(fa, n, temp);
            break;
        case 4:
            cout << "Nhap CMND: ";
            cin >> n;
            fa.open(rif, ios_base::in);
            ri = findReaderID(fa, n);
            fa.close();
            if (ri.id == -1) {
                cout << "Doc gia khong ton tai\n";
                break;
            }
            else
                printOneReader(ri);
            _delete(ri);
            break;
        case 5:
            cin.ignore();
            cout << "Nhap ten: ";
            cin.getline(temp, 100);
            fa.open(rif, ios_base::in);
            ri = findReaderName(fa, temp);
            fa.close();
            if (ri.id == -1) {
                cout << "Doc gia khong ton tai\n";
                break;
            }
            break;
        case 6:
            cin.ignore();
            cout << "Nhap ten: ";
            cin.getline(temp, 100);
            cout << "Nhap CMND: ";
            cin >> n;
            removeReader(fa, n, temp);
            break;
        default:
            break;
        }
        break;
    case 3:
        book_info b;
        switch (subFunc)
        {
        case 1:
            cout << "--- TIM KIEM SACH THEO ISBN ---\n";
            cin.ignore();
            findBookISBN();
            break;
        case 2:
            cout << "--- TIM KIEM SACH THEO TEN SACH ---\n";
            cin.ignore();
            findBookName();
            break;
        case 3:
            cout << "--- DANH SACH TAT CA SACH TRONG THU VIEN ---\n";
            printBookList();
            break;
        case 4:
            cout << "--- THEM SACH ---\n";
            cin.ignore();
            addBook();
            break;
        case 5:
            cout << "--- CHINH SUA THONG TIN SACH ---\n";
            cin.ignore();
            editBookInfo();
            break;
        case 6:
            cout << "--- XOA THONG TIN SACH ---\n";
            cin.ignore();
            deleteBookInfo();
            break;
        default:
            break;
        }
        break;
    case 4:
        cout << "--- LAP PHIEU MUON SACH ---\n";
        f = borrowForm();
        printBorrowFormToFile(f);
        break;
    case 5:
        cout << "--- LAP PHIEU TRA SACH ---\n";
        //fa.open("rform.txt", ios::in);
        //fu.open("reader.csv", ios::in);
        cout << "Nhap ID doc gia: ";
        int n;
        cin >> n;
        f = getReturnForm(n);
        if (f.reader_id == -1)
            cout << "Khong ton tai doc gia co ID nhu tren.";
        else {
            returnForm(f);
        }
        printReturnFormToFile(f);
        removeFormTempMem(f);
        //fa.close();
        //fu.close();
        break;
    case 6:
        switch (subFunc)
        {
        case 1:
            cout << "--- THONG KE SO LUONG SACH DANG DUOC MUON ---\n";
            fa.open("rform.txt", ios::in);
            cout << "So luong sach dang duoc muon la: " << borrowedBook(fa) << endl;
            fa.close();
            break;
        case 2:
            cout << "--- THONG KE DANH SACH DOC GIA TRE HAN ---\n";
            fa.open("rform.txt", ios::in);
            fu.open(rif, ios::in);
            expired(fa, fu);
            fa.close();
            fu.close();
            break;
        case 3:
            cout << "--- THONG KE SO LUONG SACH TRONG THU VIEN ---\n";
            cout << "Tong so luong sach hien co trong thu vien: " << totalBook() << endl;
            break;
        case 4:
            cout << "--- THONG KE SO LUONG SACH THEO THE LOAI ---\n";
            cin.ignore();
            n = totalBookByCategory();
            cout << "Tong so luong sach hien co: " << n << endl;
            break;
        case 5:
            cout << "--- THONG KE SO LUONG DOC GIA ---\n";
            n = numberOfReader();
            cout << "So luong doc gia: " << n << endl;
            break;
        case 6:
            cout << "--- THONG KE SO LUONG DOC GIA THEO GIOI TINH ---\n";
            n = numberOfReaderByGender(1);
            cout << "Nam\t: " << n << endl;
            n = numberOfReaderByGender(2);
            cout << "Nu\t: " << n << endl;
            n = numberOfReaderByGender(3);
            cout << "Khac\t: " << n << endl;
            break;
        default:
            break;
        }
    default:
        break;
    }
}