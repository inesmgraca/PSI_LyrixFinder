#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void texto1(int lang, int adminops)
{
    gotoxy(25,2);
    printf(" _     _     ___   _   _     ____  _   _      ___   ____  ___       ");
    gotoxy(25,3);
    printf("| |   \\ \\_/ | |_) | | \\ \\_/ | |_  | | | |\\ | | | \\ | |_  | |_)");
    gotoxy(25,4);
    printf("|_|__  |_|  |_| \\ |_| /_/ \\ |_|   |_| |_| \\| |_|_/ |_|__ |_| \\  ");

    gotoxy(4,8);
    if (lang==0)
    {
        printf("Bem-vindo, Lyrix");
    }
    else
    {
        printf("Welcome, Lyrix");
    }

    if (adminops==6) //admin
    {
        printf("Admin");
    }
    else             //user
    {
        printf("Lover");
    }

    if (lang==0)
    {
        gotoxy(47,10);
        printf("Pesquisar músicas");
        gotoxy(49,12);
        printf("Ver favoritos");
        gotoxy(50,14);
        printf("Definições");
        gotoxy(49,16);
        printf("Fim de sessão");
    }
    else
    {
        gotoxy(50,10);
        printf("Search song");
        gotoxy(49,12);
        printf("See favorites");
        gotoxy(52,14);
        printf("Options");
        gotoxy(52,16);
        printf("Log out");
    }

    if (adminops==6)
    {
        if (lang==0)
        {
            gotoxy(48,19);
            printf("Adicionar música");
            gotoxy(47,21);
            printf("Registo de músicas");
            gotoxy(50,22);
            printf("adicionadas");
        }
        else
        {
            gotoxy(51,19);
            printf("Add song");
            gotoxy(50,21);
            printf("Added songs");
            gotoxy(51,22);
            printf("registry");
        }
    }
}

void texto2(int lang)
{
    if (lang==0)
    {
        gotoxy(50,5);
        printf("DEFINIÇÕES");
        gotoxy(49,10);
        printf("Mudar idioma");
        gotoxy(47,12);
        printf("Alterar as cores");
        gotoxy(52,14);
        printf("Voltar");
    }
    else
    {
        gotoxy(52,5);
        printf("OPTIONS");
        gotoxy(48,10);
        printf("Change language");
        gotoxy(49,12);
        printf("Change colors");
        gotoxy(53,14);
        printf("Back");
    }
}

void texto3(int lang)
{
    if (lang==0)
    {
        gotoxy(48,5);
        printf("FIM DE SESSÃO");
        gotoxy(47,10);
        printf("Voltar ao login");
        gotoxy(47,12);
        printf("Sair do programa");
        gotoxy(51,14);
        printf("Cancelar");
    }
    else
    {
        gotoxy(51,5);
        printf("LOG OUT");
        gotoxy(48,10);
        printf("Return to login");
        gotoxy(49,12);
        printf("Exit program");
        gotoxy(53,14);
        printf("Back");
    }
}

