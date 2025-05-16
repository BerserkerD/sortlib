# sortlib

A lightweight sorting library implemented in pure C, featuring a collection of common sorting algorithms including Bubble Sort, Selection Sort, Insertion Sort, Quick Sort, and Merge Sort. The library is designed with simplicity and consistency in mind, offering a unified interface with customizable comparison functions, making it easy to integrate into various C/C++ projects.

## Directory Structure

```
sortlib/
├── include/
│ └── sort.h
├── src/
│ └── sort.c
├── test/
│ └── test_sort.c
├── CMakeLists.txt
├── .gitignore
└── README.md
```

## Build Instructions

```bush
git clone https://github.com/BerserkerD/sortlib.git
cd sortlib
mkdir build && cd build
cmake ..
make
./test
```

## Performance

By default, the performance test is conducted on a random array with a size of 10,000.

```
bubble_sort    : 0.44297 s
selection_sort : 0.11276 s
insert_sort    : 0.10435 s
merge_sort     : 0.00169 s
quick_sort     : 0.00104 s
```

