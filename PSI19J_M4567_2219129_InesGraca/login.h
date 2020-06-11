#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED

#define numlogins 10

void texto9(int lang)
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

void texto10()
{
    gotoxy(44,10);
    printf("Username:");
    gotoxy(44,12);
    printf("Password:");
}

void texto11(int lang)
{
    if (lang==0)
    {
        gotoxy(5,17);
        printf("As informações estão corretas?");
        gotoxy(5,19);
        printf("SIM     NÃO");
    }
    else
    {
        gotoxy(5,17);
        printf("Are the informations correct?");
        gotoxy(5,19);
        printf("YES     NO");
    }
}

int login()
{
    int usernum=-1,login1,login2,lang,cor,key,p,op=1,opc=0,text[5]={3,6,10,12,13};

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
    texto9(lang);

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
                for (int i=0;i<numlogins;i++)
                {
                    fread(&login[i],sizeof(struct log),1,getusers);
                }

                fclose(getusers);
                gotoxy(53,5);
                printf("LOGIN");

                texto10();

                gotoxy(54,10);
                gets(logininfo.user);
                gotoxy(54,12);

                p=0;

                do
                {
                    key=getch();
                    switch (key)
                    {
                    case 8:
                        if (p>0)
                        {
                            gotoxy(p+53,12);
                            printf(" ");
                            gotoxy(p+53,12);
                            p--;
                            logininfo.pass[p]='\0';
                        }
                        break;
                    case 13:
                        break;
                    default:
                        logininfo.pass[p]=key;
                        printf("*");
                        p++;
                    }

                } while (key!=13);

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
                        gotoxy(5,17);
                        printf("O username e/ou a password estão incorretas ");
                    }
                    else
                    {
                        gotoxy(5,17);
                        printf("Username and/or password are incorrect ");
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
                    op=3;
                }
                break;
            case 2:
                if (lang==0)
                {
                    gotoxy(49,5);
                    printf("NOVA CONTA");
                }
                else
                {
                    gotoxy(48,5);
                    printf("NEW ACCOUNT");
                }

                texto10();
                fflush(stdin);

                gotoxy(54,10);
                gets(logininfo.user);
                gotoxy(54,12);

                p=0;

                do
                {
                    key=getch();
                    switch (key)
                    {
                    case 8:
                        if (p>0)
                        {
                            gotoxy(p+53,12);
                            printf(" ");
                            gotoxy(p+53,12);
                            p--;
                            logininfo.pass[p]='\0';
                        }
                        break;
                    case 13:
                        break;
                    default:
                        logininfo.pass[p]=key;
                        printf("*");
                        p++;
                    }

                } while (key!=13);

                logininfo.usertype=0;   // colocar 1 para adicionar admins

                texto11(lang);
                opc=0;

                do
                {
                    textbackground(text[cor]); //cor do highlight da opção

                    if (lang==0)
                    {
                        if (opc==0)
                        {
                            gotoxy(4,19); //local do highlight da opção 0
                            printf(" SIM ");
                        }
                        else
                        {
                            gotoxy(12,19); //local do highlight da opção 1
                            printf(" NÃO ");
                        }
                    }
                    else
                    {
                        if (opc==0)
                        {
                            gotoxy(4,19); //local do highlight da opção 0
                            printf(" YES ");
                        }
                        else
                        {
                            gotoxy(12,19); //local do highlight da opção 1
                            printf(" NO ");
                        }
                    }

                    gotoxy(1,25);
                    key=_getch();

                    system("color 0F");

                    if(key==0 || key==224)
                    {
                        switch (_getch())
                        {
                        case 75:
                            if (opc!=0)
                            {
                                opc--;
                            }
                            break;
                        case 77:
                            if (opc!=1)
                            {
                                opc++;
                            }
                            break;
                        }
                    }
                    else if (key==13)
                    {
                        if (opc==0)
                        {
                            FILE *newuser;
                            newuser=fopen(".\\user\\users.txt","a");
                            fwrite(&logininfo,sizeof(struct log),1,newuser);
                            fclose(newuser);

                            if (lang==0)
                            {
                                gotoxy(36,17);
                                printf("SIM");
                                gotoxy(5,19);
                                printf("Utilizador criado ");
                            }
                            else
                            {
                                gotoxy(35,17);
                                printf("YES");
                                gotoxy(5,19);
                                printf("User created ");
                            }
                        }
                        else
                        {
                            if (lang==0)
                            {
                                gotoxy(36,17);
                                printf("NÃO");
                                gotoxy(5,19);
                                printf("Novo utilizador cancelado ");
                            }
                            else
                            {
                                gotoxy(36,17);
                                printf("NO");
                                gotoxy(5,19);
                                printf("New user canceled ");
                            }
                        }
                        opc=2;
                    }

                } while (opc!=2);

                getch();
                system("cls");

                goto logon;
                break;
            }
        }

    } while (op!=3);

    return login[usernum].usertype;
}

#endif // LOGIN_H_INCLUDED
