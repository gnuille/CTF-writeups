/*
 * Compute pi by approximating the area under the curve f(x) = 4 / (1 + x*x)
 * between 0 and 1.
 *
 * Parallel version using OpenMP
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <omp.h>	
#include <openssl/sha.h>
#define ALPHABET_SIZE 17

const static char alphabet[] = {'s','f','g','c','m','S','F','G','C','M','1','3','5','0','!','%','='};
const static char *hash = "\x0e\xc0\x9e\xf9\x83\x6d\xa0\x3f\x1a\xdd\x21\xe3\xef\x60\x76\x27\xe6\x87\xe7\x90";

//const static char alphabet[] = { 'd','b','a','t'};
//const static char *hash = "\xac\x97\x54\x94\x62\x03\xe3\xc3\x85\x8b\x60\x00\x68\x3a\xe5\x8f\x5e\x8d\xe2\xa0";
unsigned char xhash[SHA_DIGEST_LENGTH];
char done = 0;
void checkHash(char words[ALPHABET_SIZE+1]){
	unsigned char nhash[SHA_DIGEST_LENGTH];
	SHA1(words, strlen(words),nhash);
	
	if(!memcmp(hash, nhash, SHA_DIGEST_LENGTH)){
		printf("Found!\n%s\n",words);
		done = 1;
	}
}

void backtrack(char words[ALPHABET_SIZE+1], char used[ALPHABET_SIZE], int d){
	if(done) return;
	checkHash(words);
	int i;
	for(i = 0; i< ALPHABET_SIZE; i++){
		#pragma omp task
		if(!used[i]){
			char *w1 = alloca(ALPHABET_SIZE+1);
			memcpy(w1,words, ALPHABET_SIZE+1);
			char *u1 = alloca(ALPHABET_SIZE);
			memcpy(u1, used, ALPHABET_SIZE);
			w1[d] = alphabet[i];
			w1[d+1] = '\0';
			u1[i] = 1;
			backtrack(w1, u1, d+1);
		}
	}
	#pragma omp taskwait
		
}

int main(int argc, char *argv[]) {
	char *words=calloc(ALPHABET_SIZE+1,1);
	char *used=calloc(ALPHABET_SIZE, 1);
	#pragma omp parallel
	#pragma omp single		
	backtrack(words, used, 0);
}

