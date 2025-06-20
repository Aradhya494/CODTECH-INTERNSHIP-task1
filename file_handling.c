#include <stdio.h>
#include <stdlib.h>

void writeToFile() {
    FILE *fp = fopen("data.txt", "w");  // Create or overwrite
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    char text[100];
    printf("Enter text to write to file: ");
    getchar(); // consume newline
    fgets(text, sizeof(text), stdin);
    fputs(text, fp);
    fclose(fp);
    printf("Data written successfully.\n");
}

void readFromFile() {
    FILE *fp = fopen("data.txt", "r");  
    if (fp == NULL) {
        printf("File does not exist or can't be opened.\n");
        return;
    }
    char ch;
    printf("File contents:\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);
}

void appendToFile() {
    FILE *fp = fopen("data.txt", "a");  
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    char text[100];
    printf("Enter text to append: ");
    getchar(); 
    fgets(text, sizeof(text), stdin);
    fputs(text, fp);
    fclose(fp);
    printf("Data appended successfully.\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n----- File Handling Menu -----\n");
        printf("1. Write to File (Create/Overwrite)\n");
        printf("2. Read from File\n");
        printf("3. Append to File\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                writeToFile();
                break;
            case 2:
                readFromFile();
                break;
            case 3:
                appendToFile();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
