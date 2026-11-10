from pybind11.setup_helpers import Pybind11Extension, build_ext
from setuptools import setup

ext_modules = [
    Pybind11Extension(
        "mediane",
        ["src/interface.cpp", "src/cum_mediane.cpp"],
    ),
]

setup(
    name="mediane",
    version="0.0.1",
    author="Jacob",
    description="Mediane cumulative en C++ avec pybind11",
    ext_modules=ext_modules,
    cmdclass={"build_ext": build_ext},
    python_requires=">=3.9",
)