#include <iostream>

#define MAX_SIZE (100)

//task 3
void removeX(char * source, char * destination) {
	if(!*source) {
		return;
	}
	
	if(*source == 'X') {
		removeX(source+1, destination);
	} else {
		*destination = *source;
		removeX(source+1, destination+1);
	}
}

void cleanSingleLetter(char* text) {
	if(!*text) {
		return;
	}
	*text = *(text+1);
	cleanSingleLetter(text+1);
}

//task 4
void cleanText(char * text) {
	if(!*text) {
		return;
	}

	if(*text == *(text+1)) {
		cleanSingleLetter(text);
		cleanText(text);
	} else {	
		cleanText(text+1);
	}	

}


int main () {
	
	char src[MAX_SIZE];
	char dest[MAX_SIZE] = {'\0', };
	
	std::cin >> src;

	removeX(src, dest);

	std::cout << dest << std::endl;

	cleanText(src);
	std::cout << src << std::endl;

	return 0;
}