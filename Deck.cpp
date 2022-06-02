#include <iostream>
#include <ctime>
#include "Deck.h"
#include "Card.h"
using namespace std;




Deck::Deck(){ // Constructor
    char rank[13] = {'A','2','3','4','5','6','7','8','9','X','J','Q','K'};
    char suit[4] = {'S','H','D','C'};
    int index = 0;
        for(int k = 0; k < 4;++k){
            for(int j= 0;j < 13;++j){
                
                dDeck[index] = Card(rank[j],suit[k]);
                index++;

            }
    }
}
void Deck::refreshDeck(){
    char rank[13] = {'A','2','3','4','5','6','7','8','9','X','J','Q','K'};
    char suit[4] = {'S','H','D','C'};
    int index = 0;
        for(int k = 0; k < 4;++k){
            for(int j= 0;j < 13;++j){
                
                dDeck[index] = Card(rank[j],suit[k]);
                index++;

            }
    }
}
Card Deck::deal( ){


    Card value = dDeck[0];
    
    int size = sizeof(dDeck)/sizeof(dDeck[0]);
    for (int i = 0; i <= size; ++i){
        dDeck[i] = dDeck[i+1];
    }
    dDeck[size-1] = nullCard;
    
    
    return value;
    

}

void Deck::shuffle(){
    srand(time(0));
    Card temp;
    
    for (int i = 0;i<52;++i){
        int random = rand() % 50 + 1;
        
        temp = dDeck[i];
        dDeck[i] = dDeck[random];
        dDeck[random] = temp;
        
    }

}
bool Deck::isEmpty( ){
    
    if(dDeck[0].getValue()==0){
        return true;
    }
    return false;
    
}


void Deck::display( ){
    
    for (int i=0; i<52;++i){
        if (dDeck[i].getValue() != 0){
            
            dDeck[i].display(); 
            std::cout << ", ";
            
            
            if (i == 12 || i == 25 || i== 38){
                std::cout << "\n";
            }          
        }
        
    }   
    std::cout << "\n \n";
}












