#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

void AddMag(const char *filename){
    mag m;
    FILE *file = fopen(filename, "a");
    if (!file){
        perror("Unable to open file");
        return;
    }
    printf("Enter name: ");
    scanf("%s", m.name);
    printf("Enter author: ");
    scanf("%s", m.author);
    printf("Enter pass(approved or rejected): ");
    scanf("%s", m.pass);
    printf("Enter release date: ");
    scanf("%s", m.release_date);
    fprintf(file, "%s %s %s %s\n", m.name, m.author, m.pass, m.release_date);
    fclose(file);
}

void ReadMags(const char *filename){
    mag m;
    FILE *file = fopen(filename, "r");
    if (!file){
        perror("Unable to open file");
        return;
    }
    while (fscanf(file, "%s %s %s %s\n", m.name, m.author, m.pass, m.release_date) != EOF){
        printf("Name: %s, Author: %s, Pass: %s, Date of release: %s\n", m.name, m.author, m.pass, m.release_date);
    }
    fclose(file);
}

void RemoveMag(const char *filename, const char *nameToDelete){
    mag m;
    FILE *file = fopen(filename, "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!file || !temp){
        perror("Unable to open file");
        return;
    }
    while (fscanf(file, "%s %s %s %s\n", m.name, m.author, m.pass, m.release_date) != EOF){
        if (strcmp(m.name, nameToDelete) != 0){
            fprintf(temp, "%s %s %s %s\n", m.name, m.author, m.pass, m.release_date);
        }
    }
    fclose(file);
    fclose(temp);
    remove(filename);
    rename("temp.txt", filename);
}

void SearchMagByName(const char *filename, const char *nameToSearch){
    mag m;
    FILE *file = fopen(filename, "r");
    if (!file){
        perror("Unable to open file");
        return;
    }
    int found = 0;
    while (fscanf(file, "%s %s %s %s\n", m.name, m.author, m.pass, m.release_date) != EOF){
        if (strcmp(m.name, nameToSearch) == 0){
            printf("Found: Name: %s, Author: %s, Pass: %s, Date of release: %s\n", m.name, m.author, m.pass, m.release_date);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Magazine not found\n");
    }
    fclose(file);
}
void SearchMagByAuthor(const char *filename, const char *authorToSearch){
    mag m;
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        return;
    }
    int found = 0;
    while (fscanf(file, "%s %s %s %s\n", m.name, m.author, m.pass, m.release_date) != EOF){
        if (strcmp(m.author, authorToSearch) == 0){
            printf("Found: Name: %s, Author: %s Pass: %s, Date of release: %s\n", m.name, m.author, m.pass, m.release_date);
            found ++;
        }
    }
    if (!found) {
        printf("Magazine not found\n");
    }
    fclose(file);
}