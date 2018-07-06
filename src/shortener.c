#include <stdio.h>
#include <stdlib.h>

typedef struct command {
    short int type;
    char *payload;
} Command;

int parse_command(Command *c, const char *data, ssize_t len) {
    char GET[] = "GET";
    char PUT[] = "PUT";
    char cmd[4];
    short int i;
    int cmd_len = 0;
    
    if (len < 8) {
        return -1;
    }
    
    c->type = -1;
    c->payload = malloc(len * sizeof(char));

    for (i = 0; i < len; i++) {
        if (i < 3) {
            cmd[i] = data[i];  
        } else if(i >= 3) {
            if(data[i] != ' ') {
                c->payload[cmd_len] = data[i];
                cmd_len++;
            }        
        }
    }
    
    cmd[3] = '\0';
 
    if(strcmp(GET, cmd) == 0){
    	c->type = 1;	
    } else if (strcmp(PUT, cmd) == 0) {
    	c->type = 2;
    } else {
    	return -1;
    }

    return 0;
}

void free_command(Command *c){
    free(c->payload);
}

int main(int argc, char *argv[]) {
    const char EXIT_COMMAND[] = "exit\n";
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    Command cmd;

    while((read = getline(&line, &len, stdin)) != -1) {
        if(strcmp(EXIT_COMMAND, line) == 0) {
      	    exit(0);
        }      
        int success = parse_command(&cmd, line, read);
        if(success == 0) {
            printf("type: %i\n", cmd.type);
            printf("url: %s\n", cmd.payload);
        } else {
            printf("command invalid\n");
        }
    }
    free_command(&cmd);
    free(line);
    exit(0);
}


