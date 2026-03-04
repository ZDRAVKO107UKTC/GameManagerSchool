# GameManager (C++20) — Singleton Pause Manager
A tiny C++20 example demonstrating a **Singleton** that owns a simple **pause/running** state and exposes a method. The program also verifies that multiple references point to the **same** instance. `GameManager``togglePause()``GameManager`
## What it demonstrates
- **Singleton pattern** using a function-local instance `static`
- Preventing copies:
    - Copy constructor deleted
    - Copy assignment deleted

- A boolean game state:
    - flips the paused state and prints the result `togglePause()`
    - returns the current state `getIsPaused()`

- Proof of singleton behavior by comparing addresses of two references

## Requirements
- A **C++20** compatible compiler
    - Examples: GCC, Clang, MSVC

- Works well in **CLion** on **Windows 11** (and other platforms too)

## Build & Run
### Using a terminal (generic)
From the folder containing your source file (e.g., ): `main.cpp```` bash
g++ -std=c++20 -O2 -Wall -Wextra -pedantic main.cpp -o GameManager
./GameManager
```

Using MSVC (Developer Command Prompt)``` bat
cl /std:c++20 /W4 /EHsc main.cpp
main.exe
```

Using CLion
Open the project in CLion.
Ensure the CMake profile uses a C++20 toolchain.
Click Run (the default run configuration should work for a single-file sample).
Expected Output (example)
Exact formatting may vary slightly, but you should see:
Initialization message once
A pause toggle message
A read of the paused state from a second reference
A success message confirming both references are the same instance
Notes
The singleton is created on first use (getInstance()), and its lifetime lasts until program exit.
Since it uses a function-local static, initialization is thread-safe in modern C++ (C++11 and later).