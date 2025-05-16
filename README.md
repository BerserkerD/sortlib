# sortlib

sortlib is a lightweight sorting library implemented in pure C, featuring a collection of common sorting algorithms including Bubble Sort, Selection Sort, Insertion Sort, Quick Sort, and Merge Sort. The library is designed with simplicity and consistency in mind, offering a unified interface with customizable comparison functions, making it easy to integrate into various C/C++ projects.

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
