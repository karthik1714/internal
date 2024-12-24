#include <stdio.h>
#include <string.h>

struct fileTable {
    char name[20];
    int blocks[30]; // Array to store block numbers
    int nob; // Number of blocks
} ft[30];

void linkedAllocation(int n) {
    printf("\nLinked Allocation:\n");
    printf("File Name\tNumber of Blocks\tLinked Blocks\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t\t%d\t\t", ft[i].name, ft[i].nob);
        for (int j = 0; j < ft[i].nob; j++) {
            printf("%d", ft[i].blocks[j]);
            if (j != ft[i].nob - 1) {
                printf(" -> ");
            }
        }
        printf("\n");
    }
}

int main() {
    int n;

    // Input number of files
    printf("Enter number of files: ");
    scanf("%d", &n);

    // Input file details
    for (int i = 0; i < n; i++) {
        printf("\nEnter file name %d: ", i + 1);
        scanf("%s", ft[i].name);
        printf("Enter number of blocks in file %d: ", i + 1);
        scanf("%d", &ft[i].nob);
        printf("Enter the blocks for file %d: ", i + 1);
        for (int j = 0; j < ft[i].nob; j++) {
            scanf("%d", &ft[i].blocks[j]);
        }
    }

    // Simulate Linked Allocation
    linkedAllocation(n);

    return 0;
}
