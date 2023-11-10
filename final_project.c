#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

char words[22][20] = {"ant", "bear", "cat", "dog", "elephant", "frog", "goose", "horse", "iguana", "jaguar", "kangaroo",
                     "lion", "mouse", "ox", "pig", "rabbit", "sheep", "tiger", "urchin", "bat", "wolf", "zebra"};

char hidenword[20], usedLetters[20];
int tries = 5, usedLetterCount=0;

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

void result(int f, int tries, int cg, int len){
                if(f==0){
                        printf("You did not guess the letter\n\n");
                }else{
                        printf("You guessed right\n\n");
                }
                if(tries==0){
                        printf("YOU LOSE!\n\n");
                }
                if(cg == len){
                        printf("Congrats! You won!\n");
                }        
}

int main(){
        while(1){

        int lenword, countGuess=0, flag=0, flagLetter=0;
        char word[20], letter, playAgain;

        strcpy(word, words[randomNumber()]);
        lenword = strlen(word);

        printf("%s\n", word); //DELETE AFTER. IT JUST SHOWS A WORD

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
                }

                result(flag, tries, countGuess, lenword);


                if(tries==0){
                printf("The guessed word was '%s'\n\n", word);
                }
                else{
                        printWordWindow(lenword);
                }
                
        }
        
        printf("Do you want to play again? ('y' - yes / 'n' - no) ");
        scanf(" %c", &playAgain);

        if(playAgain=='n'){
                break;
        }else if(playAgain=='y'){
                printf("%s %s", hidenword, usedLetters);
                char hidenword[20], usedLetters[20]; //initialized again because need to clear char arrays for the new game
                tries = 5;                 //same reason
                usedLetterCount = 0;       //same reason
        }

        }
        return 0;
}