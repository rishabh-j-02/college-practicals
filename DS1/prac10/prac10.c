#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void read();
void create();
void removed();
void append();
int main()
{
    int opt, runMenu = 1;
    while (runMenu)
    {
        printf("1. Read the file.");
        printf("\n2. Create the file.");
        printf("\n3. Append the file.");
        printf("\n4. Delete an item in file.");
        printf("\n5. Exit\n");

        printf("Enter the choice : ");
        scanf("%d", &opt);
        switch (opt)
        {
            case 1:
                read();
                break;
            case 2:
                create();
                break;
            case 3:
                append();
                break;
            case 4:
                removed();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Select valid option.\n");
                break;
        }

        printf("To Menu? (0/1) : ");
        scanf("%d", &runMenu);
    }
    return 0;
}
void read()
{
    FILE *fp;
    fp = fopen("Cricket_items.txt", "r");
    if (fp == NULL)
    {
        printf("The file is empty\n");
        return;
    }
    do
    {
        char c = fgetc(fp);
        if (feof(fp))
        {
            break;
        }
        printf("%c", c);
    } while (1);
    fclose(fp);
    printf("File displayed successfully\n");
}
void append()
{
    FILE *fp;
    fp = fopen("Cricket_items.txt", "a");
    if (fp == NULL)
    {
        printf("The file does not exist\n");

        return;
    }
    char str[10];
    printf("Enter the item\n");
    scanf("%s", str);
    fprintf(fp, "%s\n", str);
    fclose(fp);
    printf("File appended successfully\n");
}
void create()
{
    FILE *fp;
    fp = fopen("Cricket_items.txt", "w");
    if (fp == NULL)
    {
        printf("The file does not exist\n");
        return;
    }
    char str[10];
    printf("Enter the item\n");
    scanf("%s", str);
    fprintf(fp, "%s\n", str);
    fclose(fp);
    printf("File created successfully\n");
}
void removed()
{
    int lno, ctr = 0;
    char ch;
    FILE *fptr1, *fptr2;
    char str[256], temp[] = "temp.txt ";
    fptr1 = fopen("Cricket_items.txt", "r");
    if (!fptr1)
    {
        printf("File doesn't exists\n");
        return;
    }
    fptr2 = fopen(temp, "w");
    // if (!fptr1)
    // {
    //     printf("File doesn't exists\n");
    //     return;
    // }
    printf("Enter the line number to be deleted\n");
    scanf("%d", &lno);
    lno++;
    while (!feof(fptr1))
    {
        strcpy(str, "0");
        fgets(str, 256, fptr1);
        if (!feof(fptr1))
        {
            ctr++;
            if (ctr != lno)

            {
                fprintf(fptr2, "%s", str);
            }
        }
    }
    fclose(fptr1);
    fclose(fptr2);
    remove("Cricket_items.txt");
    rename(temp, "Cricket_items.txt");
    printf("Item removed successfully\n");
}