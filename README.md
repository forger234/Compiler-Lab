````markdown
# 🔧 Compiler Design Project

A comprehensive implementation of a **mini compiler** built using C, demonstrating all major phases of compilation — from lexical analysis to code optimization. This project showcases the practical aspects of **compiler design**, including syntax and semantic analysis, intermediate code generation, and optimization.

---

## 📘 Table of Contents

- [✨ Features](#-features)
- [🧩 Project Structure](#-project-structure)
- [⚙️ Compilation & Execution](#️-compilation--execution)
- [🧠 Implementation Details](#-implementation-details)
- [📊 Example Workflow](#-example-workflow)
- [🚀 Future Enhancements](#-future-enhancements)
- [📜 License](#-license)

---

## ✨ Features

- 🧾 **Lexical Analysis** using tokenization  
- 🧮 **Top-Down & Bottom-Up Parsing** approaches  
- 🧠 **Recursive Descent Parser** implementation  
- 🏗️ **Intermediate Code Generation** (Three Address Code / Quadruples)  
- 🧰 **Code Optimization** via:
  - Constant Propagation  
  - Dead Code Elimination  
  - Data Flow Analysis  
- 🔄 **Symbol Table Management**  
- 💡 Modular C design for each compiler phase  

---

## 🧩 Project Structure

| File | Description |
|------|--------------|
| `lexical.c`, `lexical_analyser.lux` | Lexical Analyzer – token generation and classification |
| `top_down.c` | Top-down parsing implementation |
| `bottum_up.c` | Bottom-up parsing (shift-reduce) implementation |
| `recursive_descend.c` | Recursive Descent Parser |
| `inter.c` | Intermediate code generation (Three Address Code) |
| `quad.c` | Quadruple representation for intermediate code |
| `dfa_const.c` | Data Flow Analysis for constant propagation |
| `constant_prop.c` | Constant propagation optimization |
| `code_optimization.c` | Code optimization algorithms |
| `Makefile` *(optional)* | Automates build process (if added) |

---

## ⚙️ Compilation & Execution

### 🔹 Using GCC

```bash
gcc lexical.c top_down.c bottum_up.c recursive_descend.c inter.c quad.c constant_prop.c code_optimization.c dfa_const.c -o compiler
./compiler
````

> 💡 Make sure all source files are in the same directory before compilation.

### 🔹 Using Lex/Flex (if applicable)

If using `.lux` file for lexical analysis:

```bash
lex lexical_analyser.lux
gcc lex.yy.c -o lexer
./lexer
```

---

## 🧠 Implementation Details

### 🔸 Lexical Analysis

* Tokenizes input source code.
* Handles identifiers, keywords, operators, and literals.
* Outputs tokens for parser.

### 🔸 Syntax Analysis

* Implements **both** top-down and bottom-up parsing strategies.
* Recursive descent parser checks grammar conformance.

### 🔸 Intermediate Code Generation

* Converts parsed statements into **Three Address Code (TAC)** and **quadruples**.

### 🔸 Code Optimization

* Constant propagation and folding.
* Dead code removal.
* Basic data flow analysis.

---

## 📊 Example Workflow

```text
Input:
a = 3 + 5;
b = a * 2;

Output (Intermediate Code):
t1 = 3 + 5
a = t1
t2 = a * 2
b = t2

Optimized Code:
a = 8
b = 16
```

---

## 🚀 Future Enhancements

* Add **symbol table visualization**
* Integrate **error recovery** in parser
* Implement **register allocation**
* Extend support for more data types and control structures

---

## 📜 License

This project is licensed under the **MIT License** — feel free to modify and distribute with attribution.

---
