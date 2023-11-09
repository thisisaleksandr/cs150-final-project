#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

char words[22][20] = {"ant", "bear", "cat", "dog", "elephant", "frog", "goose", "horse", "iguana", "jaguar", "kangaroo"
                     "lion", "mouse", "ox", "pig", "rabbit", "sheep", "tiger", "urchin", "bat", "wolf", "zebra"};
char hidenword[20], usedLetters[20];
int tries = 5, extraHelp = 1, usedLetterCount=0;

int randomNumber(){

        srand(time(NULL));
        int randomNum;
        randomNum = rand()%22;  //Change to exact number of words

        return randomNum;
}

void printWordWindow(int lenofword){

        for(int i = 0; i < lenofword; i++){
                printf("| %c ", hidenword[i]);
        }
        printf("|\n\n");
        printf("YOU HAVE %d TRIES\n\n", tries);

}

int checkUsedLetters(char letter){

        for(int j=0; j<usedLetterCount; j++){
                if(letter==usedLetters[j]){
                        return 1;
                }
        }
        usedLetters[usedLetterCount] = letter;
        usedLetterCount++;
        return 0;
}


int main(){

        int lenword, countGuess, flag=0, flagLetter=0;
        char word[20], letter;

        strcpy(word, words[randomNumber()]);
        lenword = strlen(word);

        printf("%s\n", word); //DELETE AFTER IT JUST SHOWS A WORD

        for(int i = 0; i < lenword; i++){  //WE HAVE WORD HERE AND _
                hidenword[i] = '_';
        }

        printWordWindow(lenword);

        while(tries>0 && countGuess < lenword){
                printf("Enter a letter: ");
                scanf(" %c", &letter);
                printf("\n");

                if(checkUsedLetters(letter) == 1){
                        printf("You have already typed this letter\nTry again\n");
                        continue;
                }

                flag = 0;

                for(int k=0; k<lenword; k++){
                        if(letter==word[k]){
                                hidenword[k] = letter;
                                countGuess++;
                                flag=1;
                        }
                }
                if(flag==0){
                        tries--;
                        printf("You did not guess the letter\n\n");
                }else{
                        printf("You guessed right\n\n");
                }
                if(tries==0){
                        printf("YOU LOSE!\n\n");
                }
                if(countGuess == lenword){
                        printf("Congrats! You won!\n");
                }
                printWordWindow(lenword);

        }
        return 0;
}