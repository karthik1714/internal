#include <stdio.h>
#define MAX 20

struct node {
    unsigned dist[MAX], from[MAX];
} rt[MAX];..nn

int main() {
    int dmat[MAX][MAX], n;

    // Input number of nodes and the cost matrix
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dmat[i][j]);
            if (i == j) dmat[i][j] = 0;  // No cost to reach itself
            rt[i].dist[j] = dmat[i][j];
            rt[i].from[j] = j;
        }
    }

    // Bellman-Ford algorithm to update the distance vectors
    int count;
    do {
        count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    // If a shorter path is found through a neighbor, update the table
                    if (rt[i].dist[j] > dmat[i][k] + rt[k].dist[j]) {
                        rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j];
                        rt[i].from[j] = k;
                        count++;
                    }
                }
            }
        }
    } while (count > 0);

    // Print the routing table for each node
    for (int i = 0; i < n; i++) {
        printf("\nRouting table for node %d:\n", i + 1);
        for (int j = 0; j < n; j++) {
            printf("To node %d via %d, Distance: %d\n", j + 1, rt[i].from[j] + 1, rt[i].dist[j]);
        }
    }

    return 0;
}
 