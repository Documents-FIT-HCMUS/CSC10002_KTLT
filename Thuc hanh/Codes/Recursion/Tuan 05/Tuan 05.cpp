#include <iostream>
#include <cmath>
#define max 1000
using namespace std;

double bai1(int n)
{
	if (n == 1) return 1;
	return (1.0 / (n*1.0)) + bai1(n - 1);
}
int bai2(int n)
{
	if (n == 0) return 1;
	return n * bai2(n - 1);
} 
int bai3(int x, int n)
{
	if (n == 1) return x;
	return pow(x, n) + bai3(x, n - 1);
}
int bai4(int x, int n)
{
	if (n == 0) return x;
	return pow(x, 2 * n + 1) + bai4(x, n - 1);;
}
double bai5(int x, int n)
{
	if (n == 1) return x;
	return (pow(x, n) * 1.0 / bai2(n) * 1.0) + bai5(x, n - 1);
}
long int bai6(int n, int m)
{
	if (n == 0) return 1;
	long int s(0);
	for (int i = m - n + 1; i <= m; ++i) s += i * i * bai6(m - i, m);
	return s;
}
int bai7(int n)
{
	if (n == 0) return 0;
	return bai7(n / 10) + 1;
}
int bai8(int n)
{
	if (n == 0) return 0;
	return bai8(n / 10) + n % 10;
}
int bai9(int n)
{
	if (n < 10)
		if (n % 2 == 0) return 0;
		else return 1;
	int dem = bai9(n / 10);
	if ((n % 10) % 2 == 0) return dem;
	else return dem + 1;
}
int bai10(int n)
{
	if (n < 10)
		if (n % 2 == 0) return 1;
		else return 0;
	int dem = bai10(n / 10);
	if ((n % 10) % 2 == 0) return dem + 1;
	else return dem;
}

void nhapMang(int a[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << "Nhap a[" << i << "] = ";
		cin >> a[i];
	}
}
bool ngto(int n)
{
	if (n < 2) return false;
	for (int i = 2; i < n; ++i)
		if (n % i == 0) return false;
	return true;
}
int bai11(int a[], int n, int x, int y)
{
	if (x == y) return a[x] % 2 == 0 ? a[x] : 0;
	int tong1, tong2;
	int z = (x + y) / 2;
	tong1 = bai11(a, n, x, z);
	tong2 = bai11(a, n, z + 1, y);
	return tong1 + tong2;
}
int bai12(int a[], int n, int x, int y)
{
	if (x == y) return ngto(a[x]) ? a[x] : 1;
	int tich1, tich2;
	int z = (x + y) / 2;
	tich1 = bai12(a, n, x, z);
	tich2 = bai12(a, n, z + 1, y);
	return tich1 * tich2;
}
int bai13(int a[], int n)
{
	int kq1(1);
	if (a[n - 1] < 0) kq1 *= a[n - 1];
	if (n == 1) return kq1;
	int kq2(bai13(a, n - 1));
	return kq1 * kq2;
}
int bai14(int a[], int n)
{
	int dem1(0);
	if (a[n - 1] < 0) ++dem1;
	if (n == 1) return dem1;
	int dem2(bai14(a, n - 1));
	return dem1 + dem2;
}
int bai15(int a[], int n)
{
	int max1(INT_MIN);
	if (a[n - 1] > max1) max1 = a[n - 1];
	if (n == 1) return max1;
	int max2(bai15(a, n - 1));
	return max1 > max2 ? max1 : max2;
}
int bai16(int a[], int n, int x)
{
	int dem1(0);
	if (a[n - 1] == x) ++dem1;
	if (n == 1) return dem1;
	int dem2(bai16(a, n - 1, x));
	return dem1 + dem2;
}
int bai17(int a[], int n)
{
	int dem1(0);
	if (a[n - 1] > 0) ++dem1;
	if (n == 1) return dem1;
	int dem2(bai17(a, n - 1));
	return dem1 + dem2;
}
int daXuatHien(int a[], int n, int x)
{
	for (int i = 0; i < n; ++i)
		if (a[i] == x) return false;
	return true;
}
int bai18(int a[], int n)
{
	if (n == 1) return 1;
	int dem = bai18(a, n - 1);
	if (!daXuatHien(a, n - 1, a[n - 1])) return dem;
	else return dem + 1;
}


