#include "Struct Pointer.h"

void nhapPS(phanSo* ps)
{
	cout << "Nhap tu so va mau so: ";
	cin >> ps->tu >> ps->mau;
}
void xuatPS(phanSo* ps)
{
	cout << ps->tu << "/" << ps->mau << " ";
}
void quyDongPS(phanSo* a, phanSo* b)
{
	int temp(a->mau);
	a->tu *= b->mau;
	a->mau *= b->mau;
	b->tu *= temp;
	b->mau *= temp;
}
phanSo tongPS(phanSo a, phanSo b)
{
	phanSo kq;
	quyDongPS(&a, &b);
	kq.tu = a.tu + b.tu;
	kq.mau = a.mau;
	return kq;
}
phanSo hieuPS(phanSo a, phanSo b)
{
	phanSo kq;
	quyDongPS(&a, &b);
	kq.tu = a.tu - b.tu;
	kq.mau = a.mau;
	return kq;
}
phanSo tichPS(phanSo a, phanSo b)
{
	phanSo kq;
	kq.tu = a.tu * b.tu;
	kq.mau = a.mau * b.mau;
	return kq;
}
phanSo thuongPS(phanSo a, phanSo b)
{
	int temp(b.tu);
	b.tu = b.mau;
	b.mau = temp;
	return tichPS(a, b);
}
phanSo toiGian(phanSo a)
{
	int i;
	for (i = a.tu>a.mau?a.mau:a.tu; i >=0; --i)
	{
		if (a.tu % i == 0 && a.mau % i == 0)
		{
			a.tu /= i;
			a.mau /= i;
			break;
		}
	}
	return a;
}
int soSanhPS(phanSo a, phanSo b)
{
	quyDongPS(&a, &b);
	if (a.tu > b.tu) return 1;
	if (a.tu < b.tu) return -1;
	return 0;
}

void nhapDayPS(phanSo* p, int n)
{
	int i;
	for (i = 0; i < n; ++i)
	{
		cout << "PS " << i + 1 << ": ";
		nhapPS(p + i);
	}
}
phanSo tongDayPS(phanSo* p, int n)
{
	phanSo kq = { 0, 0 };
	int i;
	for (i = 0; i < n; ++i)
		kq = tongPS(kq, *(p + i));
	return kq;
}
void xuatDayPS(phanSo* p, int n)
{
	int i;
	for (i = 0; i < n; ++i)
		xuatPS(p + i);
	cout << endl;
}
void thayThePS(phanSo* p, int n)
{
	int i;
	for (i = 0; i < n; ++i)
		*(p + i) = toiGian(*(p + i));
}
void swapPS(phanSo* a, phanSo* b)
{
	phanSo temp(*a);
	*a = *b;
	*b = temp;
}
void sapXepPS(phanSo* p, int n)
{
	int i, j;
	for (i = 0; i < n - 1; ++i)
		for (j = i + 1; i < n; ++i)
			if (soSanhPS(*(p + i), *(p + j)) == 1) swapPS(p + i, p + j);
}
int timK(phanSo* p, int n, phanSo k)
{
	int i;
	for (i = 0; i < n; ++i)
		if (soSanhPS(*(p + i), k) == 0) return 1;
	return 0;

}


void nhapDuongTron(duongTron* c) 
{
	cout << "Nhap toa do x va y cua tam duong tron: ";
	cin >> c->tam.x >> c->tam.y;
	cout << "Nhap ban kinh duong trong: ";
	cin >> c->r;
}
void xuatDuongTron(duongTron* c)
{
	cout << "Toa do tam la (" << c->tam.x << "," << c->tam.y << "). Ban kinh la " << c->r ;
	cout << endl;
}
double chuVi(duongTron* c)
{
	return (c->r) * 2 * pi;
}
double dienTich(duongTron* c)
{
	return (c->r) * (c->r) * pi;
}
double khoangCach(diem a, diem b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int tuongQuan(duongTron* c, diem a)
{
	if (khoangCach(c->tam, a) > c->r) return 1;
	if (khoangCach(c->tam, a) < c->r) return -1;
	return 0;
}
void mangDuongTron(duongTron* c, int n)
{
	int i;
	for (i = 0; i < n; ++i)
	{
		cout << "Nhap thong tin cho duong trong thu " << i + 1 << endl;
		nhapDuongTron(c + i);
	}
}
void xuatMangDuongTron(duongTron* c, int n)
{
	int i;
	for (i = 0; i < n; ++i)
	{
		cout << "Duong tron thu " << i + 1 << ": ";
		xuatDuongTron(c + i);
	}
}
void swapDuongTron(duongTron* a, duongTron* b)
{
	duongTron temp(*a);
	*a = *b;
	*b = temp;
}
void sapXepDuongTron(duongTron* c, int n)
{
	int i, j;
	for (i = 0; i < n - 1; ++i)
		for (j = i + 1; j < n; ++j)
			if (dienTich(c + i) > dienTich(c + j)) swapDuongTron(c + i, c + j);
}


