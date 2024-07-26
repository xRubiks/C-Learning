#include "stdio.h"
#include "stdbool.h"
#include "string.h"

void readAndReverseArray(int arr[], int size) {
    printf("Input Array: %p\n", arr);
    int reversedArray[size];
    for(int i = 0; i < size; i++) {
        reversedArray[i] = arr[size - i - 1];
    }
    for(int i = 0; i < size; i++) {
        printf("%d\n", reversedArray[i]);
    }
}

bool isPalindrome(const char str[]) {
    int performanceboost = strlen(str);
    for(int i = 0; i < performanceboost; i++) {
        if(str[i] != str[performanceboost - i - 1]) {
            return false;
        }
    }
    return true;
}

void bubbleSort(int arr[], int size) {
    for(int x = 0; x < size; x++) {
        for(int y = 0; y < size - x - 1; y++) {
            if(arr[y] > arr[y+1]) {
                int temp = arr[y];
                arr[y] = arr[y+1];
                arr[y+1] = temp;
            }
        }
    }
}



//hello\0
// str = []
//  -> [a, b, c, d, e]
//       *, [a]*
//    int test = *arr;
//    int test2 = *(arr+4);
//    int test3 = *(arr+4+4);
//    int test4 = 2[arr];