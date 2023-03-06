import matplotlib.pyplot as plt
import numpy as np
import time
import random 
import copy

from sortingAlgo.bubbleSort import bubbleSort
from sortingAlgo.selectionSort import selectionSort
from sortingAlgo.insertionSort import insertionSort
from sortingAlgo.heapSort import heapSort
from sortingAlgo.mergeSort import mergeSort
from sortingAlgo.quickSort import quickSort

algos = ["bubble sort", "selection sort", "insertion sort", "merge sort", "quick sort", "heap sort"]
sortingFunctions = [bubbleSort,selectionSort,insertionSort,mergeSort,quickSort,heapSort]

N = 20 #Number of points
xpointsN = list(range(100,100*N+1,100)) #100,200,300,400,500,600,700,800,900...

timeAxis = [] #2D list containing the list of time values corrsponding to each N value for each sorting algo 

array = np.random.randint(1,100,100*(N+1)) #defining a fixed large array to compute all the sorting operations on 

def calculateTime(array,n,sort):
    temp = copy.deepcopy(array)
    startTime = time.time()
    sort(temp,n)
    completeTime = time.time()
    return completeTime - startTime

for i in range(0,6): #for each algorithm
    timeArray = []
    for j in range(0,len(xpointsN)): #for each value of N(number of elements in array)
        timeArray.append(calculateTime(array,xpointsN[j],sortingFunctions[i])) #time taken by ith algorithm for xpointsN[j] number of elements
    timeAxis.append(timeArray)

plot1 = plt.subplot2grid((6,2),(0,0),rowspan=3,colspan=2)
plot2 = plt.subplot2grid((6,2),(4,0),rowspan=2,colspan=2)

for i in range(6): #plotting the waveform of all 6 algorithms in first graph
    plot1.plot(xpointsN,timeAxis[i],label=algos[i])

plot1.set_xlabel('Size of Array')
plot1.set_ylabel('Time Complexity')
plot1.grid()
plot1.legend()

for i in range(3,6): # plotting the waveform of merge, heap, quick sort algorithms in second graph
    plot2.plot(xpointsN,timeAxis[i],label=algos[i])

plot2.set_xlabel('Size of Array')
plot2.set_ylabel('Time Complexity')
plot2.grid()
plot2.legend()

plt.subplots_adjust(left=0.1,
                    bottom=0.1,
                    right=0.9,
                    top=0.9,
                    wspace=0.3,
                    hspace=0.3)
plt.show()





