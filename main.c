#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

struct details{
    char name[50], gender[20], status[20];
    int file_num;
}d;

void inputData();                               //line 40
void checkData();                               //line 71
void editStatus();                              //line 147
void deleteData();                              //line 231
void optionSelecter(int number);                //line 314
void delay(unsigned int mseconds);              //line 344

int main()
{
    system("color 3");
    int select;
    system("cls");
    while (1)
    {
        printf("\t\tWELCOME TO HOSPITAL DATABASE\n\n");
        printf("\tSELECT ONE OF THE OPTION FROM THIS [1-5]\n");
        printf("\t[1] Input Patient Data\n");
        printf("\t[2] Check Data\n");
        printf("\t[3] Edit Data\n");
        printf("\t[4] Delete Data\n");
        printf("\t[5] Exit\n\n");
        printf("\t Select one of the option provided above : ");
        scanf("%d", &select);
        optionSelecter(select);
    }
    return 0;
}

void inputData()
{
    system("cls");
    
    FILE *fp = fopen("database.csv", "a+");

    if (!fp)
    {
        printf("Can't open file\n");
    }

    

    printf("\tPatient's Name : ");
    scanf("%s", d.name);
    printf("\tPatient's File Number : ");
    scanf("%d",&d.file_num);
    printf("\tPatient's Gender: ");
    scanf("%s", d.gender);
    printf("\tPatient's Status: ");
    scanf("%s", d.status);

    
    fprintf(fp, "%s, %s, %s, %d\n", d.name,d.gender,d.status,d.file_num);
    system("cls");
    printf("\tSuccessfully saved data!");
    fclose(fp);
    delay(2000);
    system("cls");
}

void checkData()
{
    system("cls");
    FILE *fp = fopen("database.csv", "a+");

    if (!fp)
    {
        printf("Can't open file\n");
    }

    int file_num;
    printf("\tEnter Patient's File Number to view their data : ");
    scanf("%d",&file_num);

    char buffer[1024];

    int row = 0;
    int column = 0;
    int flag = 0;

    while (fgets(buffer, 1024, fp))
    {
        column = 0;
        row++;

        if (row == 0)
        {
            continue;
        }

        char *value = strtok(buffer, ", ");
        char nameStore[50];
        char genderStore[20];
        char statusStore[20];
        int fileStore;
        while (value)
        {

            if (column == 0)
            {
                strcpy(nameStore, value);
            }
            if (column == 1)
            {
                strcpy(genderStore, value);
            }
            if (column == 2)
            {
                strcpy(statusStore,value);
            }
            if (column == 3)
            {
                fileStore = atoi(value);
                if (fileStore == file_num)
                {
                    flag = 1;
                    printf("\n\tPatient's Name : %s\n",nameStore);
                    printf("\tPatient's Gender : %s\n",genderStore);
                    printf("\tPatient's Status: %s\n\n",statusStore);
                    break;
                    break;
                }
            }
            value = strtok(NULL, ", ");
            column++;
        }
    }
    if (flag != 1)
    {
        printf("\tData not found!\n\n");
    }
    fclose(fp);
    delay(2000);
    system("cls");
}

void editStatus()
{
    system("cls");
    FILE *fp = fopen("database.csv", "a+");
    FILE *fp1 = fopen("temp.csv","a+");

    if (!fp)
    {
        printf("Can't open file\n");
    }

    int file_num;
    printf("\tEnter Patient's File number to edit their status: ");
    scanf("%d", &file_num);

    char buffer[1024];

    int row = 0;
    int column = 0;
    int flag = 0;
    while (fgets(buffer, 1024, fp))
    {
        column = 0;
        row++;

        if (row == 0)
        {
            continue;
        }

        char *value = strtok(buffer, ", ");
        char nameStore[50], genderStore[20], statusStore[20];
        int fileStore;
        while (value)
        {
            if (column == 0)
            {
                strcpy(nameStore, value);
            }

            if (column == 1)
            {
                strcpy(genderStore, value);
            }

            if (column == 2)
            {
                strcpy(statusStore,value);
            }

            if (column == 3)
            {
                fileStore = atoi(value);
                if (fileStore==file_num)
                {
                    flag = 1;
                    printf("\tEnter New status: ");
                    char newStatus[20];
                    scanf("%s",newStatus);
                    fprintf(fp1, "%s, %s, %s, %s",nameStore,genderStore, newStatus,value);
                    printf("\tEdited Succesfully!\n\n");
                }
                else
                {
                    fprintf(fp1, "%s, %s, %s, %s", nameStore,genderStore,statusStore,value);
                }
            }
            value = strtok(NULL, ", ");
            column++;
        }}
    
    if (flag != 1)
    {
        printf("\tData not found!\n\n");
    }
    fclose(fp);
    fclose(fp1);
    remove("database.csv");
    rename("temp.csv","database.csv");
    delay(2000);
    system("cls");
    
}

void deleteData()
{
    system("cls");
    printf("\t*THIS CANNOT BE UNDONE!!!*\n\n");
    FILE *fp = fopen("database.csv", "a+");
    FILE *fp1 = fopen("temp.csv","a+");

    if (!fp)
    {
        printf("Can't open file\n");
    }

    int file_num;
    printf("\tEnter Patient's ID number to delete data: ");
    scanf("%d", &file_num);

    char buffer[1024];

    int row = 0;
    int column = 0;
    int flag = 0;
    while (fgets(buffer, 1024, fp))
    {
        column = 0;
        row++;

        if (row == 0)
        {
            continue;
        }

        char *value = strtok(buffer, ", ");
        char nameStore[50];
        char genderStore[20];
        char statusStore[20];
        int idStore;
        while (value)
        {
            if (column == 0)
            {
                strcpy(nameStore, value);
            }

            if (column == 1)
            {
                strcpy(genderStore, value);
            }

            if (column == 2)
            {
                strcpy(statusStore,value);
            }

            if (column == 3)
            {
                idStore = atoi(value);
                if (idStore==file_num)
                {
                    flag = 1;
                    printf("\tDeleted Succesfully!\n\n");
                    delay(2500);
                }
                else
                {
                    fprintf(fp1, "%s, %s, %s, %s", nameStore,genderStore,statusStore,value);
                }
            }
            value = strtok(NULL, ", ");
            column++;
        }
    }
    if (flag != 1)
    {
        printf("\n\tData not Found!");
    }
    fclose(fp);
    fclose(fp1);
    remove("database.csv");
    rename("temp.csv","database.csv");
    delay(2000);
    
}

void optionSelecter(int number)
{
    switch (number)
    {
    case 1:
        inputData();
        break;
    case 2:
        checkData();
        break;
    case 3:
        editStatus();
        break;
    case 4:
        deleteData();
        break;
    case 5:
        system("cls");
        printf("\n\tHave a Nice Day!!");
        delay(3000);
        system("cls");
        exit(0);
    default:
        printf("\tPlease select the correct number [1-5]\n");
        delay(2000);
        system("cls");
        break;
    }
}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
