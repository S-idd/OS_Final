#include <stdio.h>
#include <stdlib.h>

int main() {

    int tp, hc, choice;
    int i, j, pos = 0;

    int p[20], status[20], hp[20];

    printf("Enter Total Number Of Philosophers : ");
    scanf("%d", &tp);

    for(i = 0; i < tp; i++) {
        p[i] = i + 1;
        status[i] = 1;
    }

    printf("Enter The Number Of Hungry Philosophers : ");
    scanf("%d", &hc);

    if(hc == tp) {
        printf("\nAll Philosophers Are Hungry\n");
        printf("Dead Lock Will Occur\n");
        return 0;
    }

    for(i = 0; i < hc; i++) {
        printf("Enter The %d Position Of Hungry Philosopher : ", i + 1);
        scanf("%d", &hp[i]);

        if(hp[i] < 1 || hp[i] > tp) {
            printf("Invalid Position\n");
            return 0;
        }

        hp[i]--;
        status[hp[i]] = 2;
    }

    do {

        printf("\n1.Allow One Philosopher To Eat");
        printf("\n2.Exit");
        printf("\nEnter Your Choice : ");
        scanf("%d", &choice);

        if(choice == 1) {

            if(pos < hc) {

                printf("\nOnly One Philosopher Eats At A Time:\n");

                printf("\nPhilosopher %d Is Eating\n", p[hp[pos]]);

                for(j = pos + 1; j < hc; j++)
                    printf("Philosopher %d Is Waiting\n", p[hp[j]]);

                printf("--------------------------\n");

                pos++;

            } else {
                printf("\nAll Hungry Philosophers Have Eaten.\n");
            }

        }
        else if(choice == 2) {
            printf("\nProgram Terminated\n");
            break;
        }
        else {
            printf("Invalid Choice!\n");
        }

    } while(1);

    return 0;
}