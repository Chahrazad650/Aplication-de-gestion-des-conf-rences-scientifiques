#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures
typedef struct {
    char titre[100];
    int nbPages;
    char auteurs[3][50];
    int nbAuteurs;
    char etat[10]; // soumis, accepté, refusé
    char dateSoumission[20];
} Papier;

typedef struct {
    char nom[50];
    char date[20];
    char lieu[50];
    char dateDebutSoumission[20];
    char dateFinSoumission[20];
    Papier papiers[100];
    int nbPapiers;
} Conference;

// Variables globales
Conference conferences[100];
int nbConferences = 0;
int choix, quitterProg = -1;

// Fonctions

void ajouterConference() {
    system("cls");
    printf("=== Ajouter une conference ===\n");
    printf("Nom de la conference: ");
    fflush(stdin);
    gets(conferences[nbConferences].nom);

    printf("Date de la conference JJ/MM/AAAA : ");
    gets(conferences[nbConferences].date);

    printf("Lieu: ");
    gets(conferences[nbConferences].lieu);

    printf("Date debut de soumission : ");
    gets(conferences[nbConferences].dateDebutSoumission);

    printf("Date fin de soumission : ");
    gets(conferences[nbConferences].dateFinSoumission);

    conferences[nbConferences].nbPapiers = 0;
    nbConferences++;

    printf("\nConference ajoutee avec succes !\n");
    system("PAUSE");
    system("cls");
}

void rechercherConference() {
    char nomRecherche[50];
    int trouve = 0;
    system("cls");
    printf("=== Rechercher une conference ===\n");
    printf("Entrez le nom de la conference: ");
    fflush(stdin);
    gets(nomRecherche);

    for (int i = 0; i < nbConferences; i++) {
        if (strcmp(conferences[i].nom, nomRecherche) == 0) {
            printf("Conference trouvee : %s, %s, %s\n", conferences[i].nom, conferences[i].date, conferences[i].lieu);
            trouve = 1;
            break;
        }
    }

    if (!trouve) {
        printf("Conference non trouvee !\n");
    }

    system("PAUSE");
    system("cls");
}

void modifierConference() {
    char nomRecherche[50];
    int trouve = 0;
    system("cls");
    printf("=== Modifier une conference ===\n");
    printf("Entrez le nom de la conference: ");
    fflush(stdin);
    gets(nomRecherche);

    for (int i = 0; i < nbConferences; i++) {
        if (strcmp(conferences[i].nom, nomRecherche) == 0) {
            printf("Nouvelle date JJ/MM/AAAA : ");
            gets(conferences[i].date);
            printf("Nouveau lieu: ");
            gets(conferences[i].lieu);
            printf("Nouvelle date debut soumission: ");
            gets(conferences[i].dateDebutSoumission);
            printf("Nouvelle date fin soumission: ");
            gets(conferences[i].dateFinSoumission);

            printf("\nConference modifiee avec succes !\n");
            trouve = 1;
            break;
        }
    }

    if (!trouve) {
        printf("Conference non trouvee !\n");
    }

    system("PAUSE");
    system("cls");
}

void afficherConference() {
    char nomRecherche[50];
    int trouve = 0;
    system("cls");
    printf("=== Afficher informations d'une conference ===\n");
    printf("Entrez le nom de la conference: ");
    fflush(stdin);
    gets(nomRecherche);

    for (int i = 0; i < nbConferences; i++) {
        if (strcmp(conferences[i].nom, nomRecherche) == 0) {
            printf("\nNom: %s\nDate: %s\nLieu: %s\nDebut Soumission: %s\nFin Soumission: %s\n",
                   conferences[i].nom, conferences[i].date, conferences[i].lieu,
                   conferences[i].dateDebutSoumission, conferences[i].dateFinSoumission);
            trouve = 1;
            break;
        }
    }

    if (!trouve) {
        printf("Conference non trouvee !\n");
    }

    system("PAUSE");
    system("cls");
}

void afficherToutesConferences() {
    system("cls");
    printf("=== Liste de toutes les conferences ===\n");
    for (int i = 0; i < nbConferences; i++) {
        printf("%d) %s - %s - %s\n", i + 1, conferences[i].nom, conferences[i].date, conferences[i].lieu);
    }

    if (nbConferences == 0) {
        printf("Aucune conference enregistree.\n");
    }

    system("PAUSE");
    system("cls");
}

