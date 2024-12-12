#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

int main(){
    const char *filename = "base.txt";
    int choice;
    char name[35];
    char author[35];

    while (1){
        printf("1. Add magazine\n2. Read magazines\n3. Delete magazine\n4. Search magazine\n5. Edit magazine\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                AddMag(filename);
                break;

            case 2:
                ReadMags(filename);
                break;

            case 3:
                printf("Enter name of the magazine to remove from list: ");
                scanf("%s", name);
                RemoveMag(filename, name);
                break;

            case 4:
                int k;
                printf("What criteria do you use to find a magazine?\n 1 - name\n 2 - author\n");
                printf("Enter your choice: ");
                scanf("%i", &k);

                if (k == 1){
                    printf("Enter name of the magazine to search: ");
                    scanf("%s", name);
                    SearchMagByName(filename, name);
                    break;
                }
                if (k == 2){
                    printf("Enter author of the magazine to search: ");
                    scanf("%s", author);
                    SearchMagByAuthor(filename, author);
                    break;
                }
                else{
                    printf("Invalid choice\n");
                    break;
                }

            case 5:
                printf("Enter name of the magazine to edit: ");
                scanf("%s", name);
                EditMag(filename, name);
                break;

            case 6:
                exit(0);
                
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
