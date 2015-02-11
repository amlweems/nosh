#include<stdlib.h>
#include<stdio.h>

void nosh_loop();
char* nosh_read_line();
char** nosh_make_tokens();
int nosh_execute();


int main(int argc, char **argv) {
    nosh_loop();
    return EXIT_SUCCESS;
}

void nosh_loop() {
    char * line;
    char ** tokens;
    int status;
    do {
        printf("> ");
        line = nosh_read_line();
        tokens = nosh_make_tokens(line);
        status = nosh_execute(tokens);
    } while (status);
}

char * nosh_read_line() {
    char *line = NULL;
    ssize_t bufsize = 0;

    if (getline(&line, &bufsize, stdin) == -1) {
        fprintf(stderr, "nosh: allocation error\n");
        exit(EXIT_FAILURE);
    }
    return line;
}
