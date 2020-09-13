#include<iostream>
#include <ctime>
using namespace std;

int checkLotteryArray(int lottery[], int arraySize){
    int i, j;
    int repeatingNumbersLottery;
    for(i = 0; i < arraySize; i++)
        for(j = i + 1; j < arraySize; j++)
        if(lottery[i] == lottery[j]){
            repeatingNumbersLottery = lottery[i];
        }
    return repeatingNumbersLottery;
}

int checkPlayerArray(int player[], int arraySize){
    int i, j;
    int repeatingNumbers;

    for(i = 0; i < arraySize; i++)
        for(j = i + 1; j < arraySize; j++)
        if(player[i] == player[j]){
            repeatingNumbers = player[i];
        }
    return repeatingNumbers;
}

int main(){
    int arraySize = 5; // Sets the size of the arrays used in this program, since they are to be compared
    int maxRange = 9; // 0-8 is equal to 9 digits. We will add +1 to our maxRange below, to shift our range from 1-9, since we don't want to use 0.
    int lottery[arraySize]; // Initializes the lottery array
    int player[arraySize]; // Initializes the players array
    int  r;
    srand(time(0));

    for (int i=0; i < arraySize; i++){ // Sets lottery array to random numbers, based on arraySize value
        r = rand();
        lottery[i] = (r % maxRange) + 1; // maxRange +1 means we are working with 1-9, instead of 0-8
    }

    int passFailLottery = checkLotteryArray(lottery, arraySize);

    while (passFailLottery > 0){
        for (int i=0; i < arraySize; i++){ // Sets lottery array to random numbers, based on arraySize value
            r = rand();
            lottery[i] = (r % maxRange) + 1; // maxRange +1 means we are working with 1-9, instead of 0-8
        }

        int passFailLottery = checkLotteryArray(lottery, arraySize);
        cout<<"Generating new lottery numbers since "<<passFailLottery<<" is a duplicate.";
        cout<<endl;

        if (passFailLottery == 0){
            break; // There are no duplicates
        }
    }

    // Start of player interaction

    cout<<endl;
    cout<<"Please enter "<<arraySize<<" unique numbers from 1-9: "; // Simple message to the player
    cout<<endl;

    for (int i=0; i < arraySize; i++) // Prompts the user to enter numbers via a loop and store them into player array
    cin>>player[i];
    int count=0;
    for (int i=0; i < arraySize; i++)
    if (player[i]==lottery[i])
    count++;

    int passFail = checkPlayerArray(player, arraySize);

    while (passFail > 0){

        count=0; // Reset count, so that the count uses latest values

        cout<<"Please enter "<<arraySize<<" unique numbers from 1-9: "; // Simple message to the player
        cout<<endl;

        for (int i=0; i < arraySize; i++) // Prompts the user to enter numbers via a loop and store them into player array
        cin>>player[i];
        int count=0;
        for (int i=0; i < arraySize; i++)
        if (player[i]==lottery[i])
        count++;

        int passFail = checkPlayerArray(player, arraySize);

        if (passFail == 0){
            break;
        }
    }

    cout<<"Lottery Numbers: ";
    for (int i=0; i < arraySize; i++)
    cout<<lottery[i]<<" "; // Shows next number in for-loop with a space after it, until all numbers are shown
    cout<<endl;

    cout<<"Player's Numbers: ";
    for (int i=0; i < arraySize; i++)
    cout<<player[i]<<" "; // Shows next number in for-loop with a space after it, until all numbers are shown
    cout<<endl;

    if (count==arraySize){
        cout<<"Congratulations! You win!";
    }
    else{
        cout<<"There are "<<count<<" matching numbers. Thank you for playing." ;
        cout<<endl;
        cout<<endl;
    }
    return 0;
}
