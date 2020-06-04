#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED

void texto5(int lang)
{
    gotoxy(53,5);
    printf("LOGIN");

    if (lang==0)
    {
        gotoxy(47,10);
        printf("Conta já existente");
        gotoxy(48,12);
        printf("Criar nova conta");
    }
    else
    {
        gotoxy(48,10);
        printf("Existing account");
        gotoxy(47,12);
        printf("Create new account");
    }
}

int login()
{
    int usernum=-1,login1,login2,lang,cor,key,op=1,text[5]={3,6,10,12,13};
    char verif;

    struct log
    {
        char user[25],pass[25];
        int usertype;               //0- normal user, 1- admin
    };

    struct log logininfo;
    struct log login[25];

    FILE *cores;                    //saber cor e idioma escolhidos anteriormente
    FILE *langs;
    cores=fopen(".\\options\\cor.txt","r");
    langs=fopen(".\\options\\lang.txt","r");
    fscanf(cores,"%i",&cor);
    fscanf(langs,"%i",&lang);
    fclose(cores);
    fclose(langs);

    textcolor(15);

    logon:
    texto5(lang);

    do
    {
        textbackground(text[cor]); //cor do highlight da opção

        if (lang==0)
        {
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
        }
        else
        {
            if (op==1)
            {
                gotoxy(47,10); //local do highlight da opção 1
                printf(" Existing account ");
            }
            else
            {
                gotoxy(46,12); //local do highlight da opção 2
                printf(" Create new account ");
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
            getusers=fopen(".\\user\\users.txt","r");
            system("cls");

            switch(op)
            {
            case 1:
                for (int i=0;i<25;i++)
                {
                    fread(&login[i],sizeof(struct log),1,getusers);
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
                    if (lang==0)
                    {
                        printf("\n\n O username e/ou a password estão incorretas \n");
                    }
                    else
                    {
                        printf("\n\n Username and/or password are incorrect \n");
                    }
                    getch();
                    system("cls");
                    goto logon;
                }
                else
                {
                    system("cls");
                    FILE *userlogin;
                    userlogin=fopen(".\\user\\userlogin.txt","w");
                    fprintf(userlogin,"%s\n",login[usernum].user);
                    fclose(userlogin);
                    return login[usernum].usertype;
                }
                break;
            case 2:
                if (lang==0)
                {
                    printf("Novo login \n\n");
                }
                else
                {
                    printf("New login \n\n");
                }

                printf(" Username: ");
                gets(logininfo.user);
                printf(" Password: ");
                gets(logininfo.pass);

                /*printf(" 0- User, 1- Admin: ");
                scanf("%i",&logininfo.usertype);
                fflush(stdin);*/                    //! utilizar para adicionar mais admins

                logininfo.usertype=0;
                fflush(stdin);

                if (lang==0)
                {
                    printf("\n A informação está correta? \n");
                    printf(" S/N \n");
                }
                else
                {
                    printf("\n Is the information correct? \n");
                    printf(" Y/N \n");
                }

                verif=getch();

                if (verif=='S' || verif=='s' || verif=='Y' || verif=='y')
                {
                    FILE *newuser;
                    newuser=fopen(".\\user\\users.txt","a");
                    fwrite(&logininfo,sizeof(struct log),1,newuser);
                    fclose(newuser);

                    if (lang==0)
                    {
                        printf("\n\n Utilizador criado \n");
                    }
                    else
                    {
                        printf("\n\n User created \n");
                    }
                }
                else
                {
                    if (lang==0)
                    {
                        printf("\n\n Novo utilizador cancelado \n");
                    }
                    else
                    {
                        printf("\n\n New user canceled \n");
                    }
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
