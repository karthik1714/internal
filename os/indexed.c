#include <stdio.h>
#include <string.h>

struct fileTable {
    char name[20];
    int blocks[30]; // Array to store block numbers
    int nob; // Number of blocks
} ft[30];

void indexedAllocation(int n) {
    printf("\nIndexed Allocation:\n");
    printf("File Name\tNumber of Blocks\tIndexed Blocks\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t\t%d\t\t", ft[i].name, ft[i].nob);
        for (int j = 0; j < ft[i].nob; j++) {
            printf("%d ", ft[i].blocks[j]);
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

    // Simulate Indexed Allocation
    indexedAllocation(n);

    return 0;
}
