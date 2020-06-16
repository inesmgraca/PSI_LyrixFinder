#ifndef INFOS_H_INCLUDED
#define INFOS_H_INCLUDED

void favoritos()
{
    int lang=getlang(),c=0;
    char r,user[25],fav[200]=".\\fav\\";

    FILE *userlogin;
    userlogin=fopen(".\\user\\userlogin.txt","r");
    r=getc(userlogin);

    while (r!=EOF)
    {
        user[c]=r;
        r=getc(userlogin);
        c++;
    }

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

    strcat(fav,user);
    strcat(fav,".txt");

    FILE *favorites;
    favorites=fopen(fav,"r");

    gotoxy(1,10);

    if (favorites==NULL)
    {
        if (lang==0)
            printf("    Não tem favoritos ");
        else
            printf("    You have no favorites ");
    }
    else
    {
        r=getc(favorites);

        do
        {
            printf("%c",r);
            r=getc(favorites);

        } while (r!=EOF);
    }

    fclose(favorites);
    getch();
    system("cls");
}

void registo()
{
    int lang=getlang();
    char r;
    setlocale(LC_ALL,"Portuguese");

    FILE *registo;
    if (lang==0)
    {
        registo=fopen(".\\registos\\registo_pt.txt","r");
        gotoxy(40,5);
        printf("REGISTO");
    }
    else
    {
        registo=fopen(".\\registos\\registo_en.txt","r");
        gotoxy(35,5);
        printf("REGISTRY");
    }

    gotoxy(1,10);
    r=getc(registo);

    do
    {
        printf("%c",r);
        r=getc(registo);

    } while (r!=EOF);

    fclose(registo);
    getch();
    system("cls");
}

#endif // INFOS_H_INCLUDED
