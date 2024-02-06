#ifndef _MY_MAT_H
#define _MY_MAT_H
#define SIZE 10
#define MAXWEIGHT 20
#define ITEMSAMOUNT 5


void insertsGraph(int arr[][SIZE]);
void floydWarshall(int arr[][SIZE]);
int thereIsPath(int arr[][SIZE], int i, int j);
int knapSack (int weights[], int values[], int selected_bool[]);

#endif