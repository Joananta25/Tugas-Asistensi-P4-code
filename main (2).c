#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int energy;
    int loves;
    char type[20];
} Character;

Character* createCharacter(char* name, char* type, int energy, int loves) {
    Character* newCharacter = (Character*)malloc(sizeof(Character));
    strcpy(newCharacter->name, name);
    strcpy(newCharacter->type, type);
    newCharacter->energy = energy;
    newCharacter->loves = loves;
    return newCharacter;
}

void petting(Character* character) {
    if (strcmp(character->type, "pet") == 0) {
        character->loves += 10;
        character->energy -= 5;
        printf("%s sedang dimanja! Loves sekarang: %d, Energy sekarang: %d\n", character->name, character->loves, character->energy);
    } else {
        printf("%s bukan hewan! Perintah PETTING hanya bisa digunakan pada hewan.\n", character->name);
    }
}

void serveCoffee(Character* character) {
    if (strcmp(character->type, "pegawai") == 0) {
        character->loves += 5;
        character->energy -= 10;
        printf("%s sedang menyajikan kopi! Loves sekarang: %d, Energy sekarang: %d\n", character->name, character->loves, character->energy);
    } else {
        printf("%s bukan pegawai! Perintah SERVE hanya bisa digunakan pada pegawai.\n", character->name);
    }
}

void showAttributes(Character* character) {
    printf("Atribut dari %s (%s):\n", character->name, character->type);
    printf("Energy: %d\n", character->energy);
    printf("Loves: %d\n", character->loves);
}

void handleCommand(char* command, Character* characters[], int numCharacters) {
    char action[50];
    char name[50];

    int matches = sscanf(command, "%s %s", action, name);

    Character* selectedCharacter = NULL;
    for (int i = 0; i < numCharacters; i++) {
        if (strcmp(characters[i]->name, name) == 0) {
            selectedCharacter = characters[i];
            break;
        }
    }

    if (selectedCharacter == NULL) {
        printf("Karakter %s tidak ditemukan!\n", name);
        return;
    }

    if (strcmp(action, "PETTING") == 0) {
        petting(selectedCharacter);
    } else if (strcmp(action, "SERVE") == 0) {
        serveCoffee(selectedCharacter);
    } else if (strcmp(action, "ATTR") == 0) {
        showAttributes(selectedCharacter);
    } else {
        printf("Perintah tidak dikenali!\n");
    }
}

int main() {
    Character* characters[6];
    characters[0] = createCharacter("Moka", "pet", 100, 50);
    characters[1] = createCharacter("Matcha", "pet", 90, 60);
    characters[2] = createCharacter("Milo", "pet", 80, 70);
    characters[3] = createCharacter("Inul", "pegawai", 120, 70);
    characters[4] = createCharacter("Nassar", "pegawai", 110, 80);
    characters[5] = createCharacter("Keanu", "pegawai", 105, 90);

    printf("Selamat datang di Pet Cafe!\n");
    printf("Gunakan perintah 'PETTING <NAMA>' untuk memanjakan hewan.\n");
    printf("Gunakan perintah 'SERVE <NAMA>' untuk pegawai menyajikan kopi.\n");
    printf("Gunakan perintah 'ATTR <NAMA>' untuk melihat atribut karakter.\n");
    printf("Ketik 'exit' untuk keluar.\n");

    char input[100];
    while (1) {
        printf("Masukkan perintah: ");
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = 0;
        
        if (strcmp(input, "exit") == 0) {
            printf("Simulasi dihentikan.\n");
            break;
        }

        handleCommand(input, characters, 6);
    }

    for (int i = 0; i < 6; i++) {
        free(characters[i]);
    }

    return 0;
}
