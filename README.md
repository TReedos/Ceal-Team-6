# Ceal-Team-6 Project 1 - Wordle (C++ and Python)

This is a desktop version of **Wordle** built using a C++ backend (game logic) and a Python Tkinter GUI.
The C++ logic is exposed to Python using [pybind11](https://github.com/pybind/pybind11).

---
# Project Structure

WordleProject/
├── wordle_ui.py
├── wordle_module.pyd
├── wordlist.txt
├── mingw_runtime/
│   ├── libstdc++-6.dll
│   ├── libgcc_s_seh-1.dll
│   └── libwinpthread-1.dll
├── README.txt
├── build.bat


---

# How to Run

## Requirements

- **Python 3.11+**
- `pybind11` installed
  Run:
  ```bash
  pip install pybind11

## Build
- without make (commmand prompt)
  run './build.bat'
  then run 'python wordle_ui.py' to start the game

- with make
  input make
  then input make run

# wordList.txt format

The file should contain 5-letter words, one per line:
apple
mango
berry
munch
lunch

# Include Runtime DLLs

The mingw_runtime/ folder includes necessary MinGW DLLs so users don't need to install anything.
The Python code dynamically loads them using os.add_dll_directory() for compatibility on any Windows machine.

# Developer Notes

make clean will remove the .pyd file
make run will launch the game if wordle_module.pyd is built


