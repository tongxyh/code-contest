import time
time_begin = time.time()

import sys
import copy
sys.setrecursionlimit(1000000)

x,y,z,start,end = [int(i) for i in raw_input().split()]

def lowest(number,start,value_list):
    if number > 2*end or number < 1:
        return
    if value_list[number - 1] == 0 or min_list[number - 1] >=0:
        return
    else:
        value_list[number - 1] = 0
        if number == start:
            min_list[number - 1] = 0
            return

        lowest(number-2,start,copy.deepcopy(value_list))
        lowest(number+2,start,copy.deepcopy(value_list))
        if(number%2 == 0):
            lowest(number/2,start,copy.deepcopy(value_list))

        a = 100000
        b = 100000
        c = 100000

        if number - 2 > 0 and min_list[number - 1 - 2] >= 0:
            a = min_list[number - 1 - 2] + x
        if number + 2 < 2*end and min_list[number - 1 + 2] >= 0:
            b = min_list[number - 1 + 2] + z
        if number > 0 and number % 2 == 0 and min_list[number%2] >= 0:
            c = min_list[number/2 -1 ] + y
        min_list[number - 1] = min(a,b,c)
        return

min_list = [ -1 for i in range(2*end)]
value_list = [ -1 for i in range(2*end)]

lowest(end,start,value_list)

print(min_list[end-1])
print('spend:',time.time()-time_begin,'s')

#3 100 1 2 10000
#817
#('spend:', 582.8257219791412, 's')
