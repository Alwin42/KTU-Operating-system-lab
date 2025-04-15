# KTU Operating System Lab – S4 (2019 Scheme)

This repository contains a collection of Operating System lab programs aligned with the APJ Abdul Kalam Technological University (KTU) Semester 4 syllabus (2019 Scheme). The programs are written in C and demonstrate core concepts in operating systems such as process management, memory allocation, scheduling, and inter-process communication.

---

## Lab Programs

### 1. Process Management & System Calls
- `process.c` – Creating child processes using `fork()`
- `exec.c` – Executing a new program using `exec()`
- `pid.c` – Retrieving process ID with `getpid()`
- `wait.c` – Synchronizing processes using `wait()`
- `stat.c` – File status information using `stat()`
- `opendir.c` – Directory operations using `opendir()`

### 2. CPU Scheduling Algorithms
- `fcfs.c` – First-Come, First-Served Scheduling
- `shortest.c` – Shortest Job First (SJF) Scheduling
- `roundrobin.c` – Round Robin Scheduling
- `priority.c` – Priority Scheduling

### 3. Memory Management
- `first.c` – First Fit Allocation
- `bestfit.c` – Best Fit Allocation
- `worstfit.c` – Worst Fit Allocation

### 4. Page Replacement Algorithms
- `FIFO.c` – First-In, First-Out
- `LRU.c` – Least Recently Used
- `LFU.c` – Least Frequently Used

### 5. Disk Scheduling Algorithms
- `scan.c` – SCAN Disk Scheduling
- `C-scan.c` – C-SCAN Disk Scheduling

### 6. Deadlock Handling
- `bankers.c` – Banker's Algorithm

### 7. Inter-Process Communication (IPC)
- `ipc.c` – Shared Memory Communication
- `ipc2.c` – Additional IPC Example

### 8. Process Synchronization
- `producer.c` – Producer-Consumer Problem

---

## Compilation & Execution

To compile and run a program:

```bash
gcc filename.c
./a.out
```

Replace `filename.c` with the source file name and `output` with your preferred executable name.
