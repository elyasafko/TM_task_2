#include <stdio.h>
#include "my_mat.h"

// Function to insert the graph
void insertsGraph(int arr[][SIZE])
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            scanf("%d", &arr[i][j]);
}

// Function to implement the Floyd-Warshall algorithm
void floydWarshall(int arr[][SIZE])
{
    for (int k = 0; k < SIZE; k++)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (arr[i][j] == 0 && (i!=j) &&(arr[i][k] != 0 && arr[k][j] != 0))
                    arr[i][j] = arr[i][k] + arr[k][j];
                else if (((arr[k][j] != 0) && (arr[i][k] != 0) && (arr[i][j] > (arr[i][k] + arr[k][j]))))
                    arr[i][j] = arr[i][k] + arr[k][j];
            }
        }
    }
}

// Function to check if there is a path between two vertices
int thereIsPath(int arr[][SIZE], int i, int j)
{
    if (arr[i][j] != 0)
        return 1;
    else
        return 0;
}

// Function to implement the knapsack algorithm
int knapSack (int weights[], int values[], int selected_bool[])
{
    int i, w;
    int result[ITEMSAMOUNT + 1][MAXWEIGHT + 1];

    for (i = 0; i <= ITEMSAMOUNT; i++) 
    {
        for (w = 0; w <= MAXWEIGHT; w++) 
        {
            if (i == 0 || w == 0)
                result[i][w] = 0;
            else if (weights[i - 1] <= w)
                result[i][w] = max(values[i - 1] + result[i - 1][w - weights[i - 1]], result[i - 1][w]);
            else
                result[i][w] = result[i - 1][w];
        }
    }

    int res = result[ITEMSAMOUNT][MAXWEIGHT];
    w = MAXWEIGHT;
    for (i = ITEMSAMOUNT; i > 0 && res > 0; i--) 
    {
        if (res == result[i - 1][w])
            continue;
        else 
        {
            selected_bool[i - 1] = 1;
            res -= values[i - 1];
            w -= weights[i - 1];
        }
    }

    return result[ITEMSAMOUNT][MAXWEIGHT];
}
// Function to find the maximum of two integers
int max(int a, int b) {return (a > b) ? a : b;}