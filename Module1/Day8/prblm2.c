#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 4096

void copyFile(FILE *sourceFile, FILE *targetFile, int option) {
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, sourceFile)) > 0) {
        if (option == 1) { // Upper case option
            for (size_t i = 0; i < bytesRead; i++) {
                buffer[i] = toupper(buffer[i]);
            }
        } else if (option == 2) { // Lower case option
            for (size_t i = 0; i < bytesRead; i++) {
                buffer[i] = tolower(buffer[i]);
            }
        } else if (option == 3) { // Sentence case option
            int capitalize = 1; // Flag to indicate whether the next character should be capitalized
            for (size_t i = 0; i < bytesRead; i++) {
                if (capitalize) {
                    buffer[i] = toupper(buffer[i]);
                    capitalize = 0;
                } else {
                    buffer[i] = tolower(buffer[i]);
                }

                if (buffer[i] == '.' || buffer[i] == '?' || buffer[i] == '!') {
                    capitalize = 1;
                }
            }
        }

        fwrite(buffer, 1, bytesRead, targetFile);
    }
}

int main(int argc, char *argv[]) {
    FILE *sourceFile, *targetFile;
    char *sourcePath, *targetPath;
    int option = 0;

    if (argc < 3) {
        printf("Usage: %s [-u | -l | -s] source_file target_file\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "-u") == 0) {
        option = 1; // Upper case option
    } else if (strcmp(argv[1], "-l") == 0) {
        option = 2; // Lower case option
    } else if (strcmp(argv[1], "-s") == 0) {
        option = 3; // Sentence case option
    }

    sourcePath = argv[2];
    targetPath = argv[3];

    // Open the source file in read mode
    sourceFile = fopen(sourcePath, "rb");
    if (sourceFile == NULL) {
        printf("Unable to open the source file.\n");
        return 1;
    }

    // Open the target file in write mode
    targetFile = fopen(targetPath, "wb");
    if (targetFile == NULL) {
        printf("Unable to create the target file.\n");
        fclose(sourceFile);
        return 1;
    }

    // Copy the file content with the specified case option
    copyFile(sourceFile, targetFile, option);

    printf("File copied successfully.\n");

    // Close the files
    fclose(sourceFile);
    fclose(targetFile);

    return 0;
}
