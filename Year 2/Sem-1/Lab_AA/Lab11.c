#include <stdio.h>
#include <stdlib.h>
#define N 100

int mat[N][N];
int noduri[N];
int vizitat[N];
int freeslot = 1;

void initializare(void)
{
	int i,j;
	for (i = 1; i < N; i++)
	{
		noduri[i] = -1;
		for (j = 1; j < N; j++)
			mat[i][j] = -1;
	}
}

void insert_nod(int x)
{
	int i;
	if (freeslot == N)
	{
		printf("No memory\n");
		return;
	}
	noduri[freeslot] = x;
	for (i = 1; i <= freeslot; i++)
	{
		mat[freeslot][i] = 0;
		mat[i][freeslot] = 0;
	}
	freeslot++;
}

void insert_arc(int x, int y)
{
	mat[x][y] = 1;
	mat[y][x] = 1;
}

void afisare_noduri()
{
    printf("\n");
    int i;
    for(i=0;i<N;i++)
    {
        if(noduri[i] != -1){
            if(noduri[i] != 0)
                printf("%d ",noduri[i]);
        }
    }

}

void print_matrice()
{
	int i,j;
	printf("\n\n");
	for (i = 1; i < freeslot; i++)
	{
		for (j = 1; j < freeslot; j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}
}

void stergere_nod(int x)
{
	int i;
	for (i = 1; i < freeslot; i++)
		if (noduri[i] == x) noduri[i] = 0;
	for (i = 1; i < freeslot; i++)
	{
		mat[i][x] = 0;
		mat[x][i] = 0;
	}
}

void stergere_arc(int x,int y)
{
	mat[x][y] = 0;
	mat[y][x] = 0;
}

void initializare_parcurgere()
{
    int i;
    for(i=1; i<freeslot; i++)
        vizitat[i]=0;
}

void parcurgere_graf(int x)
{
	int i;
	for (i = 1; i < freeslot; i++)
		if (noduri[i] == x) vizitat[i] = 1;
	for (i = 1; i < freeslot; i++)
	{
		if (mat[x][i] == 1 && mat[i][x] == 1 && vizitat[i] == 0)
		{
			printf("%d ", i);
			vizitat[i] = 1;
		}
	}
	for (i = 1; i < freeslot; i++)
	{
		if (mat[x][i] == 1 && mat[i][x] == 1 && vizitat[i] == 1)
		{
			parcurgere_graf(i);
		}
	}
}

int main()
{
	int opt, nod, a, b;
	initializare();
	repeat:
	{
		printf("1.Inserare nod\n");
		printf("2.Inserare arc\n");
		printf("3.Afisare matrice\n");
		printf("4.Stergere nod\n");
		printf("5.Stergere arc\n");
		printf("6.Parcurgere graf\n");
		printf("7.Iesire\n");
		printf("Introduceti optiunea dumneavoastra : ");
		scanf("%d", &opt);
		switch (opt)
		{
		case 1:
			getchar();
			printf("Introduceti nodul : ");
			scanf("%d", &nod);
			insert_nod(nod);
			break;

		case 2:
			getchar();
			printf("Introduceti arcul : \n");
			printf("Introduceti nodul initial : ");
			scanf("%d", &a);
			printf("Introduceti nodul final : ");
			scanf("%d", &b);
			insert_arc(a, b);
			break;

		case 3:
            afisare_noduri();
			print_matrice();
			break;

		case 4:
			printf("Introduceti nodul : ");
			scanf("%d", &nod);
			stergere_nod(nod);
			break;

		case 5:
			printf("Introduceti arcul care va fi sters: \n");
			printf("Introduceti nodul initial : ");
			scanf("%d", &a);
			printf("Introduceti nodul final : ");
			scanf("%d", &b);
			stergere_arc(a, b);
			break;

		case 6:
		    printf("Parcurgerea grafului:\n");
			printf("Introduceti nodul de la care se va porni : ");
			scanf("%d", &nod);
			initializare_parcurgere();
			parcurgere_graf(nod);
			break;

		case 7:
			exit(1);
			break;

		default:
			printf("Ati introdus o optiune invalida!\n");
			break;
		}
	}
	goto repeat;

	return 0;
}
