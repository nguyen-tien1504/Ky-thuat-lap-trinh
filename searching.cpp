#include <stdio.h>
int countX(int arr[], int n, int gtri){
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == gtri) count++;
    }
    
    return count;
}
int binarySearchFor(int arr[], int n, int gtri){
    int vtri = -1;
    int l = 0;
    int r = n-1;

    while (l<=r)
    {   
        int mid = (l+r)/2;

        if(arr[mid] == gtri) {
            vtri = mid;
            break;
        }

        if(arr[mid] > gtri){
            r = mid-1;
        } else{
            l = mid+1;
        }
    }
    
    return vtri;
}

int binarySearchRecurse(int arr[], int l, int r, int gtri){
    int vtri = -1;
    int mid = (l+r)/2;
    if(l > r){
        return vtri;
    }

    if(arr[mid] == gtri){
        return mid;
    } 

    if(arr[mid] < gtri){
        binarySearchRecurse(arr, mid+1, r, gtri);
    } else{
        binarySearchRecurse(arr, l, mid-1, gtri);
    }
}
int main(){
    int arr[] = {0,1,4,4,7,8,8,9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int gtri;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &gtri);
    // printf("So luong phan tu can tim trong mang: %d", countX(arr, n, gtri));

    // printf("Vi tri can tim tai: %d", binarySearchFor(arr, n, gtri));
    printf("Vi tri can tim tai: %d", binarySearchRecurse(arr, 0, n-1, gtri));

    return 0;
}