// Miguel Angel Lopez Sanchez fc65675
// Alejandro Dominguez fc64447
// Bruno Felisberto fc32435

#include <stdio.h>
#include <stdlib.h>
#include "../inc/csettings.h"

void read_args(char *filename, struct info_container* info) {
    FILE *fp = fopen(filename, "r");
    if(fp == NULL) {
        perror("Error ao abrir o ficheiro de argumentos");
        exit(EXIT_FAILURE);
    }

    if(fscanf(fp,
        "%f %d %d %d %d",
        &info->init_balance,
        &info->n_wallets,
        &info->n_servers,
        &info->buffers_size,
        &info->max_txs) != 5) {

        fclose(fp);
        perror("Error ao ler o ficheiro de argumentos");
        exit(EXIT_FAILURE);
    }

    fclose(fp);
}

void read_settings(char *filename, char *lf, char *sf, int *p) {
    FILE *fp = fopen(filename, "r");
    if(fp == NULL) {
        perror("Error ao abrir o ficheiro de argumentos");
        exit(EXIT_FAILURE);
    }
    if (fscanf(fp, "%s %s %d",
        lf,
        sf,
        p) != 3){
        
        fclose(fp);
        perror("Error ao ler o ficheiro de settings");
        exit(EXIT_FAILURE);
        
    }

    fclose(fp);
}