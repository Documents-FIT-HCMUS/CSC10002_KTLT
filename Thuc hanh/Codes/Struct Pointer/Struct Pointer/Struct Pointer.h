#pragma once
#include <iostream>
#include <cmath>
#define pi 3.14159265359
using namespace std;

struct phanSo { int tu, mau; };

void nhapPS(phanSo*);
void xuatPS(phanSo*);
void quyDongPS(phanSo*, phanSo*);
phanSo tongPS(phanSo, phanSo);
phanSo hieuPS(phanSo, phanSo);
phanSo tichPS(phanSo, phanSo);
phanSo thuongPS(phanSo, phanSo);
phanSo toiGian(phanSo);
int soSanhPS(phanSo, phanSo);

void nhapDayPS(phanSo*, int);
void xuatDayPS(phanSo*, int);
phanSo tongDayPS(phanSo*, int);
void thayThePS(phanSo*, int);
void swapPS(phanSo*, phanSo*);
void sapXepPS(phanSo*, int);
int timK(phanSo*, int, phanSo);


struct diem
{
	int x, y;
};
struct duongTron
{
	diem tam;
	double r;
};
void nhapDuongTron(duongTron*);
void xuatDuongTron(duongTron*);
double chuVi(duongTron*);
double dienTich(duongTron*);
double khoangCach(diem*, diem*);
int tuongQuan(duongTron*, diem*);
void mangDuongTron(duongTron*, int);
void xuatMangDuongTron(duongTron*, int);
void swapDuongTron(duongTron*, duongTron*);
void sapXepDuongTron(duongTron*, int);