//
//  main.cpp
//  PecasTutoring
//
//  Created by Miguel Bazán on 4/7/16.
//  Copyright © 2016 Miguel Bazán. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <iomanip>
using namespace std;

struct Peca{
    double x;
    double y;
};

Peca iArrA[100];
double grafo[100][100];

double distancia(struct Peca a,struct Peca b)
{
    return (sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
}
int minKey(int key[], bool mstSet[], int vertice)
{
    
    int min = INT_MAX, min_index = 0;
    
    for (int v = 0; v < vertice; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    
    return min_index;
}


void printMST(int parent[], int n, double grafo[100][100])
{
    double num = 0;
    for (int i = 1; i < n; i++)
        num += grafo[i][parent[i]];
    
    cout << fixed;
    cout << setprecision(2) << num << endl;
}



void primMST(double grafo[100][100], int vertice)
{
    int parent[vertice];
    int key[vertice];
    bool mstSet[vertice];
    
    
    for (int i = 0; i < vertice; i++)
        key[i] = INT_MAX, mstSet[i] = false;
    
    
    key[0] = 0;
    parent[0] = -1;
    
    
    for (int count = 0; count < vertice-1; count++)
    {
        
        
        int u = minKey(key, mstSet, vertice);
        
        
        mstSet[u] = true;
        
        
        
        for (int v = 0; v < vertice; v++)
            
            
            if (grafo[u][v] && mstSet[v] == false && grafo[u][v] <  key[v])
                parent[v]  = u, key[v] = grafo[u][v];
    }
    
    
    printMST(parent, vertice, grafo);
}



int main(int argc, const char * argv[])
{
    
    
    int vertices;
    cin >> vertices;
    
    
    for (int j=0; j<vertices; j++) {
        cin >> iArrA[j].x >> iArrA[j].y;
    }
    for (int j=0; j<vertices; j++) {
        grafo[j][j] = 0;
    }
    for (int i=0; i<vertices; i++) {
        for (int j=i+1; j<vertices; j++) {
            
            grafo[i][j]=grafo[j][i]=distancia(iArrA[j], iArrA[i]);
        }
    }
    
    primMST(grafo, vertices);
    
    return 0;
}