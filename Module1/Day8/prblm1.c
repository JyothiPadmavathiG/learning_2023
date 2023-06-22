#include <stdio.h>

#define BUFFER_SIZE 4096

int main() {
    FILE *sourceFile, *targetFile;
    char sourcePath[100], targetPath[100];
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    // Input the source file path
    printf("Enter the path of the source file: ");
    scanf("%s", sourcePath);

    // Open the source file in read mode
    sourceFile = fopen(sourcePath, "rb");
    if (sourceFile == NULL) {
        printf("Unable to open the source file.\n");
        return 1;
    }

    // Input the target file path
    printf("Enter the path of the target file: ");
    scanf("%s", targetPath);

    // Open the target file in write mode
    targetFile = fopen(targetPath, "wb");
    if (targetFile == NULL) {
        printf("Unable to create the target file.\n");
        fclose(sourceFile);
        return 1;
    }

    // Copy the contents of the source file to the target file
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, sourceFile)) > 0) {
        fwrite(buffer, 1, bytesRead, targetFile);
    }

    printf("File copied successfully.\n");

    // Close the files
    fclose(sourceFile);
    fclose(targetFile);

    return 0;
}
