#include <iostream>
#include "Card.h"
#include "Deck.h"
using namespace std;


Card::Card(){
    this->rank = 'A';
    this->suit = 'S';

}

Card::Card(char r, char s) {
    this->rank = r;
    this->suit = s;
}
void Card::setCard( char r, char s){

}
int Card::getValue( ){
    switch(this->rank){
        
        case ('A'):
            return 1;
            break;
        case ('2'):
            return 2;
            break;
        case ('3'):
            return 3;
            break;
        case ('4'):
            return 4;
            break;
        case ('5'):
            return 5;
            break;
        case ('6'):
            return 6;
            break;
        case ('7'):
            return 7;
            break;
        case ('8'):
            return 8;
            break;
        case ('9'):
            return 9;
            break;
        case ('X'):
            return 10;
            break;
        case ('J'):
            return 10;
            break;
        case ('Q'):
            return 10;
            break;
        case ('K'):
            return 10;
            break;
        default:
            return 0;
            break;
    }
} 
void Card::display( ){
    
    cout <<  this->rank << this->suit;


}


















