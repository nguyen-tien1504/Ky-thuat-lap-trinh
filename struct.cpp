//
// Created by Nguyen Tien on 08-Feb-23.
//
#include <iostream>
using namespace std;
struct Phan_so{
    int tuSo, mauSo;
//    Phan_so(int tuSo, int mauSo){
//        tuSo = tuSo;
//        mauSo = mauSo;
//    };

};
void nhapPhanSo(Phan_so &p){
    cout << "Tu so = " ;
    cin >> p.tuSo;
    cout << "Mau so = ";
    cin >> p.mauSo;
}
void xuatPS(const Phan_so p){
    cout << p.tuSo << "/" << p.mauSo << endl;
}
int UCLN(int a, int b){
    while(a != b){
        if(a > b) a -= b;
        else b -= a;
    }
    return a;
}
Phan_so toiGianPhanSo(Phan_so p){
    Phan_so q;
    int u = UCLN(p.tuSo, p.mauSo);
        q.tuSo = p.tuSo / u;
        q.mauSo = p.mauSo / u;
    return q;
}
int main(){
    Phan_so p;
    nhapPhanSo(p);
    Phan_so q = toiGianPhanSo(p);
    xuatPS(q);
    return 0;
}