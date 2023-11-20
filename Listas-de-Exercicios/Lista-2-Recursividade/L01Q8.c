#include <stdio.h>

#define MAX_N 50000 // Número máximo de pessoas na população
#define MAX_M 100000 // Número máximo de linhas após a primeira

int parent[MAX_N + 1];

int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        parent[rootX] = rootY;
    }
}

int main() {
    int n, m;
    int i; // Declare a variável i aqui
    scanf("%d %d", &n, &m);

    for (i = 1; i <= n; i++) {
        parent[i] = i; // Inicialmente, cada pessoa é seu próprio pai
    }

    for (i = 0; i < m; i++) {
        int person1, person2;
        scanf("%d %d", &person1, &person2);

        unionSets(person1, person2); // Une as famílias das duas pessoas
    }

    int distinctFamilies = 0;
    for (i = 1; i <= n; i++) {
        if (parent[i] == i) {
            distinctFamilies++;
        }
    }

    printf("%d\n", distinctFamilies);

    return 0;
}