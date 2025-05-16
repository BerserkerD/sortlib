#include <cstdio>
#include <string>
#include "sort.h"
#include <time.h>

#define N   100000


void generate_random_arr(int* arr, size_t n) {
    for(int i = 0;i < n;i ++) {
        arr[i] = rand() % 10000;
    }
}

void copy_arr(int* dest, int* src, size_t n) {
    for(size_t i = 0;i < n;i ++) {
        dest[i] = src[i];
    }
} 

int cmp(const void* a, const void* b) { // 升序
    return (*(int*)a) - (*(int*)b);
}

void test(void (*sort)(void* , size_t , size_t , int (*cmp_func) (const void*, const void*)), const char* name, int* original, size_t n) {
    int* arr = (int*)malloc(n * sizeof(int));
    copy_arr(arr, original, n);
    
    clock_t start = clock();
    sort((void*)arr, n, sizeof(int), cmp);
    clock_t end = clock();

    printf("%-15s: %.5f s\n", name, (double)(end - start) / CLOCKS_PER_SEC);

    free(arr);
}

int main() {

    srand(time(NULL));

    int* original = (int*)malloc(N * sizeof(int));
    generate_random_arr(original, N);

    test(bubble_sort, "bubble_sort", original, N);
    test(selection_sort, "selection_sort", original, N);
    test(insert_sort, "insert_sort", original, N);
    test(merge_sort, "merge_sort", original, N);
    test(quick_sort, "quick_sort", original, N);

    free(original);
    return 0;
}