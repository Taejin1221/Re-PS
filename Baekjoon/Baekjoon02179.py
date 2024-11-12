# Baekjoon02179.py
import sys
input = sys.stdin.readline

n = int(input())

word_list = { } # 각 단어의 index 정보
for i in range(n):
    word = input().rstrip()
    word_list[word] = i

sorted_word_list = sorted(list(word_list.keys()))

def get_prefix_same(str1, str2):
    result = 0
    for i in range(min(len(str1), len(str2))):
        if str1[i] == str2[i]:
            result += 1
        else:
            break

    return result

a, b = sorted_word_list[:2]
if word_list[a] < word_list[b]:
    ans = [a, b]
else:
    ans = [b, a]

ans_num = get_prefix_same(a, b)
for i in range(1, n):
    j = i - 1

    a, b = sorted_word_list[i], sorted_word_list[j]
    prefix = threshold = get_prefix_same(a, b)

    while j >= 0 and prefix == threshold:
        if word_list[a] < word_list[b]:
            curr = [a, b]
        else:
            curr = [b, a]

        if ans_num == prefix:
            if (word_list[ans[0]] >= word_list[curr[0]]) and (word_list[ans[1]] > word_list[curr[1]]):
                ans = curr
                ans_num = prefix
        elif ans_num < prefix:
            ans = curr
            ans_num = prefix

        j -= 1
        b = sorted_word_list[j]
        prefix = get_prefix_same(a, b)

print(ans[0], ans[1], sep='\n')
