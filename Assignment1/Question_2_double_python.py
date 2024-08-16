import numpy as np
import time

def matrix_multi_double(n):

    A = np.full((n, n), 2.5, dtype =float)
    B = np.full((n, n), 3.0,dtype=float)

    C = np.zeros((n, n),dtype=float)
    start=time.time()
    
    # Matrix multiplication
    for i in range(n):
        for j in range(n):
            for k in range(n):
                C[i][j] += A[i][k] *B[k][j]

    end = time.time()
    duration = end-start
    print(f"Double Matrix Multiplication n = {n} took : {duration:.6f} seconds")


# Testing with values of n as given
ns = [64, 128, 256, 512, 1024]
for n in ns:
    matrix_multi_double(n)
