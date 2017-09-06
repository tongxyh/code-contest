import math
# raw_input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Google Code Jam problems.
class Node(object):
    """Nodes"""
    def __init__(self, time_arrive=-1,cities=-1, lchild=None, rchild=None):
		self.ta = time_arrive
		self.cities = cities
		self.lchild = lchild
		self.rchild = rchild

t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
	N,Ts,Tf = [int(x) for x in raw_input().split(" ")]
	start_time = []
	freq = []
	duration = []
	for j in xrange(1,N):
		s,f,d = [int(x) for x in raw_input().split(" ")]  # read a list of integers, 2 in this case
		start_time.append(s)
		freq.append(f)
		duration.append(d)

	def GrowTree(time_arrive,cities,city_now):


		if city_now == N-1:
			return Node(time_arrive,cities),cities
		
		if start_time[city_now] < time_arrive:
			to_next_bus = start_time[city_now] + freq[city_now]*math.ceil((time_arrive - start_time[city_now])*1./freq[city_now]) - time_arrive
		else:
			to_next_bus = start_time[city_now] - time_arrive
		#print(time_arrive,cities)
		if to_next_bus >= Ts:
			if to_next_bus+time_arrive+duration[city_now] > Tf:
				return Node(time_arrive,cities),-1
			Leave = None
			NotLeave,all_cities = GrowTree(to_next_bus+time_arrive+duration[city_now],cities+1,city_now+1)
		else:
			Leave_time = time_arrive + to_next_bus + freq[city_now]*math.ceil((Ts - to_next_bus)*1./freq[city_now])
	
			if to_next_bus+time_arrive+duration[city_now] <= Tf:
				Leave,all_cities_1 = GrowTree(to_next_bus+time_arrive+duration[city_now],cities,city_now+1)
			else:
				Leave = None
				all_cities_1 = -1
			if Leave_time+duration[city_now] <= Tf:
				NotLeave,all_cities_2 = GrowTree(Leave_time+duration[city_now],cities+1,city_now+1)
			else:
				NotLeave = None
				all_cities_2 = -1

			if all_cities_2 > all_cities_1:
				all_cities = all_cities_2
			else:
				all_cities = all_cities_1
		return Node(time_arrive,cities,Leave,NotLeave),all_cities
	onbus_time = 0
	BusTree,num = GrowTree(0,0,0)
	if num >= 0:
		print "Case #{}: {}".format(i, num)
	else:
		print "Case #{}: IMPOSSIBLE".format(i)
  # check out .format's specification for more formatting options