#include <stdio.h>

int main() {
    int n, f, pf = 0, count = 0, rs[25], m[10];

    printf("Enter the length of reference string: ");
    scanf("%d", &n);
    printf("Enter the reference string: ");
    for (int i = 0; i < n; i++) 
        scanf("%d", &rs[i]);

    printf("Enter the number of frames: ");
        scanf("%d", &f);

    for (int i = 0; i < f; i++) 
        m[i] = -1;

    printf("\nPage Replacement Process:\n");
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int k = 0; k < f; k++) 
            if (m[k] == rs[i]) 
            found = 1;

        if (!found) {
            m[count] = rs[i];
            count = (count + 1) % f;
            pf++;
        }

        for (int j = 0; j < f; j++) printf("%d\t", m[j] != -1 ? m[j] : -1);
        if (!found) printf("PF No. %d", pf);
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", pf);
    return 0;
}
