#include <iostream>
#include <vector>
#include <string>
#include <cmath>

class Calculator {
private:
    double result;
    std::vector<double> history;
    std::string lastOperation;
    double memoryValue;

public:
    Calculator() : result(0.0), lastOperation(""), memoryValue(0.0) {}

    double add(double a, double b) {
        result = a + b;
        history.push_back(result);
        return result;
    }

    double subtract(double a, double b) {
        result = a - b;
        history.push_back(result);
        return result;
    }

    double multiply(double a, double b) {
        result = a * b;
        history.push_back(result);
        return result;
    }

    double divide(double a, double b) {
        if (b == 0) {
            std::cerr << "Error: Division by zero!" << std::endl;
            return 0;
        }
        result = a / b;
        history.push_back(result);
        return result;
    }

    double power(double base, int exponent) {
        result = std::pow(base, exponent);
        history.push_back(result);
        return result;
    }

    double getResult() {
        return result;
    }

    void printHistory() {
        std::cout << "Calculation history:" << std::endl;
        for (int i = 0; i < history.size(); i++) {
            std::cout << "  " << i << ": " << history.at(i) << std::endl;
        }
    }

    double getHistoryItem(int index) {
        return history.at(index);
    }

    void clearHistory() {
        history.clear();
    }

    double modulo(const double a, const double b) {
        if (b == 0) {
            std::cerr << "Error: Modulo by zero!" << std::endl;
            return 0;
        }
        result = std::fmod(a, b);
        history.push_back(result);
        lastOperation = "modulo";
        return result;
    }

    std::string getLastOperation() const {
        return lastOperation;
    }

    void storeInMemory() {
        memoryValue = result;
    }

    double recallFromMemory() {
        return memoryValue;
    }

    double sqrt(const double value) {
        if (value < 0) {
            std::cerr << "Error: Square root of negative number!" << std::endl;
            return 0;
        }
        result = std::sqrt(value);
        history.push_back(result);
        lastOperation = "sqrt";
        return result;
    }
};

double calculateCircleArea(double radius) {
    double pi = 3.14159;
    return pi * radius * radius;
}

int factorial(int n) {
    if (n < 0) {
        return -1;
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }
    
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

double calculateAverage(const std::vector<double>& numbers) {
    if (numbers.empty()) {
        return 0;
    }
    
    double sum = 0;
    for (int i = 0; i < numbers.size(); i++) {
        sum += numbers[i];
    }
    return sum / numbers.size();
}

constexpr double FAHRENHEIT_SCALE = 9.0 / 5.0;
constexpr double FAHRENHEIT_OFFSET = 32.0;

double celsiusToFahrenheit(const double celsius) {
    return celsius * FAHRENHEIT_SCALE + FAHRENHEIT_OFFSET;
}

double fahrenheitToCelsius(const double fahrenheit) {
    return (fahrenheit - FAHRENHEIT_OFFSET) / FAHRENHEIT_SCALE;
}

int main() {
    Calculator calc;
    
    std::cout << "Addition: " << calc.add(10, 5) << std::endl;
    std::cout << "Subtraction: " << calc.subtract(10, 5) << std::endl;
    std::cout << "Multiplication: " << calc.multiply(10, 5) << std::endl;
    std::cout << "Division: " << calc.divide(10, 5) << std::endl;
    std::cout << "Power: " << calc.power(2, 8) << std::endl;
    std::cout << "Modulo: " << calc.modulo(10, 3) << std::endl;
    std::cout << "Square root: " << calc.sqrt(25) << std::endl;
    
    std::cout << "Last operation: " << calc.getLastOperation() << std::endl;
    
    // メモリ機能のテスト
    calc.storeInMemory();
    std::cout << "Stored in memory: " << calc.getResult() << std::endl;
    calc.add(100, 200);
    std::cout << "Memory recall: " << calc.recallFromMemory() << std::endl;
    
    calc.printHistory();
    
    std::cout << "\nHistory item at index 2: " << calc.getHistoryItem(2) << std::endl;
    
    double radius = 5.0;
    std::cout << "\nCircle area with radius " << radius << ": " << calculateCircleArea(radius) << std::endl;
    
    int num = 5;
    std::cout << "Factorial of " << num << ": " << factorial(num) << std::endl;
    
    int primeCandidate = 17;
    std::cout << primeCandidate << " is " << (isPrime(primeCandidate) ? "prime" : "not prime") << std::endl;
    
    // 平均値計算のテスト
    std::vector<double> numbers = {10.5, 20.3, 30.1, 40.7, 50.2};
    std::cout << "\nAverage: " << calculateAverage(numbers) << std::endl;
    
    // 温度変換のテスト
    double temp = 25.0;
    std::cout << "\n" << temp << "°C = " << celsiusToFahrenheit(temp) << "°F" << std::endl;
    std::cout << temp << "°F = " << fahrenheitToCelsius(temp) << "°C" << std::endl;
    
    return 0;
}