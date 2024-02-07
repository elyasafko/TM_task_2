#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "my_mat.h"


int main()
{
    char items[ITEMSAMOUNT];
    int values[ITEMSAMOUNT];
    int weights[ITEMSAMOUNT];
    int selected_bool[ITEMSAMOUNT];

   
    for (size_t i = 0; i < ITEMSAMOUNT-1; i++)
    {
        scanf("%c", &items[i]);
        scanf("%d", &values[i]);
        scanf("%d ", &weights[i]);
    }
    scanf("%c", &items[ITEMSAMOUNT-1]);
    scanf("%d", &values[ITEMSAMOUNT-1]);
    scanf("%d", &weights[ITEMSAMOUNT-1]);

    printf("Maximum profit: %d\n", knapSack(weights, values, selected_bool));
    printf("Items that give the maximum profit: ");
    for (size_t i = 0; i < ITEMSAMOUNT; i++)
    {
        if (selected_bool[i] == 1)
        {
            printf("%c ", items[i]);
        }
    }
    printf("\n");
    
    free(selected_bool);
    free(weights);
    free(values);
    free(items);

    return 0;
}

