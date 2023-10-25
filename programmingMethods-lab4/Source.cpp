#include <iostream>
#include <string>
#include <vector>

#define ulli unsigned long long int

using namespace std;

/*
Вариант 16
*/


string incorrectInputMsg = "Некорректный ввод!";


inline void printMsgIncorrectInput() {
    cout << incorrectInputMsg << endl;
}


template <typename T>
void printVectorInRows(vector<T> v){
    for (T el: v){
        cout << el << endl;
    }
}


bool isPrimeNumber(int number){

    if (number==1){
        return false;
    }

    for (int i = 2; i < number; i++){
        if (number % i){
            continue;
        }
        else return false;
    }

    return true;
}


vector<int> findPrimeMultipliers(unsigned long long int number){
    vector<int> multipliers = {1};

    while (!(number % 2)){
        multipliers.push_back(2);
        number /= 2;
    }

    for (int i = 3; i <= number/2; i += 2){
        if (!isPrimeNumber(i)){
            continue;
        }
         
        while (!(number % i)){
            multipliers.push_back(i);
            number /= i;
        }
    }
    if(isPrimeNumber(number) && (number != 1)){
        multipliers.push_back(number);
    }
    return multipliers;
}


void task1() {
    unsigned long int number = 0;

    cout << "Введите число: " << endl;
    cin >> number;

    int maxdigit = 0;
    
    while (number>0){
        char digit = number % 10;
        maxdigit = digit > maxdigit ? digit : maxdigit;
        number /= 10;
    }

    cout << "Наибольшая цифра: " << maxdigit << endl;
}


void task2() {
    ulli number = 1;

    cout << "Введите натуральное число: " << endl;
    cin >> number;

    vector<int> multipliers = findPrimeMultipliers(number);

    cout << "Множители числа: " << endl;

    printVectorInRows(multipliers);
}


void task3() {
    ulli number = 0;

    cout << "Введите n: " << endl;
    cin >> number;

    vector<ulli> perfectNumbers;
    for (ulli i = 1; i <= number; i++){
        ulli divisorsSum = 0;

        for (ulli j = 1; j <= i/2; j++){
            divisorsSum += i%j ? 0:j;
        }

        if (divisorsSum == i){
            perfectNumbers.push_back(i);
        }
    }

    cout << "Совершенные числа: " << endl;
    printVectorInRows(perfectNumbers);
}


unsigned long int factorial(int number){
    unsigned long int f = 1;
    for (int i = 1; i <= number; i++){
        f *= i;
    }

    return f;
}


void task4() {
    /*
    Вариант 16
    */


    double p = 1;
    const int startNumber = -3;
    int k = 0;
 
    cout << "\t k\n"
         << "\t____  (n+2)|n-4|\n"
         <<"Z =\t|  |  ----------\n"   
         << "   \t|  |    (n+3)!\n"
         << "\tn=-3\n"
     << endl;

    cout << "Введите k: " << endl;
    cin >> k;

    if (k<startNumber){
        cout << "k не может быть меньше " << startNumber << ",устанавливаем " << startNumber << endl;
        k = startNumber;
    }

    for (int i = -3; i <= k; i++){
        p *= static_cast<double>((i+2)*abs(i-4))/factorial(i+3);
        if (!p){
            break;
        }
    }
    
    cout << "Произведение ряда: " << p + 0.0 << endl;
}


int main() {
    setlocale(LC_ALL, "Russian");

    int taskNumber;

    void (*tasks[])() = { task1, task2, task3, task4 };

    while (true) {
        //        system("cls");


        cout << "Введите номер задания (1-4)" << endl;
        cout << "1 - наибольшая цифра числа\n2 - простые множители\n3 - совершенные числа\n4 - посчитать ряд из файла\n0 - exit" << endl;
        cin >> taskNumber;

        if (taskNumber == 0) {
            exit(0);
        }
        else if (taskNumber > 0 && taskNumber < 5) {
            tasks[taskNumber - 1]();
        }
        else {
            printMsgIncorrectInput();
        }
        //        system("pause");
    }

    return 0;
}
