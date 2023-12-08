#include <iostream>
using namespace std;
void selectionSort(int arr[], int n){
    for (int i = 0; i < n-1; i++)
    {
        int min = arr[i], vtmin;
        for (int j = i+1; j < n; j++)
        {
            if(arr[j] < min){
                min = arr[j];
                vtmin = j;
            }
        }
        
        if(min < arr[i]){
            int temp = min;
            arr[vtmin] = arr[i];
            arr[i] = temp;
        }
    }
    
}
void bubbleSort(int arr[], int n){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = n-1; j > 0; j--)
        {
            if(arr[j] < arr[j-1]){
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
}
void insertionSort(int arr[], int n){
    for (int i = 1; i < n; i++)
    {   int current = arr[i];
        for (int j = i-1; j >= 0; j--)
        {
            if(current < arr[j]){
                arr[j+1] = arr[j];
                arr[j] = current;
            }
        }
        
    }
    
}
void quickSort(int arr[], int left, int right){
    int pivot = arr[(left+right)/2];
    int l = left, r = right;
    do
    {
        while (arr[l] < pivot)
        {
            l++;
        }
        while (arr[r] > pivot)
        {
            r--;
        }
        
        if(l <= r){
            int temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
            l++;
            r--;
        }
    } while (l <= r);
    
    if(left < r){
        quickSort(arr, left, r);
    }
    if(l < right){
        quickSort(arr, l, right);
    }
}
int* mergeFunction(int *a, int n1, int *b, int n2){
    int *c = new int[n1+n2];
    int i = 0, j = 0, dem = 0; //i tren doan a, j tren doan b
    while (i < n1 && j < n2){   
        if(a[i] < b[j]){
            c[dem++] = a[i++];
        } else {
            c[dem++] = b[j++];
        }
    }
    
    for (int k = i; k < n1; k++){
        c[dem++] = a[k];
    }

    for (int k = j; k < n2; k++){
        c[dem++] = b[k];
    }

    return c;
}
int* mergeSort(int arr[], int n){
    if (n <= 1){
        return arr;
    }
    int mid = n/2;
    int *a1 = new int[mid];
    int *a2 = new int[n-mid];

    for (int i = 0; i < mid; i++){
        a1[i] = arr[i];
    }

    for (int i = 0; i < n-mid; i++){
        a2[i] = arr[mid+i];
    }
    
    a1 = mergeSort(a1, mid);
    a2 = mergeSort(a2, n-mid);
    return mergeFunction(a1, mid, a2, n-mid);
}
int main(){
    int n;
    int arr[30];
    cout << "Nhap n: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 10;
        cout << arr[i] << "\t";
    }
    // selectionSort(arr, n);
    // bubbleSort(arr, n);
    // insertionSort(arr, n);
    // quickSort(arr, 0, n-1);
    int *c = mergeSort(arr, n);
    cout << endl << "----------------------------------------" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << c[i] << "\t";
    }
    return 0;
}