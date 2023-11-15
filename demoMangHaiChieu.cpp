// Họ và tên: Nguyễn Đức Tiến
#include <stdio.h>
#include <math.h>
#define MAX 10

void nhapMang2Chieu(int arr[MAX][MAX], int &m, int &n){
    printf("Nhap so hang: ");
    scanf("%d", &m);
    printf("Nhap so cot: ");
    scanf("%d", &n);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

void xuatMang2Chieu(int arr[MAX][MAX], int m, int n){
    printf("------------------Ma tran da cho------------------ \n");
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("\tarr[%d][%d] = %d", i, j, arr[i][j]);
        }
        printf("\n");
    }

    printf("-------------------------------------------------- \n");
}

int tongCacPhanTuTrongmang(int arr[MAX][MAX], int m, int n){
    int sum = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum+=arr[i][j];
        }
    }

    return sum;
}

int tongCacSoLeTrongMang(int arr[MAX][MAX], int m, int n){
    int sum = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(arr[i][j] % 2 != 0){
                sum+=arr[i][j];
            }
        }
    }

    return sum;
}

int tongCacSoChanTrongMang(int arr[MAX][MAX], int m, int n){
    int sum = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(arr[i][j] % 2 == 0){
                sum+=arr[i][j];
            }
        }
    }

    return sum;
}

int demSoNguyenTo(int arr[MAX][MAX], int m, int n){
    int count = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Kiem tra so nguyen to
            bool isPrime = true;
            if(arr[i][j] < 2){
                isPrime = false;
            } else {
                    for(int k = 2; k <= sqrt(arr[i][j]); k++){
                    if(arr[i][j] % k == 0){
                        isPrime = false;
                        break;
                    }
                }
            }
            
            if(isPrime) count++;
        }
    }

    return count;
}
void chen1DongMoiVaoMang(int arr[MAX][MAX], int &m, int n){
    m++;
    int vt;
    printf("Nhap vao vi tri can chen dong moi = ");
    scanf("%d",&vt);

    if(vt >= m){
        printf("Vi tri can chen vuot qua kich thuoc mang \n");
        return;
    }

    for (int i = m-1; i > vt; i--)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = arr[i-1][j];
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("Nhap gia tri moi tai vi tri arr[%d][%d] = ", vt, i);
        scanf("%d",&arr[vt][i]);
    }

    xuatMang2Chieu(arr, m, n);
}

void xoa1DongTrongMang(int arr[MAX][MAX], int &m, int n){
    int vt;
    printf("Nhap vao vi tri can xoa dong = ");
    scanf("%d",&vt);

    if(vt >= m){
        printf("Vi tri can xoa vuot qua kich thuoc mang \n");
        return;
    }

    for (int i = vt; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = arr[i+1][j];
        }
    }
    m--;

    xuatMang2Chieu(arr, m, n);
}

void chuyenViMaTran(int arr[MAX][MAX], int &m, int &n){
    // Tao 1 ma tran moi
    int newArr[MAX][MAX];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            newArr[j][i] = arr[i][j]; 
        }
        
    }

    // Gan ma tran moi vao ma tran cu
    arr = newArr;

    // Hoan vi so dong va so cot
    int temp = m;
    m = n;
    n = temp;

    xuatMang2Chieu(arr, m, n);
}
int main(){
    int m, n;
    int arr[MAX][MAX];

    nhapMang2Chieu(arr, m, n);
    //xuatMang2Chieu(arr, m, n);

    //1. Tong cac phan tu trong mang
    //printf("Tong cac phan tu trong mang: %d\n", tongCacPhanTuTrongmang(arr,m,n));

    //2. Tong cac so le, so chan
    //printf("Tong cac so le trong mang: %d\n", tongCacSoLeTrongMang(arr,m,n));
    //printf("Tong cac so chan trong mang: %d\n", tongCacSoChanTrongMang(arr,m,n));

    //3. Dem cac so nguyen to
    //printf("Dem cac so nguyen to: %d\n", demSoNguyenTo(arr,m,n));

    //4. Chen 1 dong mowi vao mang
    //chen1DongMoiVaoMang(arr, m, n);

    //5. Xoa 1 dong trong mang
    // xoa1DongTrongMang(arr, m, n);

    //6. Chuyen ma tran chuyen vi
    //chuyenViMaTran(arr, m, n);

    return 0;
}