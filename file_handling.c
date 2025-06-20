
#include <stdio.h>
#include <stdlib.h>

void writeToFile(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    fprintf(fp, "This is the first line written to the file.\n");
    fprintf(fp, "This is the second line.\n");
    fclose(fp);
    printf("Data written to file successfully.\n");
}

void readFile(const char *filename) {
    FILE *fp = fopen(filename, "r");
    char ch;

    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    printf("\nContents of the file:\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);
}

void appendToFile(const char *filename) {
    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error opening file for appending.\n");
        return;
    }
    fprintf(fp, "This line is appended to the file.\n");
    fclose(fp);
    printf("Data appended to file successfully.\n");
}

int main() {
    const char *filename = "example.txt";
    int choice;

    while (1) {
        printf("\n----- File Handling Menu -----\n");
        printf("1. Write to File (Create/Overwrite)\n");
        printf("2. Read from File\n");
        printf("3. Append to File\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                writeToFile(filename);
                break;
            case 2:
                readFile(filename);
                break;
            case 3:
                appendToFile(filename);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}


