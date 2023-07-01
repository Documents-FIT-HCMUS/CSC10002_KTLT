#include <iostream>
#include <fstream>
#define filename1 "input.txt"
#define filename2 "output.txt"
#define MAX 100
using namespace std;

struct phanSo
{
	int tu, mau;
};
struct diem
{
	double x, y;
};
struct duongTron
{
	diem tam;
	double r; //ban kinh duong tron
};
struct sinhVien
{
	char id[10];
	char ht[50];
	float gpa;
};

bool ngto(int x)
{
	if (x < 2) return false;
	for (int i = 0; i < x; ++i)
		if (x % i == 0) return false;
	return true;
}

void docMaTran(int a[MAX][MAX], int& m, int& n)
{
	int i, j;
	fstream f1, f2;
	f1.open(filename1, ios::in);
	if (f1.fail()) cout << "KHONG THE MO TEP TIN.\n";
	else
	{
		for (i = 0; i < m; ++i)
			for (j = 0; j < n; ++j)
				f1 >> a[i][j];
		f1.close();
	}
}
void xuatMaTran(int a[MAX][MAX], int m, int n)
{
	int i, j;
	fstream f1, f2;
	f2.open(filename2, ios::out);
	if (f2.fail()) cout << "KHONG THE MO TEP TIN.\n";
	else
	{
		for (i = 0; i < m; ++i)
		{
			for (j = 0; j < n; ++j)
				f2 << a[i][j] << " ";
			f2 << endl;
		}
		f2.close();
	}
}
void docMN()
{
	int m, n, i;
	fstream f1, f2;
	f1.open(filename1, ios::in);
	f2.open(filename2, ios::out);
	if (f1.fail() || f2.fail()) cout << "KHONG THE MO TEP TIN.\n";
	else
	{
		f1 >> m >> n;
		for (i = m; i <= n; ++i)
			if (ngto(i)) f2 << i << " ";
		f1.close();
		f2.close();
	}
}
void docPhanSo(phanSo& ps)
{
	fstream f1;
	f1.open(filename1, ios::in);
	if (f1.fail()) cout << "KHONG THE MO TEP TIN.\n";
	else
	{
		f1 >> ps.tu >> ps.mau;
		f1.close();
	}
}
void docMangPhanSo(phanSo ps[], int& n)
{
	int i;
	fstream f1;
	f1.open(filename1, ios::in);
	if (f1.fail()) cout << "KHONG THE MO TEP TIN.\n";
	else
	{
		for (i = 0; i < n; ++i)
			f1 >> ps[i].tu >> ps[i].mau;
		f1.close();
	}
}
void docMaTranPhanSo(phanSo ps[MAX][MAX], int& m, int& n)
{
	int i, j;
	fstream f1;
	f1.open(filename1, ios::in);
	if (f1.fail()) cout << "KHONG THE MO TEP TIN.\n";
	else
	{
		for (i = 0; i < m; ++i)
			for (j = 0; j < n; ++j)
				f1 >> ps[i][j].tu >> ps[i][j].mau;
		f1.close();
	}
}
void xuatPhanSo(phanSo ps)
{
	fstream f2;
	f2.open(filename2, ios::out);
	if (f2.fail()) cout << "KHONG THE MO TEP TIN.\n";
	else
	{
		f2 << ps.tu << "/" << ps.mau << " ";
		f2.close();
	}
}
void xuatMangPhanSo(phanSo ps[], int n)
{
	int i;
	fstream f2;
	f2.open(filename2, ios::out);
	if (f2.fail()) cout << "KHONG THE MO TEP TIN.\n";
	else
	{
		for (i = 0; i < n; ++i)
			f2 << ps[i].tu << "/" << ps[i].mau << " ";
		f2.close();
	}
}
void xuatMaTranPhanSo(phanSo ps[MAX][MAX], int& m, int& n)
{
	int i, j;
	fstream f2;
	f2.open(filename2, ios::out);
	if (f2.fail()) cout << "KHONG THE MO TEP TIN.\n";
	else
	{
		for (i = 0; i < m; ++i)
		{
			for (j = 0; j < n; ++j)
				f2 << ps[i][j].tu << "/" << ps[i][j].mau << " ";
			f2 << endl;
		}
		f2.close();
	}
}

