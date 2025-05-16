#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

void swap(void* a, void* b, size_t size);

void bubble_sort(void* base, size_t n, size_t elem_size, int (*cmp_func) (const void*, const void*));

void selection_sort(void* base, size_t n, size_t elem_size, int (*cmp_func) (const void*, const void*));

void insert_sort(void* base, size_t n, size_t elem_size, int (*cmp_func)(const void*, const void*));

void quick_sort(void* base, size_t n, size_t elem_size, int (*cmp_func)(const void*, const void*));

void merge_sort(void* base, size_t n, size_t elem_size, int (*cmp_func)(const void*, const void*));

#ifdef __cplusplus
}
#endif




// /sortlib
//   |- include/
//       |- sort.h    (对外C接口声明)
//   |- src/
//       |- quick_sort.c
//       |- merge_sort.c
//       |- heap_sort.c
//   |- test/
//       |- test_sort.cpp
//   |- CMakeLists.txt  (可选用CMake管理)
