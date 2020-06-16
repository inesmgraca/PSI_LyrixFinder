#ifndef ADDMUSIC_H_INCLUDED
#define ADDMUSIC_H_INCLUDED

void text1()
{
    int lang=getlang();

    if (lang==0)
    {
        gotoxy(46,5);
        printf("DETALHES DA MÚSICA");
        gotoxy(50,10);
        printf("Nome:");
        gotoxy(47,12);
        printf("Artista:");
        gotoxy(49,14);
        printf("Álbum:");
    }
    else
    {
        gotoxy(49,5);
        printf("SONG DETAILS");
        gotoxy(50,10);
        printf("Name:");
        gotoxy(48,12);
        printf("Artist:");
        gotoxy(49,14);
        printf("Album:");
    }
}

int op1()
{
    int key,op=0,text[]={3,6,10,12,13};
    int lang=getlang(),cor=getcor();

    if (lang==0)
    {
        gotoxy(5,17);
        printf("A música já existe");
        gotoxy(5,19);
        printf("Deseja alterar as lyrics?");
        gotoxy(5,21);
        printf("SIM     NÃO");
    }
    else
    {
        gotoxy(5,17);
        printf("The song already exists");
        gotoxy(5,19);
        printf("Would you like to change the lyrics?");
        gotoxy(5,21);
        printf("YES     NO");
    }

    do
    {
        textbackground(text[cor]); //cor do highlight da opção

        if (lang==0)
        {
            if (op==0)
            {
                gotoxy(4,21); //local do highlight da opção 0
                printf(" SIM ");
            }
            else
            {
                gotoxy(12,21); //local do highlight da opção 1
                printf(" NÃO ");
            }
        }
        else
        {
            if (op==0)
            {
                gotoxy(4,21); //local do highlight da opção 0
                printf(" YES ");
            }
            else
            {
                gotoxy(12,21); //local do highlight da opção 1
                printf(" NO ");
            }
        }

        gotoxy(1,25);
        key=_getch();

        system("color 0F");

        if(key==0 || key==224)
        {
            switch (_getch())
            {
            case 75:
                if (op!=0)
                    op--;
                break;
            case 77:
                if (op!=1)
                    op++;
                break;
            }
        }

    } while (key!=13);

    return op;
}

void addmusic()
{
    int op,c=0,lang=getlang();                     // infos definições
    char nome[50],artist[50],album[50],music[125]; // detalhes da música
    int horas,minutos,segundos,dia,mes,ano;        // tempo e data de adição/alteração
    char r,admin[25];                              // infos admin

    text1();

    gotoxy(56,10);
    gets(nome);
    gotoxy(56,12);
    gets(artist);
    gotoxy(56,14);
    gets(album);

    strcpy(music,".\\music\\");
    strcat(music,nome);
    strcat(music,"_");
    strcat(music,artist);
    strcat(music,".txt");
    strlwr(music);

    for(int i=0;i<strlen(music);i++)
    {
        if (music[i]==' ')
            music[i]='-';
    }

    FILE *useradmin;
    useradmin=fopen(".\\user\\userlogin.txt","r");
    r=getc(useradmin);

    do
    {
        admin[c]=r;
        r=getc(useradmin);
        c++;
    } while (r!=EOF);

    FILE *registo_pt;
    registo_pt=fopen(".\\registos\\registo_pt.txt","a");
    FILE *registo_en;
    registo_en=fopen(".\\registos\\registo_en.txt","a");

    fclose(useradmin);

    const char *song = music;

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

    if (access(song,F_OK)==-1)
    {
        FILE *musica;
        musica=fopen(music,"w");

        fprintf(musica,"\n%s\n by %s\n in %s\n\n Lyrics:\n\n",nome,artist,album);
        fclose(musica);

        if (lang==0)
        {
            gotoxy(5,17);
            printf("Detalhes guardados em %s",music);
            gotoxy(5,19);
            printf("Clique para inserir as lyrics da música ");
        }
        else
        {
            gotoxy(5,17);
            printf("Details saved in %s",music);
            gotoxy(5,19);
            printf("Click to insert song lyrics ");
        }

        getch();
        system(music);

        if (lang==0)
        {
            gotoxy(5,19);
            printf("Música adicionada às %02i:%02i:%02i ",horas,minutos,segundos);
            printf("no dia %02i/%02i/%i ",dia,mes,ano);
        }
        else
        {
            gotoxy(5,19);
            printf("Music added at %02i:%02i:%02i ",horas,minutos,segundos);
            printf("in %02i/%02i/%i ",dia,mes,ano);
        }

        fprintf(registo_en,"     %s added %s at ",admin,music);
        fprintf(registo_en,"%02i:%02i:%02i in ",horas,minutos,segundos);
        fprintf(registo_en,"%02i/%02i/%i\n",dia,mes,ano);

        fprintf(registo_pt,"     %s adicionou %s às ",admin,music);
        fprintf(registo_pt,"%02i:%02i:%02i no dia ",horas,minutos,segundos);
        fprintf(registo_pt,"%02i/%02i/%i\n",dia,mes,ano);
    }
    else
    {
        op=op1();

        if (op==0)
        {
            system(music);

            if (lang==0)
            {
                gotoxy(33,19);
                printf("SIM");
                gotoxy(5,21);
                printf("Música alterada às %02i:%02i:%02i ",horas,minutos,segundos);
                printf("no dia %02i/%02i/%i ",dia,mes,ano);
            }
            else
            {
                gotoxy(44,19);
                printf("YES");
                gotoxy(5,21);
                printf("Music modified at %02i:%02i:%02i ",horas,minutos,segundos);
                printf("in %02i/%02i/%i ",dia,mes,ano);
            }

            fprintf(registo_en,"     %s modified %s at ",admin,music);
            fprintf(registo_en,"%02i:%02i:%02i in ",horas,minutos,segundos);
            fprintf(registo_en,"%02i/%02i/%i\n",dia,mes,ano);

            fprintf(registo_pt,"     %s alterou %s às ",admin,music);
            fprintf(registo_pt,"%02i:%02i:%02i no dia ",horas,minutos,segundos);
            fprintf(registo_pt,"%02i/%02i/%i\n",dia,mes,ano);
        }
        else
        {
            if (lang==0)
            {
                gotoxy(33,19);
                printf("NÃO");
                gotoxy(5,21);
                printf("Operação cancelada ");
            }
            else
            {
                gotoxy(44,19);
                printf("NO");
                gotoxy(5,21);
                printf("Operation canceled ");
            }
        }
    }

    fclose(registo_pt);
    fclose(registo_en);

    getch();
    system("cls");
}

#endif // ADDMUSIC_H_INCLUDED
