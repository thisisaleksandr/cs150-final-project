#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

char words[25][20] = {"ant", "bear", "cat", "dog", "elephant", "frog", "goose", "horse", "iguana", "jaguar", "kangaroo",
                     "lion", "mouse", "ox", "pig", "rabbit", "sheep", "tiger", "urchin", "bat", "wolf", "zebra", "orangutan",
                     "opossum", "giraffe"};
char words2[25][20] = {"apple", "orange", "pineapple", "mango", "cherry", "avocado", "banana", "kiwi", "grape", "tangerine",
                        "grapefruit", "blueberrie", "strawberry", "raspberry", "lemon", "lime", "watermelon", "mandarin", 
                        "peach", "pear", "apricot", "papaya", "blackcurrant", "coconut", "cranberry"};
char words3[25][20] = {"japan", "zimbabwe", "yemen", "russia", "egypt", "luxembourg", "germany", "hungary", "rwanda",
                        "portugal", "estonia", "kyrgyzstan", "tanzania", "botswana", "singapore", "angola", "mexico",
                        "uganda", "greece", "australia", "israel", "switzerland", "paraguay", "philippines", "malaysia"};

char hidenword[20], usedLetters[20];
int tries = 5, usedLetterCount=0;

int randomNumber(){

        srand(time(NULL));
        int randomNum;
        randomNum = rand()%25;

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

        printf("\nWelcome to the Guess the Word game!\nYou'll be provided with a secret word, and your task is to guess it.\n");
        printf("Type a letter and hit enter to make a guess.\nIf your guess is correct, the corresponding letter(s) will be revealed in the word.\n");
        printf("If your guess is incorrect, you have 5 attempts to guess the word correctly.\nAll words are single words.\n");
        printf("The game ends when you correctly guess the word or run out of attempts.\nGood luck, and have fun guessing!\n\n");
        
        while(1){

        int lenword, countGuess=0, flag=0, flagLetter=0;
        char word[20], letter, playAgain, category='x';

        while(category!='a' && category !='f' && category != 'c'){
                printf("Choose category\nType 'a' for animals, 'f' for fruits, 'c' for countries: ");
                scanf(" %c", &category);
                if(category!='a' && category !='f' && category != 'c') printf("Try Again\n");
        }

        if(category=='a'){
                strcpy(word, words[randomNumber()]);
        }else if(category=='f'){
                strcpy(word, words2[randomNumber()]);
        }else{
                strcpy(word, words3[randomNumber()]);
        }

        lenword = strlen(word);

        for(int i = 0; i < lenword; i++){ 
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
                        if(countGuess != lenword){
                                printWordWindow(lenword);
                        }else{
                                printf("The guessed word was '%s'\n\n", word);
                        }
                }
                
        }
        
        printf("Do you want to play again? ('y' - yes / 'n' - no) ");
        scanf(" %c", &playAgain);

        if(playAgain=='n' || playAgain=='N'){
                printf("Thank you for playing the Guess the Word game!\nGoodbye!\n");
                break;
        }else if(playAgain=='y' || playAgain=='Y'){
                char hidenword[20], usedLetters[20]; // clearing char arrays for the new game
                tries = 5;                 //same reason
                usedLetterCount = 0;       //same reason
        }

        }
        return 0;
}