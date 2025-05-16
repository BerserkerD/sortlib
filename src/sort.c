#include "sort.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(void* a, void* b, size_t size) {
    unsigned char temp[size];
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}


void bubble_sort(void* base, size_t n, size_t elem_size, int (*cmp_func) (const void*, const void*)) {
    char* arr = (char*)base;
    for(size_t i = 0;i < n;i ++) {
        for(size_t j = 0;j < n - 1 - i;j ++) {
            void* elem1 = arr + j * elem_size;
            void* elem2 = arr + (j + 1) * elem_size;
            if(cmp_func(elem1, elem2) > 0) {
                swap(elem1, elem2, elem_size);
            }
        }
    }
}

void selection_sort(void* base, size_t n, size_t elem_size, int (*cmp_func) (const void*, const void*)) {
    char* arr = (char*) base;
    for(size_t i = 0;i < n - 1;i ++) {
        size_t minIdx = i;
        for(size_t j = i + 1;j < n;j ++) {
            if(cmp_func(arr + minIdx * elem_size, arr + j * elem_size) > 0) {
                minIdx = j;
            }
        }
        if(minIdx != i) {
            swap(arr + minIdx * elem_size, arr + i * elem_size, elem_size);
        }
    }
}


void insert_sort(void* base, size_t n, size_t elem_size, int (*cmp_func)(const void*, const void*)) {
    char* arr = (char*) base;
    void* key = malloc(elem_size);
    for(size_t i = 1;i < n;i ++) {
        memcpy(key, arr + i * elem_size, elem_size);
        ssize_t j = i - 1;
        while(j >= 0 && cmp_func(arr + j * elem_size, key) > 0) {
            memcpy(arr + (j + 1) * elem_size, arr + j * elem_size, elem_size);
            j --;
        }
        memcpy(arr + (j + 1) * elem_size, key, elem_size);
    }
    free(key);
}


void quick_sort(void* base, size_t n, size_t elem_size, int (*cmp_func)(const void*, const void*)) {
    if(n < 2) return;

    char* pivot = (char*) base;
    char* left = (char*) base + elem_size;
    char* right = (char*) base + (n - 1) * elem_size;
    while(1) {
        
        while(left <= right && cmp_func(left , pivot) < 0) left += elem_size;
        
        while(left <= right && cmp_func(right, pivot) >= 0) right -= elem_size;
        
        if(left <= right) {
            swap(left, right, elem_size);
            left += elem_size;
            right -= elem_size;
        } else break;
    }
    swap(pivot, right, elem_size);

    size_t left_size = (right - (char*)base) / elem_size;
    size_t right_size = n - left_size - 1;
    quick_sort(base, left_size, elem_size, cmp_func);
    quick_sort(left, right_size, elem_size, cmp_func);
}


static void merge(char* base, char* temp, size_t left, size_t mid, size_t right, size_t elem_size, int (*cmp_func)(const void*, const void*)) {
    size_t i = left;
    size_t j = mid;
    size_t k = left;
    while(i < mid && j < right) {
        if(cmp_func(base + i * elem_size, base + j * elem_size) < 0) {
            memcpy(temp + k * elem_size, base + i * elem_size, elem_size);
            i ++;
        } else {
            memcpy(temp + k * elem_size, base + j * elem_size, elem_size);
            j ++;
        }
        k ++;
    }

    while(i < mid) {
        memcpy(temp + k * elem_size, base + i * elem_size, elem_size);
        i ++;
        k ++;
    }

    while(j < right) {
        memcpy(temp + k * elem_size, base + j * elem_size, elem_size);
        j ++;
        k ++;
    }

    for(i = left;i < right;i ++) {
        memcpy(base + i * elem_size, temp + i * elem_size, elem_size);
    }
}

static void _merge_sort(char* base, char* temp, size_t left, size_t right, size_t elem_size, int (*cmp_func)(const void*, const void*)) {
    if(right - left <= 1) return;
    
    size_t mid = left + (right - left) / 2;
    _merge_sort(base, temp, left, mid, elem_size, cmp_func);
    _merge_sort(base, temp, mid, right, elem_size, cmp_func);
    merge(base, temp, left, mid, right, elem_size, cmp_func);
}

void merge_sort(void* base, size_t n, size_t elem_size, int (*cmp_func)(const void*, const void*)) {
    char* temp = (char*)malloc(n * elem_size);
    if(!temp) {
        perror("malloc failed");
        return;
    }
    _merge_sort((char*)base, temp, 0, n, elem_size, cmp_func);
    free(temp);
}