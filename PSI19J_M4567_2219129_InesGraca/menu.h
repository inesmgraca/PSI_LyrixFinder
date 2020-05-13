#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void menu()
{
    int key,op=1,menu=0; //    key=seta    op=opção
    setlocale(LC_ALL,"Portuguese");

    gotoxy(25,2);
    printf("LYRIXFINDER");
    gotoxy(2,4);
    printf("Bem-vindo");
    gotoxy(25,6);
    printf(" Pesquisar música ");
    gotoxy(25,8);
    printf(" Ver favoritos ");
    gotoxy(25,10);
    printf(" Opções ");
    gotoxy(25,12);
    printf(" Terminar sessão ");
    gotoxy(25,16);
    printf(" Adicionar música ");
    gotoxy(25,18);
    printf(" Registo de músicas adicionadas ");

    do
    {
        textcolor(7); //cor opção highlight
        textbackground(3);

        if (op==1)
        {
            gotoxy(25,6); //local do highlight de op 1
            printf(" Pesquisar música ");
        }
        else if (op==2)
        {
            gotoxy(25,8); //local para começar a fazer highlight de op 2
            printf(" Ver favoritos ");
        }
        else if (op==3)
        {
            gotoxy(25,10); //local para começar a fazer highlight de op 3
            printf(" Opções ");
        }
        else if (op==4)
        {
            gotoxy(25,12); //local para começar a fazer highlight de op 4
            printf(" Terminar sessão ");
        }
        else if (op==5)
        {
            gotoxy(25,16); //local para começar a fazer highlight de op 5
            printf(" Adicionar música ");
        }
        else
        {
            gotoxy(25,18); //local para começar a fazer highlight de op 6
            printf(" Registo de músicas adicionadas ");
        }

        gotoxy(1,20);
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
                    if (op!=6)
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
                printf("opções \n");
                break;
            case 4:
                printf("terminou sessão \n");
                break;
            case 5:
                addmusic();
                break;
            case 6:
                printf("registo \n"); //Olá UwU
                break;
            }

            menu=1;
        }

    } while (menu!=1);
}

#endif // MENU_H_INCLUDED
