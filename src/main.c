#include <stdio.h>
#include <stdlib.h>

void imprimir_matriz(int **matriz, int linha, int coluna){
    int i,j;
    for (i=0; i < linha; i++){
        for (j=0; j < coluna; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
}

int main(){
    FILE* arqent;
    int qtdItens;
    int qtdDim;
    int melhorSol;
    int **montante;
    int i, j;
    
    arqent = fopen("hp1.dat", "r");
    if(arqent == NULL){
		printf("Erro\n");
		exit(1);
	}
    else{
        fscanf(arqent, "%d %d %d", &qtdItens, &qtdDim, &melhorSol);
        qtdDim+=1;
        montante = malloc(qtdDim * sizeof(int *));
        for(int i=0; i < qtdDim; i++){
            montante[i] = malloc(qtdItens * sizeof(int));
        }

        for (j=0; j < qtdItens; j++)
            fscanf(arqent, "%d", &montante[0][j]);
        
        for (i=1; i < qtdDim; ++i)
            for (j=0; j < qtdItens; ++j){
                fscanf(arqent, "%d", &montante[i][j]);
            }

        fclose(arqent);
    }
    imprimir_matriz(montante, qtdDim, qtdItens);
}