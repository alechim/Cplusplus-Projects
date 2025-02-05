# C++ Projects Repository
## Introduction
This repository serves as a collection of my C++ programming work, including:
- **Textbook Practice Problems**: Exercises from my C++ textbook to reinforce core programming concepts.
- **Academic Projects** (To be added later): Assignments and coursework from my university studies.
The goal of this repository is to document my learning process, demonstrate my understanding of C++, and serve as a reference for future projects.

## Repository Structure
```
📂 C++ Projects<br>
├── 📂 Academic Projects    # (To be added) University coursework
├── 📂 C++ Textbook         # Practice problems from my C++ textbook
│   ├── README.md           # Overview of the textbook problems
│   ├── Chapter 1           # Contains problem solutions
│   ├── Chapter 2           # ...
│   └── ...
├── README.md               # Main repository introduction
```

## C++ Textbook

The C++ Textbook directory contains solutions to problems from my textbook. Each chapter has its own folder, with an `index.md` file summarizing the problems solved within that chapter. Additionally, a separate `README.md` inside the `C++ Textbook` directory provides details on:
- The textbook used (including an Amazon link)
- A list of chapter topics covered

## How to Run the Code

### Requirements
- Compiler: g++ (GCC)
- IDE: Visual Studio Code
- Extensions: Code Runner (for quick execution)

### Running a Program

#### Using Code Runner (VS Code Shortcut)
1. Open a `.cpp` file in VS Code.
2. Press `Ctrl + Alt + N` to compile and run.

#### Using the Terminal (Manual Compilation)
If Code Runner is not working, you can manually compile and run the code:
```
# Navigate to the directory containing your .cpp file
cd path/to/project

# Compile the file
g++ main.cpp -o main

# Run the executable
./main  # (Use `main.exe` on Windows)
```