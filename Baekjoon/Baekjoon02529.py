def solve():
    if len(num_list) == n + 1:
        num = num_list[0]
        for i in range(n):
            if not ((signs[i] == '>' and num_list[i] > num_list[i + 1]) or
                    (signs[i] == '<' and num_list[i] < num_list[i + 1])):
                return

            num *= 10
            num += num_list[i + 1]

        ans[0] = min(ans[0], num)
        ans[1] = max(ans[1], num)
    else:
        for i in range(10):
            if not visited[i]:
                visited[i] = True
                num_list.append(i)
                solve()
                num_list.pop()
                visited[i] = False


n = int(input())
signs = input().split()

ans = [9999999999, 0]
num_list = []
visited = [False] * 10

solve()

if len(str(ans[1])) < n + 1:
    print(0, end='')
print(ans[1])

if len(str(ans[0])) < n + 1:
    print(0, end='')
print(ans[0])
