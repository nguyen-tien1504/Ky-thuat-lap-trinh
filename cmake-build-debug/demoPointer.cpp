//
// Created by Nguyen Tien on 10-Feb-23.
//
#include <iostream>

using namespace std;

void NhapMang(int *&a, int &m){
    cout << "Nhap m = ";
    cin >> m;
    a = new int[m];
    for(int i = 0; i < m; i++){
        cout << "Nhap a[" << i << "] = ";
        cin >> a[i];
    }
}
void XuatMang(const int *arr, int j){
    for (int i = 0; i < j; ++i) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}
void NoiMang(int *a, int *b, int *&c, int m, int n){
    c = new int[m + n];
    for (int i = 0; i < m; ++i) {
        c[i] = a[i];
    }
    for (int i = 0; i < n; ++i) {
        c[m + i] = b[i];
    }
}
void HoanVi(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}
void SapXep(int *a, int n){
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if(a[i] < a[j]){
                HoanVi(&a[i], &a[j]);
            }
        }
    }
}
void NhapMaTran(int **&a, int &p, int &q){
    cout << "Nhap so dong: " ;
    cin >> p;
    cout << "Nhap so cot: " ;
    cin >> q;
    a = new int*[p];
    for (int i = 0; i < p; ++i) {
        a[i] = new int[q];
    }
    for (int i = 0; i < p; i++)
        for (int j = 0; j < q; j++)
        {
            cout << "a[" << i << ", " << j << "] = ";
            cin >> a[i][j];
        }
}
void XuatMaTran(int **a, int p, int q){
    for (int i = 0; i < p; ++i) {
        for (int j = 0; j < q; ++j) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}
int TimDiemNhoNhatDong(int **a, int q, int vitridong){
    int vt = 0;
    for (int i = 1; i < q; ++i) {
        if(a[vitridong][i] < a[vitridong][vt]) vt = i;
    }
    return vt;
}
bool TimDiemLonNhatTrenCot(int **a, int p,int vitridong, int vitricot){
    int max = a[vitridong][vitricot];
    for (int i = 0; i < p; ++i) {
        if(a[i][vitricot] > max) return false;
    }
    return true;
}
int main(){
//    int *a, *b, m, n;
//    int *c;
//    NhapMang(a,m);
//    NhapMang(b,n);
//    NoiMang(a, b, c, m, n);
//    SapXep(c, m+n);
//    XuatMang(a, m);
//    XuatMang(b, n);
//    XuatMang(c, m + n);
//    delete []a;
//    delete []b;
//    delete []c;
    int **m, p, q;
    NhapMaTran(m, p, q);
    XuatMaTran(m, p, q);

    for (int i = 0; i < p; ++i) {
        int vitricot = TimDiemNhoNhatDong(m, q, i);
        if(TimDiemLonNhatTrenCot(m, p, i, vitricot)==true){
            cout << m[i][vitricot];
        }
    }

    for (int i = 0; i < p; i++)
        delete [] m[i];
    delete []m;
    return 0;
}