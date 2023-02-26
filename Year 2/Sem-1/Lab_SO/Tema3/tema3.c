#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>


int total = 0;
int curent = 0;
int pas[7];
int poz = 0;
int timp = 0;

int pfdata[2],pfstat[2];
pid_t fiu;

void stat()
{
	printf("Semnalul SIGUSR1 a fost primit!\n");
	pas[poz] = curent;
	poz++;
	total+=curent;
	curent = 0;
}

void finproc()
{
	int i;
	write(pfstat[1], &total, sizeof(int));

	for (i = 0; i < 7; i++){
		write(pfstat[1], &pas[i], sizeof(int));
	}

	close(pfstat[1]);
	exit(0);
}

void alarma()
{
    	int i=0;

	if (timp == 7)
	{
		kill(fiu, SIGUSR2);

		read(pfstat[0], &total, sizeof(int));

		printf("Procesul fiu a terminat executia!\nStatistici:\n");

		while (read(pfstat[0], &pas[i], sizeof(int)) > 0)
		{
			printf("Numarul de caractere primite dupa SIGUSR1 nr %d : %d\n",i+1, pas[i]);
			i++;
		}

		printf("Numarul total de caractere trimise: %d\n", total);
		close(pfstat[0]);
		exit(0);

	}
	else
	{
		kill(fiu, SIGUSR1);
		timp++;
		alarm(1);
	}
}

int main()
{
	char buffer;
	int i;
	
	printf("Se incepe numaratoarea!\n");
	alarm(1);

	if (pipe(pfdata) < 0)
    	{
		perror("Eroare la pipe-ul de date!\n");
		exit(1);
	}

	if (pipe(pfstat) < 0)
    	{
		perror("Eroare la pipe-ul de statistici!\n");
		exit(1);
	}

	if ((fiu = fork()) < 0)
    	{
		perror("Eroare la fork!\n");
		exit(2);
	}

	if (fiu == 0)
	{
		close(pfdata[1]);
		close(pfstat[0]);
		
		signal(SIGUSR1, stat);
		signal(SIGUSR2, finproc);

		while(read(pfdata[0], &buffer, 1) > 0)
			curent++;
        
		close(pfdata[0]);
		close(pfstat[0]);	
		exit(0);
	}
	
	else
    	{
		close(pfdata[0]);
		close(pfstat[1]);

		signal(SIGALRM, alarma);

		alarm(1);

		while(1)
			write(pfdata[1], "e", 1);
			
		close(pfdata[0]);
		close(pfstat[1]);
	}
	return 0;
}
