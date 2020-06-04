#include <stdio.h>
#include <stdlib.h>
#include <conio.c>
#include <locale.h>
#include <string.h>
#include <time.h>
#include "addmusic.h"
#include "cores.h"
#include "idioma.h"
#include "intro.h"
#include "login.h"
#include "menu.h"
#include "pesquisa.h"
#include "registo.h"

int main()
{
    int a=0,admin;                      //0- regular user, 1- admin
    setlocale(LC_ALL,"Portuguese");
    textcolor(15);

    intro();

    login:
    admin=login();
    a=menu(admin);

    if (a==1)
    {
        goto login;
    }
    else
    {
        FILE *cores;
        cores=fopen(".\\options\\cor.txt","w");
        fprintf(cores,"0\n");
        fclose(cores);
        return 0;
    }
}
