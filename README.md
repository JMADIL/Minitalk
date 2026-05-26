# 📡 Minitalk

> A small data exchange program using UNIX signals — 42 Network project

[![42 School](https://img.shields.io/badge/42-School-000000?style=for-the-badge&logo=42&logoColor=white)](https://42.fr)
[![Language](https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)](LICENSE)

---

## 📖 About

**Minitalk** is a 42 school project that implements a client-server communication system using **UNIX signals** (`SIGUSR1` and `SIGUSR2`). The client sends a string message to the server one bit at a time, and the server reconstructs and displays the original message.

This project introduces the fundamentals of **inter-process communication (IPC)** and **bitwise operations** in C.

## 🏗️ How It Works

```
┌──────────┐     SIGUSR1 / SIGUSR2      ┌──────────┐
│  CLIENT  │ ─────────────────────────►  │  SERVER  │
│          │    (sends bits one by one)  │          │
│  PID: ?  │                             │  PID: X  │
│  Input:  │     Bit 0 → SIGUSR1        │  Output: │
│ "Hello"  │     Bit 1 → SIGUSR2        │ "Hello"  │
└──────────┘                             └──────────┘
```

1. The **server** starts and prints its **PID** (Process ID)
2. The **client** takes the server PID and the message as arguments
3. Each character is converted to its **binary representation** (8 bits)
4. For each bit, the client sends:
   - `SIGUSR1` → bit is `0`
   - `SIGUSR2` → bit is `1`
5. The server reconstructs each character bit by bit and prints it

## 🚀 Getting Started

### Prerequisites

- GCC compiler
- Make
- A UNIX-based OS (Linux / macOS)

### Build

```bash
git clone https://github.com/JMADIL/MINITALK.git
cd MINITALK
make
```

This will compile two binaries: `server` and `client`.

### Usage

**1. Start the server:**

```bash
./server
```

The server will display its PID:

```
Server PID: 12345
```

**2. Send a message from the client:**

```bash
./client <server_pid> "Hello, World!"
```

The server will display the received message.

## 📂 Project Structure

```
MINITALK/
├── Makefile            # Build system
├── Minitalk.h          # Header file with prototypes & includes
├── Minitalk_utils.c    # Utility functions (ft_atoi, ft_strlen, etc.)
├── client.c            # Client: encodes and sends message via signals
├── server.c            # Server: receives signals and decodes message
└── README.md           # This file
```

## 🔑 Key Concepts Learned

| Concept | Description |
|---------|-------------|
| **UNIX Signals** | Using `SIGUSR1` and `SIGUSR2` for inter-process communication |
| **Bitwise Operations** | Encoding/decoding characters bit by bit |
| **Signal Handlers** | Catching and processing signals with `sigaction()` |
| **Process Management** | Working with PIDs, `getpid()`, and `kill()` |
| **Signal Sets** | Managing signals with `sigemptyset()` and `sigaddset()` |

## 🔧 Allowed Functions

`write` · `ft_printf` · `signal` · `sigemptyset` · `sigaddset` · `sigaction` · `kill` · `getpid` · `malloc` · `free` · `pause` · `sleep` · `usleep` · `exit`

## 👤 Author

**Adil Jamoun** — [@JMADIL](https://github.com/JMADIL)

> 🏫 1337 Coding School (42 Network) — Morocco
