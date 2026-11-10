#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include "cum_mediane.h"
namespace py = pybind11;

py::array_t<double> cum_mediane_interface(
  py::array_t<double, py::array::c_style | py::array::forcecast> donnees
) {
  py::buffer_info buf_donnees = donnees.request();
  if (buf_donnees.ndim != 1)
    throw std::runtime_error("Number of dimensions must be one");
  // allouer mémoire pour la sortie
  auto sortie = py::array_t<double>(buf_donnees.size);
  py::buffer_info buf_sortie = sortie.request();
  // convertir en pointeurs
  double *donnees_ptr = static_cast<double *>(buf_donnees.ptr);
  double *sortie_ptr = static_cast<double *>(buf_sortie.ptr);
  int status = cum_mediane(donnees_ptr, (int)buf_donnees.size, sortie_ptr);
  if (status == ERROR_DONNEES_REPETEES)
    throw std::runtime_error("Donnees repetees");
  return sortie;
}

PYBIND11_MODULE(mediane, m, py::mod_gil_not_used()) {
  m.doc() = R"pbdoc(
    Mediane cumulative en C++ avec pybind11
    ---------------------------------------
  )pbdoc";
   m.def("cum_mediane", &cum_mediane_interface, py::arg("donnees"), R"pbdoc(
    Calculer la mediane cumulative d'un tableau numpy.

    Pour chaque position i, la sortie contient la médiane des données 0 à i.

    Parameters
    ----------
    donnees : numpy.ndarray
        Tableau 1D de nombres, sans valeurs repetees.

    Returns
    -------
    numpy.ndarray
        Tableau de meme taille, avec la mediane cumulative.

    Raises
    ------
    RuntimeError
        Si le tableau n'est pas 1D, ou s'il contient des valeurs repetees.
  )pbdoc");
}