# Multithreaded Matrix Multiplication in C++

This project implements **high-performance matrix multiplication** using **multithreading in C++**.
Work is distributed across CPU cores using `std::thread` and `hardware_concurrency()` to significantly improve performance.

---

## Features

* Multithreaded matrix multiplication
* Dynamic CPU core detection
* Workload batching across threads
* Performance measurement using `chrono`
* Large matrix multiplication support
* Compiled with high optimization (`-O3`)

---

## How It Works

1. Two large matrices are initialized
2. CPU core count is detected using `std::thread::hardware_concurrency()`
3. Work is split into batches of rows
4. Each thread processes a portion of rows
5. Threads are joined after computation
6. Execution time is measured

---

## Matrix Size

```
4000 x 4100  *  4100 x 5000
```

Output Matrix:

```
4000 x 5000
```

Total Operations:

```
~82 Billion Operations
```

---

## Performance

Compiled with:

```
g++ -O3 -march=native -pthread matrix.cpp
```

Execution Time:

```
26 seconds
```

*(Performance depends on CPU cores and hardware)*

---

## Technologies Used

* C++
* STL (vector, thread, chrono)
* Multithreading
* Parallel Programming
* Performance Optimization

---

## Compilation

Compile:

```
g++ -O3 -march=native -pthread matrix.cpp -o matrix
```

Run:

```
./matrix
```

---

## Learning Outcomes

* Multithreading in C++
* Performance optimization
* Parallel computing
* Memory optimization
* CPU core utilization

---

## Author

Aadi Jain

---

