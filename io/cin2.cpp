#include <iostream>
#include <limits>

double getDouble(){
  while (true)
  {
    std::cout << "Enter a double value: ";
    double x;
    std::cin >> x;
    if (std::cin.fail()) {
      std::cin.clear();
      ignoreLine();
    } else {
      ignoreLine();
      return x;
    }
  }
}

char getOperator(){
  while(true) {
    std::cout << "Enter one of the following: +, -, *, or /: ";
    char op;
    std::cin >> op;

    switch (op){
      case '+':
      case '-':
      case '*':
      case '/':
        ignoreLine();
        return op;
      default:
        std::cerr << "Oops, that input is invalid.  Please try again.\n";
        ignoreLine();
        break;
    }
  }
}

void ignoreLine() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void printResult(double x, char operation, double y)
{
    switch (operation)
    {
    case '+':
        std::cout << x << " + " << y << " is " << x + y << '\n';
        break;
    case '-':
        std::cout << x << " - " << y << " is " << x - y << '\n';
        break;
    case '*':
        std::cout << x << " * " << y << " is " << x * y << '\n';
        break;
    case '/':
        std::cout << x << " / " << y << " is " << x / y << '\n';
        break;
    }
}

void test01() {
  double x =  getDouble();
  char operation = getOperator();
  double y = getDouble();

  printResult(x, operation, y);
}


void test02() {
  std::int16_t x; // x is 16 bits, holds from -32768 to 32767
  while(true) {
    std::cout << "Enter a number between -32768 and 32767: ";
    std::cin >> x;
    if (std::cin.good()) {
      ignoreLine();
      break;
    } else {
      std::cout << "Oops, you had made an invalid input!" << std::endl;
      std::cin.clear();
      ignoreLine();
    }
  }
  std::int16_t y = 0; // y is 16 bits, holds from -32768 to 32767

  while(true) {
    std::cout << "Enter another number between -32768 and 32767: ";
    std::cin >> y;
    if (std::cin.good()) {
      ignoreLine();
      break;
    } else {
      std::cout << "Oops, you had made an invalid input!" << std::endl;
      std::cin.clear();
      ignoreLine();
    }

  }

  std::cout << "The sum is: " << x + y << '\n';
}

int main()
{
    test02();

    return 0;
}