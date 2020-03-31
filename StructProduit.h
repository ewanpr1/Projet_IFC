#define MAXI 200

struct Produit
{
    char ID[7];
    char categorie[MAXI];
    char nom[MAXI];
    char prix[MAXI];
    char caract [MAXI];
    char stock [MAXI];
};

typedef struct Produit Produit;
