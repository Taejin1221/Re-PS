// Baekjoon01340.cpp
#include <cstdio>

#include <cstring>

using namespace std;

int main(void) {
    char month[10];
    int day, year, hour, minute;
    scanf("%s %d, %d %d:%d", month, &day, &year, &hour, &minute);

    // 1월을 days[1], 2월을 days[2] 등으로 접근하기 위해 days[0]을 비워둠
    int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    char englishMonth[13][10] = { "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

    // 윤달 처리
    if (year % 400 == 0)
        days[2]++;
    else if (year % 100 != 0 && year % 4 == 0)
        days[2]++;

    // 총 소요 "분" 계산 및 입력 값 "월" 문자열 => 숫자
    int totalTime = 0, currMonth;
    for (int i = 1; i <= 12; i++) {
        totalTime += 60 * 24 * days[i];
        if (strcmp(month, englishMonth[i]) == 0)
            currMonth = i;
    }

    // 주어진 입력까지 소요 "분" 계산
    int passTime = 0;
    for (int i = 1; i < currMonth; i++)
        passTime += 60 * 24 * days[i];
    passTime += 60 * 24 * (day - 1) + hour * 60 + minute;

    printf("%.9lf\n", (double)passTime / totalTime * 100);

    return 0;
}