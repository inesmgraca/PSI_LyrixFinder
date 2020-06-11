#ifndef IDIOMA_H_INCLUDED
#define IDIOMA_H_INCLUDED

void texto4()
{
    gotoxy(25,2);
    printf(" _     _     ___   _   _     ____  _   _      ___   ____  ___       ");
    gotoxy(25,3);
    printf("| |   \\ \\_/ | |_) | | \\ \\_/ | |_  | | | |\\ | | | \\ | |_  | |_)");
    gotoxy(25,4);
    printf("|_|__  |_|  |_| \\ |_| /_/ \\ |_|   |_| |_| \\| |_|_/ |_|__ |_| \\  ");

    gotoxy(50,10);
    printf("Portugu�s");
    gotoxy(51,12);
    printf("English");
}

int idioma()
{
    int key,op=0,opc=0,getinfo,cor,text[5]={3,6,10,12,13};
    // key = seta   op = op��o a selecionar

    FILE *cores;                              //saber idioma escolhido anteriormente
    cores=fopen(".\\options\\cor.txt","r");
    while (fscanf(cores," %i",&getinfo)!=EOF)
    {
        cor=getinfo;
    }
    fclose(cores);

    texto4();

    do
    {
        textcolor(text[cor]);
        gotoxy(25,5);
        printf("--------------------------------------------------------------");
        textcolor(15);

        textbackground(text[cor]); //cor do highlight da op��o

        if (op==0)
        {
            gotoxy(49,10); //local do highlight da op��o 0- pt
            printf(" Portugu�s ");
        }
        else
        {
            gotoxy(50,12); //local do highlight da op��o 1- en
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
                    if (op!=0)
                    {
                        op--;
                    }
                    break;
                case 80:
                    if (op!=1)
                    {
                        op++;
                    }
                    break;
            }
        }
        else if (key==13)
        {
            opc=1;
            textcolor(text[cor]);
            gotoxy(25,5);
            printf("--------------------------------------------------------------");
            textcolor(15);

            FILE *langs;
            langs=fopen(".\\options\\lang.txt","w");

            switch(op)
            {
            case 0:
                gotoxy(43,15);
                textbackground(text[cor]);
                printf(" Portugu�s selecionado ");
                gotoxy(1,25);
                getch();
                system("color 0F");
                system("cls");
                fprintf(langs,"0\n");
                fclose(langs);
                break;
            case 1:
                gotoxy(46,15);
                textbackground(text[cor]);
                printf(" English selected ");
                gotoxy(1,25);
                getch();
                system("color 0F");
                system("cls");
                fprintf(langs,"1\n");
                fclose(langs);
                break;
            }
        }

    } while (opc!=1);

    return op;
}

#endif // IDIOMA_H_INCLUDED
