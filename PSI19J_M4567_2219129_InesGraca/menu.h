#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void menu()
{
    int key,op=1,adminops=4,menu=0;
    // key = seta
    // op = op��o a selecionar
    // adminops = op��es de admins -> 4- indispon�veis, 6- dispon�veis

    setlocale(LC_ALL,"Portuguese");
    textcolor(15);

    gotoxy(25,2);
    printf(" _     _     ___   _   _     ____  _   _      ___   ____  ___       ");
    gotoxy(25,3);
    printf("| |   \\ \\_/ | |_) | | \\ \\_/ | |_  | | | |\\ | | | \\ | |_  | |_)");
    gotoxy(25,4);
    printf("|_|__  |_|  |_| \\ |_| /_/ \\ |_|   |_| |_| \\| |_|_/ |_|__ |_| \\  ");

    gotoxy(4,8);
    printf("Bem-vindo, Lyrix");

    printf("-----");//eliminar qd login funcionar
    /*if (login==0) //admin
    {
        printf("Admin");
    }
    else            //user
    {
        printf("Lover");
    }
    */

    gotoxy(47,10);
    printf("Pesquisar m�sicas");
    gotoxy(49,12);
    printf("Ver favoritos");
    gotoxy(50,14);
    printf("Defini��es");
    gotoxy(49,16);
    printf("Fim de sess�o");

    /*if (login==0)
    {
    adminops=6; //definir op��es de admin como dispon�veis */
    gotoxy(48,19);
    printf("Adicionar m�sica");
    gotoxy(47,21);
    printf("Registo de m�sicas");
    gotoxy(50,22);
    printf("adicionadas");
    //}

    do
    {
        textcolor(3);
        gotoxy(25,5);
        printf("--------------------------------------------------------------");
        textcolor(15);

        textbackground(3); //cor do highlight de uma op��o

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
                printf("pesquisar \n");
                break;
            case 2:
                printf("seus favoritos \n");
                break;
            case 3:
                printf("op��es \n");
                break;
            case 4:
                menu=1;
                break;
            case 5:
                addmusic();
                break;
            case 6:
                printf("registo \n"); //Ol� UwU
                break;
            }
        }

    } while (menu!=1);
}

#endif // MENU_H_INCLUDED
