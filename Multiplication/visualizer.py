import matplotlib.pyplot as plt
import numpy as np
import time
import random 
import copy

from algorithms.bruteforce import bruteforce
from algorithms.divideAndConquer import divideAndConquer
from algorithms.karatsuba import karatsuba

algos = ["Bruteforce Algorithm","Divide And Conquer Algorithm","Karatsuba Algorithm"]
matchingAlgorithms = [bruteforce,divideAndConquer,karatsuba]
N = 20 #Number of points
#Taking worst case input
#String would be all 'a's and Pattern 40% length of string and consists of all 'a's and last character as 'b'
xpointsN = list(range(10,10*N+1,10)) #100,200,300,400,500,600,700,800,900...
print(xpointsN)
timeAxis = [] #2D list containing the list of time values corrsponding to each N value for each sorting algo 



def calculateTime(n,matchingAlgo):
    num1 = "9"*n
    num2 = "9"*n
    startTime = time.time()
    matchingAlgo(num1,num2)
    completeTime = time.time()
    return completeTime - startTime

for i in range(0,3): #for each algorithm
    timeArray = []
    for j in range(0,len(xpointsN)): #for each value of N(number of elements in array)
        timeArray.append(calculateTime(xpointsN[j],matchingAlgorithms[i])) #time taken by ith algorithm for xpointsN[j] number of elements
    timeAxis.append(timeArray)
for i in range(0,3):
    plt.plot(xpointsN,timeAxis[i],label=algos[i])


plt.xlabel('Size of Input')
plt.ylabel('Time Complexity')
plt.grid()
plt.legend()
plt.show()






