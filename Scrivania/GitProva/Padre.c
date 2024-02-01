#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int p1, p2;

int main() {
    // Creazione primo figlio
    if ((p1 = fork()) == 0) 
    {
        // Codice del primo figlio
        printf("Primo Figlio: PID = %d. Il mio padre ha PID = %d\n", getpid(), getppid());       
        exit(0); 
    } else if (p1 < 0) 
    {
        // Errore nella creazione del primo figlio
        perror("Errore nella creazione del primo figlio");
        return -1;
    }

    // Creazione secondo figlio
    if ((p2 = fork()) == 0) {
        // Codice del secondo figlio
        printf("Secondo Figlio: PID = %d. Il mio padre ha PID = %d\n", getpid(), getppid());      
        exit(0); 
    } else if (p2 < 0) 
    {
        // Errore nella creazione del secondo figlio
        perror("Errore nella creazione del secondo figlio");
        return -1;
    }

    // Codice del padre
    printf("Padre: PID = %d\n", getpid());
    printf("Padre: Primo figlio ha PID = %d\n", p1);
    printf("Padre: Secondo figlio ha PID = %d\n", p2);

    // Altri compiti del padre possono essere eseguiti qui

    return 0;
}

