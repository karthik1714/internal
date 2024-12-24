#include <stdio.h>

int main() {
    int n, f, rs[25], m[10], pf = 0, time[10] = {0}, current_time = 0;

    printf("Enter length of reference string: ");
    scanf("%d", &n);
    printf("Enter reference string: ");
    for (int i = 0; i < n; i++) scanf("%d", &rs[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);
    for (int i = 0; i < f; i++) m[i] = -1;

    printf("\nPage Replacement Process:\n");
    for (int i = 0; i < n; i++) {
        int found = 0, lru_idx = 0;

        for (int j = 0; j < f; j++) {
            if (m[j] == rs[i]) {
                found = 1;
                time[j] = ++current_time; // Update time for accessed frame
                break;
            }
        }

        if (!found) {
            int min_time = current_time;
            for (int j = 0; j < f; j++) {
                if (m[j] == -1) { // Empty frame available
                    lru_idx = j;
                    break;
                } else if (time[j] < min_time) { // Find LRU frame
                    min_time = time[j];
                    lru_idx = j;
                }
            }
            m[lru_idx] = rs[i];
            time[lru_idx] = ++current_time; // Update time for replaced frame
            pf++;
        }

        for (int j = 0; j < f; j++) printf("%d\t", m[j] != -1 ? m[j] : -1);
        if (!found) printf("PF No. %d", pf);
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", pf);
    return 0;
}
