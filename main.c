#include <stdio.h>
#include <stdlib.h>
#include "RodCut.h"

int main() {
    int n;
    int A[25];  //stocheaza pretul bucatilor de tija

    scanf("%d", &n); //lungimea totala a tijei
    READ_PRICES(A, n); //citeste preturile fiecarei bucati de tija i

    int maxvalue;

    maxvalue = CUT_ROD(A, n); //metoda recursiva simpla
    printf("%d\n", maxvalue);

    maxvalue = MEMOIZED_CUT_ROD(A, n); //metoda recursiva care tine minte
    printf("%d\n", maxvalue);

    maxvalue = BOTTOM_UP_CUT_ROD(A, n); //metoda iterativa bottom up
    printf("%d\n", maxvalue);

    return 0;
}
