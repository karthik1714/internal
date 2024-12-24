#include<stdio.h>

void main() {
    int buck_size, outgoing, n, incoming, store = 0;
    printf("Enter bucket size, outgoing rate and number of inputs: ");
    scanf("%d %d %d", &buck_size, &outgoing, &n);

    while (n--) {
        printf("Enter the incoming packet size: ");
        scanf("%d", &incoming);

        if (incoming <= (buck_size - store)) {
            store += incoming;
            printf("Bucket buffer size %d out of %d\n", store, buck_size);
        } else {
            printf("Dropped %d packets\n", incoming - (buck_size - store));
            store = buck_size;
            printf("Bucket buffer size %d out of %d\n", store, buck_size);
        }

        store = store - outgoing;
        printf("After outgoing, %d packets left out of %d in buffer\n", store, buck_size);
    }
}
