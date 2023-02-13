#include <iostream>
#include <math.h>
using namespace  std;
int main() {
    int n;

    do{
        cout << "Nhap bang cuu chuong: ";
        cin >> n;
    } while (n < 1 || n > 10);
    for (int i = 1; i <= 10; i++){
        cout << n << " * " << i << " = " << n*i << endl;
    }
    return 0;
}
