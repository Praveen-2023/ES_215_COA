import numpy as np
import time

def matrix_multi_int(n):

    A = np.full((n, n), 2,dtype=int)
    B = np.full((n, n), 1, dtype =int)

    C = np.zeros((n, n),dtype=int)
    start = time.time()
    
    # Matrix multiplication
    for i in range(n):
        for j in range(n):
            for k in range(n):
                C[i][j]+= A[i][k]* B[k][j]

    end = time.time()
    duration = end - start
    print(f"Integer Matrix Multiplication n = {n} took : {duration:.6f} seconds")


# Testing with values as given
ns = [64,128,256,512,1024]
for n in ns:
    matrix_multi_int(n)
