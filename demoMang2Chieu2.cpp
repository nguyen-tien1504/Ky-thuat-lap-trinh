//
// Created by Nguyen Tien on 10-Feb-23.
//
#include <iostream>
#include <random>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAX 100
using namespace std;
void NhapMaTran(int a[MAX][MAX], int &n){
    do {
        cout << "Nhap n: ";
        cin >> n;
    } while (n < 5 || n >= 100);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "Nhap a[" << i << "," << j << "] = ";
            cin >> a[i][j];
        }
    }
}
void XuatMaTran(int a[MAX][MAX],const int n){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "a[" << i << "," << j << "] = " << a[i][j] << "\t";
        }
        cout << endl;
    }
}
void SinhMaTran(int a[MAX][MAX], int &n){
//    do {
//        cout << "Nhap n: ";
//        cin >> n;
//    } while (n < 5 || n >= 100);

    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = rand() % 1000 + 2;
        }
    }
}
void TongMaTran(int a[MAX][MAX], int n){
    for (int i = 0; i < n; ++i) {
        int sumDong = 0;
        for (int j = 0; j < n; ++j) {
            sumDong += a[i][j];
        }
        cout << "Tong tren dong" << i << " = " << sumDong << endl;
    }
    for (int i = 0; i < n; ++i) {
        int sumCot = 0;
        for (int j = 0; j < n; ++j) {
            sumCot += a[j][i];
        }
        cout << "Tong tren cot" << i << " = " << sumCot << endl;
    }
    int sumDuongCheo = 0;
    for (int i = 0; i < n; ++i) {
        sumDuongCheo += a[i][i];
    }
    cout << "Tong tren duong cheo chinh = "  << sumDuongCheo << endl;

}
bool KtSoNguyenTo(int m){
    if(m >= 2){
        for (int i = 2; i <= sqrt(m); ++i) {
            if(m % i == 0) return false;
        }
        return true;
    }
    return false;
}
void TimSoNguyenTo(int a[MAX][MAX], int n){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if((i == 0 || i == n - 1 || j == 0 || j == n - 1) && KtSoNguyenTo(a[i][j]) == true){
                cout << a[i][j] << "\t";
            }
        }
    }
}
int main(){
    int a[MAX][MAX];
    int n = 5;
//    NhapMaTran(a, n);
    SinhMaTran(a, n);
    XuatMaTran(a, n);
    TongMaTran(a, n);
    TimSoNguyenTo(a, n);
    return 0;
}
