#include <stdio.h>

int main() {

    int ch, i, j;

    int start, len;      // sequential allocation

    int n, b[20], found;  // linked allocation

    char f[20];

    printf("1. Sequential\n2. Linked\nChoice: ");

    scanf("%d", &ch);

    // ---------------- SEQUENTIAL ----------------
    if (ch == 1) {

        printf("File name: "); // File Name 

        scanf("%s", f);

        printf("Start block: "); //start 

        scanf("%d", &start);

        printf("Length: ");// Length 

        scanf("%d", &len);

       for (i = 0; i < 20; i++) {

            if (i >= start && i < start + len){

                printf("%d[A] ", i);

	}else{

                printf("%d ", i);

	}
      }
    }

    // ---------------- LINKED ----------------
    else if (ch == 2) {

        printf("File name: ");

        scanf("%s", f);

        printf("Number of blocks: ");
	
        scanf("%d", &n);

        printf("Enter blocks:\n");

        for (i = 0; i < n; i++) {
	
            scanf("%d", &b[i]); //Blocks Input 
	}


      
	for (i = 0; i < 20; i++) {

            found = 0;

            for (j = 0; j < n; j++) {

                if (i == b[j]) {

                    found = 1;

                    break;
                }
            }

            if (found){

                printf("%d[A] ", i);
	    }
            else {

                printf("%d ", i);
	    }
        }

        printf("\nChain: ");

        for (i = 0; i < n; i++) {

            printf("%d", b[i]);

            if (i != n - 1)

                printf(" -> ");

        }
    }

    else {
        printf("Invalid choice!\n");
    }

    printf("\n");

    return 0;
}

