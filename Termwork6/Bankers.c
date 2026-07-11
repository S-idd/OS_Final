#include <stdio.h>

int main() {

    int p, r;
    int i, j, k;

    printf("Enter Number Of Processes : ");
    scanf("%d", &p);

    printf("Enter Number Of Resources : ");
    scanf("%d", &r);

    int alloc[10][10], max[10][10], need[10][10];
    int avail[10], finish[10] = {0}, safe[10];

    printf("\nEnter Allocation Matrix:\n");
    for(i = 0; i < p; i++)
        for(j = 0; j < r; j++)
            scanf("%d", &alloc[i][j]);

    printf("\nEnter Maximum Matrix:\n");
    for(i = 0; i < p; i++)
        for(j = 0; j < r; j++)
            scanf("%d", &max[i][j]);

    printf("\nEnter Available Resources:\n");
    for(i = 0; i < r; i++)
        scanf("%d", &avail[i]);

    // Need = Max - Allocation
    for(i = 0; i < p; i++)
        for(j = 0; j < r; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    int count = 0;

    while(count < p) {

        int found = 0;

        for(i = 0; i < p; i++) {

            if(finish[i] == 0) {

                for(j = 0; j < r; j++)
                    if(need[i][j] > avail[j])
                        break;

                if(j == r) {

                    safe[count++] = i;
                    finish[i] = 1;

                    for(k = 0; k < r; k++)
                        avail[k] += alloc[i][k];

                    found = 1;
                }
            }
        }

        if(found == 0)
            break;
    }

    if(count == p) {

        printf("\nSystem Is In Safe State\n");
        printf("Safe Sequence : ");

        for(i = 0; i < p; i++)
            printf("P%d ", safe[i]);

    } else {

        printf("\nSystem Is Not In Safe State\n");

    }

    return 0;
}
