#include <stdio.h>

int max[100][100], alloc[100][100], need[100][100], avail[100], n, r;

void input();
void show();
void cal();

int main() {
    printf("********** Banker's Algorithm ************\n");
    input();
    show();
    cal();
    return 0;
}

void input() {
    int i, j;
    printf("Enter the number of Processes: ");
    scanf("%d", &n);
    printf("Enter the number of resource instances: ");
    scanf("%d", &r);

    printf("Enter the Max Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the Allocation Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter the available Resources:\n");
    for (j = 0; j < r; j++) {
        scanf("%d", &avail[j]);
    }
}

void show() {
    int i, j;
    printf("\nProcess\t Allocation\tMax\t\tAvailable\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t ", i + 1);

        // Print Allocation Matrix
        for (j = 0; j < r; j++) {
            printf("%d ", alloc[i][j]);
        }
        printf("\t\t");

        // Print Max Matrix
        for (j = 0; j < r; j++) {
            printf("%d ", max[i][j]);
        }
        printf("\t\t");

        // Print Available Resources (only for the first process)
        if (i == 0) {
            for (j = 0; j < r; j++) {
                printf("%d ", avail[j]);
            }
        }
        printf("\n");
    }
}
void cal() {
    int finish[100], flag = 1, k, c1 = 0, i, j;

    // Initialize finish array
    for (i = 0; i < n; i++) {
        finish[i] = 0;
    }

    // Calculate need matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    printf("\nSafe Sequence: ");
    while (flag) {
        flag = 0;
        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int c = 0;
                for (j = 0; j < r; j++) {
                    if (need[i][j] <= avail[j]) {
                        c++;
                    }
                }
                if (c == r) {
                    for (k = 0; k < r; k++) {
                        avail[k] += alloc[i][k];
                    }
                    finish[i] = 1;
                    flag = 1;
                    printf("P%d ", i + 1);
                }
            }
        }
    }

    // Check if all processes finished
    for (i = 0; i < n; i++) {
        if (finish[i] == 1) {
            c1++;
        }
    }

    if (c1 == n) {
        printf("\nThe system is in a safe state.\n");
    } else {
        printf("\nThe system is in an unsafe state (deadlock detected).\n");
    }
}
