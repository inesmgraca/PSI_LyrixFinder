#ifndef ADDMUSIC_H_INCLUDED
#define ADDMUSIC_H_INCLUDED

char addmusic()
{
    char nome[50],artist[50],album[50],music[100];

    printf("\n   Detalhes da música \n");
    printf("\n Música: ");
    printf("\n Artista: ");
    printf("\n Álbum: ");

    gotoxy(10,4);
    gets(music);

    gotoxy(11,5);
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
    printf("\n Detalhes guardados no ficheiro %s \n",music);

    printf("\n Insira as lyrics da música \n (clique para continuar) \n\n");
    getch();

    fclose(musica);
    system(music);

    menu();
}

#endif // ADDMUSIC_H_INCLUDED
