#include <stdio.h>

#define N 5 

int adj[N][N] = {
    {0, 1, 1, 0, 0},
    {1, 0, 0, 1, 1},
    {1, 0, 0, 0, 1},
    {0, 1, 0, 0, 0},
    {0, 1, 1, 0, 0}
};

int valori[N] = {10, 5, 20, 30, 5}; 

int calculeazaDistanta() {
    int minV = valori[0], maxV = valori[0];
    int dist[N], coada[N], prim = 0, ultim = 0;

    
    for (int i = 0; i < N; i++) {
        if (valori[i] < minV) minV = valori[i];
        if (valori[i] > maxV) maxV = valori[i];
        dist[i] = -1; 
    }

    if (minV == maxV) return 0; 

   
    for (int i = 0; i < N; i++) {
        if (valori[i] == minV) {
            dist[i] = 0;
            coada[ultim++] = i;
        }
    }

    
    while (prim < ultim) {
        int u = coada[prim++];

       
        for (int v = 0; v < N; v++) {
            if (adj[u][v] == 1 && dist[v] == -1) {
                dist[v] = dist[u] + 1; 
                
                
                if (valori[v] == maxV) return dist[v];
                
                coada[ultim++] = v;
            }
        }
    }

    return -1;
}

int main() {
    int rezultat = calculeazaDistanta();
    
    if (rezultat != -1) {
        printf("Distanta minima intre Min si Max este: %d muchii.\n", rezultat);
    } else {
        printf("Nu exista drum intre nodurile Min si Max.\n");
    }
    
    return 0;
}