#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

std::string converter(int suit){
    if(suit == 0){
        return "hearts";
    }
    if(suit == 1){
        return "diamonds";
    }
    if(suit == 2){
        return "spades";
    }
    if(suit == 3){
        return "clubs";
    }
    return "";
}

int main(){
    srand(time(0));
    std::cout << "BLACKJACK" << "\n";
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
    std::string suit2 = converter(suit);

    std::string hand = number2 + " of " + suit2;
    std::cout << hand;
    return 0;
}