#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "my_mat.h"


int main()
{
    char items[ITEMSAMOUNT] = {'A', 'B', 'C', 'D', 'E'};
    int values[ITEMSAMOUNT];
    int weights[ITEMSAMOUNT];
    int selected_bool[ITEMSAMOUNT];
    char results[ITEMSAMOUNT];

    printf("Enter the values of the items: \n");
    for (int i = 0; i < ITEMSAMOUNT; i++)
    {
        scanf("%d", &values[i]);
    }
    printf("Enter the weights of the items: \n");
    for (int i = 0; i < ITEMSAMOUNT; i++)
    {
        scanf("%d", &weights[i]);
    }
    printf("Maximum profit: %d\n", knapSack(weights, values, selected_bool));
    printf("Items that give the maximum profit: ");
    for (int i = 0; i < ITEMSAMOUNT; i++)
    {
        if (results[i] == 1)
        {
            printf("%c ", items[i]);
        }
    }
    printf("\n");
    return 0;
}

