#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED

int login()
{
    int login1,login2,lang,cor,key,op=1,text[5]={3,6,10,12,13};
    char verif;
    int usernum=-1;

    struct log
    {
        char user[25],pass[25];
        int usertype; //0- normal user, 1- admin
    };

    struct log logininfo;
    struct log login[25];

    FILE *cores;                  //saber cor e idioma escolhidos anteriormente
    FILE *langs;
    cores=fopen("cor.txt","r");
    langs=fopen("lang.txt","r");
    fscanf(cores,"%i",&cor);
    fscanf(langs,"%i",&lang);
    fclose(cores);
    fclose(langs);

    textcolor(15);

    logon:
    gotoxy(53,5);
    printf("LOGIN");

    //if (lang==0)
    //{
        gotoxy(47,10);
        printf("Conta já existente");
        gotoxy(48,12);
        printf("Criar nova conta");
    //}

    do
    {
        textbackground(text[cor]); //cor do highlight da opção

        if (op==1)
        {
            gotoxy(46,10); //local do highlight da opção 1
            printf(" Conta já existente ");
        }
        else
        {
            gotoxy(47,12); //local do highlight da opção 2
            printf(" Criar nova conta ");
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
            FILE *getusers;
            getusers=fopen("users.txt","r");

            switch(op)
            {
            case 1:
                for (int i=0;i<25;i++)
                {
                    fread(&login[10],sizeof(struct log),1,getusers);
                }

                fclose(getusers);
                printf("Login \n\n");
                printf(" Username: ");
                gets(logininfo.user);
                printf(" Password: ");
                gets(logininfo.pass);

                for (int c=0;c<25;c++)
                {
                    login1=strcmp(logininfo.user,login[c].user);
                    login2=strcmp(logininfo.pass,login[c].pass);

                    if (login1==0 && login2==0)
                    {
                        usernum=c;
                    }
                }

                if (usernum==-1)
                {
                    printf("\n\n O username e/ou a password não estão corretas \n");
                    getch();
                    system("cls");
                    goto logon;
                }
                else
                {
                    system("cls");
                    printf("\n\n Bem-vindo, %s \n",login[usernum].user);
                    getch();
                    system("cls");
                }

                break;
            case 2:
                printf("Novo login \n\n");
                printf(" Username: ");
                gets(logininfo.user);
                printf(" Password: ");
                gets(logininfo.pass);

                logininfo.usertype=0;
                fflush(stdin);

                printf("A informação está correta? \n\n");
                printf("S/N \n");
                verif=getch();

                if (verif=='S' || verif=='s')
                {
                    FILE *newuser;
                    newuser=fopen("users.txt","a");
                    fwrite(&logininfo,sizeof(struct log),1,newuser);
                    fclose(newuser);

                    printf("\n\n User criado \n");
                }
                else
                {
                    printf("\n\n User cancelado \n");
                }

                getch();
                system("cls");

                goto logon;
                break;
            }
        }
    } while (0!=1);

    return 0;
}

#endif // LOGIN_H_INCLUDED
