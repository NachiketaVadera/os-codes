from heapq import *

def sstf(hp,reqs):
	requests = reqs.copy()
	time = 0
	position = hp
	n = len(requests)
	heap=[]
	while len(requests)>0:
		for r in requests:
			heappush(heap,(abs(position-r),r))
		x=heappop(heap)[1]
		time+=abs(position-x)
		position=x
		print("        ",x,"  seeked")
		requests.remove(x)
		heap=[]

	avg_seek_time = time/n
	return avg_seek_time


if __name__ == "__main__":
    n = int(input("Enter IO Requests: "))
    hp = int(input("Initial Arm Position(200 MAX): "))
    to_visit = []
    print("Enter positions to visit: ")
    for i in range(n):
        req = int(input())
        to_visit.append(req)

    print(to_visit)

    print("~~~~~~~~~~   SSTF   ~~~~~~~~~~")
    print("avg time for sstf is ", sstf(hp, to_visit))
