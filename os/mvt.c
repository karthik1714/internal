#include <stdio.h>

int main() {
    int totalMemory, availableMemory, processMemory, processCount = 0;
    char choice = 'y';

    printf("Enter total memory available (in Bytes): ");
    scanf("%d", &totalMemory);
    availableMemory = totalMemory;

    while (choice == 'y'  && availableMemory > 0) {
        printf("Enter memory required for process %d (in Bytes): ", processCount + 1);
        scanf("%d", &processMemory);

        if (processMemory <= availableMemory) {
            printf("Memory allocated for Process %d\n", ++processCount);
            availableMemory -= processMemory;
        } else {
            printf("Memory is Full\n");
            break;
        }

        printf("Do you want to continue (y/n)? ");
        scanf(" %c", &choice);
    }

    printf("\nTotal Memory Available: %d\nTotal Memory Allocated: %d\nExternal Fragmentation: %d\n",
           totalMemory, totalMemory - availableMemory, availableMemory);

    return 0;
}
