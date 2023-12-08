#include <stdio.h>
#define MAX 50

int main(){
    int n;
    int a[MAX];

    FILE *fp = fopen("Mang1Chieu.txt", "a+");
    if(fp == NULL){
        printf("Khong doc dc file");
    }

    fscanf(fp, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &a[i]);
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
        sum += a[i];
    }
    fprintf(fp, "\nTong mang la: %d", sum);

    fclose(fp);

    return 0;
}