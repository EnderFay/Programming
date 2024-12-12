typedef struct magazine{
    char name[35];
    char author[35];
    char pass[12];
    char release_date[20];
} mag;

void AddMag(const char *filename);
void ReadMags(const char *filename);
void RemoveMag(const char *filename, const char *nameToDelete);
void SearchMagByName(const char *filename, const char *nameToSearch);
void SearchMagByAuthor(const char *filename, const char *authorToSearch);
void EditMag(const char *filename, const char *nameToEdit);
