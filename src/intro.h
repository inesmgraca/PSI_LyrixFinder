#ifndef INTRO_H_INCLUDED
#define INTRO_H_INCLUDED

void intro()
{
    char x[]={'L','Y','R','I','X','F','I','N','D','E','R'};

    for (int c=0;c<11;c++)      //nº letras palavra
    {
        Sleep(100);
        gotoxy(10+c,5);

        for (int i=0;i<4;i++)   //nº letras erradas
        {
            printf("%c",'A'+(rand()%26));
            Sleep(100);
            gotoxy(10+c,5);
        }

        printf("%c",x[c]);
    }

    Sleep(1500);
    system("cls");
    gotoxy(10,5);

    for (int i=0;i<5;i++)
    {
        Sleep(500);
        if (i==0)
            printf("Loading");
        else if (i==4)
            system("cls");
        else
            printf(".");
    }
}

#endif // INTRO_H_INCLUDED
