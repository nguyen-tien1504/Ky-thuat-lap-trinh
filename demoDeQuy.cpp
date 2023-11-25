//
// Created by Nguyen Tien on 10-Feb-23.
//
#include <iostream>
using namespace std;
void NhiPhan(int n){
    if(n == 0) return;
    NhiPhan(n/2);
    cout << n%2;
}
void DaoNguoc(int n){
    if(n > 0) {
        cout << n%10;
        DaoNguoc(n / 10);
    }
}
void NhapMang(int a[], int n){
    for (int i = 0; i < n; ++i) {
        cout << "Nhap phan tu a[" << i << "] = " ;
        cin >> a[i];
    }
}
int TinhTong(int a[], int n){
    if(n == 1) return a[0];
    return a[n-1] + TinhTong(a, n-1);
}
int max(int a[], int n){
    if(n == 1) return a[0];
    int m = max(a, n-1);
    if(a[n-1] > m) return a[n-1];
    return m;
}
int main(){
//    NhiPhan(4);
//    DaoNguoc(123456);
    int n = 3;
    int a[n];
    NhapMang(a, n);
    cout << TinhTong(a , n) << endl;
    cout << "max = " << max(a, n) ;
    return 0;
}