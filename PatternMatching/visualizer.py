import matplotlib.pyplot as plt
import numpy as np
import time
import random 
import copy

from matchingAlgorithms.bruteforce import bruteforce_PM
from matchingAlgorithms.KMP import KMP_PM

algos = ["Bruteforce Algorithm","KMP Algorithm"]
matchingAlgorithms = [bruteforce_PM,KMP_PM]
N = 20 #Number of points
#Taking worst case input
#String would be all 'a's and Pattern 40% length of string and consists of all 'a's and last character as 'b'
xpointsN = list(range(100,100*N+1,100)) #100,200,300,400,500,600,700,800,900...
print(xpointsN)
timeAxis = [] #2D list containing the list of time values corrsponding to each N value for each sorting algo 

string = "a"*(101*20) 


def calculateTime(string,n,matchingAlgo):
    stringRef = string[0:n]
    pattern = "a"*(int(n*(0.4))) + "b"
    startTime = time.time()
    matchingAlgo(stringRef,pattern)
    completeTime = time.time()
    return completeTime - startTime

for i in range(0,2): #for each algorithm
    timeArray = []
    for j in range(0,len(xpointsN)): #for each value of N(number of elements in array)
        timeArray.append(calculateTime(string,xpointsN[j],matchingAlgorithms[i])) #time taken by ith algorithm for xpointsN[j] number of elements
    timeAxis.append(timeArray)
for i in range(0,2):
    plt.plot(xpointsN,timeAxis[i],label=algos[i])


plt.xlabel('Size of Input')
plt.ylabel('Time Complexity')
plt.grid()
plt.legend()
plt.show()






