#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

/*
goals:
make an ace change between 1 and 11 by determining which is better
make the dealer
make it easier to use
kill myself (maybe)
*/

/*
plan:
put all values 'numbers' gives in an array
make a function that checks all the values
    put values in individually and the main program uses a for loop to keep inputting values
if one of the values is 1, check whether 1 or 11 is better
*/

std::pair<std::string, int> card_generator(){
    int number = int(rand()%13);
    int suit = int(rand()%4);
    std::string number2;
    if(number == 0){
        number2 = "ACE";
        number = 11;
    }else if(number == 10){
        number2 = "JACK" ;
        number = 10;
    }else if(number == 11){
        number2 = "QUEEN";
        number = 10;
    }else if(number == 12){
        number2 = "KING";
        number = 10;
    }else{
        number2 = std::to_string(number + 1);
        number = number + 1;
    }
    std::string suit2;
    if(suit == 0){
        suit2 = "hearts";
    }
    if(suit == 1){
        suit2 = "diamonds";
    }
    if(suit == 2){
        suit2 = "spades";
    }
    if(suit == 3){
        suit2 = "clubs";
    }
    std::string card = number2 + " of " + suit2;
    return std::make_pair(card, number);
}

int ace_counter(int n){
    bool ace;
    if(n == 11){
        ace = true;
    }else{
        ace = false;
    }
    return ace;
}

int main(){
    srand(time(0));
    int i = 2;
    int j;
    bool aces;
    auto placeholder = card_generator();
    std::string hand = placeholder.first;
    int numlist[100];
    numlist[0] = placeholder.second;
    int total = placeholder.second;
    placeholder = card_generator();
    hand = hand + ", " + placeholder.first;
    total = total + placeholder.second;
    numlist[1] = placeholder.second;
    std::cout <<"your hand: " << hand << "\n";

    if(total == 21){
        std::cout <<"blackjack! you win";
        return 0;
    }
    std::string hitorstand;
    bool pluh = true;
    while(hitorstand != "s"){
        while(pluh == true){
            std::cout << "hit or stand (h or s):";
            std::cin >> hitorstand;
            if((hitorstand == "s") or (hitorstand == "h")){
                pluh = false;
            }
        }
        if(hitorstand == "s"){
            pluh = false;
        }else if((hitorstand == "h") && (total <21)){
            placeholder = card_generator();
            hand = hand + ", " + placeholder.first;
            total = total + placeholder.second;
            numlist[i] = placeholder.second;
            std::cout << "your hand: " << hand << "\n";
            i = i + 1;
            pluh = true;
        }
        if(total >= 21){
            if(total == 21){
                std::cout << "blackjack! you win";
                return 0;
            }else{
                int len = sizeof(numlist);
                for(j = 0; j < len; j++){
                    aces = ace_counter(numlist[j]);
                    if(aces == true){
                        break;
                    }
                }
                if(aces == true){
                    numlist[j] = 1;
                    total = total - 10;
                    pluh = true;
                }else{
                    pluh = false;
                    hitorstand = "s";
                }
                }
            }
        }

    if(total > 21){
        std::cout << "bust! you lose" << "\n";
    }
    return 0;
}
