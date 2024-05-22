N = int(input())
visited = [0] * (N+1)
prime = []
for i in range(2,N+1):
    if visited[i] == 0:
        prime.append(i)
        j = i
        while j<=N:
            visited[j] = 1
            j += i
cnt = [0] * (N+1)
for i in range(2,N+1):
    now = i
    for num in prime:
        while now % num == 0:
            now //= num
            cnt[num] += 2

ans = 1
for i in range(2,N+1):
    ans *= (cnt[i]+1)
print(ans)    