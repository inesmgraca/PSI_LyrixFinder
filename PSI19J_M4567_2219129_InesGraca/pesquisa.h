#ifndef PESQUISA_H_INCLUDED
#define PESQUISA_H_INCLUDED

void texto5(int lang)
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

void texto6(int lang)
{
    if (lang==0)
    {
        gotoxy(50,5);
        printf("MÚSICA");
        gotoxy(48,12);
        printf("de");
        gotoxy(48,14);
        printf("em");
        gotoxy(5,17);
        printf("Deseja adicionar a música aos seus favoritos?");
        gotoxy(5,19);
        printf("SIM     NÃO");
    }
    else
    {
        gotoxy(56,5);
        printf("SONG");
        gotoxy(5,17);
        printf("Would you like to add the song to your favorites?");
        gotoxy(5,19);
        printf("YES     NO");
    }
}

void pesquisa()
{
    int key,op=0,opc=0,text[5]={3,6,10,12,13},c=0;
    char nome[50],artist[50],music[150],r;          // detalhes da música
    int getinfo,cor,lang;                           // infos definições
    char admin[25],folder[25]=".\\music\\";         // localização do ficheiro música
    char fav[200],folder1[25]=".\\fav\\",m[4][60];  // localização do ficheiro favoritos, infos música

    FILE *corestxt;                                 // saber cor e idioma escolhidos
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

    texto5(lang);

    gotoxy(56,10);
    gets(nome);
    gotoxy(56,12);
    gets(artist);

    strcpy(music,folder);
    strlwr(nome);
    strlwr(artist);

    strcat(music,nome);
    strcat(music,"_");
    strcat(music,artist);
    strcat(music,".txt");

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

        getch();
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

        if (lang==0)
        {
            gotoxy(2,3);
            printf("de");
            gotoxy(2,4);
            printf("em");
        }

        gotoxy(1,1);
        gotoxy(10,6);

        getch();
        system("cls");

        rewind(musica);

        for (int i=1;i<5;i++)
        {
            fgets(m[i-1],60,musica);
        }

        gotoxy(48,10);
        printf("%s",m[1]);
        gotoxy(47,12);
        printf("%s",m[2]);
        gotoxy(47,14);
        printf("%s",m[3]);
        texto6(lang);

        do
        {
            textbackground(text[cor]); //cor do highlight da opção

            if (lang==0)
            {
                if (op==0)
                {
                    gotoxy(4,19); //local do highlight da opção 0
                    printf(" SIM ");
                }
                else
                {
                    gotoxy(12,19); //local do highlight da opção 1
                    printf(" NÃO ");
                }
            }
            else
            {
                if (op==0)
                {
                    gotoxy(4,19); //local do highlight da opção 0
                    printf(" YES ");
                }
                else
                {
                    gotoxy(12,19); //local do highlight da opção 1
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
                    strcpy(fav,folder1);
                    strcat(fav,admin);
                    strcat(fav,".txt");

                    FILE *favoritos;
                    favoritos=fopen(fav,"a");
                    fprintf(favoritos,"     %s     %s\n",m[1],m[2]);
                    fclose(favoritos);

                    if (lang==0)
                    {
                        gotoxy(53,17);
                        printf("SIM");
                        gotoxy(5,19);
                        printf("Música adicionada aos seus favoritos ");
                    }
                    else
                    {
                        gotoxy(57,17);
                        printf("YES");
                        gotoxy(5,19);
                        printf("Music added to your favorites ");
                    }

                    getch();
                }
                opc=1;
            }
        } while (opc!=1);
    }

    fclose(musica);
    system("cls");
}

#endif // PESQUISA_H_INCLUDED
