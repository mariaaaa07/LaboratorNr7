#include <stdio.h>
#include <stdbool.h>

#define N 4 


int graf_orientat[N][N] = {
    {0, 1, 0, 0}, 
    {0, 0, 1, 0}, 
    {0, 0, 0, 1}, 
    {0, 0, 0, 0}  
};

bool vizitat[N];


bool verificaDrum(int curent, int tinta) {
    if (curent == tinta) {
        return true;
    }

    vizitat[curent] = true;

    for (int i = 0; i < N; i++) {
        if (graf_orientat[curent][i] == 1 && !vizitat[i]) {
            if (verificaDrum(i, tinta)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int start = 0, final = 3;
    
    for(int i = 0; i < N; i++) vizitat[i] = false;

    if (verificaDrum(start, final)) {
        printf("Exista drum intre nodul %d si nodul %d.\n", start, final);
    } else {
        printf("NU exista drum intre nodul %d si nodul %d.\n", start, final);
    }

    return 0;
}