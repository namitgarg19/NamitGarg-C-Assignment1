#include "mylib.h"
#include <stdio.h>

/* reverse digits of a non-negative integer */
int reverseDigits(int n) {
    int r = 0;
    int sign = (n < 0) ? -1 : 1;
    if (n < 0) n = -n;
    while (n > 0) {
        r = r * 10 + (n % 10);
        n /= 10;
    }
    return r * sign;
}

int isArmstrong(int num) {
    if (num < 0) return 0;
    int tmp = num;
    int digits = 0;
    while (tmp > 0) { digits++; tmp /= 10; }
    if (digits == 0) digits = 1;

    tmp = num;
    int sum = 0;
    while (tmp > 0) {
        int d = tmp % 10;
        int p = 1;
        for (int i = 0; i < digits; ++i) p *= d;
        sum += p;
        tmp /= 10;
    }
    return (sum == num);
}

int isAdams(int num) {
    if (num < 0) return 0;
    int sq = num * num;
    int rev_sq = reverseDigits(sq);
    int rev_num = reverseDigits(num);
    int rev_num_sq = rev_num * rev_num;
    return (rev_sq == rev_num_sq);
}

int isPrime(int num) {
    if (num <= 1) return 0;
    if (num <= 3) return 1;
    if (num % 2 == 0) return 0;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int isPrimePalindrome(int num) {
    if (num < 0) return 0;
    if (!isPrime(num)) return 0;
    int rev = reverseDigits(num);
    return (rev == num);
}
