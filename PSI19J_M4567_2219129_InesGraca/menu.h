#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

int menu(int lang, int cor)
{
    int key,op=1,opc=1,adminops=6,text[5]={3,6,10,12,13};
    // key = seta   op = op��o a selecionar
    // adminops = op��es de admins -> 4- indispon�veis, 6- dispon�veis

    top:
    op=1;
    setlocale(LC_ALL,"Portuguese");
    textcolor(15);

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

    printf("-----");                //! eliminar quando login estiver a funcionar
    /*if (login==0) //admin
    {
        printf("Admin");
    }
    else            //user
    {
        printf("Lover");
    }
    */

    if (lang==0)
    {
        gotoxy(47,10);
        printf("Pesquisar m�sicas");
        gotoxy(49,12);
        printf("Ver favoritos");
        gotoxy(50,14);
        printf("Defini��es");
        gotoxy(49,16);
        printf("Fim de sess�o");
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


    /*if (login==0)
    {
        adminops=6; //definir op��es de admin como dispon�veis */

        if (lang==0)
        {
            gotoxy(48,19);
            printf("Adicionar m�sica");
            gotoxy(47,21);
            printf("Registo de m�sicas");
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
    //}

    do
    {
        textcolor(text[cor]);
        gotoxy(25,5);
        printf("--------------------------------------------------------------");
        textcolor(15);

        textbackground(text[cor]); //cor do highlight da op��o

        if (lang==0)
        {
            if (op==1)
            {
                gotoxy(46,10); //local do highlight da op��o 1
                printf(" Pesquisar m�sicas ");
            }
            else if (op==2)
            {
                gotoxy(48,12); //local do highlight da op��o 2
                printf(" Ver favoritos ");
            }
            else if (op==3)
            {
                gotoxy(49,14); //local do highlight da op��o 3
                printf(" Defini��es ");
            }
            else if (op==4)
            {
                gotoxy(48,16); //local do highlight da op��o 4
                printf(" Fim de sess�o ");
            }
            else if (op==5)
            {
                gotoxy(47,19); //local do highlight da op��o 5
                printf(" Adicionar m�sica ");
            }
            else
            {
                gotoxy(46,21); //local do highlight da op��o 6
                printf(" Registo de m�sicas ");
                gotoxy(49,22);
                printf(" adicionadas ");
            }
        }
        else
        {
            if (op==1)
            {
                gotoxy(49,10); //local do highlight da op��o 1
                printf(" Search song ");
            }
            else if (op==2)
            {
                gotoxy(48,12); //local do highlight da op��o 2
                printf(" See favorites ");
            }
            else if (op==3)
            {
                gotoxy(51,14); //local do highlight da op��o 3
                printf(" Options ");
            }
            else if (op==4)
            {
                gotoxy(51,16); //local do highlight da op��o 4
                printf(" Log out ");
            }
            else if (op==5)
            {
                gotoxy(50,19); //local do highlight da op��o 5
                printf(" Add song ");
            }
            else
            {
                gotoxy(49,21); //local do highlight da op��o 6
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

                if (lang==0)
                {
                    gotoxy(50,5);
                    printf("DEFINI��ES");
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

                do
                {
                    textbackground(text[cor]); //cor do highlight da op��o

                    if (lang==0)
                    {
                        if (opc==1)
                        {
                            gotoxy(48,10); //local do highlight da op��o 1
                            printf(" Mudar idioma ");
                        }
                        else if (opc==2)
                        {
                            gotoxy(46,12); //local do highlight da op��o 2
                            printf(" Alterar as cores ");
                        }
                        else
                        {
                            gotoxy(51,14); //local do highlight da op��o 3
                            printf(" Voltar ");
                        }
                    }
                    else
                    {
                        if (opc==1)
                        {
                            gotoxy(47,10); //local do highlight da op��o 1
                            printf(" Change language ");
                        }
                        else if (opc==2)
                        {
                            gotoxy(48,12); //local do highlight da op��o 2
                            printf(" Change colors ");
                        }
                        else
                        {
                            gotoxy(52,14); //local do highlight da op��o 3
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
                            lang=idioma(cor);
                            goto opcao;
                            break;
                        case 2:
                            cor=cores(lang);
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
                return 0;
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
