#ifndef PESQUISA_H_INCLUDED
#define PESQUISA_H_INCLUDED

void pesquisa()
{
    char nome[50],artist[50],music[100],r;   // detalhes da música
    int getinfo,cor,lang,a;                  // a- posição para pôr artista

    FILE *corestxt;                          //saber cor e idioma escolhidos
    FILE *langs;
    corestxt=fopen("cor.txt","r");
    langs=fopen("lang.txt","r");
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

    if (lang==0)
    {
        printf("\n   Detalhes da música \n");
        printf("\n Nome: \n Artista: ");
        a=11;
    }
    else
    {
        printf("\n   Song details \n");
        printf("\n Name: \n Artist: ");
        a=10;
    }

    gotoxy(8,4);
    gets(music);

    gotoxy(a,5);
    gets(artist);

    strcpy(nome,music);

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
            printf("Erro \n");
        }
        else
        {
            printf("Error \n");
        }
    }
    else
    {
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
