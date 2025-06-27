# OS Codes

This repository contains a collection of Operating System (OS) lab programs and simulations written in **C**, developed during academic coursework. These programs focus on core OS concepts such as **process synchronization**, **multithreading**, **pipes**, **inter-process communication**, and **resource sharing**.

---

## 📁 Folder & File Structure

OS/
├── L10-Mutex-Semaphore/ # Programs related to mutual exclusion and semaphores
├── Unsolved_Labs/ # Lab exercises yet to be completed
├── mcSeries_pi.c # Multithreaded calculation (MC series & Pi value)
├── n_threads.c # Thread creation and handling example
├── thread.c # Basic multithreaded task
├── thread_Prog.c # Multithreading and synchronization logic
├── oldBridge.c # Classic concurrency problem simulation
├── Pipesg2prac.c # Pipe-based inter-process communication
├── Dup Lab 6.c # File descriptor duplication and I/O redirection
├── example_task_dup.c # Task using dup/dup2 system calls
├── G5-Solution.c # Group-based solution (pipe/thread/IPC task)
├── GL2 Solved(Pipes).c # Solved pipe-based problem
├── C_Basics.c # Refresher on basic I/O and syntax
├── OS_Lab1 (Installation).docx # Instructions for Linux setup and GCC


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
