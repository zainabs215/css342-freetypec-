#include <iostream>
#include <string>
#include <cstdio>
// declaring functions
bool isPowerOf2(int num);
bool isPowerOf2NoLoop(int num);
bool checkPrime(int number);
void powerTest();
void primeTest();
void fractionTest();

int main() {
    //tests if num is a power of two
    printf("Testing powers of 2:\n");
    powerTest();

    //tests if the number is prime
    primeTest();

    //test simplifying fraction code
    fractionTest();
    return 0;
}
//loop version, repeatedly divides num by 2 & checks divisibility
bool isPowerOf2(int num){
    while (num != 1){
        if (num % 2 == 0){
            num = num/2;
            continue;
        } else{
            return false;
        }
    }
    return true;
}
// checks if num is a power of 2 without loops
bool isPowerOf2NoLoop(int num){
    if (num == 2 || num % 4 == 0){
        return true;
    } else {
        return false;
    }
}
// checks of the number is prime
bool checkPrime(int number){
    if (number < 2 || (number > 2 && number % 2 == 0)){
        return false;
    } else if (number == 2){
        return true;
    } else {
        for (int i = 2; i <= number - 1; i++){
            if (number % i == 0){
                return false;
            }
        }
        return true;
    }
}
//reduce given fraction to minimum terms
//void test();
// fraction class to create fraction objects that have a numerator & denominator
class Fraction {
public:
    int numerator;
    int denominator;

    Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {};
    std::string to_string(){
        return std::to_string(numerator) + "/" + std::to_string(denominator);
    }

    //operator overload
    bool operator==(Fraction &other){
        return this->numerator == other.numerator && this->denominator == other.denominator;
    }
};

Fraction reduce(Fraction input){
    int min;
    //figures out if numerator or denominator is greater
    if (input.numerator >= input.denominator){
        min = input.denominator;
    } else if (input.numerator < input.denominator){
        min = input.numerator;
    }
    //finds greatest common denominator
    int gcd = 1;
    for (int i = 1; i <= min; i++){
        if (input.numerator % i == 0 && input.denominator % i == 0){
            gcd = i;
        }
    }
    input.numerator /= gcd;
    input.denominator /= gcd;
    return input;
}
//testing if power of 2
void powerTest(){
    // 4 -> true
    // 9 -> false
    // 32 -> true
    // 27 -> false

    //arrays created for inputs and their expected outputs
    int inputs[4] = {4, 9, 32, 27};
    bool outputs[4] = {true, false, true, false};
    for (int i = 0; i < 4; i++){
        int input = inputs[i];
        bool expect = outputs[i];

        bool actual = isPowerOf2(input);
        //compare expected vs output
        if (expect==actual){
            std::cout << "PASS!" << std::endl;
        } else {
            std::cout << "FAIL!" << std::endl;
        }
        if (actual){
            printf("%d is a power of 2\n", input);
        } else {
            printf("%d is NOT a power of 2\n", input);
        }
    }
    printf("Checking non-loop function:\n");
    for (int i = 0; i < 4; i++){
        int input = inputs[i];
        bool expect = outputs[i];

        bool actual = isPowerOf2NoLoop(input);
        //compare expected vs output
        if (expect==actual){
            std::cout << "PASS!" << std::endl;
        } else {
            std::cout << "FAIL!" << std::endl;
        }
        if (actual){
            printf("%d is a power of 2\n", input);
        } else {
            printf("%d is NOT a power of 2\n", input);
        }
    }
}
void primeTest(){
    // 15 -> false
    // 3 -> true
    // 21 -> false
    // 7 -> true

    //arrays created for inputs and their expected outputs
    int inputs[4] = {15, 3, 21, 7};
    bool outputs[4] = {false, true, false, true};
    for (int i = 0; i < 4; i++) {
        int input = inputs[i];
        bool expect = outputs[i];

        bool actual = checkPrime(input);
        //compare expected vs output
        if (expect == actual) {
            std::cout << "PASS!" << std::endl;
        } else {
            std::cout << "FAIL!" << std::endl;
        }
    }
}
//testing method for simplifying fractions
void fractionTest(){
    //reduce given fraction to minimum terms
    // 2/4 -> 1/2
    // 4/2 -> 2/1
    // 6/8 -> 3/4
    // 30/45 -> 2/3
    // 6/6 -> 1

    //given an input, the output should match the expected output
    Fraction inputs[4] = {Fraction(1,2), Fraction(2, 4), Fraction(4, 2), Fraction(6, 8)};
    Fraction outputs[4] = {Fraction(1,2), Fraction(1, 2), Fraction(2, 1), Fraction(3, 4)};

    //compare the received output to the expected output
    for (int i = 0; i < 4; i++){
        Fraction input = inputs[i];
        Fraction expect = outputs[i];

        Fraction actual = reduce(input);
        //compare expected vs output
        if (expect==actual){
            std::cout << "PASS!" << std::endl;
        } else {
            std::cout << "FAIL! Case is: " << input.to_string() << std::endl;
        }
    }

}
// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.