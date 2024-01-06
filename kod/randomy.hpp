#ifndef P1_CPP_LAB_RANDOMNAMEGENERATOR_HPP
#define P1_CPP_LAB_RANDOMNAMEGENERATOR_HPP

#include <array>
#include <random>
#include <string>
#include <sstream>

using namespace std;

struct RandomIntGenerator{
    static std::mt19937 prng;
};

mt19937 RandomIntGenerator::prng = mt19937{random_device{}()};

constexpr array first_names{
    "Ann",
    "Andrew",
    "John",
    "Jane",
    "Bob",
    "Alice",
    "Bertram",
    "Monica",
    "Laura",
    "Eric",
    "Richard",
    "Karen",
    "Clara",
    "Rupert",
    "Bruce",
    "Martha",
    "Elizabeth",
    "Corey",
    "Nancy",
    "Joe",
    "Amy",
    "Mike",
    "Michal", 
    "Marcin", 
    "Asia",
    "Weronika",
    "Piotr",
    "Wiktoria",
    "Jacob",
    "Ula",
    "Phil",
    "Jarek",
    "Pam",
    "Ola"
};


string get_random_name(){
    uniform_int_distribution<size_t> fnd{0, first_names.size() - 1};
    stringstream name;
    name << first_names[fnd(RandomIntGenerator::prng)];
    return name.str();
}

bool get_random_widlowy(){
    srand(time(0));
    int g = rand();
    return(g%2);
}

constexpr array faculties{
    "MEIL",
    "MINI",
    "EITI",
    "FIZYKI",
    "ZARZADZANIA",
    "SIMR",
    "MECHATRONICZNY",
    "ELEKTRO",
    "GIK"
};


string get_random_faculty(){
    uniform_int_distribution<size_t> fnd{0, faculties.size() - 1};
    stringstream name;
    name << faculties[fnd(RandomIntGenerator::prng)];
    return name.str();
}

double get_random_size(){
    srand(time(0));
    
    double lower_bound = 20;
    double upper_bound = 50;
 
    uniform_real_distribution<double> unif(lower_bound, upper_bound);
 
    default_random_engine re;

    return(unif(re));
}

int get_random_follows(){
    srand(time(0));

    return(rand()%10000);
}

#endif
