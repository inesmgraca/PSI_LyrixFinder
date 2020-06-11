#ifndef ADDMUSIC_H_INCLUDED
#define ADDMUSIC_H_INCLUDED

void texto7(int lang)
{
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

void texto8(int lang)
{
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
}

void addmusic()
{
    int key,op=0,opc=0,text[5]={3,6,10,12,13};
    char nome[50],artist[50],album[50],music[125]; // detalhes da música
    int horas,minutos,segundos,dia,mes,ano;        // tempo e data de adição/alteração
    int getinfo,cor,lang;                          // infos definições
    char r,admin[25];                              // infos admin
    char folder[25]=".\\music\\";                  // localização do ficheiro

    FILE *corestxt;                                // saber cor e idioma escolhidos
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

    texto7(lang);

    gotoxy(56,10);
    gets(nome);
    gotoxy(56,12);
    gets(artist);
    gotoxy(56,14);
    gets(album);

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

    FILE *useradmin;
    useradmin=fopen(".\\user\\userlogin.txt","r");
    r=getc(useradmin);

    do
    {
        printf("%c",r);
        r=getc(useradmin);
    } while (r!=EOF);

    FILE *registo_pt;
    registo_pt=fopen(".\\registos\\registo_pt.txt","a");
    FILE *registo_en;
    registo_en=fopen(".\\registos\\registo_en.txt","a");


    const char *existe = music;

    if (access(existe,F_OK)==-1)
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

        getch();
    }
    else
    {
        texto8(lang);

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
                        {
                            op--;
                        }
                        break;
                    case 77:
                        if (op!=1)
                        {
                            op++;
                        }
                        break;
                }
            }
            else if (key==13)
            {
                if (op==0)
                {
                    system(music);

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
                opc=1;
            }

        } while (opc!=1);
    }

    fclose(registo_pt);
    fclose(registo_en);

    getch();
    system("cls");
}

#endif // ADDMUSIC_H_INCLUDED
