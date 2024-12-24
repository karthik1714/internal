#include <stdio.h>
#include <string.h>

struct fileTable {
    char name[20];
    int sb; // Starting Block
    int nob; // Number of blocks
} ft[30];

int main() {
    int n;

    // Input number of files
    printf("Enter number of files: ");
    scanf("%d", &n);

    // Input file details
    for (int i = 0; i < n; i++) {
        printf("\nEnter file name %d: ", i + 1);
        scanf("%s", ft[i].name);
        printf("Enter starting block for file %d: ", i + 1);
        scanf("%d", &ft[i].sb);
        printf("Enter number of blocks in file %d: ", i + 1);
        scanf("%d", &ft[i].nob);
    }

    // Simulate Sequential Allocation
    printf("\nSequential Allocation:\n");
    printf("File Name\tStarting Block\tNumber of Blocks\tIndexed Blocks\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t\t%d\t\t%d\t\t", ft[i].name, ft[i].sb, ft[i].nob);
        for (int j = 0; j < ft[i].nob; j++) {
            printf("%d ", ft[i].sb + j);
        }
        printf("\n");
    }

    return 0;
}
