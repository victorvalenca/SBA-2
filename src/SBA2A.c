#include <string.h>
#include <stdio.h>

/*
 * Name: Victor Fernandes
 * Student #: 404772243
 */

void getString(char*, char*);
int compareStr(char*, char*);
void displayDiff(int);

int main(void){

	char loadStr[5000] = {'\0'}, str1[80]={'\0'}, str2[80] = {'\0'};

	//Pointer assignments
	char* pLoad = loadStr;
	char* ps1 = str1;
	char* ps2 = str2;
	int ctr;
	printf("Enter two strings of less than 80 characters each: \n");

	getString(pLoad, ps1);	// Get first string
	getString(pLoad, ps2);	// Get second string

	ctr = compareStr(ps1, ps2);	// String comparison and store the point where strings differ

	displayDiff(ctr);


}



void getString(char *loadString, char *S){

	do {
		fgets(loadString, 5000, stdin);
		if (strlen(loadString) > 80){
			// Re-prompt if too many characters given
			printf("Too many characters! Try again: \n");
		}
		else {
			// Copy loaded string into string 1 (or 2)
			strcpy(S, loadString);
		}
	}
	while (strlen(loadString) > 80);

}

int compareStr(char *s1, char *s2){

	int count = 0;

	// Iterate through until characters differ
	// (Was having some weird issue with checking for null character hence this little hack)
	while ( (*(s1++) == *(s2++))) {
		count++;
	}
	if (count > 80 ){
		return -1;
	}
	else {
		return count;
	}

}



void displayDiff(int diff){

	if (diff == -1){
		printf("The strings are equal\n\n");
		return;
}
	for (int i = 0; i < diff; i++){
		printf("-");
	}
	printf(">\n\n");
}

