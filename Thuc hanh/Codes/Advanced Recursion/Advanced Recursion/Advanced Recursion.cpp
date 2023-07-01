#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void test(int n)
{
	for (int i = 1; i <= n; i++)
	{
	}
}

void towerOfHanoi(int n, char A, char C, char B)
{
    if (n == 1)
    {
        cout << "Chuyen dia so 1 tu  " << A << " sang cot  " << C << endl;
        return;
    }
    towerOfHanoi(n - 1, A, B, C);
    cout << "Chuyen dia so " << n << " tu cot  " << A << " sang cot  " << C << endl;
    towerOfHanoi(n - 1, B, C, A);
}

int a[100];
bool ktra(int x, int y) //kiem tra co dat duoc tai vi tri (x,y) khong
{
    for (int i = 1; i <= x - 1; ++i)
    {
        if (a[i] == y) return false; //kiem tra cung cot
        if (abs(i - x) == abs(a[i] - y)) return false; //kiem tra cung duong cheo
    }
    return true;
}
void Try(int i, int n)
{
    for (int j = 1; j <= n; ++j)
    {
        if (ktra(i, j))
        {
            a[i] = j;
            if (i == n)
            {
                /*for (int i = 1; i <= n; ++i) cout << a[i] << " ";
                cout << endl;*/
            }
            Try(i + 1, n);
        }
    }
}

/*int stepX[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int stepY[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
void MaDiTuan(int banCo[20][20], int n, int i, int j, int dem)
{
    if (daCoMotDapAn) return;
    if (i < 0 || j < 0 || i >= n || j >= n || banCo[i][j] != -1)
        return;

    banCo[i][j] = dem;
    dem++;
    if (dem > n * n) {
        XuatKetQuaMDT(banCo, n);
        daCoMotDapAn = true;
        return;
    }

    for (int k = 0; k < 8; k++)
        MaDiTuan(banCo, n, i + stepX[k], j + stepY[k], dem);

    banCo[i][j] = -1;
    dem--;
}
*/

int KQ[16][16] = { 0 };
int p[8] = { -2,-2,-1,-1, 1, 1, 2, 2 };
int q[8] = { -1, 1,-2, 2,-2, 2,-1, 1 };
int d(0), k(0);
void xuat(int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j) cout << KQ[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}
void diChuyen(int n, int x, int y)
{
    d += 1;
    KQ[x][y] = d;
    for (int i = 0; i < n; ++i)
    {
        if (d == n * n) //dem du so luong
        {
            cout << "CAC BUOC DI: \n";
            xuat(n);
            return;
        }
        int u, v;
        u = x;
        v = y;
        for (int j = 0; j < 8; ++j)
        {
            u += p[i];  //di chuyen quan Ma
            v += q[i];
            if (u >= 0 && u < n && v >= 0 && v < n && KQ[u][v] == 0) //kiem tra vi tri (u,v) hop le
                diChuyen(n, u, v);
        }
    }
    d -= 1;
    KQ[x][y] = 0;
}

void XuatKetQuaMDT(int a[16][16], int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}
bool daCoMotDapAn(false);
int stepX[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int stepY[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
bool PosValid(int banCo[16][16], int n, int y, int x) {
    return y >= 0 && y < n&& x >= 0 && x < n&& banCo[y][x] == -1;
}
int KhaNangDi(int banCo[16][16], int n, int y, int x) {
    int result = 0;
    for (int i = 0; i < 8; i++) {
        if (PosValid(banCo, n, x + stepX[i], y + stepY[i]))
            result++;
    }

    return result;
}
bool MaDiTuan(int banCo[16][16], int n, int i, int j, int dem)
{
    if (daCoMotDapAn) return true;
    banCo[i][j] = dem;
    dem++;
    if (dem > n * n) {
        XuatKetQuaMDT(banCo, n);
        daCoMotDapAn = true;
        return true;
    }

    bool gone[8] = { false };

    int leastAccessibility_k, leastAccessibility_num;

    do {
        leastAccessibility_k = -1;
        leastAccessibility_num = 9;

        for (int k = 0; k < 8; k++) {
            if (gone[k]) continue;
            int currentI = i + stepY[k];
            int currentJ = j + stepX[k];
            if (PosValid(banCo, n, currentI, currentJ)) {
                if (KhaNangDi(banCo, n, currentI, currentJ) < leastAccessibility_num) {
                    leastAccessibility_k = k;
                    leastAccessibility_num = KhaNangDi(banCo, n, i + stepY[leastAccessibility_k], j + stepX[leastAccessibility_k]);
                }
            }
            else {
                gone[k] = true;
            }
        }
        if (leastAccessibility_k == -1) {
            banCo[i][j] = -1;
            dem--;
            return false;
        }
        gone[leastAccessibility_k] = true;
    } while (!MaDiTuan(banCo, n, i + stepY[leastAccessibility_k], j + stepX[leastAccessibility_k], dem));

    return false;
}
int main()
{
    int a[16][16] = { -1 };
	auto start = high_resolution_clock::now();
    //towerOfHanoi(13, 'A', 'C', 'B');
    //Try(1, 16);
    //MaDiTuan(a, 24, 0, 0, 1);
    diChuyen(8, 0, 0);
	auto end = high_resolution_clock::now();
	auto executionTime = duration_cast<milliseconds>(end - start);
	cout << "Execution Time: " << executionTime.count() << " ms." << endl;
	return 0;
}