int menu(int admin)
{
    int key,op,opc,getinfo,lang,cor,adminops,text[5]={3,6,10,12,13};
    // key = seta   op = opção a selecionar
    // adminops = opções de admins -> 4- indisponíveis, 6- disponíveis

    top:
    op=1;

    FILE *corestxt;                     //saber cor e idioma escolhidos
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

    if (admin==0)
    {
        adminops=4;
    }
    else
    {
        adminops=6;
    }

    texto1(lang,adminops);

    /**/

    do
    {
        textcolor(text[cor]);
        gotoxy(25,5);
        printf("--------------------------------------------------------------");
        textcolor(15);

        textbackground(text[cor]); //cor do highlight da opção

        if (lang==0)
        {
            if (op==1)
            {
                gotoxy(46,10); //local do highlight da opção 1
                printf(" Pesquisar músicas ");
            }
            else if (op==2)
            {
                gotoxy(48,12); //local do highlight da opção 2
                printf(" Ver favoritos ");
            }
            else if (op==3)
            {
                gotoxy(49,14); //local do highlight da opção 3
                printf(" Definições ");
            }
            else if (op==4)
            {
                gotoxy(48,16); //local do highlight da opção 4
                printf(" Fim de sessão ");
            }
            else if (op==5)
            {
                gotoxy(47,19); //local do highlight da opção 5
                printf(" Adicionar música ");
            }
            else
            {
                gotoxy(46,21); //local do highlight da opção 6
                printf(" Registo de músicas ");
                gotoxy(49,22);
                printf(" adicionadas ");
            }
        }
        else
        {
            if (op==1)
            {
                gotoxy(49,10); //local do highlight da opção 1
                printf(" Search song ");
            }
            else if (op==2)
            {
                gotoxy(48,12); //local do highlight da opção 2
                printf(" See favorites ");
            }
            else if (op==3)
            {
                gotoxy(51,14); //local do highlight da opção 3
                printf(" Options ");
            }
            else if (op==4)
            {
                gotoxy(51,16); //local do highlight da opção 4
                printf(" Log out ");
            }
            else if (op==5)
            {
                gotoxy(50,19); //local do highlight da opção 5
                printf(" Add song ");
            }
            else
            {
                gotoxy(49,21); //local do highlight da opção 6
                printf(" Added songs ");
                gotoxy(50,22);
                printf(" registry ");
            }
        }

        gotoxy(1,25);
        key=_getch();

        system("color 0F");

        if(key==0 || key==224)
        {
            switch (_getch())
            {
                case 72:
                    if (op!=1)
                    {
                        op--;
                    }
                    break;
                case 80:
                    if (op!=adminops)
                    {
                        op++;
                    }
                    break;
            }
        }
        else if (key==13)
        {
            system("cls");

            switch(op)
            {
            case 1:
                //pesquisa
                break;
            case 2:
                //favoritos
                break;
            case 3:
                opcao:
                opc=1;
                texto2(lang);

                do
                {
                    textbackground(text[cor]); //cor do highlight da opção

                    if (lang==0)
                    {
                        if (opc==1)
                        {
                            gotoxy(48,10); //local do highlight da opção 1
                            printf(" Mudar idioma ");
                        }
                        else if (opc==2)
                        {
                            gotoxy(46,12); //local do highlight da opção 2
                            printf(" Alterar as cores ");
                        }
                        else
                        {
                            gotoxy(51,14); //local do highlight da opção 3
                            printf(" Voltar ");
                        }
                    }
                    else
                    {
                        if (opc==1)
                        {
                            gotoxy(47,10); //local do highlight da opção 1
                            printf(" Change language ");
                        }
                        else if (opc==2)
                        {
                            gotoxy(48,12); //local do highlight da opção 2
                            printf(" Change colors ");
                        }
                        else
                        {
                            gotoxy(52,14); //local do highlight da opção 3
                            printf(" Back ");
                        }
                    }

                    gotoxy(1,25);
                    key=_getch();

                    system("color 0F");

                    if(key==0 || key==224)
                    {
                        switch (_getch())
                        {
                        case 72:
                            if (opc!=1)
                            {
                                opc--;
                            }
                            break;
                        case 80:
                            if (opc!=3)
                            {
                                opc++;
                            }
                            break;
                        }
                    }
                    else if (key==13)
                    {
                        system("cls");
                        gotoxy(45,11);

                        switch(opc)
                        {
                        case 1:
                            lang=idioma();
                            goto opcao;
                            break;
                        case 2:
                            cor=cores();
                            goto opcao;
                            break;
                        case 3:
                            opc=0;
                            break;
                        }
                    }

                } while (opc!=0);
                goto top;
                break;
            case 4:
                texto3(lang);
                opc=1;
                do
                {
                    textbackground(text[cor]); //cor do highlight da opção

                    if (lang==0)
                    {
                        if (opc==1)
                        {
                            gotoxy(46,10); //local do highlight da opção 1
                            printf(" Voltar ao login ");
                        }
                        else if (opc==2)
                        {
                            gotoxy(46,12); //local do highlight da opção 2
                            printf(" Sair do programa ");
                        }
                        else
                        {
                            gotoxy(50,14); //local do highlight da opção 3
                            printf(" Cancelar ");
                        }
                    }
                    else
                    {
                        if (opc==1)
                        {
                            gotoxy(47,10); //local do highlight da opção 1
                            printf(" Return to login ");
                        }
                        else if (opc==2)
                        {
                            gotoxy(48,12); //local do highlight da opção 2
                            printf(" Exit program ");
                        }
                        else
                        {
                            gotoxy(52,14); //local do highlight da opção 3
                            printf(" Back ");
                        }
                    }

                    gotoxy(1,25);
                    key=_getch();

                    system("color 0F");

                    if(key==0 || key==224)
                    {
                        switch (_getch())
                        {
                        case 72:
                            if (opc!=1)
                            {
                                opc--;
                            }
                            break;
                        case 80:
                            if (opc!=3)
                            {
                                opc++;
                            }
                            break;
                        }
                    }
                    else if (key==13)
                    {
                        system("cls");
                        gotoxy(45,11);

                        switch(opc)
                        {
                        case 1:
                            return 1;
                            break;
                        case 2:
                            return 0;
                            break;
                        case 3:
                            opc=0;
                            break;
                        }
                    }

                } while (opc!=0);
                goto top;
                break;
            case 5:
                addmusic(lang);
                goto top;
                break;
            case 6:
                //registo
                break;
            }
        }

    } while (0!=1);
}

#endif // MENU_H_INCLUDED
