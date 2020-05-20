#ifndef ADDMUSIC_H_INCLUDED
#define ADDMUSIC_H_INCLUDED

void addmusic(int lang)
{
    char nome[50],artist[50],album[50],music[150];  // detalhes da música
    int horas,minutos,segundos,dia,mes,ano;         // tempo e data de adição
    int a;                                          // posição para pôr artista

    if (lang==0)
    {
        printf("\n   Detalhes da música \n");
        printf("\n Nome: \n Artista: \n Álbum: ");
        a=11;
    }
    else
    {
        printf("\n   Song details \n");
        printf("\n Name: \n Artist: \n Album: ");
        a=10;
    }

    gotoxy(8,4);
    gets(music);

    gotoxy(a,5);
    gets(artist);

    gotoxy(9,6);
    gets(album);

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
    musica=fopen(music,"w+");

    fprintf(musica,"\n%s\n by %s\n in %s\n\n",nome,artist,album);
    fclose(musica);

    if (lang==0)
    {
        printf("\n Detalhes guardados no ficheiro %s \n",music);
        printf("\n Insira as lyrics da música \n (clique para continuar) \n\n");
    }
    else
    {
        printf("\n Details saved in file %s \n",music);
        printf("\n Insert song lyrics \n (click to continue) \n\n");
    }

    getch();
    system(music);
    system("cls");

    FILE *registo_pt;
    registo_pt=fopen("registo_pt.txt","a");
    FILE *registo_en;
    registo_en=fopen("registo_en.txt","a");

    time_t atual;
    time(&atual); //obtém o tempo atual, time() dá o valor atual em formato time_t
    struct tm *tempo=localtime(&atual);
    //localtime converte valor em formato time_t e devolve ponteiro para tm struct

    horas=tempo->tm_hour;
    minutos=tempo->tm_min;
    segundos=tempo->tm_sec;
    dia=tempo->tm_mday;
    mes=tempo->tm_mon+1;
    ano=tempo->tm_year+1900;

    if (lang==0)
    {
        printf("Música adicionada às %02d:%02d:%02d ",horas,minutos,segundos);
        printf("no dia %02d/%02d/%d \n",dia,mes,ano);
    }
    else
    {
        printf("Music added at %02d:%02d:%02d ",horas,minutos,segundos);
        printf("in %02d/%02d/%d \n",dia,mes,ano);
    }

    fprintf(registo_en,"admin added %s at ",music);                                 //! corrigir admin para %s qd criar login
    fprintf(registo_en,"%02d:%02d:%02d in ",horas,minutos,segundos);
    fprintf(registo_en,"%02d/%02d/%d\n",dia,mes,ano);

    fprintf(registo_pt,"admin adicionou %s às ",music);                             //! corrigir também
    fprintf(registo_pt,"%02d:%02d:%02d no dia ",horas,minutos,segundos);
    fprintf(registo_pt,"%02d/%02d/%d\n",dia,mes,ano);

    fclose(registo_pt);
    fclose(registo_en);
}

#endif // ADDMUSIC_H_INCLUDED
