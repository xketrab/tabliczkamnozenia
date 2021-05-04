#include <iostream>
#include <random>

int main()
{
    using namespace std;

    int max_questions;
    int min_range = 2; // Minimalny czynnik w mnożeniu jest ustawiony na 2, ponieważ mnozenie przez 1 jest bezsensowne.
    int max_range;

    std::cout << "Podaj ilosc pytan, jakie program ma Tobie zadac: ";
    std::cin >> max_questions;
    int r = max_questions * 2;

    std::cout << "Podaj do jakiej liczby maja zostac zadane pytania(np. do 10): ";
    std::cin >> max_range;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(min_range, max_range);

    int score = 0;
    int result = 0;

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

    if(percent == 100 ){
        string odpowiedz;
        int result;
        cout << "\n\nCzy chcesz dostac pytanie na szostke?(tak, nie)";
        cin >> odpowiedz;
        if(odpowiedz == "tak"){
            int one = distr(gen) + 5;
            int two = distr(gen) + 4;
            if((one*two)<216){
                one += 3;
                two += 3;
            }else{
                cout << "Zadanie Dodatkowe: " << one << " * " << two << " =";
                cin >> result;
                if(result == (two * one)){
                    cout << "\n\nBrawo! Przyklad wykonany prawidlowo! Otrzymujesz ocene 6!" << endl;

                }else{
                    cout << "Niestety nie udało Ci się odpowiedziec prawidlowo na pytanie :c Ale nadal otrzymujesz ocene 5 c:" << endl;
                }
            }
        }else if(odpowiedz == "nie"){
            cout << "Szkoda :c Dostajesz ocene 5";
        }else{
            cout << "Niepoprawny argument!";
        }
    }
}

/* TODO:
- limit czasu na odpowiedz,
- naprawienie funkcji dodatkowego pytanie(na ocene celujaca[6])
- zmiecic system losowosci(rand(), srand(TIME))
*/
