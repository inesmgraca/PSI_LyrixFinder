#ifndef IDIOMA_H_INCLUDED
#define IDIOMA_H_INCLUDED

int idioma()
{
    int key,op=1,opc=0,getinfo,cor,text[5]={3,6,10,12,13};
    // key = seta   op = opção a selecionar

    FILE *cores;                //saber idioma escolhido anteriormente
    cores=fopen("cor.txt","r");
    while (fscanf(cores," %i",&getinfo)!=EOF)
    {
        cor=getinfo;
    }
    fclose(cores);

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
        textcolor(text[cor]);
        gotoxy(25,5);
        printf("--------------------------------------------------------------");
        textcolor(15);

        textbackground(text[cor]); //cor do highlight da opção

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
            opc=1;
            textcolor(text[cor]);
            gotoxy(25,5);
            printf("--------------------------------------------------------------");
            textcolor(15);

            FILE *langs;
            langs=fopen("lang.txt","w");

            switch(op)
            {
            case 1:
                gotoxy(43,15);
                textbackground(text[cor]);
                printf(" Português selecionado ");
                gotoxy(1,25);
                getch();
                system("color 0F");
                system("cls");
                fprintf(langs,"%i\n",0);
                fclose(langs);
                return 0;
                break;
            case 2:
                gotoxy(46,15);
                textbackground(text[cor]);
                printf(" English selected ");
                gotoxy(1,25);
                getch();
                system("color 0F");
                system("cls");
                fprintf(langs,"%i\n",1);
                fclose(langs);
                return 1;
                break;
            }
        }

    } while (opc!=1);
}

#endif // IDIOMA_H_INCLUDED
