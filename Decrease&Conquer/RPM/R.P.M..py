import random
import time

def rpm(n,m):
    ret=0
    while(n>0):
        if(n%2):
            ret+=m
        n=n>>1
        m=m<<1
    return ret

start_t1=time.time()
ret1=19534236238247351384500342 * 39925363457925217438
end_t1=time.time()
print("수식의 결과: ", ret1)
print("일반 수식의 경우 걸리는 시간: ", "%0.6f" %float(end_t1-start_t1))

start_t2=time.time()
ret2=rpm(19534236238247351384500342, 39925363457925217438)
end_t2=time.time()
print("수식의 결과: ", ret2)
print("Russian peasant 방식의 경우 걸리는 시간: ", "%0.6f" %float(end_t2-start_t2))

