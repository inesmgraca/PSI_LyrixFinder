#ifndef SELECIONAR_H_INCLUDED
#define SELECIONAR_H_INCLUDED

int selecionar()
{
    int key,op=1,select=0;
    // key = seta
    // op = opção a selecionar

    setlocale(LC_ALL,"Portuguese");
    textcolor(15);

    gotoxy(25,2);
    printf(" _     _     ___   _   _     ____  _   _      ___   ____  ___       ");
    gotoxy(25,3);
    printf("| |   \\ \\_/ | |_) | | \\ \\_/ | |_  | | | |\\ | | | \\ | |_  | |_)");
    gotoxy(25,4);
    printf("|_|__  |_|  |_| \\ |_| /_/ \\ |_|   |_| |_| \\| |_|_/ |_|__ |_| \\  ");

    gotoxy(50,10);
    printf("Português");
    gotoxy(51,12);
    printf("English");

    do
    {
        textcolor(3);
        gotoxy(25,5);
        printf("--------------------------------------------------------------");
        textcolor(15);

        textbackground(3); //cor do highlight de uma opção

        if (op==1)
        {
            gotoxy(49,10); //local do highlight da opção 1- pt
            printf(" Português ");
        }
        else
        {
            gotoxy(50,12); //local do highlight da opção 2- en
            printf(" English ");
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
                    if (op!=2)
                    {
                        op++;
                    }
                    break;
            }
        }
        else if (key==13)
        {
            system("cls");
            gotoxy(45,11);

            switch(op)
            {
            case 1:
                printf("Português selecionado \n");
                return 0;
                break;
            case 2:
                printf("  English selected \n");
                return 1;
                break;
            }
        }

    } while (select!=1);
}

#endif // SELECIONAR_H_INCLUDED
