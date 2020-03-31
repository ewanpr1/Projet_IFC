#define MAXI 200

struct Client
{
    char ID[5];
    char NOM[MAXI];
    char MDP[MAXI];
};

typedef struct Client Client;
