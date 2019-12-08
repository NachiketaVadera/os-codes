import threading as thread
import numpy as np

number = int(input("Enter a number:"))
fibo_array = np.zeros((number), dtype=int)

def funonacci(n):
    if(n == 0):
        fibo_array[n] = 0
    if(n == 1):
        fibo_array[n] = 1
    else:
        fibo_array[n] = fibo_array[n - 1] + fibo_array[n - 2]


string = ""
for i in range(number):
    init_thread = thread.Thread(target=funonacci, args=(i,))
    init_thread.start()
    init_thread.join()
    string += str(fibo_array[i]) + " "


print(string)