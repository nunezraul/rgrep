#include <stdio.h>
#define MAXSIZE 4096

/**
 * You can use this recommended helper function 
 * Returns true if partial_line matches pattern, starting from
 * the first char of partial_line.
 */
int matches_leading(char *partial_line, char *pattern) {

	if(partial_line[0] == 0 && pattern[0] == 0){
		return 1;
	}
	if(partial_line[0] == pattern[0] && pattern[1] != '+' && pattern[1] != '?'){
		if(partial_line[1] != 0 && pattern[1] != 0){
			int i=0; int j=0;
			char partial[MAXSIZE]; char pat[MAXSIZE];
			for(int k = 0; k < MAXSIZE; k++){
				partial[k] = 0;
			}
			while(partial_line[i+1] != 0){
				partial[i] = partial_line[i+1];
				i++;
			}
			for(int k = 0; k < MAXSIZE; k++){
				pat[k] = 0;
			}
			while(pattern[j+1] != 0){
				pat[j] = pattern[j+1];
				j++;
			}
			int matches = -1;
			matches = matches_leading(partial, pat);
			if(matches == 0){
				return 0;
			}
			for(int k = 0; k < MAXSIZE; k++){
				partial[k] = 0;
			}
		}
		return 1;
	}
	if((partial_line[0] == 0 && pattern[0] != 0) || (partial_line[0] != 0 && pattern[0] == 0)){
		return 0;
	}
	if(partial_line[0] != pattern[0] && pattern[0] != '.' && pattern[1] != '?' && pattern[0] != '\\'){
		return 0;
	}
	if(pattern[1] == '+' && pattern[0] != '\\'){
		char pat[MAXSIZE]; int i = 0; int matches = -1;
		while(matches != 1 && partial_line[i] != 0){
			for(int k = 0; k < MAXSIZE; k++){
				pat[k] = 0;
			}
			int g = 0; int f = 0;
			for(g = 0; g < i; g++){
				pat[g] = pattern[0];
			}
			while(pattern[f] != 0){
				if(pattern[f] == '+'){
					f++;
					continue;
				}
				pat[g] = pattern[f];
				g++; f++;
			}
			matches = matches_leading(partial_line, pat);
			i++;
		}
		if(matches == 1){
			return 1;
		}
		else 
			return 0;

	}
	if(pattern[0] == '.' && pattern[1] != '+' && pattern[1] != '?' && pattern[0] != '\\'){
		char partial[MAXSIZE]; char pat[MAXSIZE]; int j = 0; int matches = -1;
		for(int k = 0; k < MAXSIZE; k++){
				partial[k] = 0;
		}
		while(partial_line[j+1] != 0){
			partial[j] = partial_line[j+1];
			j++;
		}
		for(int k = 0; k < MAXSIZE; k++){
			pat[k] = 0;
		}
		j = 0;
		while(pattern[j+1] != 0){
			pat[j] = pattern[j+1];
			j++;
		}
		matches = matches_leading(partial, pat);
		if(matches == 0){
			return 0;
		}
	}
	if(pattern[1] == '?' && pattern[1] != '+' && pattern[1] != 0 && pattern[0] != '\\'){
		char pat1[MAXSIZE]; char pat2[MAXSIZE]; int j = 0; int matches1 = -1; int matches2 = -1;
		if(matches1 != 0){
			for(int k = 0; k < MAXSIZE; k++){
				pat1[k] = 0;
			}
			while(pattern[j+2] != 0){
				pat1[j] = pattern[j+2];
				j++;
			}
			matches1 = matches_leading(partial_line, pat1);
		}
		if(matches2 != 0){
			for(int k = 0; k < MAXSIZE; k++){
				pat2[k] = 0;
			}
			pat2[0] = pattern[0]; j = 1;
			while(pattern[j+1] != 0){
				pat2[j] = pattern[j+1];
				j++;
			}
			matches2 = matches_leading(partial_line, pat2);
		}
		if(matches1 == 0 && matches2 == 0){
			return 0;
		}
	}
	if(pattern[0] == '\\'){
		char partial[MAXSIZE]; char pat[MAXSIZE]; int j = 0; int matches = -1;
		if(partial_line[0] == pattern[1]){
			while(pattern[j+2] != 0){
				pat[j] = pattern[j+2];
				j++;
			}
			j = 0;
			while(partial_line[j] != 0){
				partial[j] = partial_line[j+1];
				j++;
			}
			matches = matches_leading(partial, pat);
			if(matches == 0){
				return 0;
			}
		}
		else{
			return 0;
		}
	}
	return 1;
}

/**
 * You may assume that all strings are properly null terminated 
 * and will not overrun the buffer set by MAXSIZE 
 *
 * Implementation of the rgrep matcher function
 */
int rgrep_matches(char *line, char *pattern) {

    //
    // Implement me 
    //
    //looking for partial pattern
    int i = 0; int j = 0; int match;
    char partial[MAXSIZE];
	while(line[i+1] != 0){
		if(line[i] == pattern[j] || pattern[j] == '.'){
			int k = 0;
			while(line[i+1] != 0){
				partial[k] = line[i];
				if(line[i+1] == ' ' || line[i+1] == '\n')
					break;
				i++; k++;
			}
			partial[k+1] = 0;
			match = matches_leading(partial, pattern);
			for(int p = 0; p < k+1; p++)
				partial[p] = 0;
			if(match == 1){
				return 1;
			}
			
		}
		i++;
	}
	
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <PATTERN>\n", argv[0]);
        return 2;
    }

    /* we're not going to worry about long lines */
    char buf[MAXSIZE];

    while (!feof(stdin) && !ferror(stdin)) {
        if (!fgets(buf, sizeof(buf), stdin)) {
            break;
        }
        if (rgrep_matches(buf, argv[1])) {
            fputs(buf, stdout);
            fflush(stdout);
        }
    }

    if (ferror(stdin)) {
        perror(argv[0]);
        return 1;
    }

    return 0;
}
