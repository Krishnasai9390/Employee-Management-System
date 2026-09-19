#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include<time.h>
struct employee {
    int empno;
    char name[50];
    char location[50];
    char band[20];
    char role[50];
    char skills[100];
    struct employee *next;
};
struct employee *addemployee(int empno,
                             char name[],
                             char location[],
                             char band[],
                             char role[],
                             char skills[])
{
    struct employee *newemployee= malloc(sizeof(struct employee));
    if (newemployee == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newemployee->empno = empno;
    strcpy(newemployee->name, name);
    strcpy(newemployee->location, location);
    strcpy(newemployee->band, band);
    strcpy(newemployee->role, role);
    strcpy(newemployee->skills, skills);
    newemployee->next = NULL;
    return newemployee;
}
struct employee *loademployees(const char filename[])
{
    FILE *file;
    struct employee *head = NULL;
    struct employee *tail = NULL;
    struct employee *newemployee;
    int empno;
    char name[50];
    char location[50];
    char band[20];
    char role[50];
    char skills[100];
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Cannot open %s\n", filename);
        return NULL;
    }
    while (fscanf(file,
                  "%d %49s %49s %19s %49s %99s",
                  &empno,
                  name,
                  location,
                  band,
                  role,
                  skills) == 6)
    {
        newemployee = addemployee(empno,name,location,band,role,skills);
if(head == NULL || newemployee->empno < head->empno)
{
    newemployee->next = head;
    head = newemployee;
}
else
{
    struct employee *temp = head;
    while(temp->next != NULL &&
          temp->next->empno < newemployee->empno)
    {
        temp = temp->next;
    }
    newemployee->next = temp->next;
    temp->next = newemployee;
}
    }
    fclose(file);
    return head;
}
struct employee *saveemployees(const char filename[],
                                   struct employee *head)
{
    FILE *file;
    struct employee *temp;
    file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Cannot open %s for writing\n", filename);
        return head;
    }
    temp = head;
    while (temp != NULL)
    {
        fprintf(file,
                "%d %s %s %s %s %s\n",
                temp->empno,
                temp->name,
                temp->location,
                temp->band,
                temp->role,
                temp->skills);
        temp = temp->next;
    }
    fclose(file);
    return head;
}
int hasskill(char skills[], char word[]) {
    char skillcopy[100];
    char *oneskill;
    strcpy(skillcopy, skills);
    oneskill = strtok(skillcopy, ",");
    while(oneskill != NULL) {
        if(strcasecmp(oneskill, word) == 0) {
            return 1;
        }
        oneskill = strtok(NULL, ",");
    }
    return 0;
}
struct employee *addnewemployee(struct employee *head)
{
    int empno;
    char name[50];
    char location[50];
    char band[20];
    char role[50];
    char skills[100];
    struct employee *newemp;
    struct employee *temp;
    printf("Enter Employee Number: ");
    if(scanf("%d", &empno) != 1)
    {
        printf("Invalid Employee Number.\n");
        while(getchar() != '\n');
        return head;
    }
    temp = head;
    while(temp != NULL)
    {
        if(temp->empno == empno)
        {
            printf("Employee Number %d already exists.\n",
                   empno);
            return head;
        }
        temp = temp->next;
    }
    printf("Enter Name: ");
    scanf("%49s", name);
    printf("Enter Location: ");
    scanf("%49s", location);
    printf("Enter Band: ");
    scanf("%19s", band);
    printf("Enter Role: ");
    scanf("%49s", role);
    printf("Enter Skills : ");
    scanf("%99s", skills);
    newemp = addemployee(empno,
                         name,
                         location,
                         band,
                         role,
                         skills);
    if(head == NULL || newemp->empno < head->empno)
{
    newemp->next = head;
    head = newemp;
}
else
{
    temp = head;
 
    while(temp->next != NULL &&
          temp->next->empno < newemp->empno)
    {
        temp = temp->next;
    }
 
    newemp->next = temp->next;
    temp->next = newemp;
}
    head = saveemployees("empdata.txt", head);
    printf("Employee Added Successfully.\n");
    return head;
}
 
struct employee *update(struct employee *head)
{
    int empno;
    int choice;
    struct employee *temp;
 
