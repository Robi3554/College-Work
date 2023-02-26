#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

void ModFiles(char *source, char *dest)
{
	int r=open(source, O_RDONLY);
	int w=creat(dest, S_IREAD|S_IWRITE);
	int citit;
	char buffer[1024];
	while(citit=read(r, &buffer, 4))
	{
		buffer[citit]="\0";
		write(w,buffer,4);
	}
	close(r);
	close(w);
}

void list(char *path, char *dest)
{
	struct stat stare;
	char Path[1024];
	char Dest[1024];
	struct dirent *entry;
	DIR *dr;
	if((dr=opendir(path))==NULL)
	{
		return -1;
	}
	 while ((entry = readdir(dr)) != NULL)
    	{
        	if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
        	{
			printf("\n%s\n", entry->d_name);
                        strcpy(Path, path);
                        strcat(Path, "/");
                        strcat(Path, entry->d_name);	
			stat(Path,&stare);

					strcpy(Dest, dest);
                                        strcat(Dest, "/");
                                        strcat(Dest, entry->d_name);
			if(S_ISDIR(stare.st_mode))
				{
					mkdir(Dest,stare.st_mode);
					printf("S-a creat directorul cu numele %s!\n", Dest);		
				}
			
			if(S_ISREG(stare.st_mode))
			{
				if(stare.st_size >= 500 )
					{
						ModFiles(Path,Dest);
						chmod(Dest,stare.st_mode|S_IWUSR|S_IWGRP|S_IWOTH);
						printf("S-a modificat fisierul %s!\n", Path);
					}
				else if(stare.st_size < 500 && stare.st_size >=300)
					{
						link(Path,Dest);
						printf("Hardlink a fost creat pt %s!\n", Path);
					}
				else if(stare.st_size < 300)
					{
						symlink(Path,Dest);
						chmod(Dest,stare.st_mode);
						printf("Symlink a fost creat pt %s!\n", Path);
					}	
			}
                        list(Path,Dest);	
		}
        }
}

void main(int argc, char* argv[])
{
	DIR *dr;
	struct dirent *entryData;
	char source[100],dest[100],aux;
	
	if(argv[1]==NULL || argv[2]== NULL)
		printf("[ + ] USAGE: ./runme [SOURCE] destination");
		
	strcpy(source,argv[1]);
	strcpy(dest,argv[2]);

	if((dr=opendir(dest))==NULL)
	{
		printf("Nu a fost gasit directorul destinatie !\nDoriti sa il creati acum [Y/n]: ");
		aux=getchar();
		if(tolower(aux)=='y')
		{
			mkdir(dest, S_IRUSR | S_IWUSR | S_IXUSR);
			printf("\nDirectorul a fost creat!\n");
		}
		else
		{
			return -1;
		}
	}
	list(source,dest);	
}


