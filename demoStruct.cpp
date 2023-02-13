//
// Created by Nguyen Tien on 10-Feb-23.
//
#include <iostream>
#include <math.h>
#define PI 3.14
using namespace std;
struct Diem{
    double hoanhDo;
    double tungDo;
};
struct DuongTron{
    Diem tam;
    double banKinh;
};
void NhapDiem(Diem &p){
    cout << "Hoanh do: ";
    cin >> p.hoanhDo;
    cout << "Tung do: ";
    cin >> p.tungDo;
}
void NhapDuongTron(DuongTron &dt){
    NhapDiem(dt.tam);
    cout << "Nhap ban kinh: ";
    cin >> dt.banKinh;
}
double TinhKhoangCach(Diem p, Diem q){
    return sqrt(pow(p.hoanhDo - q.hoanhDo, 2) + pow(q.tungDo - p.tungDo, 2));
}
void DiemNamTrongDuongTron(Diem p, DuongTron dt){
    double khoangCach = TinhKhoangCach(p, dt.tam);
    if (khoangCach > dt.banKinh){
        cout << "Diem nam ngoai duong tron";
    } else if(khoangCach < dt.banKinh) {
        cout << "Diem nam trong duong tron";
    } else{
        cout << "Diem nam tren duong tron";
    }
}
void HaiDuongTronGiaoNhau(DuongTron dt1, DuongTron dt2){
    double kc = TinhKhoangCach(dt1.tam, dt2.tam);
    if(kc <= dt1.banKinh + dt2.banKinh){
        cout << "Hai duong tron giao nhau";
        return;
    }
    cout << "Hai duong tron khong giao nhau";
}
void NhapDsDuongTron(DuongTron *&a, int &n){
    cout << "Nhap so duong tron: ";
    cin >> n;
    a = new DuongTron[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap duong tron thu: " << i << endl;
        NhapDuongTron(a[i]);
    }
}
double DienTichDuongTron(const double r){
    return PI * pow(r, 2);
}
void InDsDuongTron(DuongTron *a, int n){
    for (int i = 0; i < n; i++) {
        cout << "Duong tron thu " << i << " : {Hoanh do: " << a[i].tam.hoanhDo
        << ", tung do: " << a[i].tam.tungDo << ", r: " << a[i].banKinh << ", S: " << DienTichDuongTron(a[i].banKinh) <<"}" << endl;
    }
}

void HoanVi(DuongTron &a, DuongTron &b){
    DuongTron t = a;
    a = b;
    b = t;
}
void SapXepDuongTron(DuongTron *&a, int n){
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (DienTichDuongTron(a[i].banKinh) < DienTichDuongTron(a[j].banKinh)){
                HoanVi(a[i], a[j]);
            }
        }
    }
}
int main(){
//    Diem p;
//    DuongTron dt;
//    NhapDiem(p);
//    NhapDuongTron(dt);
//    DiemNamTrongDuongTron(p, dt);
//    DuongTron dt1, dt2;
//    NhapDuongTron(dt1);
//    NhapDuongTron(dt2);
//    HaiDuongTronGiaoNhau(dt1, dt2);
    DuongTron *a;
    int n;
    NhapDsDuongTron(a, n);
    SapXepDuongTron(a, n);
    InDsDuongTron(a, n);
    delete []a;
    return 0;
}
