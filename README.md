# 🐚 Asif’s Custom Shell (v1.0)

> A simple yet powerful **command-line shell** written in **C**, built from scratch to mimic the behavior of Linux shells such as Bash and Zsh — built and tested inside **WSL (Windows Subsystem for Linux)**.

---

## 🧠 Overview

This project demonstrates my understanding of **Operating System concepts**, **process management**, and **system calls** in C.  
It is designed to be lightweight, modular, and easy to extend.

The shell supports both built-in commands and external Linux commands.  
Every function — from reading user input to executing processes — is manually implemented using core C features and UNIX system calls like `fork()`, `execvp()`, and `waitpid()`.

---

## 🎯 **Key Objectives**
- Understand how real shells like **Bash** work internally.  
- Gain hands-on experience with **process creation**, **child-parent synchronization**, and **I/O handling**.  
- Design a **modular C project** with headers, multiple source files, and a `Makefile` for compilation.

---

## ⚙️ **Features**

✅ **Built-in Commands:**
| Command | Description |
|----------|-------------|
| `cd [dir]` | Change directory |
| `help` | Display help for built-in commands |
| `exit` | Exit the shell |
| `greet [name]` | Custom greeting message 👋 |
| `clear` | Clears the screen |
| `about` | Show shell info |

✅ **System Commands:**
- Supports all valid **Linux system commands**, e.g. `ls`, `pwd`, `mkdir`, `cat`, `echo`, etc.

✅ **Additional Features:**
- Colorful prompt showing **current working directory**.
- Structured output for readability.
- Error handling for invalid inputs.
- Modular source structure (`src` + `include` + `build` + `bin`).
- Simple and clean **Makefile build system**.
- Runs perfectly in **WSL** and **Linux terminals**.

---

## 🧩 **Project Structure**

Shell/
├── Makefile
├── README.md
├── src/
│   ├── main.c
│   ├── loop.c
│   ├── execute.c
│   ├── builtins.c
│   ├── utils.c
├── include/
│   ├── shell.h
│   ├── builtins.h
│   ├── utils.h
├── build/
├── bin/

##  🚀 **HOW TO COMPILE AND RUN**
    $ make clean        ---> This will delete all files of bin and build 
    $ make              ---> This will compile the code
    $ make run          ---> This will run the code 