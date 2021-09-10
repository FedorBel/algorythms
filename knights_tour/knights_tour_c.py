import ctypes
import pathlib


def solveKT(x: int, y: int, board_size: int) -> bool:
    libname = pathlib.Path().absolute() / "libknights_tour.so"
    c_lib = ctypes.CDLL(libname)
    return c_lib.solveKT(x, y, board_size)
