#include <iostream>
#include "Deck.h"
#include "Card.h"

using namespace std;

bool isFibonacci(int num){
    int fib[19] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181};
    for ( int i = 0 ; i < 19;i++){
        if (num == fib[i]){
            return true;
        }
    }
    return false;

}


int menu(){
    int menuChoice;
    
    
    do{
        cout << "\nWelcome to Fibonacci Solitaire! \n"
            "1) New Deck \n"
            "2) Display Deck \n"
            "3) Shuffle Deck: \n"
            "4) Play Solitaire \n"
            "5) Exit \n";

        cin >> menuChoice;
        if (menuChoice == 5){
            return 0;
        }
        else if (cin.fail()) {    
                cout << "Not a valid option!!!" << endl;
                std::cin.clear();
                std::cin.ignore(256,'\n');
        }
        else if (menuChoice < 1 || menuChoice > 5){cout << "Not a valid option!!! \n";}
        
        
        

    }while(!cin || menuChoice < 1 || menuChoice > 5);
    return menuChoice;
}



int main (){
    int choice=-1,lossCounter=0,winCounter=0,gamesPlayed=0;
    Deck obj1;
    


    
    while (choice != 0){
        choice = menu();
        if (choice == 0){
            return 0;
        }
        else if (choice == 1){
            obj1.refreshDeck();

        }
        else if (choice == 2){
            obj1.display();
        }
        else if (choice == 3){
            obj1.shuffle();
            cout << "\nDeck has been shuffled!\n";
        }
        else if (choice == 4){ // Play Solitaire
            int piles = 1;
            cout << " \n";
            while(!obj1.isEmpty()) {
                
                Card currentCard;
                int currentValue;
                int sum = 0;
                while (!isFibonacci(sum)){
                    
                    currentCard = obj1.deal();
                    currentValue = currentCard.getValue();
                    currentCard.display();
                    cout << ", ";
                    //cout <<currentValue<< " ";
                    sum += currentValue;
                    //cout <<sum<< " ";
                    if(obj1.isEmpty()){
                        if(isFibonacci(sum)){
                            piles++;
                            cout << "Pile " << piles << " Fibo: " << sum << endl;
                            cout << "\nWinner in " << piles << " piles!!!";
                            winCounter++;
                            gamesPlayed++;
                            cout << "\nGames Played: " << gamesPlayed;
                            
                        }
                        else if(!isFibonacci(sum)){
                            cout << " Last hand value: " << sum;
                            cout << "\nLoser in " << piles- 1 << " piles!!! ";
                            lossCounter++;
                            gamesPlayed++;
                            cout << "\nGames Played: " << gamesPlayed << "\n";
                        }
                        //cout << sum;
                        sum =1;
                    }
                    
                    else if (isFibonacci(sum)){
                        cout << "Pile " << piles << " Fibo: " << sum << endl;
                        sum = 0;
                        piles++;
                        
                    }
                }
                choice=-1;    
            }
        }
        
    }
}