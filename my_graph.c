#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "my_mat.h"


int main()
{
    int i, j;
    char choice;
    int arr[SIZE][SIZE];

    do{
        scanf(" %c", &choice);

        switch (choice)
        {
        case 'A':
            insertsGraph(arr);
            floydWarshall(arr);
            break;
        case 'B':
            scanf("%d %d", &i, &j);
            printf("%s\n", thereIsPath(arr, i, j) ? "True" : "False");
            break;
        case 'C':
            scanf("%d %d", &i, &j);
            if (arr[i][j] != 0)
                printf("%d\n", arr[i][j]);
            else
                printf("-1\n");
            break;
        default:
            break;
        }
    }
    while (choice != 'D' && !EOF);


    return 0;
}