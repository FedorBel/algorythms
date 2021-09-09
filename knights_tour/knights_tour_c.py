import ctypes
import pathlib


def solveKT() -> bool:
    libname = pathlib.Path().absolute() / "libknights_tour.so"
    c_lib = ctypes.CDLL(libname)
    return c_lib.solveKT()
