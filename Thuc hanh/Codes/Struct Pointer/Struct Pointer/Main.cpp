#include "Struct Pointer.h"

int main()
{
	int menu;
	cout << "--MENU INSTRUCTIONS--\n";
	cout << "Nhap 1 neu thay muon kiem tra struct phanSo.\n";
	cout << "Nhap 2 neu thay muon kiem tra struct duongTron.\n";
	cout << "Nhap so bat ky de thoat khoi chuong trinh.\n";
	cout << "Nhap muc can kiem tra:";
	cin >> menu;
	switch (menu)
	{
	case 1:
		phanSo * ps, k;
		int n;
		cout << "Nhap so phan tu trong day: ";
		cin >> n;
		ps = new phanSo[n];
		cout << "Nhap day cac phan so co " << n << " phan tu:\n";
		nhapDayPS(ps, n);
		xuatDayPS(ps, n);
		cout << "Tong cua day phan so la: ";
		xuatPS(&tongDayPS(ps, n));
		cout << endl;
		thayThePS(ps, n);
		cout << "Day phan so sau khi toi gian: ";
		xuatDayPS(ps, n);
		sapXepPS(ps, n);
		cout << "Day phan so sau khi sap xep tang dan: ";
		xuatDayPS(ps, n);
		cout << "Nhap phan so can tim trong day: ";
		nhapPS(&k);
		k = toiGian(k);
		if (timK(ps, n, k) == 1) cout << "Phan so can tim co trong day.\n";
		else cout << "Phan so can tim khong co trong day.\n";
		delete[]ps;
		break;
	case 2:
		duongTron * c;
		int n;
		cout << "Nhap so luong duong tron trong mang: ";
		cin >> n;
		c = new duongTron[n];
		mangDuongTron(c, n);
		sapXepDuongTron(c, n);
		cout << "Mang cac duong tron sau khi sap xep tang dan theo dien tich:\n";
		xuatMangDuongTron(c, n);
		delete[]c;
	default:
		cout << "KET THUC CHUONG TRINH.";
		break;
	}
	/*phanSo* ps, k;
	int n;
	cout << "Nhap so phan tu trong day: ";
	cin >> n;
	ps = new phanSo[n];
	cout << "Nhap day cac phan so co " << n << " phan tu:\n";
	nhapDayPS(ps, n);
	xuatDayPS(ps, n);
	cout << "Tong cua day phan so la: ";
	xuatPS(&tongDayPS(ps, n));
	cout << endl;
	thayThePS(ps, n);
	cout << "Day phan so sau khi toi gian: ";
	xuatDayPS(ps, n);
	sapXepPS(ps, n);
	cout << "Day phan so sau khi sap xep tang dan: ";
	xuatDayPS(ps, n);
	cout << "Nhap phan so can tim trong day: ";
	nhapPS(&k);
	k = toiGian(k);
	if (timK(ps, n, k) == 1) cout << "Phan so can tim co trong day.\n";
	else cout << "Phan so can tim khong co trong day.\n";
	delete[]ps*/

	/*duongTron* c;
	int n;
	cout << "Nhap so luong duong tron trong mang: ";
	cin >> n;
	c = new duongTron[n];
	mangDuongTron(c, n);
	sapXepDuongTron(c, n);
	cout << "Mang cac duong tron sau khi sap xep tang dan theo dien tich:\n";
	xuatMangDuongTron(c, n);
	delete[]c;*/
	return 0;
}