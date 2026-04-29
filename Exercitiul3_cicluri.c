#include <stdio.h>
#include <stdbool.h>

#define MAX 5

int adj[MAX][MAX] = {
    {0, 1, 1, 0, 0}, 
    {1, 0, 1, 0, 0}, 
    {1, 1, 0, 0, 0}, 
    {0, 0, 0, 0, 1},
    {0, 0, 0, 1, 0}
};

bool vizitat[MAX];


bool areCiclu(int nod, int parinte) {
    vizitat[nod] = true;

    for (int i = 0; i < MAX; i++) {
       
        if (adj[nod][i] == 1) {
          
            if (!vizitat[i]) {
                if (areCiclu(i, nod)) return true;
            } 
          
            else if (i != parinte) {
                return true;
            }
        }
    }
    return false;
}

int main() {

    for (int i = 0; i < MAX; i++) vizitat[i] = false;

    bool gasit = false;

    for (int i = 0; i < MAX; i++) {
        if (!vizitat[i]) {
            if (areCiclu(i, -1)) { // -1 inseamna ca primul nod nu are parinte
                gasit = true;
                break;
            }
        }
    }

    if (gasit) {
        printf("Rezultat: Graful contine cel putin un ciclu.\n");
    } else {
        printf("Rezultat: Graful NU contine cicluri.\n");
    }

    return 0;
}