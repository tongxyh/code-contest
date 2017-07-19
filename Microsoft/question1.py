import math

def comparee(a,b,c):
    if abs(a-b) <= 1 and abs(a-c) <=1 and abs(b-c) <=1:
        return True
    else:
        return False

N = long(raw_input())
while N >= 3:
    try:
        arr = [long(x) for x in raw_input().split()]
        sum_a = 0
        for i in arr:
            sum_a = sum_a + i

        avg_min = math.floor(sum_a/3.0)
        avg_max = math.ceil(sum_a/3.0)
        #print(avg_min,avg_max)

        sum_1 = 0
        sum_2 = 0
        sum_3 = 0
        count = 0
        for i in xrange(len(arr)):
            sum_1 = sum_1 + arr[i]
            #print(sum_1)
            if sum_1 < avg_min or sum_1 > avg_max:
                continue
            sum_2 = 0
            for j in xrange(i+1,len(arr)-1):
                sum_2 = sum_2+arr[j]
                if sum_2 < avg_min or sum_2 > avg_max:
                    continue
                sum_3 = sum_a - sum_1 - sum_2
                if comparee(sum_1,sum_2,sum_3) == True:
                    count = count + 1
                    #print(i,j,sum_1,sum_2,sum_3)
                
        print count

    except EOFError:
        break
