#ifndef CORES_H_INCLUDED
#define CORES_H_INCLUDED

void texto6(int lang)
{
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
}

int cores()
{
    int key,op=0,opc=0,lang,text[5]={3,6,10,12,13};

    FILE *langs;             //saber idioma escolhido anteriormente
    langs=fopen("lang.txt","r");
    fscanf(langs,"%i",&lang);
    fclose(langs);

    texto6(lang);

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
                    {
                        op--;
                    }
                    break;
                case 80:
                    if (op!=4)
                    {
                        op++;
                    }
                    break;
            }
        }
        else if (key==13)
        {
            system("cls");
            FILE *cores;
            cores=fopen("cor.txt","w");
            fprintf(cores,"%i\n",op);
            fclose(cores);
            opc=1;
            return op;
        }

    } while (opc!=1);
}

#endif // CORES_H_INCLUDED
