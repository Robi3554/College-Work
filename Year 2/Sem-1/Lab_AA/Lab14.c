#include <stdio.h>
#include <stdlib.h>
#define INF 999
#define N 10

//void dijkstra(int G[N][N], int n, int st_nod)

void dijkstra(int G[N][N], int n, int st_nod){
    int cost[N][N], dist[N], pred[N];
    int vizitat[N], counter, min_dist, next_node, i, j;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            if(G[i][j] == 0)
                cost[i][j] = INF;
            else
                cost[i][j] = G[i][j];
    for(i = 0; i < n; i++){
        dist[i] = cost[st_nod][i];
        pred[i] = st_nod;
        vizitat[i] = 0;
    }
    dist[st_nod] = 0;
    vizitat[st_nod] = 1;
    counter = 1;
    while (counter < n-1){
        min_dist = INF;
        for(i = 0; i < n; i++)
            if(dist[i] < min_dist&& !vizitat[i]){
                min_dist = dist[i];
                next_node = i;
            }
    }
}

int main(){
    int G[N][N], i, j, n, u;
    printf("Introdu numarul de noduri: ");
    scanf("%d", &n);
    printf("\nIntrodu matricea de adiacenta: \n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &G[i][j]);
    printf("\nIntrodu nodul de inceput: ");
    scanf("%d", &u);
    dijkstra(G, n, u);
    return 0;
}
