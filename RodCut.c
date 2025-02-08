#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "RodCut.h"

void READ_PRICES(int A[], int n) {
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
    }
}

int MAX(int A, int B) {
    return (A > B) ? A : B;
}

int CUT_ROD(int P[], int n) {  //metoda recursiva; backtracking;
    if (n == 0) {
        return 0; // nu putem taia nimic
    }
    int q = INT_MIN;  //parcurge toate lungimile 1<=i<=n
    for (int i = 1; i <= n; i++) {
        q = MAX(q, P[i] + CUT_ROD(P, n - i)); //pentru fiecare i se apeleaza functia CUT_ROD care cauta solutia maxima
    }
    return q; t
}

int MEMOIZED_CUT_ROD_AUX(int P[], int n, int R[]) {
    if (R[n] >= 0) { //parcurge toate lungimile si le stocheaza in R
        return R[n];
    }
    int q;
    if (n == 0) {
        q = 0;
    } else {
        q = INT_MIN;
        for (int i = 1; i <= n; i++) {
            q = MAX(q, P[i] + MEMOIZED_CUT_ROD_AUX(P, n - i, R));
        }
    }
    R[n] = q;
    return q;
}

int MEMOIZED_CUT_ROD(int P[], int n) {
    int R[25];
    for (int i = 0; i <= n; i++) {
        R[i] = INT_MIN;
    }
    return MEMOIZED_CUT_ROD_AUX(P, n, R); //ajuta la memorare, evita calculele deja facute
}

int BOTTOM_UP_CUT_ROD(int P[], int n) { //iterativ
    int R[25];
    R[0] = 0;
    for (int j = 1; j <= n; j++) {
        int q = INT_MIN;
        for (int i = 1; i <= j; i++) {
            q = MAX(q, P[i] + R[j - i]);
        }
        R[j] = q;
    }
    return R[n];
}
