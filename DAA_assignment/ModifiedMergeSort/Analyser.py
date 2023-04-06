import numpy as np
import time
import random
import copy

from algorithms.mergeSort import mergeSort
from algorithms.modifiedMergeSort import modifiedMergeSort


algos = ["Merge Sort","Modified Merge Sort"]
mergeSortFunctions = [mergeSort,modifiedMergeSort]
N = 20
xpointsN = list(range(100,100*N+1,100))

arr = np.random.randint(1,100,100*(N+1)) #defining a fixed large array to compute all the sorting operations on 

timeAxis = []

def calculateTime(array,n,sort):
    temp = copy.deepcopy(array)
    startTime = time.time()
    sort(temp,n)
    completeTime = time.time()
    return round(completeTime - startTime,6)

for i in range(len(algos)):  
    timeRecord = []
    for num in range(N):
        timeRecord.append(calculateTime(arr,xpointsN[num],mergeSortFunctions[i]))
    timeAxis.append(timeRecord)

data = list(zip(xpointsN,timeAxis[0],timeAxis[1]))

with open("./output/graphPlot.dat","w") as f:
	for row in data:
		f.write("{}\t {}\t {}\n".format(*row))

print("i am done")




