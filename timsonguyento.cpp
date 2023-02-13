//
// Created by Nguyen Tien on 15-Jan-23.
//

#include <iostream>
#include <math.h>
using namespace std;
bool ktSoNguyenTo(int x){
    for(int i = 2; i <= sqrt(x); i++){
        if(x % i == 0) return false;
    }
    return true;
}
int main(){
    int n;
    int total;
    cout << "Nhap n = " ;
    cin >> n;
    if(n < 2) cout << "Nhap lai n";
    for (int i = 2; i<= n; i++){
        if(ktSoNguyenTo(i)) total +=i ;
    }
    cout << total;
    return 0;
}
