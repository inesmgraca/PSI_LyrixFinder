#ifndef FAVORITOS_H_INCLUDED
#define FAVORITOS_H_INCLUDED

void favoritos()
{
    int lang,c=0;
    char r,admin[25],fav[200],folder1[25]=".\\fav\\";
    setlocale(LC_ALL,"Portuguese");

    FILE *langs;             //saber idioma escolhido anteriormente
    langs=fopen(".\\options\\lang.txt","r");
    fscanf(langs,"%i",&lang);
    fclose(langs);

    FILE *userlogin;
    userlogin=fopen(".\\user\\userlogin.txt","r");
    r=getc(userlogin);

    do
    {
        admin[c]=r;
        r=getc(userlogin);
        c++;
    } while (r!=EOF);

    fclose(userlogin);

    if (lang==0)
    {
        gotoxy(35,5);
        printf("FAVORITOS");
    }
    else
    {
        gotoxy(35,5);
        printf("FAVORITES");
    }

    strcpy(fav,folder1);
    strcat(fav,admin);
    strcat(fav,".txt");

    FILE *favoritos;
    favoritos=fopen(fav,"r");

    gotoxy(1,10);
    r=getc(favoritos);

    do
    {
        printf("%c",r);
        r=getc(favoritos);

    } while (r!=EOF);

    fclose(favoritos);
    getch();
    system("cls");
}

#endif // FAVORITOS_H_INCLUDED
