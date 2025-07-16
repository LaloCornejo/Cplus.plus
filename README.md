# C++ Programming Collection

A comprehensive collection of C++ programs, projects, and exercises spanning from beginner learning exercises to advanced competitive programming solutions.

## 🏗️ Repository Structure

### 📚 Learning Materials (`C++.txt`)
Contains progressive C++ learning exercises covering:
- **Part 1-5**: Basic syntax, variables, input/output, and data types
- **Part 6-8**: Conditional statements and logical operations  
- **Part 9-10**: Boolean logic and compatibility matching
- **Part 11-12**: Loop structures and pattern printing
- **Part 13-14**: Arrays and grade calculation systems
- **Part 15-18**: Multi-dimensional arrays and student management
- **Part 19-22**: Advanced array operations and sorting algorithms

### 🎮 Game Projects

#### **ConFPS** - 3D Console FPS Game
A sophisticated first-person shooter game implemented in the Windows console using ray-casting technology.

**Features:**
- Real-time 3D rendering using ray-casting algorithms
- WASD movement controls with collision detection
- Dynamic lighting and shading effects
- Console-based graphics with ASCII characters
- Frame rate display and player position tracking

**Technical Details:**
- Uses Windows API for console manipulation
- Implements mathematical ray-casting for 3D projection
- Optimized rendering with distance-based shading
- Real-time player movement and rotation

#### **Snake Game** (`Self/snake.cpp`)
A classic Snake game implementation with console graphics.

**Features:**
- Windows console-based interface
- Color-coded graphics using Windows API
- Score tracking system
- Collision detection for walls and self-collision

### 🏆 Competitive Programming

#### **Template System** (`CPCtemplate/`)
Optimized competitive programming template with:
- GCC optimization pragmas for maximum performance
- Comprehensive macro definitions for quick coding
- Standard library shortcuts and typedefs
- Built-in timing functionality

#### **LeetCode Solutions** (`Leetcode/`)
- Problem solutions with automated build system
- Makefile for compilation and testing
- Input/output file handling for testing

#### **Programming Contests** (`Prog Compet/`)
Solutions from various programming competitions including:
- **ICPC** (International Collegiate Programming Contest)
- **Camp Jun** - Summer programming camp problems
- **IDK** - Miscellaneous competitive programming challenges

### 🎓 Academic Projects (`School/`)

#### **First Semester** (`1er/`)
Foundational programming concepts:
- **Functions and Arrays** - Function implementations with array manipulation
- **Loops and Structures** - Control flow and data structure basics
- **Pointers** - Memory management and pointer operations
- **Volume Calculations** - Mathematical computation programs

#### **Second Semester** (`2do/estructuradeDatos/`)
Advanced data structures and algorithms:
- **Linked Lists** - Single and double linked list implementations
- **Stacks and Queues** - LIFO and FIFO data structure operations
- **Trees and Graphs** - Hierarchical and network data structures
- **File I/O** - Binary and text file manipulation
- **Encryption** - Basic cryptographic algorithms
- **Banking System** - Complete file-based database simulation

### 🔧 Build Systems

#### **Makefile Configuration** (`Leetcode/Makefile`)
Automated build system featuring:
- C++17 standard with full optimization
- Comprehensive warning flags
- Debug symbol generation
- Automatic compilation and execution

### 🌟 Key Projects Highlights

1. **3D Ray-Casting Engine** - Advanced graphics programming in ConFPS
2. **Data Structure Library** - Complete implementation of fundamental data structures
3. **Competitive Programming Framework** - Optimized template for contests
4. **Educational Progression** - From basic syntax to advanced algorithms

## 🚀 Getting Started

### Prerequisites
- **Windows**: Microsoft Visual Studio or MinGW-w64
- **Linux/macOS**: GCC with C++17 support
- **Git**: For version control

### Compilation Examples

#### ConFPS Game (Windows)
```bash
cd ConFPS/ConFPS
g++ -std=c++17 ConFPS.cpp -o ConFPS.exe
./ConFPS.exe
```

#### LeetCode Solutions
```bash
cd Leetcode
make  # Compiles and runs a.cpp
```

#### Competitive Programming Template
```bash
cd CPCtemplate
g++ -O3 -std=c++17 cpcTemplate.cpp -o solution
./solution < input.txt > output.txt
```

## 📁 Directory Guide

| Directory | Purpose | Language | Complexity |
|-----------|---------|----------|------------|
| `ConFPS/` | 3D FPS Game | C++ | Advanced |
| `CPCtemplate/` | Competitive Programming | C++ | Intermediate |
| `Leetcode/` | Algorithm Solutions | C++ | Variable |
| `School/1er/` | Beginner Exercises | C++ | Beginner |
| `School/2do/` | Data Structures | C++/Java | Intermediate |
| `Prog Compet/` | Contest Solutions | C++ | Advanced |
| `Self/` | Personal Projects | C++ | Variable |
| `HackerRank/` | Online Judge Solutions | C++ | Intermediate |

## 🎯 Learning Path

1. **Start with**: `C++.txt` for basic concepts
2. **Practice with**: `School/1er/` exercises
3. **Advance to**: `School/2do/` data structures
4. **Challenge yourself**: `Leetcode/` and competitive programming
5. **Explore advanced**: ConFPS ray-casting implementation

## 🛠️ Technologies Used

- **C++17/20**: Modern C++ features and STL
- **Windows API**: Console manipulation and graphics
- **GCC**: Compilation with optimization flags
- **Make**: Build automation
- **Git**: Version control

## 📚 Educational Value

This repository serves as a comprehensive learning resource demonstrating:
- **Programming Fundamentals**: Variables, loops, functions
- **Object-Oriented Programming**: Classes, inheritance, polymorphism
- **Data Structures**: Arrays, linked lists, trees, graphs
- **Algorithms**: Sorting, searching, dynamic programming
- **System Programming**: File I/O, memory management
- **Graphics Programming**: Ray-casting, console graphics
- **Competitive Programming**: Optimization techniques

## 🤝 Contributing

This is primarily an educational repository documenting a programming learning journey. Feel free to:
- Suggest improvements to existing solutions
- Report bugs in game implementations
- Share alternative approaches to problems

## 📞 Contact

- **Email**: lalocornejoofficial@gmail.com
- **Author**: Lalo Cornejo

---

*This repository represents a complete journey through C++ programming, from first "Hello World" to advanced 3D graphics and competitive programming. Each directory tells a story of growth and learning in software development.*