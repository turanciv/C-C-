#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <dirent.h>
/* Some list of combinations

    0 = Black
    1 = Blue
    2 = Green
    3 = Aqua
    4 = Red
    5 = Purple
    6 = Yellow
    7 = White
    8 = Gray
    9 = Light Blue
    A = Light Green
    B = Light Aqua
    C = Light Red
    D = Light Purple
    E = Light Yellow
    F = Bright White */
#include <unistd.h>

struct dirent *de;

typedef struct{
    int sno;
    char category[20];
    char name[20];
    char gender[1];
    int age;
    char address[50];
    char email[50];
}contact;

contact cont;
int main()
{
    //char name[30];
    char pass[30],original[30],ch;
    int auth;//Variable zur Password Authentifiezierung
    int i;

    printf("\n\n\t\t\tEnter the password: ");
    i = 0;
    while(1){
        ch = getch();
        if(ch==13){ // ASCII code für ENTER Taste ist 13
            pass[i]='\0';
            break;
        }
        pass[i++]=ch;
        printf("*");
    }
    //lese daten von der datei
    FILE * fp = fopen("pwd.dat", "r");
    fgets(original,30,fp);
    fclose(fp);

    //auth = strcmp(original,pass);

    if(strcmp(original,pass)== 0){ //Wenn das Password der Original datei ubereinstimmt dan 'true' bzw. 'wahr' = 1, 'falsch' = 0
        printf("\n\n\t\t\tLogged in!\n\n\t\t\tPress ENTER");
        if(getch()==13){
            system("cls");
        }
        //next Window
        mainMenu();
    }
    else if(!strcmp(original,pass)== 0){
        printf("\nWrong Password!\nTry Again..");
        printf("%d", strcmp(original,pass));
        main();
    }

    getch();
    return 0;
}
//HAUPTMENU
void mainMenu()
{
    int delay = 10;
    int i2 =0;
    system("COLOR 3A");
    printf("\n\n\t\t\t\t\tMade by Turi-G\n\t\t\t\t\tVersion: 1.0\n");
    printf("\n\n\t\t\t\t\tPlease wait..\n\t\t");
    for(i2=0;i2<=50;i2++){
        printf("%c", 220);
        Sleep(delay);
    }
    system("cls");
    //next Window(MainMenu)
    system("COLOR 3E");
    printf("\n\n\n\t\t\t\t\t\tMain-Menu\n\t\t\t\t\t_________________________");
    printf("\n\n\t\t\t\t\tChoose an 'option'\n\n\t\t\t\t\t1: Add 'Data\n\t\t\t\t\t2: Read and write 'Data\n\t\t\t\t\t3: Delete file\n\t\t\t\t\t4: Contact-Management\n\t\t\t\t\t5: Other Options\n\t\t\t\t\tCHOICE: ");
    int optionChoice = 0;
    while(optionChoice == 0){
        scanf("%d", &optionChoice);
        switch(optionChoice){
            case 1:
                system("cls");
                createFile();
                break;
            case 2:
                system("cls");
                listDirectory();
                //readFile();
                break;
            case 3:
                system("cls");
                delFile();
                //delete existing File
                break;
            case 4:
                system("cls");
                ContactManagement();
                //Contact-Management Menu
                break;
            case 5:
                //Other Options(next window where new option like contact management and games etc are available)
                break;
            default:
                printf("Your choice is invalid.");
                break;
        }
    }
}
//DATEI SCHREIBEN
void createFile()
{
    char data[1000];
    char fileName[100];
    FILE * fp;
    printf("\nDon't press ENTER until your file is not finished.\n");
    printf("Enter name of file: ");
    scanf("%s\n", &fileName);
    fp = fopen(fileName, "w");
    if(fileName!=NULL){

    }
    if(fp == NULL){
        printf("File not found...");
        return createFile();
    }
    fgets(data, 1000, stdin);
    fputs(data, fp);

    fclose(fp);
    printf("\nSuccessfully created file.\n\t       _\n\t    ( |\n\t___\\ \\.\n\t(__()  `-|\n\t(___()   |\n\t(__()    |\n\t(_()__.--|");
    if(getch){
        main();
    }
}
//DATEI LÖSCHEN
void delFile()
{
    int i;
    char ch, file[100], fileName[] = "./DATA/";
    //LSIT DIRECTORY
    DIR *dr = opendir("./DATA");

    if(dr == NULL){
        printf("Could not open current directory or directory those not exist.");
    }
    while((de = readdir(dr)) != NULL){
        printf("%s\n", de->d_name);
    }
    closedir(dr);
    //DELETE DATA
    printf("\nChoose witch file you want to delete: ");
    scanf("%s", file);
    for(i=0;fileName[i]!='\0';i++);
    for(int j=0;file[j]!='\0';j++)
    {
        fileName[i]=file[j];
        i++;
    }
    fileName[i]='\0';
    int del = remove(fileName);
    if(!del){
        printf("\nThe file was deleted successfully.");
    }
    else{
        printf("\nERROR!-->File might not exist.");
    }
    printf("PRESS ENTER.");
    if(getch()==13){
        system("cls");
        mainMenu();
    }
}
//LEESEN UND SCHREIBEN
void readFile(){
    char ch, file[100], fileName[] = "./DATA/";
    char data[1000];
    int i;
    FILE * fp;
    //listDirectory();
    printf("\nChoose witch file you want to read: ");
    gets(file);
    for(i=0;fileName[i]!='\0';i++);
    for(int j=0;file[j]!='\0';j++)
    {

        fileName[i]=file[j];
        i++;
    }
    fileName[i]='\0';

    //fileName = strcat(fileName, file);
    if(file != NULL){
        fp = fopen(fileName, "r");// r = lesen , w = schreiben
        if(fp == NULL){
            printf("Error while opening the file or file does not exist.\n");
            //system("cls");
            readFile();
        }
    }
    //printf("%s", fileName);

    printf("%s : \n", fileName);
    while((ch=fgetc(fp))!= EOF){
        printf("%c", ch);
    }
    fclose(fp);
    printf("\n---------------------------------------------------------------\nTo close this file press ENTER.\nTo edit this file press 'w'.\n---------------------------------------------------------------\n");
    char ch1;
    if(getch() == 13){
        system("cls");
        main();
    }else if(getch() == 119){
        //LESEN UND SCHREIBEN IN EINE DATEI
        fp = fopen(fileName, "r+");
        while(1){
            ch1 = fgetc(fp);
            if(ch1 == EOF)
                break;
            printf("%c", ch1);
        }
        fgets(data, 1000, stdin);
        fputs(data, fp);
        /*while(1){
            char ch1;
            ch1=fgetc(fp);
            if(ch1==EOF){
                printf("done");
                break;
            }
            if(ch1=='i'){
                fputc('a', fp);
            }
        }*/
        fclose(fp);
    }
    return 0;
}
//VERZEICHNIS AUFLISTEN FUNKTION
void listDirectory(){
    printf("These are the file's you have made so far.\n------------------------------------------------------------\n\n");
    DIR *dr = opendir("./DATA");
    if(dr == NULL){
        printf("Could not open current directory or directory those not exist.");
    }
    while((de = readdir(dr)) != NULL){
        printf("%s\n", de->d_name);

    }
    readFile();
    if(readFile==0 ){
        closedir(dr);
    }
    /*if(getch()==13){
        return mainMenu();
    }*/
}
void ContactManagement(){
    system("COLOR 04");
    int choice;
    printf("\n\n\t\t\t+++++++++++++++++++CONTACT-MANAGEMENT+++++++++++++++++++\n");
    printf("\n\n\t\t\t\t------Choose an option------");
    printf("\n\n\t\t\t\tAdd Contact[1]\n\n\t\t\t\tDelete Contact[2]\n\n\t\t\t\tEdit Contact[3]\n\n\t\t\t\tList Contact[4]\n\n\t\t\t\tEXIT[5]\n\n\t\t\t\tCHOICE: ");
    scanf("%d", &choice);
    switch(choice){
    case 1:
        system("cls");
        add_contact();
        break;
    case 2:

        system("cls");
        //del_contact()
        break;
    case 3:
        system("cls");
        //edit_contact();
        break;
    case 4:
        system("cls");
        list_contact();
        break;

    case 5:
        return(main());
        break;
    }
}
void add_contact(){
    system("COLOR 3E");
    int i;
    printf("\n\n\t\t\t\t\tAdd/Create Contact\n\n");
    for(i=1;i<=80;i++){
        printf("-");
    }
    FILE * fp;
    printf("Enter serial no: ");
    scanf("%d", &cont.sno);
    fflush(stdin);//clear input buffer
    printf("Enter category (Friend/Business) : ");
    gets(cont.category);
    fflush(stdin);
    printf("Enter name: ");
    gets(cont.name);
    fflush(stdin);
    printf("Enter gender m/f: ");
    gets(cont.gender);
    fflush(stdin);
    printf("Enter age: ");
    scanf("&d", &cont.age);
    fflush(stdin);
    printf("Enter address: ");
    gets(cont.address);
    fflush(stdin);
    printf("Enter email: ");
    gets(cont.email);
    fflush(stdin);
    fp = fopen("info.dat","ab");
    fwrite(&cont,sizeof(cont),1,fp);
    fclose(fp);
    printf("\nCONTACT SAVED, PRESS ANY KEY....");
    getch();
    system("cls");
    return ContactManagement();
}
void list_contact(){
    FILE * fp;
    int i;
    printf("\n\n\t\t\t\t\tContact-List\n\n");
    for(i=1;i<=80;i++){
        printf("-");
    }
    printf("\n");
    printf("SNO");
    printf("\tCATEGORY");
    printf("\tNAME");
    printf("\t\tGENDER");
    printf("\tAGE");
    printf("\tADDRESS\n");
    for(i=1;i<=80;i++){
        printf("-");
    }
    printf("\n");
    fp = fopen("info.dat", "rb");
    i=5;
    if(!fp){
        printf("Unable to open file!");
        return 1;
    }
    /*fseek(fp,sizeof(contact),SEEK_END);
    rewind(fp);*/
    while(fread(&cont,sizeof(cont),1,fp)!=NULL){
        printf("%d\t", cont.sno);
        printf("%s\t", cont.category);
        printf("%s\t", cont.name);
        printf("%s\t", cont.gender);
        printf("%d\t", cont.age);
        printf("%s\t", cont.address);
        printf("%s\t\n", cont.email);
        i++;
    }
    fclose(fp);
    printf("\n");
    printf("PRESS ANY KEY....");
    getch();
    system("cls");
    return(ContactManagement());

}





















