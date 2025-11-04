import json

n = int(input())

arr = ""
for _ in range(n):
    arr += input().rstrip()
j = json.loads(arr)

ans = sorted(j, key=lambda x: (-x["score"], x["name"]))

prev_rank = 1
if (ans[0]["isHidden"] == 0):
    print(1, ans[0]["name"], ans[0]["score"])

for i in range(1, n):
    if (ans[i - 1]["score"] != ans[i]["score"]):
        prev_rank = i + 1

    if (ans[i]["isHidden"] == 0):
        print(prev_rank, ans[i]["name"], ans[i]["score"])