void docDiem(diem& a)
{
	fstream f1;
	f1.open(filename1, ios::in);
	if (f1.fail()) cout << "KHONG THE MO TEP TIN.\n";
	else
	{
		f1 >> a.x >> a.y;
		f1.close();
	}
}
void docMangDiem(diem a[], int& n)
{
	int i;
	fstream f1;
	f1.open(filename1, ios::in);
	if (f1.fail()) cout << "KHONG THE MO TEP TIN.\n";
	else
	{
		for (i = 0; i < n; ++i)
			f1 >> a[i].x >> a[i].y;
		f1.close();
	}
}
void docMaTranDiem(diem a[MAX][MAX], int& m, int& n)
{
	int i, j;
	fstream f1;
	f1.open(filename1, ios::in);
	if (f1.fail()) cout << "KHONG THE MO TEP TIN.\n";
	else
	{
		for (i = 0; i < m; ++i)
			for (j = 0; j < n; ++j)
				f1 >> a[i][j].x >> a[i][j].y;
		f1.close();
	}
}
void xuatDiem(diem a)
{
	fstream f2;
	f2.open(filename2, ios::out);
	if (f2.fail()) cout << "KHONG THE MO TEP TIN.\n";
	else
	{
		f2 << "(" << a.x << ", " << a.y << ") ";
		f2.close();
	}
}
void xuatMangDiem(diem a[], int n)
{
	int i;
	fstream f2;
	f2.open(filename2, ios::out);
	if (f2.fail()) cout << "KHONG THE MO TEP TIN.\n";
	else
	{
		for (i = 0; i < n; ++i)
			f2 << "(" << a[i].x << ", " << a[i].y << ") ";
		f2.close();
	}
}
void xuatMaTranDiem(diem a[MAX][MAX], int m, int n)
{
	int i, j;
	fstream f2;
	f2.open(filename2, ios::out);
	if (f2.fail()) cout << "KHONG THE MO TEP TIN.\n";
	else
	{
		for (i = 0; i < m; ++i)
		{
			for (j = 0; j < n; ++j)
				f2 << "(" << a[i][j].x << ", " << a[i][j].y << ") ";
			f2 << endl;
		}
		f2.close();
	}
}

void docDuongTron(duongTron c)
{
	fstream f1;
	f1.open(filename1, ios::in);
	if (f1.fail()) cout << "KHONG THE MO TEP TIN.\n";
	else
	{
		f1 >> c.tam.x >> c.tam.y;
		f1 >> c.r;
		f1.close();
	}
}
void docMangDuongTron(duongTron c[], int& n)
{
	int i;
	fstream f1;
	f1.open(filename1, ios::in);
	if (f1.fail()) cout << "KHONG THE MO TEP TIN.\n";
	else
	{
		for(i=0;i<n;++i)
		f1 >> c[i].tam.x >> c[i].tam.y;
		f1 >> c[i].r;
		f1.close();
	}
}
void docMaTranDuongTron(duongTron c[MAX][MAX], int& m, int& n)
{
	int i, j;
	fstream f1;
	f1.open(filename1, ios::in);
	if (f1.fail()) cout << "KHONG THE MO TEP TIN.\n";
	else
	{
		for (i = 0; i < m; ++i)
			for (j = 0; j < n; ++j)
				f1 >> c[i][j].tam.x >> c[i][j].tam.y >> c[i][j].r;
		f1.close();
	}
}
void xuatDuongTron(duongTron c)
{
	fstream f2;
	f2.open(filename2, ios::out);
	if (f2.fail()) cout << "KHONG THE MO TEP TIN.\n";
	else
	{
		f2 << "(" << c.tam.x << ", " << c.tam.y << ")\n" << "R = " << c.r << "\n\n";
		f2.close();
	}
}
void xuatMangDuongTron(duongTron c[], int n)
{
	int i;
	fstream f2;
	f2.open(filename2, ios::out);
	if (f2.fail()) cout << "KHONG THE MO TEP TIN.\n";
	else
	{
		for (i = 0; i < n; ++i)
			f2 << "(" << c[i].tam.x << ", " << c[i].tam.y << ")\n" << "R = " << c[i].r << "\n\n";
		f2.close();
	}
}
void xuatMaTranDuongTron(duongTron c[MAX][MAX], int m, int n)
{

	int i, j;
	fstream f2;
	f2.open(filename2, ios::out);
	if (f2.fail()) cout << "KHONG THE MO TEP TIN.\n";
	else
	{
		for (i = 0; i < m; ++i)
		{
			for (j = 0; j < n; ++j)
				f2 << "(" << c[i][j].tam.x << "," << c[i][j].tam.y << ")," << "R=" << c[i][j].r << " ";
			f2 << endl;
		}
		f2.close();
	}
}

void docSinhVien(sinhVien& sv)
{
	fstream f;
	f.open(filename1, ios::in);
	if (f.fail()) cout << "KHONG THE MO TEP TIN.";
	else
	{
		f >> sv.id;
		f.getline(sv.ht, 51);
		f >> sv.gpa;
	}
}
void ghiSinhVien(sinhVien sv)
{
	fstream f;
	f.open(filename1, ios::out);
	if (f.fail()) cout << "KHONG THE MO TEP TIN.";
	else
	{
		f << sv.id << " " ;
		f << sv.ht << " ";
		f << sv.gpa << endl;
	}
}

int main()
{
	return 0;
}