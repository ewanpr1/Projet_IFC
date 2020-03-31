#define MAXI 200

struct Panier
{
    char ID[7];
    char categorie[MAXI];
    char nom[MAXI];
    char prix[MAXI];
    char caract [MAXI];
    char stock [MAXI];
    char quantite [MAXI];
};

typedef struct Panier Panier;
