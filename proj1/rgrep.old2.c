#include <stdio.h>
#define MAXSIZE 4096

/**
 * You can use this recommended helper function 
 * Returns true if partial_line matches pattern, starting from
 * the first char of partial_line.
 */
int matches_leading(char *partial_line, char *pattern) {

	//int matches = -1;
	printf("partial_line =%s | pattern =%s\n", partial_line, pattern);
	if(partial_line[0] == 0 && pattern[0] == 0){
		printf("partial_line and pattern reached end of line. Returning 1\n");
		return 1;
	}
	if(partial_line[0] == pattern[0] && pattern[1] != '+' && pattern[1] != '?'){
		printf("pattern_line[0] = %c is equal to pattern[0] = %c\n",partial_line[0], pattern[0]);
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
			printf("i = %d partial2 = %s\n", i, partial);
			int matches = -1;
			matches = matches_leading(partial, pat);
			if(matches == 0){
				printf("Return 0 from partial_line[0] = pattern[0]. Matches returned 0\n");
				return 0;
			}
			for(int k = 0; k < MAXSIZE; k++){
				partial[k] = 0;
			}
		}
		printf("Passed partial_line[0] = pattern[0]. Returning 1\n");
		return 1;
	}
	if((partial_line[0] == 0 && pattern[0] != 0) || (partial_line[0] != 0 && pattern[0] == 0)){
		return 0;
	}
	if(partial_line[0] != pattern[0] && pattern[0] != '.' && pattern[1] != '?' && pattern[0] != '\\'){
		printf("partial_line[0] != pattern[0]\n");
		return 0;
	}
	if(pattern[1] == '+' && pattern[0] != '\\'){
		printf("pattern[1] = %c\n", pattern[1]);
		char partial[MAXSIZE]; char pat[MAXSIZE]; int j = 0; int matches = -1;
		if((pattern[0] == partial_line[0] || pattern[0] == '.') && partial_line[0] != 0){
			while(partial_line[j] != 0 && partial_line[j] != pattern[2] && partial_line[j] != pattern [3]){
				j++;
			}
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
			int k = 0;
			while(pattern[k+1] != 0){
				pat[k] = pattern[k+2];
				k++;
			}
			if(partial_line[j] == 0){
				return 1;
			}
			matches = matches_leading(partial, pat);
			if(matches == 0){
				printf("returning 0 from pattern[1] = +\n");
				return 0;
			}

		}
		if()
		printf("Did not go inside if loop\n");

	}
	if(pattern[0] == '.' && pattern[1] != '+' && pattern[1] != '?' && pattern[0] != '\\'){
		printf("pattern[0] = '.'\n");
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
			printf("Returning 0 from pattern[0] = . \n");
			return 0;
		}
	}
	if(pattern[1] == '?' && pattern[1] != '+' && pattern[1] != 0 && pattern[0] != '\\'){
		printf("pattern[1] = %c\n", pattern[1]);
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
			printf("pattern = %s pat2 = %s\n", pattern, pat2);
			matches2 = matches_leading(partial_line, pat2);
		}
		if(matches1 == 0 && matches2 == 0){
			printf("Returning 0 from pattern[1] = ? Matches1 & 2 returned 0\n");
			return 0;
		}
	}
	if(pattern[0] == '\\'){
		printf("pattern[0] = %c\n", pattern[0]);
		char partial[MAXSIZE]; char pat[MAXSIZE]; int j = 0; int matches = -1;
		if(partial_line[0] == pattern[1]){
			while(pattern[j+2] != 0){
				pat[j] = pattern[j+2];
				j++;
			}
			printf("next pat = %s\n", pat);
			j = 0;
			while(partial_line[j] != 0){
				partial[j] = partial_line[j+1];
				j++;
			}
			printf("next partial = %s\n", partial);
			matches = matches_leading(partial, pat);
			if(matches == 0){
				printf("Returning 0 from pattern[0] = '\\' \n");
				return 0;
			}
		}
		else{
			printf("Returning 0 from pattern[0] = '\\' else loop\n");
			return 0;
		}
	}
	printf("Returning 1 at end of function\n");
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
		//printf("line[%d] = %c pattern[%d] = %c\n", i, line[i], j, pattern[j]);
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
			//printf("partial1 = %s\n", partial);
			for(int p = 0; p < k+1; p++)
				partial[p] = 0;
			//printf("match = %d\n", match);
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
