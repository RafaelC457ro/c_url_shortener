#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "base_62.h"
#include "hash_list.h"

typedef struct command {
    short int type;
    char *payload;
} Command;

#define TYPE_GET 1
#define TYPE_PUT 2

int parse_command(Command *c, const char *data, size_t len) {
    char cmd[4];
    short int i;
    int cmd_len = 0;

    if (len < 8) {
        return -1;
    }

    c->type = -1;
    c->payload = malloc(len * sizeof(char));

    for (i = 0; i < len - 1; i++) {
        if (i < 3) {
            cmd[i] = data[i];
        } else if (i >= 3) {
            if (data[i] != ' ') {
                c->payload[cmd_len] = data[i];
                cmd_len++;
            }
        }
    }

    cmd[3] = 0x00;

    if (strcmp("GET", cmd) == 0) {
        c->type = TYPE_GET;
    } else if (strcmp("PUT", cmd) == 0) {
        c->type = TYPE_PUT;
    } else {
        return -1;
    }

    return 0;
}

void free_command(Command *c) { free(c->payload); }

void generate_random_key(char *s) {
    uint64_t i;
    srand(time(NULL));
    i = rand() % 0x7538DCFB7617FF + 0x70C849DCFFFEE;
    base_62_encode(i, s);
}

void handle_get_command(HashList *h, char *k) {
    char *scmp;

    if (hash_list_get(h, k, &scmp) != 0) {
        printf("key not found\n\n");
    } else {
        printf("%s\n\n", scmp);
    }
}

void handle_put_command(HashList *h, char *v) {
    char *scmp;
    char key[15];
    generate_random_key(key);

    while (hash_list_get(h, key, &scmp) == 0) {
        generate_random_key(key);
    }

    hash_list_append(h, key, v);
    printf("%s\n\n", key);
}

int main(int argc, char *argv[]) {
    char *input = NULL;
    size_t input_size = 0;
    HashList *h = hash_list_init();
    Command cmd;
    
    printf("Enter a command (or 'quit' to exit): \n\n");
    while (1) {   
        getline(&input, &input_size, stdin);

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "quit") == 0) {
            printf("Exiting the program...\n");
            break;
        }

        int success = parse_command(&cmd, input, input_size);
        if (success != 0) {
            printf("command invalid\n\n");
        } else {
            if (cmd.type == TYPE_GET) {
                handle_get_command(h, cmd.payload);
            } else if (cmd.type == TYPE_PUT) {
                handle_put_command(h, cmd.payload);
            }
        }
    }

    free(input); 
    hash_list_free(h);
    free_command(&cmd);

    return 0;
}
