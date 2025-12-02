#include <stdio.h>

struct patient {
    char name[40];
    int age;
    char disease[30];
    int id;
};

void addPatient(struct patient p[], int *n);
void displayPatients(struct patient p[], int n);
int searchPatient(struct patient p[], int n, int id);
void editPatient(struct patient *x);
void deletePatient(struct patient p[], int *n, int id);
void sortByName(struct patient p[], int n);
void sortByAge(struct patient p[], int n);

int main() {
    struct patient p[100];
    int id, n = 0, index, choice;

    while (1) {
        printf("\n1. ADD NEW PATIENT.\n");
        printf("2. DISPLAY DETAILS OF PATIENTS.\n");
        printf("3. SEARCH ANY PATIENT.\n");
        printf("4. EDIT DETAILS OF A PATIENT.\n");
        printf("5. DELETE PATIENT'S RECORD.\n");
        printf("6. SORT PATIENTS BY NAME.\n");
        printf("7. SORT PATIENTS BY AGE.\n");
        printf("8. EXIT.\n");

        printf("ENTER YOUR CHOICE (1 to 8): ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addPatient(p, &n);
            break;

        case 2:
            displayPatients(p, n);
            break;

        case 3:
            printf("Enter Patient ID: ");
            scanf("%d", &id);
            index = searchPatient(p, n, id);
            if (index != -1)
                printf("Found → Name: %s, Age: %d, Disease: %s\n",
                       p[index].name, p[index].age, p[index].disease);
            else
                printf("Patient not found!\n");
            break;

        case 4:
            printf("Enter Patient ID to Edit: ");
            scanf("%d", &id);
            index = searchPatient(p, n, id);
            if (index != -1)
                editPatient(&p[index]);
            else
                printf("Patient not found!\n");
            break;

        case 5:
            printf("Enter Patient ID to Delete: ");
            scanf("%d", &id);
            deletePatient(p, &n, id);
            break;

        case 6:
            sortByName(p, n);
            printf("Sorted by Name!\n");
            break;

        case 7:
            sortByAge(p, n);
            printf("Sorted by Age!\n");
            break;

        case 8:
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }
}

void addPatient(struct patient p[], int *n) {
    printf("\nEnter ID: ");
    scanf("%d", &p[*n].id);
    printf("Enter Name: ");
    scanf(" %[^\n]", p[*n].name);
    printf("Enter Age: ");
    scanf("%d", &p[*n].age);
    printf("Enter Disease: ");
    scanf(" %[^\n]", p[*n].disease);
    (*n)++;
    printf("Patient Added Successfully!\n");
}

void displayPatients(struct patient p[], int n) {
    int i;
    if (n == 0) {
        printf("No patients found!\n");
        return;
    }
    for (i = 0; i < n; i++) {
        printf("\nID: %d\nName: %s\nAge: %d\nDisease: %s\n",
               p[i].id, p[i].name, p[i].age, p[i].disease);
    }
}

int searchPatient(struct patient p[], int n, int id) {
    int i;
    for (i = 0; i < n; i++) {
        if (p[i].id == id)
            return i;
    }
    return -1;
}

void editPatient(struct patient *x) {
    printf("Enter New Name: ");
    scanf(" %[^\n]", x->name);
    printf("Enter New Age: ");
    scanf("%d", &x->age);
    printf("Enter New Disease: ");
    scanf(" %[^\n]", x->disease);
    printf("Record Updated!\n");
}

void deletePatient(struct patient p[], int *n, int id) {
    int i, index = -1;
    for (i = 0; i < *n; i++) {
        if (p[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Patient not found!\n");
        return;
    }
    for (i = index; i < *n - 1; i++)
        p[i] = p[i + 1];
    (*n)--;
    printf("Patient Deleted!\n");
}

void sortByName(struct patient p[], int n) {
    int i, j, k;
    struct patient temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            k = 0;
            while (p[i].name[k] == p[j].name[k] && p[i].name[k] != '\0')
                k++;
            if (p[i].name[k] > p[j].name[k]) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

void sortByAge(struct patient p[], int n) {
    int i, j;
    struct patient temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].age > p[j].age) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}
