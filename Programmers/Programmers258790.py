# Programmers258790.py
from bisect import bisect_left, bisect_right
from copy import deepcopy

def get_dice_sum_list(dice, dice_list, team_list):
    n = len(dice_list)

    def solve(idx, curr):
        if idx >= n:
            team_list.append(curr)
        else:
            for i in range(6):
                solve(idx + 1, curr + dice[dice_list[idx]][i])
    solve(0, 0)

def solution(dice):
    n = len(dice)
    half = n // 2
    isTeam1 = [False] * n

    ans = (0, [])
    def select(team1, team2, idx):
        nonlocal ans
        if len(team1) == half and len(team2) == half:
            team1_score, team2_score = [], []
            get_dice_sum_list(dice, team1, team1_score)
            get_dice_sum_list(dice, team2, team2_score)

            team1_score.sort()

            win, lose, draw = 0, 0, 0
            for target in team2_score:
                low = bisect_left(team1_score, target)
                high = bisect_right(team1_score, target)

                lose += low
                draw += high - low
                win += len(team1_score) - high

            if ans[0] < win:
                ans = (win, deepcopy(team1))

        else:
            if len(team1) < half:
                team1.append(idx)
                select(team1, team2, idx + 1)
                team1.pop()

            if len(team2) < half:
                team2.append(idx)
                select(team1, team2, idx + 1)
                team2.pop()

    select([], [], 0)

    for i in range(len(ans[1])):
        ans[1][i] += 1

    return ans[1]
