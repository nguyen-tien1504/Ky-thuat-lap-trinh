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

void demSoLuongChuSoNguyenDuong(int arr[MAX][MAX], int m, int n){
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(arr[i][j] < 0){
                printf("arr[%d][%d] khong phai la so nguyen duong \n",i ,j);
                break;
            }

            int count = 0;
            int current = arr[i][j];
            while (current >= 10)
            {
                count++;
                current /= 10;
            }
            printf("So luong chu so trong arr[%d][%d] la: %d\n", i, j, count + 1);
        }
        
    }
}

void hoanDoi2Dong(int arr[MAX][MAX], int m, int n){
    int d1, d2, temp[n];
    printf("Nhap vao dong hoan doi 1 : ");
    scanf("%d", &d1);
    printf("Nhap vao dong hoan doi 2 : ");
    scanf("%d", &d2);

    for (int i = 0; i < n; i++)
    {
        temp[i] = arr[d1][i];
        arr[d1][i] = arr[d2][i];
        arr[d2][i] = temp[i];
    }
    
    xuatMang2Chieu(arr, m, n);
}

void demSoLanXuatHien(int arr[MAX][MAX], int m, int n){
    int s, vt = -1;
    printf("Nhap so can tim: ");
    scanf("%d", &s);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(arr[i][j] == s){
                printf("So can tim nam tai vi tri arr[%d][%d]", i, j);
                vt = 1;
                break;
            }
        }
        
        if(vt == 1) break;
    }
    
    if(vt == -1) printf("Khong tim thay");
}

// void sapXepTangTheoCot(int arr[MAX][MAX], int m, int n){
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             arr[m][n]
//         }
        
//     }
// }

void cacSoNguyenTo(int arr[MAX][MAX], int m, int n){
    printf("Cac so nguyen to trong ma tran \n");
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
            
            if(isPrime) printf("%d\t", arr[i][j]);
        }
    }
}
void congHaiMaTran(int arr[MAX][MAX], int m, int n, int arr2[MAX][MAX], int a, int b){
    if(m != a || n != b){
        printf("2 ma tran khong cung cap");
        return;
    }

    int tempArray[MAX][MAX];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tempArray[i][j] = arr[i][j] + arr2[i][j];
        }
        
    }
    
    xuatMang2Chieu(tempArray, m, n);
}

void tongNgoaiBien(int arr[MAX][MAX], int m, int n){
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i != 0 && i != m-1 && j != 0 && j != n-1){
                sum+=arr[i][j];
            }
        }
        
    }
    printf("%d",sum);
}

void tongHoanThien(int arr[MAX][MAX], int m, int n){
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sumofGCD = 0;
            if(arr[i][j] == 1) sumofGCD++;
            for (int k = 1; k < arr[i][j]; k++)
            {
                if(arr[i][j] % k == 0){
                    sumofGCD+=k;
                }
            }
            
            if(sumofGCD == arr[i][j]){
                sum+=arr[i][j];
            }
        }
        
    }
    printf("%d",sum);
}

void trungBinhNhan(int arr[MAX][MAX], int m, int n){
    int count = 0;
    double product = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(arr[i][j] > 0){
                count++;
                product *= arr[i][j];
            }
        }
        
    }
    
    double result = pow(product, 1.0/count); 
    printf("%f", result);

}

void tongTungHang(int arr[MAX][MAX], int m, int n){
    for (int  i = 0; i < m; i++)
    {   int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += arr[i][j];
        }
        printf("Tong hang %d: %d \n", i, sum);
    }
    
}

void tongSoChinhPhuong(int arr[MAX][MAX], int m, int n){
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {   //Kiem tra so nguyen
            if( sqrt(arr[i][j])  - (int)sqrt(arr[i][j]) == 0){
                sum += arr[i][j];
            }
        }
    }
    
    printf("Tong cac so chinh phuong: %d\n", sum);
}

void xuatPhanTuNgoaiBien(int arr[MAX][MAX], int m, int n){
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i != 0 && i != m-1 && j != 0 && j != n-1){
                printf("%d \t", arr[i][j]);
            }
        }
    }
    
}

void demCucTri(int arr[MAX][MAX], int m, int n){
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {

        }
        
    }
    // printf("So luong cuc tri: %d", count);
}

void demPhanBiet(int arr[MAX][MAX], int m, int n){
    int count = 0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            bool is_unique = true;
            for (int k = 0; k < m; k++) {
                for (int l = 0; l < n; l++) {
                    if (i != k || j != l) {
                        if (arr[i][j] == arr[k][l]) {
                            is_unique = false;
                            break;
                        }
                    }
                }
                if (!is_unique) {
                    break;
                }
            }
            if (is_unique) {
                count++;
            }
        }
    }
    printf("%d", count);
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

    //7. Dem so luong chu so cua so nguyen duong trong ma tran
    // demSoLuongChuSoNguyenDuong(arr, m ,n);

    //8. Hoan doi 2 giong trong ma tran
    // hoanDoi2Dong(arr, m ,n);

    //9. Dem so lan xuat hien cua 1 so
    //demSoLanXuatHien(arr, m, n);

    //10. Sap xep ma tran tang theo cot
    // sapXepTangTheoCot(arr, m ,n);

    //11. Cac so nguyen to trong ma tran
    //cacSoNguyenTo(arr, m ,n);

    //12. tong 2 ma tran
    // int arr2[MAX][MAX];
    // int a, b;
    // nhapMang2Chieu(arr2, a, b);
    // congHaiMaTran(arr, m ,n, arr2, a, b);

    //13. Tong cac phan tu ngoai bien   
    // tongNgoaiBien(arr, m, n);

    //14. Tong cac so hoan thien
    // tongHoanThien(arr, m, n);

    //15. Trung binh nhan
    // trungBinhNhan(arr, m, n);

    //16. tong cac so tung hang
    // tongTungHang(arr, m, n);

    //17. Tong cac so chinh phuong
    // tongSoChinhPhuong(arr, m, n);

    //18. Xuat cac phan tu nam ngoai bien
    // xuatPhanTuNgoaiBien(arr, m, n);

    //19. dem cuc tri 
    // demCucTri(arr, m, n);

    //20. dem cac phan tu phan biet
    demPhanBiet(arr, m, n);
    return 0;
}