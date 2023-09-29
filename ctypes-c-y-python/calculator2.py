import ctypes


calculator_lib = ctypes.CDLL('./calculator.dll')


calculator_lib.add.argtypes = (ctypes.c_float, ctypes.c_float)
calculator_lib.add.restype = ctypes.c_float

calculator_lib.subtract.argtypes = (ctypes.c_float, ctypes.c_float)
calculator_lib.subtract.restype = ctypes.c_float

calculator_lib.multiply.argtypes = (ctypes.c_float, ctypes.c_float)
calculator_lib.multiply.restype = ctypes.c_float

calculator_lib.divide.argtypes = (ctypes.c_float, ctypes.c_float)
calculator_lib.divide.restype = ctypes.c_float


result_add = calculator_lib.add(5.0, 3.0)
result_subtract = calculator_lib.subtract(5.0, 3.0)
result_multiply = calculator_lib.multiply(5.0, 3.0)
result_divide = calculator_lib.divide(5.0, 1.0)


print(f"5.0 + 3.0 = {result_add}")
print(f"5.0 - 3.0 = {result_subtract}")
print(f"5.0 * 3.0 = {result_multiply}")
print(f"5.0 / 1.0 = {result_divide}")
