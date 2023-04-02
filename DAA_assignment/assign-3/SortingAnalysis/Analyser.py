import numpy as np
import time
import random 
import copy

from sortingAlgo.bubbleSort import bubbleSort
from sortingAlgo.selectionSort import selectionSort
from sortingAlgo.insertionSort import insertionSort
from sortingAlgo.mergeSort import mergeSort

algos = ["bubble sort", "selection sort", "insertion sort", "merge sort"]
sortingFunctions = [bubbleSort,selectionSort,insertionSort,mergeSort]

N = 20 #Number of points
xpointsN = list(range(100,100*N+1,100)) #100,200,300,400,500,600,700,800,900...


#randomized input
arr1 = np.random.randint(1,100,100*(N+1)) #defining a fixed large array to compute all the sorting operations on 

#best case input
arr2 = list(range(100*(N+1)))

#worst case input
arr3 = list(reversed(range(100*(N+1))))

inputArray = [arr1,arr2,arr3]
inputNames = ["randomInput","bestcase","worstcase"]

def calculateTime(array,n,sort):
    temp = copy.deepcopy(array)
    startTime = time.time()
    sort(temp,n)
    completeTime = time.time()
    return round(completeTime - startTime,6)

for input in range(len(inputArray)):
    timeAxis = [] #2D list containing the list of time values corrsponding to each N value for each sorting algo 
    for i in range(0,len(algos)): #for each algorithm
        timeArray = []
        for j in range(0,len(xpointsN)): #for each value of N(number of elements in array)
            timeArray.append(calculateTime(inputArray[input],xpointsN[j],sortingFunctions[i])) #time taken by ith algorithm for xpointsN[j] number of elements
        timeAxis.append(timeArray)



    data = list(zip(xpointsN,timeAxis[0],timeAxis[1],timeAxis[2],timeAxis[3]))

    with open("./output/"+ inputNames[input] +"/graphPlot.dat","w") as f:
        for row in data:
            f.write("{}\t {}\t {}\t {}\t {}\n".format(*row))
    print(inputArray[input][:10])
    print("i am done")