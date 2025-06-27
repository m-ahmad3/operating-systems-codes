# OS Codes

This repository contains a collection of Operating System (OS) lab programs and simulations written in **C**, developed during academic coursework. These programs focus on core OS concepts such as **process synchronization**, **multithreading**, **pipes**, **inter-process communication**, and **resource sharing**.

---

## 💡 Topics Covered

| Concept                 | Covered in Files/Folders                      |
|------------------------|-----------------------------------------------|
| **Multithreading**     | `n_threads.c`, `thread.c`, `thread_Prog.c`     |
| **Semaphores & Mutex** | `L10-Mutex-Semaphore/`, `oldBridge.c`          |
| **Pipes (IPC)**        | `Pipesg2prac.c`, `GL2 Solved(Pipes).c`         |
| **Process Duplication**| `Dup Lab 6.c`, `example_task_dup.c`            |
| **System Calls**       | Various files demonstrate `fork()`, `pipe()`, `dup()`, `exec()` |
| **Concurrency Problems**| `oldBridge.c`, `mcSeries_pi.c`                |
| **OS Setup**           | `OS_Lab1 (Installation).docx`                  |

---

## 🛠️ Requirements

- **Compiler:** GCC (`gcc`)
- **Libraries:** POSIX Threads (`pthread`)
- **Operating System:** Linux/Unix-based environment (or WSL on Windows)

---

## 🚀 How to Compile & Run

### 🔹 Compile a Program
```bash
gcc thread.c -o thread -lpthread
./thread
