#include <stdio.h>

#include <stdlib.h>



#define N 100



int A[N];

int flag = 0;

char chei[N];



void Initializare() {

    int i;

    for (i = 0; i < N; i++) {

        A[i] = -1;

        chei[i] = '|';

    }

    A[0] = -999;



}







void insert(char cheie, char tata) {

    int i,j;

    if (flag == 0 || flag == 1) {

        A[flag+1] = flag;

        chei[flag+1] = cheie;

        ++flag;



    }



    else {



        for (i = 1; i < N; i++)



            if (A[i] == -1) {



                chei[i] = cheie;



                for(j=1;j<i;j++)



                    if (chei[j]==tata)



                    {



                        A[i]=j;



                        return;



                    }



                        printf("\nTatal nu s-a gasit!!\n");



                        chei[i] = '|';



                        return;



            }



    }



}







void afisareArbori() {



    int i;



    for (i = 1; i < N; i++) {



        if (A[i] != -1)



        {



            printf("\n%2d  %c %2d", i, chei[i],A[i]);



        }



    }



}

void stergere(char cheie) {

    int i,j;

    for (i = 1; i < N; i++) {
        if (cheie == chei[i]) {
            for (j = i + 1; j < N; j++) {
                if (A[j] == i) {
                    stergere(chei[j]);
                }
            }
            A[i] = -1;
        }

    }

    return;

}

int main(void) {

    int opt;

    char cheie, tata;

    Initializare();

    while (1) {
        printf("\n1. Initializare\n2. Afisare\n3. Stergere\nOptiunea: ");
        scanf("%d", &opt);
        printf("\n");
        switch (opt) {
        case 1:
            while (1) {
                if (flag == 0 || flag == 1) {
                    printf("Cheie: ");
                    scanf(" %c", &cheie);
                    insert(cheie, 'm');
                    continue;
                }
                printf("Cheie: ");
                scanf(" %c", &cheie);
                if (cheie == 'm')
                    break;
                printf("Tata: ");
                scanf(" %c", &tata);
                insert(cheie, tata);
            }
            break;
        case 2:
             afisareArbori();
            break;
        case 3:
             printf("Cheie: ");
             scanf(" %c",&cheie);
             stergere(cheie);
            break;

        default:
            printf("\nOptiune invalida!");
            break;
        }
    }

    return 0;



}
