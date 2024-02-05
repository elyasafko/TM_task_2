#include <stdio.h>
#include "my_mat.h"

// Function to insert the graph
void insertsGraph(int arr[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }   
}
// Function to implement the Floyd-Warshall algorithm
void floydWarshall(int arr[SIZE][SIZE])
{
    for (int k = 0; k < SIZE; k++)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (arr[i][j] == 0 && (i!=j) &&(arr[i][k] != 0 && arr[k][j] != 0))
                {
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
                else if (((arr[k][j] != 0) && (arr[i][k] != 0) && (arr[i][j] > (arr[i][k] + arr[k][j]))))
                {
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }
}

// Function to check if there is a path between two vertices
int 
thereIsPath(int arr[SIZE][SIZE], int i, int j)
{
    if (arr[i][j] != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}