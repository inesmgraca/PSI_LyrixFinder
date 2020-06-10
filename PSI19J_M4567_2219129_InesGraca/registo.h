#ifndef REGISTO_H_INCLUDED
#define REGISTO_H_INCLUDED

void registo()
{
    int lang;
    char r;
    setlocale(LC_ALL,"Portuguese");

    FILE *langs;             //saber idioma escolhido anteriormente
    langs=fopen(".\\options\\lang.txt","r");
    fscanf(langs,"%i",&lang);
    fclose(langs);

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

    printf("\n");
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

#endif // REGISTO_H_INCLUDED
