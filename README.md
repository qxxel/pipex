# pipex
![42 Project](https://img.shields.io/badge/42-Project-blue)
![Language](https://img.shields.io/badge/C-0E7FC0?logo=c)

---

## 📌 Summary
- [About](#about)
- [Features](#features)
- [Installation](#installation)
- [Utilisation](#utilisation)
- [Directories structure](#directories-structure)
- [Author](#author)

---

<a id="about"></a>
## 📖 About

**pipex** is a project of 42 school.
It's a program that's follow the command `< file1 cmd1 | cmd2 > file2` in the shell. It will execute `cmd1` on `infile` and `cmd2` on the result to put in `outfile`.

---

<a id="features"></a>
## ✨ Features

✅ Use shell command in C program  
✅ Handle errors  
✅ Read and write in files  
✅ Handle pipes

---

<a id="installation"></a>
## ⚙️ Installation

**1. Clone the repository**

```bash
git clone git@github.com:qxxel/pipex.git
```

**2. Access the directory**

```bash
cd pipex
```

---

<a id="utilisation"></a>
## 🕹️ Utilisation

**1. Compile the project**

```bash
make
```

**2. Launch it**

```bash
./pipex [infile] [cmd1] [cmd2] [outfile]
```

---

<a id="directories-structure"></a>
## 📂 Directories structure

```plaintext
📂 pipex
 ┣ 📂 includes   → headers files (.h)
 ┣ 📂 libft      → my own C library (you can see on my profile)
 ┣ 📂 srcs       → sources files (.c)
 ┣ Makefile
 ┗ README.md
```

<a id="author"></a>
## 👤 Author

* Axel – [GitHub](https://gitub.com/qxxel)
* 42 student - login: *agerbaud*