    if(head == NULL)
    {
        printf("Employee list is empty.\n");
        return head;
    }
 
    printf("Enter Employee Number to Update: ");
    scanf("%d", &empno);
 
    temp = head;
 
    while(temp != NULL)
    {
        if(temp->empno == empno)
        {
            printf("\nEmployee Found:\n");
            printf("EmpNo    : %d\n", temp->empno);
            printf("Name     : %s\n", temp->name);
            printf("Location : %s\n", temp->location);
            printf("Band     : %s\n", temp->band);
            printf("Role     : %s\n", temp->role);
            printf("Skills   : %s\n", temp->skills);
 
            printf("\nSelect Field To Update\n");
            printf("1. Location\n");
            printf("2. Band\n");
            printf("3. Role\n");
            printf("4. Skills\n");
            printf("Enter Choice : ");
            scanf("%d", &choice);
 
            switch(choice)
            {
                case 1:
                    printf("Enter New Location : ");
                    scanf("%49s", temp->location);
                    break;
 
                case 2:
                    printf("Enter New Band : ");
                    scanf("%19s", temp->band);
                    break;
 
                case 3:
                    printf("Enter New Role : ");
                    scanf("%49s", temp->role);
                    break;
 
                case 4:
                    printf("Enter New Skills : ");
                    scanf("%99s", temp->skills);
                    break;
 
                default:
                    printf("Invalid Choice.\n");
                    return head;
            }
 
            printf("Employee Updated Successfully.\n");
            return head;
        }
 
        temp = temp->next;
    }
 
    printf("Employee Number %d not found.\n", empno);
    return head;
}
struct employee *shiftlocation(struct employee *head)
{
    int empno;
    char newlocation[50];
 
    struct employee *temp = head;
 
    printf("Enter Employee Number : ");
    scanf("%d", &empno);
 
    while(temp != NULL)
    {
        if(temp->empno == empno)
        {
            printf("Current Location : %s\n",
                   temp->location);
 
            printf("Enter New Location : ");
            scanf("%49s", newlocation);
 
            strcpy(temp->location,
                   newlocation);
 
            printf("Location Updated Successfully.\n");
 
            return head;
        }
 
        temp = temp->next;
    }
 
    printf("Employee Not Found.\n");
 
