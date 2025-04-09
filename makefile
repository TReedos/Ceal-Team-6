PYTHON = python
PYBIND11_INC = $(shell $(PYTHON) -m pybind11 --includes)
PYTHON_LIB_DIR = $(shell $(PYTHON) -c "import sysconfig; print(sysconfig.get_config_var('LIBDIR'))")
PYTHON_LIB = $(shell $(PYTHON) -c "import sysconfig; print(sysconfig.get_config_var('LDLIBRARY').split('.')[0].replace('.dll', '').replace('.lib', '').replace('.a', ''))")

SRC = wordleBindings.cpp wordleGameEngine.cpp
OUT = wordle_module.pyd

CXX = g++
CXXFLAGS = -O3 -Wall -shared -std=c++17

all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT) $(PYBIND11_INC) -L$(PYTHON_LIB_DIR) -l$(PYTHON_LIB)

run:
	python wordle_ui.py

clean:
	rm -f $(OUT)

