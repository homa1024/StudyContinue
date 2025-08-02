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

    // POINT: この関数はconstにできる（メンバ変数を変更しているので実際はできないが、設計を見直せばconst化可能）
    double add(double a, double b) {
        result = a + b;
        history.push_back(result);
        return result;
    }

    // POINT: この関数もconstにできる可能性がある
    double subtract(double a, double b) {
        result = a - b;
        history.push_back(result);
        return result;
    }

    // POINT: この関数もconstにできる可能性がある
    double multiply(double a, double b) {
        result = a * b;
        history.push_back(result);
        return result;
    }

    // POINT: この関数もconstにできる可能性がある
    double divide(double a, double b) {
        if (b == 0) {
            std::cerr << "Error: Division by zero!" << std::endl;
            return 0;
        }
        result = a / b;
        history.push_back(result);
        return result;
    }

    // POINT: この関数もconstにできる可能性がある
    double power(double base, int exponent) {
        result = std::pow(base, exponent);
        history.push_back(result);
        return result;
    }

    // POINT: この関数は明らかにconstにすべき
    double getResult() {
        return result;
    }

    // POINT: この関数もconstにすべき
    void printHistory() {
        std::cout << "Calculation history:" << std::endl;
        // POINT: size()の型はsize_tなのでintと比較すると警告が出る可能性
        for (int i = 0; i < history.size(); i++) {
            std::cout << "  " << i << ": " << history[i] << std::endl;
        }
    }

    // POINT: この関数はconstにすべき
    // POINT: vector::at()を使うべき（範囲外アクセスチェックのため）
    double getHistoryItem(int index) {
        return history[index];  // POINT: 範囲外アクセスの可能性
    }

    void clearHistory() {
        history.clear();
    }
};

// POINT: この関数の引数と変数はconstにすべき
// POINT: piの値はconstexprにすべき
double calculateCircleArea(double radius) {
    double pi = 3.14159;  // POINT: constexprまたは少なくともconstにすべき
    return pi * radius * radius;
}

// POINT: この関数はconstexprにできる可能性がある
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

// POINT: この関数はconstにすべき（引数に対してのみ動作）
// POINT: constexprにできる可能性もある
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
    
    // POINT: ここで範囲外アクセスの可能性がある
    std::cout << "\nHistory item at index 2: " << calc.getHistoryItem(2) << std::endl;
    
    // POINT: radiusはconstにすべき
    double radius = 5.0;
    std::cout << "\nCircle area with radius " << radius << ": " << calculateCircleArea(radius) << std::endl;
    
    // POINT: numはconstにすべき
    int num = 5;
    std::cout << "Factorial of " << num << ": " << factorial(num) << std::endl;
    
    // POINT: primeCandidateはconstにすべき
    int primeCandidate = 17;
    std::cout << primeCandidate << " is " << (isPrime(primeCandidate) ? "prime" : "not prime") << std::endl;
    
    return 0;
}