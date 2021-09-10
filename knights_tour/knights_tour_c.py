import ctypes
import pathlib


def solveKT(board_size: int) -> bool:
    libname = pathlib.Path().absolute() / "libknights_tour.so"
    c_lib = ctypes.CDLL(libname)
    return c_lib.solveKT(board_size)
