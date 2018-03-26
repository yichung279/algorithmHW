import time
def insertionSort(alist):
    for index in range(1,len(alist)):
        currentvalue = alist[index]
        position = index
        while position>0 and alist[position-1]>currentvalue:
            alist[position]=alist[position-1]
            position = position-1
        alist[position]=currentvalue

def mergeSort(alist):
    if len(alist)>1:
        mid = len(alist)//2
        lefthalf = alist[:mid]
        righthalf = alist[mid:]

        mergeSort(lefthalf)
        mergeSort(righthalf)

        i=0
        j=0
        k=0
        while i < len(lefthalf) and j < len(righthalf):
            if lefthalf[i] < righthalf[j]:
                alist[k]=lefthalf[i]
                i=i+1
            else:
                alist[k]=righthalf[j]
                j=j+1
            k=k+1

        while i < len(lefthalf):
            alist[k]=lefthalf[i]
            i=i+1
            k=k+1

        while j < len(righthalf):
            alist[k]=righthalf[j]
            j=j+1
            k=k+1

alist = [1]
blist = [1]
for i in range(1,50):
    alist.reverse()
    alist += [50-i]
    blist.reverse()
    blist += [50-i]
    
    tStart1 = time.time()#計時開始
    insertionSort(alist)
    tEnd1 = time.time()
    
    tStart2 = time.time()#計時開始
    mergeSort(blist)
    tEnd2 = time.time()
    
    a = tEnd1 - tStart1
    b = tEnd2 - tStart2
    if a>b:
        print(len(alist))
