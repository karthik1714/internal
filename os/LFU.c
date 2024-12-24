#include<stdio.h>
int main() {
    int rs[50], a[20], cntr[20], m, f, i, j, k, min, pf = 0;
    printf("\nEnter number of page references: ");
    scanf("%d", &m);
    printf("\nEnter the reference string: ");
    for(i = 0; i < m; i++) scanf("%d", &rs[i]);
    printf("\nEnter available frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++) { 
        cntr[i] = 0; 
        a[i] = -1; 
        }

    printf("\nThe Page Replacement Process:\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < f; j++) {
            if(rs[i] == a[j]) {
                cntr[j]++; break;
            }
        }
        if(j == f) {
            min = 0;
            for(k = 1; k < f; k++) 
            if(cntr[k] < cntr[min]) 
                min = k;
            a[min] = rs[i]; 
            cntr[min] = 1; 
            pf++;
        }
        for(j = 0; j < f; j++) printf("\t%d", a[j]);
        if(j == f) printf("\tPF No. %d", pf);
        printf("\n");
    }
    printf("\nTotal page faults: %d", pf);
    return 0;
}
