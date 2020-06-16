#ifndef OPCOES_H_INCLUDED
#define OPCOES_H_INCLUDED

int getcor()
{
    int cor;

    FILE *cores;                                // saber cor escolhida
    cores=fopen(".\\options\\cor.txt","r");
    fscanf(cores," %i",&cor);
    fclose(cores);

    return cor;
}

int getlang()
{
    int lang;

    FILE *langs;                                // saber idioma escolhido
    langs=fopen(".\\options\\lang.txt","r");
    fscanf(langs," %i",&lang);
    fclose(langs);

    return lang;
}

void cores()
{
    int key,op=0,lang=getlang(),text[]={3,6,10,12,13};

    if (lang==0)
    {
        gotoxy(53,5);
        printf("CORES");
        gotoxy(53,10);
        printf("Padrão");
        gotoxy(52,12);
        printf("Estilo 1");
        gotoxy(52,14);
        printf("Estilo 2");
        gotoxy(52,16);
        printf("Estilo 3");
        gotoxy(52,18);
        printf("Estilo 4");
    }
    else
    {
        gotoxy(52,5);
        printf("COLORS");
        gotoxy(52,10);
        printf("Default");
        gotoxy(52,12);
        printf("Style 1");
        gotoxy(52,14);
        printf("Style 2");
        gotoxy(52,16);
        printf("Style 3");
        gotoxy(52,18);
        printf("Style 4");
    }

    do
    {
        textbackground(text[op]); //cor do highlight da opção

        if (lang==0)
        {
            if (op==0)
            {
                gotoxy(52,10); //local do highlight da opção 0
                printf(" Padrão ");
            }
            else if (op==1)
            {
                gotoxy(51,12); //local do highlight da opção 1
                printf(" Estilo 1 ");
            }
            else if (op==2)
            {
                gotoxy(51,14); //local do highlight da opção 2
                printf(" Estilo 2 ");
            }
            else if (op==3)
            {
                gotoxy(51,16); //local do highlight da opção 3
                printf(" Estilo 3 ");
            }
            else
            {
                gotoxy(51,18); //local do highlight da opção 4
                printf(" Estilo 4 ");
            }
        }
        else
        {
            if (op==0)
            {
                gotoxy(51,10); //local do highlight da opção 0
                printf(" Default ");
            }
            else if (op==1)
            {
                gotoxy(51,12); //local do highlight da opção 1
                printf(" Style 1 ");
            }
            else if (op==2)
            {
                gotoxy(51,14); //local do highlight da opção 2
                printf(" Style 2 ");
            }
            else if (op==3)
            {
                gotoxy(51,16); //local do highlight da opção 3
                printf(" Style 3 ");
            }
            else
            {
                gotoxy(51,18); //local do highlight da opção 4
                printf(" Style 4 ");
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
                if (op!=4)
                    op++;
                break;
            }
        }

    } while (key!=13);

    system("cls");
    FILE *cores;
    cores=fopen(".\\options\\cor.txt","w");
    fprintf(cores,"%i\n",op);
    fclose(cores);
}

void idioma()
{
    int key,op=0,cor=getcor(),text[]={3,6,10,12,13};

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

        if (op==0)
        {
            gotoxy(49,10); //local do highlight da opção 0- pt
            printf(" Português ");
        }
        else
        {
            gotoxy(50,12); //local do highlight da opção 1- en
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
                    op--;
                break;
            case 80:
                if (op!=1)
                    op++;
                break;
            }
        }

    } while (key!=13);

    textcolor(text[cor]);
    gotoxy(25,5);
    printf("--------------------------------------------------------------");
    textcolor(15);

    switch(op)
    {
    case 0:
        gotoxy(43,15);
        textbackground(text[cor]);
        printf(" Português selecionado ");
        break;
    case 1:
        gotoxy(46,15);
        textbackground(text[cor]);
        printf(" English selected ");
        break;
    }

    gotoxy(1,25);
    getch();
    system("color 0F");
    system("cls");

    FILE *langs;
    langs=fopen(".\\options\\lang.txt","w");
    fprintf(langs,"%i\n",op);
    fclose(langs);
}

#endif // OPCOES_H_INCLUDED
