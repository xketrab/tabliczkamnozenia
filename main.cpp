#include <iostream>
#include <math.h>
#include <random>
#include <stdlib.h>
#include <random>
//Tabliczka mnożenia
//liczbę pytań i zakres tabliczki mnożenia ustala użytkownik, np. 5 pytań i tabliczka do 10
////program losuje zmienne z podanego zakresu i zadaje pytanie np. ile to jest 7*9
//użytkownik odpowiada i otrzymuje komunikat zwrotny w każdym przypadku
//program zlicza poprawne odpowiedzi i oblicza wynik procentowy
//na podstawie wyniku procentowego program wystawia ocenę zgodnie z PZO

int main()
{
    using namespace std;

    int max_questions;
    int min_range = 1;
    int max_range;

    std::cout << "Podaj ilosc pytan, jakie program ma Tobie zadac: ";
    std::cin >> max_questions;
    int r = max_questions * 2;

    std::cout << "Podaj do jakiej liczby maja zostac zadane pytania(np. do 10): ";
    std::cin >> max_range;

    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(min_range, max_range); // define the range

    int score = 0;
    int result = 0;
    //int one = distr(gen);
    //int two = distr(gen);

    for(int n=0; n<max_questions; ++n){

        int one = distr(gen);
        int two = distr(gen);

        std::cout << "#" << n+1 << "  " << one << " * " << two << " = " << std::endl;
        std::cin >> result;

        if(result == one*two){
            ++score;
            std::cout << "Brawo! Poprawnie wykonany przyklad!\n" << std::endl;
        }else{
            std::cout << "Niestety! Przyklad zostal zrobiony zle!\n" << std::endl;
        }
    }

    std::cout << "Twoj wynik to: " << score << "/" << max_questions << "\n" << std::endl;
    float percent = ((float) score/(float) max_questions)*100;
    std::cout << "Wynik procentowy: " << percent << "%" << std::endl;

    if(percent >= 91){
        std::cout << "Brawo! Otrzymujesz ocene 5"<< std::endl;
    }

    if(91>percent && percent>=75){
        std::cout << "Otrzymujesz ocene 4"<< std::endl;
    }

    if(75>percent && percent>=51){
        std::cout << "Otrzymujesz ocene 3"<< std::endl;
    }

    if(51>percent && percent>=31){
        std::cout << "Otrzymujesz ocene 2"<< std::endl;
    }

    if(31>percent){
        std::cout << "Otrzymujesz ocene 1"<< std::endl;
    }
}