void publierPapier() {
    char nomRecherche[50];
    int trouve = -1;
    system("cls");
    printf("=== Publier un papier scientifique ===\n");
    printf("Entrez le nom de la conference: ");
    fflush(stdin);
    gets(nomRecherche);

    for (int i = 0; i < nbConferences; i++) {
        if (strcmp(conferences[i].nom, nomRecherche) == 0) {
            trouve = i;
            break;
        }
    }

    if (trouve != -1) {
        Papier *p = &conferences[trouve].papiers[conferences[trouve].nbPapiers];

        printf("Titre du papier: ");
        gets(p->titre);

        printf("Nombre de pages: ");
        scanf("%d", &p->nbPages);
        fflush(stdin);

        printf("Nombre d'auteurs (max 3): ");
        scanf("%d", &p->nbAuteurs);
        fflush(stdin);

        for (int j = 0; j < p->nbAuteurs; j++) {
            printf("Auteur %d: ", j + 1);
            gets(p->auteurs[j]);
        }

        printf("Etat du papier (soumis/accepté/refusé): ");
        gets(p->etat);

        printf("Date de soumission JJ/MM/AAAA ");
        gets(p->dateSoumission);

        conferences[trouve].nbPapiers++;

        printf("\nPapier ajoute avec succes !\n");
    } else {
        printf("Conference non trouvee !\n");
    }

    system("PAUSE");
    system("cls");
}

void afficherPapiersConference() {
    char nomRecherche[50];
    int trouve = -1;
    system("cls");
    printf("=== Afficher les papiers d'une conference ===\n");
    printf("Entrez le nom de la conference: ");
    fflush(stdin);
    gets(nomRecherche);

    for (int i = 0; i < nbConferences; i++) {
        if (strcmp(conferences[i].nom, nomRecherche) == 0) {
            trouve = i;
            break;
        }
    }

    if (trouve != -1) {
        printf("\nListe des papiers de la conference %s:\n", conferences[trouve].nom);
        for (int j = 0; j < conferences[trouve].nbPapiers; j++) {
            printf("Titre: %s, Etat: %s, Date Soumission: %s\n",
                   conferences[trouve].papiers[j].titre,
                   conferences[trouve].papiers[j].etat,
                   conferences[trouve].papiers[j].dateSoumission);
        }

        if (conferences[trouve].nbPapiers == 0) {
            printf("Aucun papier soumis.\n");
        }
    } else {
        printf("Conference non trouvee !\n");
    }

    system("PAUSE");
    system("cls");
}

void afficherPapiersAcceptes() {
    system("cls");
    printf("=== Afficher les papiers acceptes ===\n");

    for (int i = 0; i < nbConferences; i++) {
        for (int j = 0; j < conferences[i].nbPapiers; j++) {
            if (strcmp(conferences[i].papiers[j].etat, "accepte") == 0 || strcmp(conferences[i].papiers[j].etat, "accepté") == 0) {
                printf("Conference: %s\nTitre: %s, Auteurs: ", conferences[i].nom, conferences[i].papiers[j].titre);
                for (int k = 0; k < conferences[i].papiers[j].nbAuteurs; k++) {
                    printf("%s ", conferences[i].papiers[j].auteurs[k]);
                }
                printf(", Date Soumission: %s\n", conferences[i].papiers[j].dateSoumission);
            }
        }
    }

    system("PAUSE");
    system("cls");
}

void quitter() {
    quitterProg = 1;
    printf("\n\n\n\n\n\n\n                     *---------     FIN DU PROGRAMME     ---------*\n");
}

// Main

int main() {
    do {
        printf("\n\n=== Application de gestion des conferences scientifiques ===\n\n");
        printf("============================================================\n\n");
        printf("[1] Ajouter une conference\n");
        printf("[2] Rechercher une conference\n");
        printf("[3] Modifier une conference\n");
        printf("[4] Afficher les informations d'une conference\n");
        printf("[5] Afficher toutes les conferences\n");
        printf("[6] Publier un papier scientifique\n");
        printf("[7] Afficher les papiers soumis a une conference donnee\n");
        printf("[8] Afficher les papiers acceptes\n");
        printf("[9] Quitter\n\n");
        printf("============================================================\n\n");

        printf("Entrez votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: ajouterConference(); break;
            case 2: rechercherConference(); break;
            case 3: modifierConference(); break;
            case 4: afficherConference(); break;
            case 5: afficherToutesConferences(); break;
            case 6: publierPapier(); break;
            case 7: afficherPapiersConference(); break;
            case 8: afficherPapiersAcceptes(); break;
            case 9: quitter(); break;
            default: system("cls"); printf("Choix invalide, veuillez entrer un choix valide.\n"); break;
        }
    } while (choix != 9 && quitterProg == -1);

    return 0;
}
