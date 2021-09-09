import ctypes
import pathlib

if __name__ == "__main__":
    # Load the shared library into ctypes
    libname = pathlib.Path().absolute() / "libknights_tour.so"
    c_lib = ctypes.CDLL(libname)
    answer = c_lib.solveKT()
    print(answer)
