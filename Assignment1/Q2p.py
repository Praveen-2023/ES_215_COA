import matplotlib.pyplot as plt

# Example data
sizes = [64, 128, 256, 512, 1024]
python_int_times = [0.1, 0.5, 2.0, 8.0, 30.0]  # Replace with actual data
python_double_times = [0.2, 0.6, 2.5, 9.0, 35.0]  # Replace with actual data
cpp_int_times = [0.05, 0.3, 1.5, 6.0, 20.0]  # Replace with actual data
cpp_double_times = [0.1, 0.4, 1.8, 7.0, 25.0]  # Replace with actual data

plt.figure(figsize=(10, 6))
plt.plot(sizes, python_int_times, 'o-', label='Python Integer')
plt.plot(sizes, python_double_times, 's-', label='Python Double')
plt.plot(sizes, cpp_int_times, '^-', label='C++ Integer')
plt.plot(sizes, cpp_double_times, 'd-', label='C++ Double')

plt.xlabel('Matrix Size (N)')
plt.ylabel('Execution Time (seconds)')
plt.title('Matrix Multiplication Execution Time')
plt.legend()
plt.grid(True)
plt.show()
