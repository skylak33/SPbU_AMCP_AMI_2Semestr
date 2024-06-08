#include <bits/stdc++.h>
using namespace std;

class Number {
    private:
        int* number;
//      Обьявление 10 свойств
        int number1, number2, number3, number4, number5, number6, number7, number8,number9, number10;
//      2+2 private метода
        void privateMethod1();
        void privateMethod2();
        void privateMethod3() {
            *number++;
        }
        void privateMethod4() {
            *number--;
        }
    protected:
        int rofl = 1;
    public:
//        Констуркторы + Деструкторы
        Number(int num) {
            number = new int(num);
        }
        Number(int num1, int num2) {
            number = new int(num1 * num2);
        }
        Number(int num, int degree, int sign) {
            number = new int(int(pow(num, degree)) * sign);
        }
        Number(const Number& other) {
            number = new int(*(other.number));
        }
        ~Number() {
            delete number;
        }
//       5 public методов для работы с объектом класса
        void setNumber(int num) {
            *number = num;
        }
        int getNumber() {
            return *number;
        }
        void add(int num) {
            *number += num;
        }
        void subtract(int num) {
            *number -= num;
        }
        void print() {
            cout << "Number: " << *number << endl;
        }
//      Перегрузка операторов
        Number operator+(const Number& other) {
            return Number(*(this->number) + *(other.number));
        }
        Number operator-(const Number& other) {
            return Number(*(this->number) - *(other.number));
        }
        bool operator==(const Number& other) {
            return (*(this->number) == *(other.number));
        }
//      Перегрузка операторов с дружественной функцией
        friend Number operator*(const Number& n, int multiplier);
        friend Number operator*(int multiplier, const Number& n);
//      Перегрузку вывода << с дружественной функцией
        friend ostream& operator<<(ostream& os, const Number& n);
//      Запись данных объекта в формат xml
        string toXML() const {
            ostringstream os;
            os << "<Number>\n"
               << "  <value>" << *number << "</value>\n"
               << "</Number>";
            return os.str();
        }
//      Автоматическое преобразование типов
        operator int() const {
            return *number;
        }
        operator double() const {
            return static_cast<double>(*number);
        }
        operator string() const {
            return to_string(*number);
        }
//       Обьявление + Реализация 20 методов
        int getnumber1() { return number1; }
        void setnumber1(int value) { number1 = value; }

        int getnumber2() { return number2; }
        void setnumber2(int value) { number2 = value; }

        int getnumber3() { return number3; }
        void setnumber3(int value) { number3 = value; }

        int getnumber4() { return number4; }
        void setnumber4(int value) { number4 = value; }

        int getnumber5() { return number5; }
        void setnumber5(int value) { number5 = value; }

        int getnumber6();
        void setnumber6(int value);

        int getnumber7(); 
        void setnumber7(int value); 

        int getnumber8();
        void setnumber8(int value); 

        int getnumber9(); 
        void setnumber9(int value); 

        int getnumber10(); 
        void setnumber10(int value); 
};
//      Дружественные функции
Number operator*(const Number& n, int multiplier) {
    return Number(*(n.number) * multiplier);
}

Number operator*(int multiplier, const Number& n) {
    return Number(multiplier * *(n.number));
}

ostream& operator<<(ostream& os, const Number& n) {
    os << *(n.number);
    return os;
}
//      Дочерний класс
class PrimeNumber : public Number {
public:
    PrimeNumber(int num) : Number(num) {
        if (!isPrime(num)) {
            PrimeStatus = false;
        }
        previousPrime = true;
        int temp = num - 1;
        while (!isPrime(temp)) {
            temp--;
        }
        previousPrime = temp;
    }
    int nextPrime() {
        int temp = getNumber() + 1;
        while (!isPrime(temp)) {
            temp++;
        }
        return temp;
    }
    int getPreviousPrime() {
        return previousPrime;
    }
    bool getPrimeStatus() {
        return PrimeStatus;
    }
//      Могу трогать в дочернем классе (protected)  
    int roflProtected() {
        rofl = 189;
        return rofl;
    }
private:
    bool PrimeStatus;
    int previousPrime;

    bool isPrime(int num) {
        if (num <= 1) return false;
        if (num == 2) return true;
        if (num % 2 == 0) return false;
        for (int i = 3; i * i <= num; i += 2) {
            if (num % i == 0) return false;
        }
        return true;
    }
};

signed main() {
    //Демонстрация работы
    Number n1(5);
    Number n2(3, 1);
    Number n3 = n1 + n2;
    Number n4 = n1 - n2;
    bool isEqual = n1 == n2;
    Number n5 = n1 * 2;
    Number n6 = 2 * n1;
    cout << "n1 = " << n1 << endl;
    cout << "n2 = " << n2 << endl;
    cout << "n3 = (n1 + n2) = " << n3 << endl;
    cout << "n4 = (n1 - n2) = " << n4 << endl;
    cout << "n1 is " << (isEqual ? "" : "не ") << "равен n2" << endl;
    cout << "n5 (n1 * 2) = " << n5 << endl;
    cout << "n6 (2 * n1) = " << n6 << endl;
    cout << "n1 in XML: \n" << n1.toXML() << endl;
    for (int i = 2; i <= 10; ++i) {
        cout << "Число " << i;
        PrimeNumber pn(i);
        cout << (pn.getPrimeStatus() ? " - простое" : " - составное") << endl;
    }
    PrimeNumber pn1(11), pn2(14);
    cout  << "Следующее простое число после " << pn1.getNumber() << " - " << pn1.nextPrime() << endl;
    cout  << "Предыдущее простое число перед " << pn1.getNumber() << " - " << pn1.getPreviousPrime() << endl;
    cout  << pn1 + pn2 << endl; 
    return 0;
}