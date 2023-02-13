//
// Created by Nguyen Tien on 09-Feb-23.
//
#include <iostream>
#define MAX 100
using namespace std;
struct PhanSo{
    int TuSo;
    int MauSo;
};
void NhapPhanSo(PhanSo a[MAX][MAX], int &n, int &m){
    cout << "Nhap so hang = " ;
    cin >> n ;
    cout << "Nhap so cot = ";
    cin >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << "a[" << i << "," << j << "]" << endl;
            cout << "Tu so = ";
            cin >> a[i][j].TuSo;
            cout << "Mau so = ";
            cin >> a[i][j].MauSo;
        }
    }
}
void XuatPhanSo(const PhanSo a[MAX][MAX], int n, int m){
    cout << "Xuat danh sach phan so" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << "a[" << i << "," << j << "] = " << a[i][j].TuSo << "/" <<a[i][j].MauSo << endl;
        }
    }
}
int UCLN(int tuso, int mauso){
    while(tuso != mauso){
        if (tuso > mauso) tuso -= mauso;
        else mauso -= tuso;
    }
    return tuso;
}
void ToiGianPhanSo(PhanSo a[MAX][MAX], int n, int m){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int u = UCLN(a[i][j].TuSo, a[i][j].MauSo);
            a[i][j].TuSo = a[i][j].TuSo / u;
            a[i][j].MauSo = a[i][j].MauSo / u;
        }
    }
}
PhanSo TongMaTran(PhanSo a[MAX][MAX], int n, int m){
    PhanSo kq;
    kq.TuSo = 0;
    kq.MauSo = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            kq.TuSo = kq.TuSo*a[i][j].MauSo + a[i][j].TuSo*kq.MauSo;
            kq.MauSo = kq.MauSo*a[i][j].MauSo;
        }
    }
    int u = UCLN(kq.TuSo, kq.MauSo);
    kq.TuSo = kq.TuSo / u;
    kq.MauSo = kq.MauSo / u;
    return kq;
}
PhanSo PhanSoLonNhat(PhanSo a[MAX][MAX], int n, int m){
    PhanSo max;
    max.TuSo = 0;
    max.MauSo = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
           double p1 = max.TuSo * 1.0 / max.MauSo;
           double p2 = a[i][j].TuSo * 1.0 / a[i][j].MauSo;
           if(p2 > p1){
               max.TuSo = a[i][j].TuSo;
               max.MauSo = a[i][j].MauSo;
           }
        }
    }
    return max;
}
void TongDong(PhanSo a[MAX][MAX], int n, int m){
    for (int i = 0; i < n; ++i) {
        PhanSo kq;
        kq.TuSo = 0;
        kq.MauSo = 1;
        for (int j = 0; j < m; ++j) {
            kq.TuSo = kq.TuSo * a[i][j].MauSo + a[i][j].TuSo * kq.MauSo;
            kq.MauSo = kq.MauSo * a[i][j].MauSo;
        }
        int u = UCLN(kq.TuSo, kq.MauSo);
        kq.TuSo = kq.TuSo / u;
        kq.MauSo = kq.MauSo / u;
        cout << "Tong dong thu " << i << " = " << kq.TuSo << "/" << kq.MauSo << endl;
    }
}
void TimMaxDong(PhanSo a[MAX][MAX], int n, int m){
    for (int i = 0; i < n; ++i) {
        PhanSo max = a[i][0];
        for (int j = 0; j < m; ++j) {
            double p1 = max.TuSo * 1.0 / max.MauSo;
            double p2 = a[i][j].TuSo * 1.0 / a[i][j].MauSo;
            if(p2 > p1){
                max = a[i][j];
            }
        }
        cout << "Phan so lon nhat trong dong " << i << " la = " << max.TuSo << "/" << max.MauSo << endl;
    }
}
int main(){
    //Khai bao phan so co toi da 100 phan tu
    PhanSo a[MAX][MAX];
    int n, m;
    NhapPhanSo(a, n ,m);
    ToiGianPhanSo(a, n, m);
    XuatPhanSo(a, n , m);
    PhanSo sum = TongMaTran(a, n, m);
    PhanSo max = PhanSoLonNhat(a, n, m);
    cout << "Tong ma tran la: " << sum.TuSo << "/" << sum.MauSo << endl;
    cout << "Phan so lon nhat la: " << max.TuSo << "/" << max.MauSo << endl;
    TongDong(a, n, m);
    TimMaxDong(a, n, m);
    return 0;
}