from heapq import *

def cscan(hp,reqs):
	requests = reqs.copy()
	pos = hp
	time = 0
	end = 200
	start = 0
	for i in range(pos, end+1):
		if i in requests:
			time += abs(pos-i)
			pos = i
			print("        ",i,"  seeked")
			requests.remove(i)
	time+=abs(pos-end)
	pos=end
	
	for i in range(start,hp+1):
		if i in requests:
			time+=abs(pos-i)
			pos=i
			print("        ",i,"  seeked")
			requests.remove(i)
	
	
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

    print("~~~~~~~~~~   CSCAN   ~~~~~~~~~~")
    print("avg time for cscan is ", cscan(hp, to_visit))