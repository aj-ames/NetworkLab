#include <stdio.h>

struct network {
        int dist[10];
        int out[10];
} nodes[10];

void init(int n) {
        int i, j;
        for(i=0; i<n; i++) {
                for(j=0; j<n; j++) {
                        if(i!=j) {
                                nodes[i].dist[j] = 999;
                                nodes[i].out[j] = j;
                        }
                }
        }
        nodes[i].dist[j] = 0;
        nodes[i].out[j] = 1;
}

void floyd(int n) {
        int i,j,k;
        for(k=0; k<n; k++) {
                for(i=0; i<n; i++) {
                        for(j=0; j<n; j++) {
                                if(nodes[i].dist[j] > (nodes[i].dist[k]+nodes[k].dist[j])) {
                                        nodes[i].out[j] = k;
                                        nodes[i].dist[j] = (nodes[i].dist[k]+nodes[k].dist[j]);
                                }
                        }
                }
        }
}

int main() {
        int n, i, j;
        printf("Enter the number of nodes: ");
        scanf("%d", &n);
        printf("\n");

        init(n);

        for(i=0; i<n; i++) {
                for(j=0; j<n; j++) {
                        if(i!=j) {
                                printf("Enter the value of node %d to node %d: \t", i+1, j+1);
                                scanf("%d", &nodes[i].dist[j]);
                                printf("\n");
                        }
                }
        }

        floyd(n);

        printf("The distance vector table is as follows:\n");
        for(i=0; i<n; i++) {
                printf("Node\tDist\tHops\n");
                for(j=0; j<n; j++) {
                        printf("%d\t%d\t%d\n", j+1, nodes[i].dist[j], nodes[i].out[j]+1);
                }
        }
        return 0;
}
