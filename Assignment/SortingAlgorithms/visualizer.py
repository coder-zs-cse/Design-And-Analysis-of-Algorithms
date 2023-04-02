import matplotlib.pyplot as plt
import numpy as np
import time
import random 
import copy
#!/usr/bin/env python3
#coding=utf8
from pygnuplot import gnuplot 

from sortingAlgo.bubbleSort import bubbleSort
from sortingAlgo.selectionSort import selectionSort
from sortingAlgo.insertionSort import insertionSort
from sortingAlgo.heapSort import heapSort
from sortingAlgo.mergeSort import mergeSort

AVERAGE_CASE = 0
BEST_CASE = 1
WORST_CASE = -1

algos = ["bubble sort", "selection sort", "insertion sort", "merge sort", "heap sort"]
sortingFunctions = [bubbleSort,selectionSort,insertionSort,mergeSort,heapSort]

N = 2 #Number of points
xpointsN = list(range(100,100*N+1,100)) #100,200,300,400,500,600,700,800,900...

timeAxis = [] #2D list containing the list of time values corrsponding to each N value for each sorting algo 


def generateInputArray(n,typeInput):

    if typeInput==AVERAGE_CASE:
        array = np.random.randint(1,1000,n)
    elif typeInput==BEST_CASE:
        array = [i for i in range(1,n+1)]
    elif typeInput==WORST_CASE:
        array = [i for i in reversed(range(1,n+1))]
    return array    
               
array = generateInputArray(101*N,AVERAGE_CASE)

def calculateTime(array,n,sort):
    temp = copy.deepcopy(array)
    startTime = time.time()
    sort(temp,n)
    completeTime = time.time()
    return completeTime - startTime

for i in range(0,len(algos)): #for each algorithm
    timeArray = []
    for j in range(0,len(xpointsN)): #for each value of N(number of elements in array)
        timeArray.append(calculateTime(array,xpointsN[j],sortingFunctions[i])) #time taken by ith algorithm for xpointsN[j] number of elements
    timeAxis.append(timeArray)


print(xpointsN)
print(timeAxis)


g = gnuplot.Gnuplot(terminal = 'pngcairo font "arial,10" fontscale 1.0 size 600, 400',
                    output = '"simple.1.png"')
g.plot('[-10:10] sin(x)',
       'atan(x)',
       'cos(atan(x))',
       key = 'fixed left top vertical Right noreverse enhanced autotitle box lt black linewidth 1.000 dashtype solid',
       style = 'increment default',
       samples = '50, 50',
       title = '"Simple Plots" font ",20" norotate')