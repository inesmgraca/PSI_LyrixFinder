#include <stdio.h>
#include <stdlib.h>
#include <conio.c>
#include <locale.h>
#include <string.h>
#include <time.h>
#include "addmusic.h"
#include "cores.h"
#include "favoritos.h"
#include "idioma.h"
#include "intro.h"
#include "login.h"
#include "pesquisa.h"
#include "registo.h"
#include "menu.h"

int main()
{
    int a=0,admin;                      //0- regular user, 1- admin
    setlocale(LC_ALL,"Portuguese");
    textcolor(15);

    intro();

    do
    {
        admin=login();
        a=menu(admin);
    } while (a==1);

    FILE *cores;
    cores=fopen(".\\options\\cor.txt","w");
    fprintf(cores,"0\n");
    fclose(cores);
    FILE *userlogin;
    userlogin=fopen(".\\user\\userlogin.txt","w");
    fprintf(userlogin,"");
    fclose(userlogin);
    return 0;

}