int main()
{
	int menu, n, x;
	int a[max];
	cout << "1.  Tinh tong S = 1/1 + 1/2 + ... + 1/n.\n";
	cout << "2.  Tinh n giai thua: 1 x 2 x 3 x ... x n.\n";
	cout << "3.  Tinh tong S = x + x^2 + x^3 + .. + x^n.\n";
	cout << "4.  Tinh tong S = x + x^3 + x^5 + .. + x^(2n+1).\n";
	cout << "5.  Tinh tong S = x + x^2/2! + ... + x^n/n!.\n";
	cout << "6.  Tinh tong S(n), X(0) = 1, X(n) = n^2*S(0) + (n-1)^2*S(1) + ... + 2^2*S(n - 2) + 1^2*S(n - 1).\n";
	cout << "7.  Dem so luong chu so cua mot so nguyen duong.\n";
	cout << "8.  Tinh tong cac chu so cua mot so nguyen duong.\n";
	cout << "9.  Dem so luong chu so le cua mot so nguyen duong.\n";
	cout << "10. Kiem tra mot so nguyen duong co toan chu so chan hay khong.\n";
	cout << "11. Tinh tong cac phan tu chan trong mang mot chieu.\n";
	cout << "12. Tinh tong cac so nguyen to trong mang mot chieu.\n";
	cout << "13. Tinh tich cac so am trong mang mot chieu.\n";
	cout << "14. Kiem tra mang co chua toan bo cac so am hay khong.\n";
	cout << "15. Tim so lon nhat trong mang mot chieu.\n";
	cout << "16. Dem so luong phan tu bang so cho truoc trong mang mot chieu.\n";
	cout << "17. Dem so luong so nguyen duong trong mang mot chieu.\n";
	cout << "18. Dem so luong phan tu phan biet trong mang mot chieu.\n";
	cout << "0.  Thoat khoi chuong trinh.\n";
	do
	{
		cout << "Nhap bai can kiem tra (tu 1 den 18):";
		cin >> menu;
		switch (menu)
		{
		case 1:
			cout << "Nhap n: ";
			cin >> n;
			cout << "Tong la: " << bai1(n) << endl;
			break;
		case 2:
			cout << "Nhap n: ";
			cin >> n;
			cout << "Ket qua la: " << bai2(n) << endl;
			break;
		case 3:
			cout << "Nhap x: ";
			cin >> x;
			cout << "Nhap n: ";
			cin >> n;
			cout << "Ket qua la: " << bai3(x, n) << endl;
			break;
		case 4:
			cout << "Nhap x: ";
			cin >> x;
			cout << "Nhap n: ";
			cin >> n;
			cout << "Ket qua la: " << bai4(x, n) << endl;
			break;
		case 5:
			cout << "Nhap x: ";
			cin >> x;
			cout << "Nhap n: ";
			cin >> n;
			cout << "Ket qua la: " << bai5(x, n) << endl;
			break;
		case 6:
			cout << "Nhap n: ";
			cin >> n;
			cout << "Ket qua la: " << bai6(n, n) << endl;
			break;
		case 7:
			cout << "Nhap n: ";
			cin >> n;
			cout << "Ket qua la: " << bai7(n) << endl;
			break;
		case 8:
			cout << "Nhap n: ";
			cin >> n;
			cout << "Ket qua la: " << bai8(n) << endl;
			break;
		case 9:
			cout << "Nhap n: ";
			cin >> n;
			cout << "Ket qua la: " << bai9(n) << endl;
			break;
		case 10:
			cout << "Nhap n: ";
			cin >> n;
			if (bai10(n) == bai7(n)) cout << "Cac chu so deu la so chan.\n";
			else cout << "Co it nhat mot chu so le.\n" ;
			break;
		case 11:
			cout << "Nhap so phan tu trong mang:";
			cin >> n;
			nhapMang(a, n);
			cout << "Ket qua la: " << bai11(a, n, 0, n - 1) << endl;
			break;
		case 12:
			cout << "Nhap so phan tu trong mang:";
			cin >> n;
			nhapMang(a, n);
			cout << "Ket qua la: " << bai12(a, n, 0, n - 1) << endl;
			break;
		case 13:
			cout << "Nhap so phan tu trong mang:";
			cin >> n;
			nhapMang(a, n);
			cout << "Ket qua la: " << bai13(a, n) << endl;
			break;
		case 14:
			cout << "Nhap so phan tu trong mang:";
			cin >> n;
			nhapMang(a, n);
			if (n == bai14(a, n)) cout << "Mang chua toan bo so am.\n";
			else cout << "Mang co chua it nhat mot so duong.\n";
			break;
		case 15:
			cout << "Nhap so phan tu trong mang:";
			cin >> n;
			nhapMang(a, n);
			cout << "Ket qua la: " << bai15(a, n) << endl;
			break;
		case 16:
			cout << "Nhap so phan tu trong mang:";
			cin >> n;
			nhapMang(a, n);
			cout << "Nhap gia tri x:";
			cin >> x;
			cout << "Ket qua la: " << bai16(a, n, x) << endl;
			break;
		case 17:
			cout << "Nhap so phan tu trong mang:";
			cin >> n;
			nhapMang(a, n);
			cout << "Ket qua la: " << bai17(a, n) << endl;
			break;
		case 18:
			cout << "Nhap so phan tu trong mang:";
			cin >> n;
			nhapMang(a, n);
			cout << "Ket qua la: " << bai18(a, n) << endl;
			break;
		default:
			cout << "KET THUC CHUONG TRINH!";
			break;
		}
	} while (menu != 0);
	cout << endl;
	return 0;
}