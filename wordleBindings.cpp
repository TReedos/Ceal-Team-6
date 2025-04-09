#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wordleGameEngine.hpp"

namespace py = pybind11;

PYBIND11_MODULE(wordle_module, m) {
	py::class_<Wordle>(m, "Wordle")
		.def(py::init<const std::string&>())
		.def("evaluate_guess", &Wordle::evaluateGuess)
		.def("play", &Wordle::play);
}
