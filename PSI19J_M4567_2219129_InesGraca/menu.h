#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

int op4(int adminops)
{
    int key,op=0,text[]={3,6,10,12,13};
    int cor=getcor(),lang=getlang();

    gotoxy(25,2);
    printf(" _     _     ___   _   _     ____  _   _      ___   ____  ___       ");
    gotoxy(25,3);
    printf("| |   \\ \\_/ | |_) | | \\ \\_/ | |_  | | | |\\ | | | \\ | |_  | |_)");
    gotoxy(25,4);
    printf("|_|__  |_|  |_| \\ |_| /_/ \\ |_|   |_| |_| \\| |_|_/ |_|__ |_| \\  ");

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
        gotoxy(4,8);
        printf("Bem-vindo, Lyrix");
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
        gotoxy(4,8);
        printf("Welcome, Lyrix");
    }

    if (adminops==5)    //admin
    {
        printf("Admin");

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
    else                //user
    {
        printf("Lover");
    }

    do
    {
        textcolor(text[cor]);
        gotoxy(25,5);
        printf("--------------------------------------------------------------");
        textcolor(15);

        textbackground(text[cor]); //cor do highlight da opção

        if (lang==0)
        {
            if (op==0)
            {
                gotoxy(46,10); //local do highlight da opção 0
                printf(" Pesquisar músicas ");
            }
            else if (op==1)
            {
                gotoxy(48,12); //local do highlight da opção 1
                printf(" Ver favoritos ");
            }
            else if (op==2)
            {
                gotoxy(49,14); //local do highlight da opção 2
                printf(" Definições ");
            }
            else if (op==3)
            {
                gotoxy(48,16); //local do highlight da opção 3
                printf(" Fim de sessão ");
            }
            else if (op==4)
            {
                gotoxy(47,19); //local do highlight da opção 4
                printf(" Adicionar música ");
            }
            else
            {
                gotoxy(46,21); //local do highlight da opção 5
                printf(" Registo de músicas ");
                gotoxy(49,22);
                printf(" adicionadas ");
            }
        }
        else
        {
            if (op==0)
            {
                gotoxy(49,10); //local do highlight da opção 0
                printf(" Search song ");
            }
            else if (op==1)
            {
                gotoxy(48,12); //local do highlight da opção 1
                printf(" See favorites ");
            }
            else if (op==2)
            {
                gotoxy(51,14); //local do highlight da opção 2
                printf(" Options ");
            }
            else if (op==3)
            {
                gotoxy(51,16); //local do highlight da opção 3
                printf(" Log out ");
            }
            else if (op==4)
            {
                gotoxy(50,19); //local do highlight da opção 4
                printf(" Add song ");
            }
            else
            {
                gotoxy(49,21); //local do highlight da opção 5
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
                if (op!=0)
                    op--;
                break;
            case 80:
                if (op!=adminops)
                    op++;
                break;
            }
        }

    } while (key!=13);

    return op;
}

int op5()
{
    int key,op=0,text[]={3,6,10,12,13};
    int cor=getcor(),lang=getlang();

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

    do
    {
        textbackground(text[cor]); //cor do highlight da opção

        if (lang==0)
        {
            if (op==0)
            {
                gotoxy(48,10); //local do highlight da opção 0
                printf(" Mudar idioma ");
            }
            else if (op==1)
            {
                gotoxy(46,12); //local do highlight da opção 1
                printf(" Alterar as cores ");
            }
            else
            {
                gotoxy(51,14); //local do highlight da opção 2
                printf(" Voltar ");
            }
        }
        else
        {
            if (op==0)
            {
                gotoxy(47,10); //local do highlight da opção 0
                printf(" Change language ");
            }
            else if (op==1)
            {
                gotoxy(48,12); //local do highlight da opção 1
                printf(" Change colors ");
            }
            else
            {
                gotoxy(52,14); //local do highlight da opção 2
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
                if (op!=0)
                    op--;
                break;
            case 80:
                if (op!=2)
                    op++;
                break;
            }
        }

    } while (key!=13);

    return op;
}

int op6()
{
    int key,op=0,text[]={3,6,10,12,13};
    int cor=getcor(),lang=getlang();

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

    do
    {
        textbackground(text[cor]); //cor do highlight da opção

        if (lang==0)
        {
            if (op==0)
            {
                gotoxy(46,10); //local do highlight da opção 0
                printf(" Voltar ao login ");
            }
            else if (op==1)
            {
                gotoxy(46,12); //local do highlight da opção 1
                printf(" Sair do programa ");
            }
            else
            {
                gotoxy(50,14); //local do highlight da opção 2
                printf(" Cancelar ");
            }
        }
        else
        {
            if (op==0)
            {
                gotoxy(47,10); //local do highlight da opção 0
                printf(" Return to login ");
            }
            else if (op==1)
            {
                gotoxy(48,12); //local do highlight da opção 1
                printf(" Exit program ");
            }
            else
            {
                gotoxy(52,14); //local do highlight da opção 2
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
                if (op!=0)
                    op--;
                break;
            case 80:
                if (op!=2)
                    op++;
                break;
            }
        }

    } while (key!=13);

    return op;
}

int menu(int admin)
{
    int op,adminops;    // adminops: opções de admins -> 4- indisponíveis, 6- disponíveis

    if (admin==0)
        adminops=3;
    else
        adminops=5;

    do
    {
        op=op4(adminops);

        system("cls");

        switch(op)
        {
        case 0:
            pesquisa();
            break;
        case 1:
            favoritos();
            break;
        case 2:
            opcao:
            op=op5();

            system("cls");
            gotoxy(45,11);

            switch(op)
            {
            case 0:
                idioma();
                goto opcao;
                break;
            case 1:
                cores();
                goto opcao;
                break;
            case 2:
                break;
            }
            break;
        case 3:
            op=op6();

            system("cls");
            gotoxy(45,11);

            switch(op)
            {
            case 0:
                return 1;
                break;
            case 1:
                return 0;
                break;
            case 2:
                break;
            }
            break;
        case 4:
            addmusic();
            break;
        case 5:
            registo();
            break;
        }

    } while (0!=1);
}

#endif // MENU_H_INCLUDED
