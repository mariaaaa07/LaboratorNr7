#include <stdio.h>
#include <stdbool.h>

int adj[5][5] = {
    {0, 1, 1, 0, 0},
    {1, 0, 0, 1, 1},
    {1, 0, 0, 0, 1},
    {0, 1, 0, 0, 0},
    {0, 1, 1, 0, 0}
};

bool vizitat[5];

void DFS(int nod) {
    printf("%d ", nod);
    vizitat[nod] = true;
    
    for (int i = 0; i < 5; i++) {
        if (adj[nod][i] == 1 && !vizitat[i]) {
            DFS(i);
        }
    }
}

void BFS(int start) {
    bool viz[5] = {false};
    int coada[5], prim = 0, ultim = 0;

    viz[start] = true;
    coada[ultim++] = start;

    while (prim < ultim) {
        int nod_curent = coada[prim++];
        printf("%d ", nod_curent);

        for (int i = 0; i < 5; i++) {
            if (adj[nod_curent][i] == 1 && !viz[i]) {
                viz[i] = true;
                coada[ultim++] = i;
            }
        }
    }
}

int main() {
    printf("Parcurgere DFS (pornind din 0): ");
    DFS(0);
    
    printf("\nParcurgere BFS (pornind din 0): ");
    BFS(0); 
    return 0;
}