#include <iostream>
#include <vector>
#include <string>
#include <cmath>

class Calculator {
private:
    double result;
    std::vector<double> history;

public:
    Calculator() : result(0.0) {}

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
            std::cout << "  " << i << ": " << history[i] << std::endl;
        }
    }

    double getHistoryItem(int index) {
        return history[index];
    }

    void clearHistory() {
        history.clear();
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

int main() {
    Calculator calc;
    
    std::cout << "Addition: " << calc.add(10, 5) << std::endl;
    std::cout << "Subtraction: " << calc.subtract(10, 5) << std::endl;
    std::cout << "Multiplication: " << calc.multiply(10, 5) << std::endl;
    std::cout << "Division: " << calc.divide(10, 5) << std::endl;
    std::cout << "Power: " << calc.power(2, 8) << std::endl;
    
    calc.printHistory();
    
    std::cout << "\nHistory item at index 2: " << calc.getHistoryItem(2) << std::endl;
    
    double radius = 5.0;
    std::cout << "\nCircle area with radius " << radius << ": " << calculateCircleArea(radius) << std::endl;
    
    int num = 5;
    std::cout << "Factorial of " << num << ": " << factorial(num) << std::endl;
    
    int primeCandidate = 17;
    std::cout << primeCandidate << " is " << (isPrime(primeCandidate) ? "prime" : "not prime") << std::endl;
    
    return 0;
}