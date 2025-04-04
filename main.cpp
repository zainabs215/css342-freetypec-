int main() {
    //tests if num is a power of two
    int num = 6;
    //int num = 8;
    is_power_of_2(num);
    bool result = is_power_of_2(num);
    if (result){
        printf("%d is divisible by 2", num);
    } else {
        printf("%d is NOT divisible by 2", num);
    }
    //tests if the number is prime
    int number = 15;
    //int number = 3;
    bool primeOrNo = checkPrime(number);
    if (primeOrNo){
        printf("PASS");
    } else {
        printf("FAIL");
    }
    //tests
    Fraction num1(2, 4);
    std::cout << num1.numerator << "/" << num1.denominator << std::endl;
    test();
    return 0;
}
//loop version, repeatedly divides num by 2 & checks divisibility
bool is_power_of_2(int num){
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
void test();
// fraction class to create fraction objects that have a numerator & denominator
class Fraction {
public:
    int numerator;
    int denominator;

    Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {};
    std::string to_string(){
        return std::to_string(numerator) + "/" + std::to_string(denominator)
    }

    //operator overload
    bool operator==(Fraction &other){
        return this->numerator == other.numerator && this->denominator == other.denominator;
    }
};

//Fraction reduce(Fraction input){
//return input; //TODO: replace with my code, change it
//}

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
void test(){
    //reduce given fraction to minimum terms
    // 2/4 -> 1/2
    // 4/2 -> 2/1
    // 6/8 -> 3/4
    // 30/45 -> 2/3
    // 6/6 -> 1

    //given an input, the output should match the expected output
    Fraction inputs[4] = {Fraction(1,2), Fraction(2, 4), Fraction(4, 2), Fraction(6, 8)};
    Fraction outputs[4] = {Fraction(1,2), Fraction(1, 2), Fraction(2, 1), Fraction(3, 4)};

    //call the function
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