    return head;
}
struct employee *delete(struct employee *head)
{
    int empno;
    struct employee *temp;
    struct employee *prev;
    if(head == NULL)
    {
        printf("Employee list is empty.\n");
        return head;
    }
    printf("Enter Employee Number to Delete: ");
    scanf("%d", &empno);
    temp = head;
    prev = NULL;
    while(temp != NULL)
    {
        if(temp->empno == empno)
        {
            printf("\nEmployee Found:\n");
            printf("EmpNo    : %d\n", temp->empno);
            printf("Name     : %s\n", temp->name);
            printf("Location : %s\n", temp->location);
            printf("Band     : %s\n", temp->band);
            printf("Role     : %s\n", temp->role);
            printf("Skills   : %s\n", temp->skills);
            char confirm;
            printf("\nAre you sure you want to delete? (Y/N): ");
            scanf(" %c", &confirm);
            if(confirm != 'Y' && confirm != 'y')
            {
                printf("Delete operation cancelled.\n");
                return head;
            }
            if(prev == NULL)
            {
                head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            free(temp);
            printf("Employee Deleted Successfully.\n");
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Employee Number %d not found.\n", empno);
    return head;
}
void printline(FILE *out) {
    fprintf(out, "------------------------------------------------------------------------------------------------\n");
}
void printheader(FILE *out) {
    printline(out);
    fprintf(out, "%-10s %-15s %-14s %-8s %-12s %-30s\n",
           "Emp No", "Name", "Location", "Band", "Role", "Skills");
    printline(out);
}
void printemployee(FILE *out, struct employee *employee) {
    fprintf(out, "%-10d %-15s %-14s %-8s %-12s %-30s\n",
           employee->empno, employee->name, employee->location,
           employee->band, employee->role, employee->skills);
}
int matchesoneword(struct employee *employee, char word[])
{
    char empnostr[20];
    sprintf(empnostr, "%d", employee->empno);
    return strcasecmp(employee->name, word) == 0 ||
           strcmp(empnostr, word) == 0 ||
           strcasecmp(employee->location, word) == 0 ||
           strcasecmp(employee->band, word) == 0 ||
           strcasecmp(employee->role, word) == 0 ||
           hasskill(employee->skills, word);
}
int matchesallwords(struct employee *employee, char words[][50], int wordcount) {
    int i;
    for (i = 0; i < wordcount; i++) {
        if (!matchesoneword(employee, words[i])) {
            return 0;
        }
    }
    return 1;
}
void showall(FILE *out, struct employee *head) {
    int count = 0;
    printheader(out);
    while (head != NULL) {
        printemployee(out, head);
        count++;
        head = head->next;
    }
    printline(out);
    fprintf(out, "Total employees: %d\n", count);
}
void searchemployees(FILE *out, struct employee *head, char words[][50], int wordcount) {
    int count = 0;
    printheader(out);
    while (head != NULL) {
        if (matchesallwords(head, words, wordcount)) {
            printemployee(out, head);
            count++;
      }
        head = head->next;
    }
    printline(out);
    if (count == 0) {
        fprintf(out, "No matching employees found.\n");
    } else {
       fprintf(out, "Total matching employees: %d\n", count);
    }
}
int splitwords(char input[], char words[][50]) {
    char *word;
    int wordcount = 0;
    word = strtok(input, " \t\n");
    while (word != NULL ) {
        strcpy(words[wordcount], word);
        wordcount++;
        word = strtok(NULL, " \t\n");
    }
    return wordcount;
}
void freelist(struct employee *head) {
    struct employee *next;
    while (head != NULL) {
        next = head->next;
        free(head);
        head = next;
    }
}
void makefilename(char filename[], char prefix[])
{
    time_t now;
    struct tm *t;
    now = time(NULL);
    t = localtime(&now);
    sprintf(filename,
            "%s_%02d%02d%02d_%02d%02d%04d.txt",
            prefix,
            t->tm_hour,
            t->tm_min,
            t->tm_sec,
            t->tm_mday,
            t->tm_mon + 1,
            t->tm_year + 1900);
}
int main(void)
{
    struct employee *head;
    int choice;
    char input[200];
    char words[10][50];
    int wordcount;
    char filename[100];
    FILE *out;
    head = loademployees("empdata.txt");
    if (head == NULL)
    {
        return 1;
    }
    printf("Employees loaded from empdata.txt\n");
    while (1)
    {
        printf("\n");
        printf("1. Add Employee\n");
        printf("2. Search Employee\n");
        printf("3. Update Employee\n");
        printf("4. Delete Employee\n");
        printf("5. Show All Employees\n");
        printf("6. Shift Employee Location\n");
        printf("7. Exit\n");
        printf("Enter Choice : ");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
            case 1:
                head = addnewemployee(head);
                break;
            case 2:
                printf("Search : ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = '\0';
                if(input[0] == '\0')
                {
                    printf("Search value cannot be empty.\n");
                    break;
                }
                wordcount = splitwords(input, words);
                makefilename(filename, "search");
                out = fopen(filename, "w");
                if (out == NULL)
                {
                    printf("Could not create output file %s\n",
                           filename);
                    break;
                }
                searchemployees(out,
                                head,
                                words,
                                wordcount);
                fclose(out);
                printf("Output written to %s\n",
                       filename);
                break;
            case 3:
                head = update(head);
                head = saveemployees("empdata.txt",
                                     head);
                break;
            case 4:
                head = delete(head);
                head = saveemployees("empdata.txt",
                                     head);
                break;
            case 5:
                makefilename(filename, "showall");
                out = fopen(filename, "w");
                if (out == NULL)
                {
                    printf("Could not create output file %s\n",
                           filename);
                    break;
                }
                showall(out, head);
                fclose(out);
                printf("Output written to %s\n",
                       filename);
                break;
            case 6:
                head = shiftlocation(head);
                head = saveemployees("empdata.txt", head);
                break;
            case 7:
                freelist(head);
                printf("program exit\n");
                return 0;
            default:
                printf("Invalid Choice. Please enter 1 to 6.\n");
        }
    }
    freelist(head);
    return 0;
}