#include<stdio.h>
#include<limits.h>

void main(){
    int V;
    printf("Enter Number of vertex : ");
    scanf("%d", &V);
    int G[V][V];
    printf("Enter the Adjacency Matrix : \n");
    for(int i = 0 ; i < V ; i++){
        for(int j = 0 ; j < V ; j++){
            scanf("%d", &G[i][j]);
        }
    }
    int selected[V];
    for(int i = 0 ; i < V ; i ++){
        selected[i] = 0;
    }
    selected[0] = 1;
    int E = 0;
    int x,y;
    int totalCost = 0;
    printf("Edge  : Weight \n");
    while(E < V - 1 ){
        int min = INT_MAX;
        x = 0;
        y = 0;
        for(int i = 0; i < V ; i++){
            if(selected[i]){
                for(int j = 0 ; j < V ; j++){
                    if(!selected[j] && G[i][j]){
                        if(G[i][j] < min){
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        selected[y] = 1;
        printf("%d - %d : %d \n", x , y , G[x][y]);
        totalCost += G[x][y];
        E++;
    }
    printf("Total cost : %d", totalCost);
}
