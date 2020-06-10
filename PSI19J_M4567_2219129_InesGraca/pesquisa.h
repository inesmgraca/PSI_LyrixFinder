#ifndef PESQUISA_H_INCLUDED
#define PESQUISA_H_INCLUDED

void texto9(int lang)
{
    if (lang==0)
    {
        gotoxy(50,5);
        printf("PESQUISA");
        gotoxy(50,10);
        printf("Nome:");
        gotoxy(47,12);
        printf("Artista:");
    }
    else
    {
        gotoxy(55,5);
        printf("SEARCH");
        gotoxy(50,10);
        printf("Name:");
        gotoxy(48,12);
        printf("Artist:");
    }
}

void pesquisa()
{
    char nome[50],artist[50],music[150],r;   // detalhes da música
    int getinfo,cor,lang;                    // infos definições
    char folder[25]=".\\music\\";            // localização do ficheiro

    FILE *corestxt;                          //saber cor e idioma escolhidos
    FILE *langs;
    corestxt=fopen(".\\options\\cor.txt","r");
    langs=fopen(".\\options\\lang.txt","r");
    while (fscanf(corestxt," %i",&getinfo)!=EOF)
    {
        cor=getinfo;
    }
    while (fscanf(langs," %i",&getinfo)!=EOF)
    {
        lang=getinfo;
    }
    fclose(corestxt);
    fclose(langs);

    texto9(lang);

    gotoxy(56,10);
    gets(nome);
    gotoxy(56,12);
    gets(artist);

    strcpy(music,folder);
    strcat(music,nome);
    strcat(music,"_");
    strcat(music,artist);
    strcat(music,".txt");

    strlwr(music);

    for(int i=0;i<strlen(music);i++)
    {
        if (music[i]==' ')
        {
            music[i]='-';
        }
    }

    FILE *musica;
    musica=fopen(music,"r");

    if (musica==NULL)
    {
        if (lang==0)
        {
            gotoxy(5,16);
            printf("A música ainda não consta do programa ");
        }
        else
        {
            gotoxy(5,16);
            printf("The song's not on the program yet ");
        }
    }
    else
    {
        system("cls");
        r=getc(musica);

        do
        {
            printf("%c",r);
            r=getc(musica);
        } while (r!=EOF);
    }

    fclose(musica);
    getch();
    system("cls");
}

#endif // PESQUISA_H_INCLUDED
