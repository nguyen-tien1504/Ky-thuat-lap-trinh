//
// Created by Nguyen Tien on 09-Feb-23.
//
#include <iostream>
#include <string>
#define SO_MON 3
using namespace std;
struct SinhVien{
    int mssv;
    string ten;
    char queQuan[100];
    double diemTB[SO_MON];
};
struct DsSinhVien{
    SinhVien *sv;
    int n;
};
void NhapSV(SinhVien &sv){
    cout << "MSSV = ";
    cin >> sv.mssv;
    cin.ignore();
    cout << "Ten = ";
    getline(cin, sv.ten);
    cout << "Que quan = ";
    cin.getline(sv.queQuan, 100);
    for(int i = 0; i < SO_MON; i++){
        cout << "Nhap mon thu" << i + 1 << " = ";
        cin >> sv.diemTB[i];
    }
}
void xuatSV(const SinhVien sv){
    cout << "MSSV = " << sv.mssv << endl;
    cout << "Ten = " << sv.ten << endl;
    cout << "Que quan = " << sv.queQuan <<endl;
    for (int i = 0; i < SO_MON; ++i) {
        cout << "Diem mon thu " << i+1 << " : " << sv.diemTB[i] << endl;
    }
}
DsSinhVien* timKiem(DsSinhVien ds, string key){
    DsSinhVien *kq;
    kq->n=0;
    int dem = 0;
    for (int i = 0; i < ds.n;  i++){
        if(ds.sv[i].ten.find(key) != -1){
            kq[kq->n++] = ds[i];
        }
    }
    return NULL;
}
int main(){
//    int n;
    DsSinhVien ds;
//    SinhVien sv;
    cout << "Nhap so luong sv = " ;
    cin >> ds.n;
    ds.sv = new SinhVien[ds.n];
    for(int i = 0; i < ds.n; i++){
        cout << "Nhap sv thu " << i + 1 << endl;
        NhapSV(ds.sv[i]);

    }
    cout << "==========" << endl;
    for(int i = 0; i < ds.n; i++){
        xuatSV(ds.sv[i]);
    }
    return 0;
}