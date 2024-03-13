#include <iostream>
#include <cmath>

class Math {
private:
   double first;
   double second;

public:
   Math(double &first, double &second) 
   {// Конструктор
      this->first = first;
      this->second = second;
   }

   double hipotenuse()
   {// Метод для нахождения гипотинузы
      return sqrt(pow(first, 2) + pow(second, 2));
   }
};

int main()
{
   double first = rand() % 10;
   std::cout << "First: " << first << std::endl;
   double second = rand() % 10;
   std::cout << "Second: " << second << std::endl;
   Math a(first, second);
   std::cout << "Hipotenuse: " << a.hipotenuse() << std::endl;
   return 0;
}
