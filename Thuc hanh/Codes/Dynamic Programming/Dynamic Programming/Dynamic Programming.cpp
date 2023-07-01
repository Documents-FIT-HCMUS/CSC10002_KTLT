#include <iostream>
#define max 100
using namespace std;

short int fiboTopDown(int n, short int f[])
{
    if (f[n] >= 0) return f[n];
    if (f[n] < 0)
    {
        if (n == 0) 
            f[n] = 0;
        else
            if (n == 1) f[n] = 1;
        else
            f[n] = fiboTopDown(n - 1, f) + fiboTopDown(n - 2, f);
    }
    return f[n] % 10;
}
short int fiboBottomUp(int n, short int f[])
{
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= n; ++i)
        f[i] = (f[i - 1] + f[i - 2]) % 10;
    return f[n];
}

int toHop(int n, int k)
{
    if (k == 0 || k == n) return 1;
    return toHop(n - 1, k) + toHop(n - 1, k - 1);
}
int toHopTopDown(int n, int k, int g[max][max])
{
    if (k > n) return g[k][n] = -1;   //check if the input is valid, if not then exit
    if (g[k][n] > 0) return g[k][n];  //check if the (n,k) is calculated or not, if not then continue
    if (k == 0 || k == n) g[k][n] = 1;//basic results for further calculation
    else 
        g[k][n] = toHopTopDown(n - 1, k, g) + toHopTopDown(n - 1, k - 1, g);//calculate the new (n,k)
    return g[k][n];//and return that value
}
int toHopBottomUp(int n, int k, int g[max][max])
{
    int i, j;
    n;
    k;
    for (i = 0; i <= n; ++i) g[i][0] = 1;

    for (i = 1; i <= n; ++i)
        for (j = 1; j <= k; ++j)
            if (i == 0 || i == j) g[i][j] = 1;

    for (i = 1; i <= n; ++i)
        for (j = 1; j <= k; ++j)
        {
            if (j >= i) continue;
            if (i == 0 || i == j) continue;
            g[i][j] = g[i - 1][j] + g[i - 1][j - 1];
        }

    return g[n][k];
}

int doiTien(int n, int m, int a[])//n: money, S: array contains all values, m: length of S
{
    if (n < 0) return 0;    //less than 0, no soulution
    if (n == 0) return 1;   //money = 1, only 1 way to choose
    if (m <= 0 && n >= 1) return 0;	//money > 0 but there is no more coins, then no solution for this

    // We divide the problem into to parts
    // The result will be equal to
    // Solution that contains at least 1 m-th coin or s[m] + solution that do not contains s[m]
    int kq;
    kq = doiTien(n, m - 1, a) + doiTien(n - a[m - 1], m, a);

    return kq;
}

void input(int a[], int b[], int& n)
{
    cout << "Nhap so luong do vat: ";
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cout << "Nhap khoi luong cua do vat thu " << i + 1 << ": ";
        cin >> a[i];
        cout << "Nhap gia tri cua do vat thu " << i + 1 << ": ";
        cin >> b[i];
    }
}
int maxInt(int a, int b)
{
    if (a > b) return a;
    return b;
}
int knapSack(int W, int w[], int v[], int n)
{
    int i, j;
    int f[max][max];

    for (i = 0; i <= n; ++i) 
    {
        for (j = 0; j <= W; ++j) 
        {
            if (i == 0 || j == 0)
                f[i][j] = 0;
            else 
                if (w[i - 1] <= j)
                f[i][j] = maxInt(v[i - 1] + f[i - 1][j - w[i - 1]], f[i - 1][j]);
            else
                f[i][j] = f[i - 1][j];
        }
    }

    return f[n][W];
}

int main()
{
    int f[max][max];
    int s[10] = { 1,3,4 };
    int menu, n, m(3), W;
    int a[max], b[max];

    cout << "1. Ket hop 1 3 4 sao cho tong chung bang N.\n";
    cout << "2. Bai toan cai tui.\n";
    cout << "Nhap so bat ky de thoat khoi chuong trinh.\n";
    do
    {
        cout << "Nhap muc can kiem tra: ";
        cin >> menu;
        switch (menu)
        {
        case 1:
        {
            
            cout << "Nhap so can quy doi: ";
            cin >> n;
            cout << "Co " << doiTien(n, m, s) << " cach doi.\n";
            break;
        }
        case 2:
        {
            
            cout << "Nhap kich thuoc balo: ";
            cin >> W;
            input(a, b, n);
            cout << "Gia tri toi da co the lay la " << knapSack(W, a, b, n) << endl;
            break;
        }
        default:
            break;
        }
    } while (menu > 0 && menu < 3);

    cout << "KET THUC CHUONG TRINH.\n";
    cout << "LUU Y: Bai lam co tham khao code va y tuong tu trang web geeksforgeeks.\n";
    //LUU Y: Bai lam co tham khao code va y tuong tu trang web geeksforgeeks.

    return 0;
}