//
// Created by Nguyen Tien on 15-Jan-23.
//
#include <iostream>;
using namespace std;
int timSoLonNhat(int a[], int first, int last){
    if(first == last) return a[first];
    int m = timSoLonNhat(a, first + 1 , last);
    if(m < a[first]) m = a[first];
    return m;
}
void NhapDS(int a[], int &n){
    cout << "Nhap n: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
}
void XuatDS(int a[], const int n){
    for (int i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
}
void ChenViTri(int a[], int &n, int vt, int nd){
    n++;
    for (int i = n - 1; i > vt ; i--) {
        a[i] = a[i-1];
    }
    a[vt]=nd;
}
int main(){
//    int a[] = {1,2,4,6,3,2};
//    int max = timSoLonNhat(a, 0, 5);
//    cout << "So lon nhat: " << max;
    int n;
    int a[100];
    NhapDS(a, n);
    ChenViTri(a, n, 2, 99);
    XuatDS(a, n);
    return 0;
};