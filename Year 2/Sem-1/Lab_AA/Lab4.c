#include <stdio.h>
#include <stdlib.h>

#define N 100

int A[N];
int chei[N];
int prim_fiu[N];
int frate[N];
int liber = 1;

void initializare(void){

    int i;
    for (i = 1; i < N; i++){
        A[i] = -1;
        chei[i] = -1;
        prim_fiu[i] = -1;
        frate[i] = -1;
    }
}

void insert(char cheie, int father){

    int i;
    if (liber == N){
        printf("NU ESTE MEMORIE!\n");
        return;
}
    A[liber] = father;
    chei[liber] = cheie;
    prim_fiu[liber] = -1;
    frate[liber] = -1;
    if (prim_fiu[father] == -1)
        prim_fiu[father] = liber;
    for (i = 1; i < liber; i++)
        if (A[i] == father && frate[i] == -1)
            frate[i] = liber;
    liber++;
}

void stergere_stramosi(int tatal){



    int i = 0;

    for (i = 1; i < liber; i++){

        if (A[i] == tatal){

            A[i] = -1;

            chei[i] = -1;

            prim_fiu[i] = -1;

            frate[i] = -1;

        }

    }

}



void stergere(char cheie){

    int i,j;

    for (i = 1; i < liber; i++){

        if (chei[i] == cheie){

            stergere_stramosi(i);

        if (prim_fiu[A[i]] == i)

         prim_fiu[A[i]] = frate[i];

        for (j = 1; j < liber; j++)

            if (frate[j] == i)

             frate[j] = frate[i];

          A[i] = -1;

          chei[i] = -1;

          prim_fiu[i] = -1;

          frate[i] = -1;

        }

    }

}



void afisare(){

    int i;

    printf("\nArborele este alcatuit din :\n");

    for (i = 1; i < liber; i++){

        if (chei[i] != -1)

            printf("Nodul %d | chei %c | tata %d | prim fiu %d | frate dreapta %d\n", i, chei[i], A[i], prim_fiu[i], frate[i]);

    }

}



int Prim_fiu(int cheie){

    int i;

    for(i=0; i < N; i++){

        if(chei[i] == i) break;

        if((i == (N-1)) && (chei[i]!=cheie))

            return -1;

        return (prim_fiu[i]);

    }

}



int set_prim_fiu(int parent,int cheie){

    int i;

    for(i=0; i < N;i++)

        if(chei[i]==i)

            break;

        if( (i==(N-1)) && ((cheie)!=parent))

            return -1;



        if(prim_fiu[parent]==0)

            prim_fiu[parent]=i;

            return -1;

}



int main()

{

    int opt, tatal;

    char cheie;

    initializare();

    while (1){

        printf("Meniul este : \n");

        printf("1.Inserare nod\n");

        printf("2.Stergere nod\n");

        printf("3.Afisare tablou\n");

        printf("4.Iesire\n");

        printf("Introduceti optiunea dumneavoastra : ");

        scanf("%d", &opt);



        switch (opt){

        case 1:

            getchar();

            printf("Introduceti cheia nodului : ");

            scanf("%c", &cheie);

            printf("Introduceti tatal nodului : ");

            scanf("%d", &tatal);

            insert(cheie, tatal);

            break;

        case 2:

            getchar();

            printf("Introduceti cheia nodului : ");

            scanf("%c", &cheie);

            stergere(cheie);

            break;

        case 3:

            afisare();

            break;

        case 4:

            exit(1);

            break;

        default:

            printf("Ati introdus o optiune invalida!\n");

        break;

    }

  }

    return 0;

}
