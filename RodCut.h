#ifndef RODCUT_H
#define RODCUT_H

void READ_PRICES(int A[], int n);
int MAX(int A, int B);
int CUT_ROD(int P[], int n);
int MEMOIZED_CUT_ROD(int P[], int n);
int BOTTOM_UP_CUT_ROD(int P[], int n);
int MEMOIZED_CUT_ROD_AUX(int P[], int n, int R[]);

#endif // RODCUT_H
