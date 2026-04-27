/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 03 - Structures and Dynamic Arrays
 *   Hari dan Tanggal    : Senin, 27 April 2026
 *   Nama (NIM)          : 13224043
 *   Nama File           : autograderusak.c
 *   Deskripsi           : 
     Program autograder menggunakan array dinamis dari tipe data struct Praktikan untuk manajemen data praktikannya.
 */

#include <stdio.h>
#include <stdlib.h>
 
int main(){
    int count = 0;
    int input;
    int *arr;

    while (scanf("%d", &input) == 1 && input != -1){
        int *newarr = realloc(arr, (count + 1) * sizeof(int));
        if(newarr == NULL)
        {
            free(arr);
            return 0;
        }
        arr = newarr;
        arr[count] = input;
        ++count;
    }
    if (count == 0){
        free(arr);
        return 0;
    }

    for (int i = 0; i < count - 1; i++){
        for (int j = 0; j < count - i - 1; j++){
            if (arr[j] > arr[j+1]){
                int temp;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    double Median;
    if (count % 2 == 0){
        Median = (arr[count / 2 - 1] + arr[count/2])/2.0;
    }

    else{
        Median = (arr[count / 2]);
    
    printf("COUNT %d ", count);
        printf("SORTED ");
        for (int i = 0; i < count; i++){
            printf("%d ", arr[i]);
    }
    printf("MEDIAN %.2f", Median);

    free(arr);
}
return 0;
}
