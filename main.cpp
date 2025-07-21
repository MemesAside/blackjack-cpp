#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

std::string card_generator(){
    int number = int(rand()%13);
    int suit = int(rand()%4);
    std::string number2;
    if(number == 0){
        number2 = "ACE";
    }else if(number == 10){
        number2 = "JACK" ;
    }else if(number == 11){
        number2 = "QUEEN";
    }else if(number == 12){
        number2 = "KING";
    }else{
        number2 = std::to_string(number + 1);
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
    return card;
}

int main(){
    srand(time(0));
    std::string placeholder = card_generator();
    std::string hand = card_generator();
    hand = hand + ", " + placeholder;
    std::cout << hand << "\n";
    char hitorstand;
    bool pluh = true;
    while(hitorstand != 's'){
        while(pluh == true){
            std::cin >> hitorstand;
            if((hitorstand == 's') or (hitorstand == 'h')){
                pluh = false;
            }
        }
        if(hitorstand == 'h'){
            placeholder = card_generator();
            hand = hand + ", " + placeholder;
            std::cout << hand <<"\n";
            pluh = true;
        }
    }


    return 0;
}
