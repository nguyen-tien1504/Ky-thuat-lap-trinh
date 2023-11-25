//Nguyễn Đức Tiến
//2310060007
//Đệ quy

#include <stdio.h>
#define MAX 10
#include <string.h>
// Bai 1
int tinhGiaiThua(int n){
    if(n == 1) return n;
    return n * tinhGiaiThua(n-1);
}
// bai 2
void nhapMang1Chieu(int arr[MAX], int n){
    if(n == 0) return;

    nhapMang1Chieu(arr, n-1);   

    printf("Nhap arr[%d] = ", n-1);
    scanf("%d", &arr[n-1]); 
}

int tongMang(int arr[MAX], int n){
    if(n-1 == 0) return arr[0];
    int sum = arr[n-1];
    return sum + tongMang(arr, n-1);
}

int demSoDuong(int arr[MAX], int n){
    if(n == 0) return 0;

    int count = 0;
    if(arr[n-1] > 0) count++;

    return count + demSoDuong(arr, n-1);
}

int timLonNhat(int arr[MAX], int n){
    if(n == 1) return arr[n-1];
    int max = timLonNhat(arr, n-1);

    if(arr[n-1] > max) return arr[n-1];

    return max;
}

int demPhanTu(int arr[MAX], int n){
    if(n == 0) return n;

    int count = 0;
    if(arr[n-1] == 5) count++;
    return count + demPhanTu(arr, n-1);
}

void inChuoiDaoNguoc(char text[100], int strLength){
    if(strLength == - 1) return;
    printf("%c", text[strLength-1]);
    inChuoiDaoNguoc(text, strLength-1);
}

void bieuDienNhiPhan(int n){
    if(n==0) return;
    bieuDienNhiPhan(n/2);
    printf("%d", n%2);
}

void chuyenGioPhutGiay(int n, int m = 2){
    const char *arr[] = {"Gio", "phut", "Giay"};
    if(n==0) return;

    chuyenGioPhutGiay(n/60, m-1);
    printf("%d %s ", n%60, arr[m]);
}

void kiemTraSoNguyenTo(int n, int m = 2){
    if(m == n || n == 2 || n == 3){
        printf("%d la so nguyen to", n);
        return;
    }
    if(n % m == 0 || n < 2){
        printf("%d khong phai so nguyen to", n);
        return;
    }
    if(m < n){
        kiemTraSoNguyenTo(n, m+1);
    }
}


int tongCacSoNguyen(int n){
    if(n == 0) return n;
    return n%10 + tongCacSoNguyen(n/10);
}
int main(){
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);

    // printf("%d", tinhGiaiThua(n));

    // int arr[MAX];
    // nhapMang1Chieu(arr, n);

    // printf("%d", tongMang(arr, n));
    //printf("%d", demSoDuong(arr, n));
    // printf("%d", timLonNhat(arr, n));
    // printf("%d", demPhanTu(arr, n));

    // char str[100];
    // printf("Nhap chuoi: ");
    // scanf("%[^\n]s", str);

    // int strLength = strlen(str);
    // inChuoiDaoNguoc(str, strLength);

    // bieuDienNhiPhan(n);

    // chuyenGioPhutGiay(n);

    // kiemTraSoNguyenTo(n);
    printf("%d", tongCacSoNguyen(n));
    return 0;
}