//FUNCTIONS TO ADD LATER....
/*void HttpGetRequest()
{
    char pszRequest[100]= {0};
    char pszResourcePath[]="2016/04/create-xml-request-in-c-for-server.html";//pfad der webseite
    char pszHostAddress[]="www.aticleworld.com";//Hostadresse
    printf("Geben sie den pfad ein; ");
    scanf("%s", pszResourcePath);
    printf("Geben sie die Webseite ein; ");
    scanf("%s", pszHostAddress);
    sprintf(pszRequest, "GET /%s HTTP/1.1\r\nHost: %s\r\nContent-Type: text/plain\r\n\r\n", pszResourcePath, pszHostAddress);
    printf("Created Get Request is below:\n\n\n");
    printf("%s", pszRequest);
}
void HttpPostRequest()
{
    char aszXmlData[]="<body><name>amlendra</name><age>25</age></body>";
    char aszXmlRequest[250]= {0};
    char aszServiceMethod[]="applicationform.svc/getdetail";
    char aszRequest[150]= {0};
    char aszHostIp[30]="74.125.28.121";
    char aszPort[]="80";
    sprintf(aszRequest,"http://%s:%s/%s/%s HTTP/1.1",aszHostIp,aszPort,aszServiceMethod);
    printf("Method and Resource path is below:\n\n\n");
    printf("%s",aszRequest);
    strcat(aszHostIp,":");
    strcat(aszHostIp,aszPort);
    printf("\n\nHOST header is below:\n\n\n");
    printf("%s",aszHostIp);
    sprintf(aszXmlRequest,"POST %s\r\nHost: %s\r\nContent-Type: application/xml\r\nContent-Length: %d\r\n\r\n%s\r\n",aszRequest,aszHostIp,strlen(aszXmlData),aszXmlData);
    printf("\n\n\nPOST Request which send to the server:\n\n");
    printf("%s",aszXmlRequest);
}
*/
