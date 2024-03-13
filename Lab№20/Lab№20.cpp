#include <iostream>
#include <cmath>
#include <ctime>

class Math {
private:
   double first;
   double second;
   double hipotenuse_result_class;

public:
   Math(double &first, double &second) 
   {// Конструктор с параметрами
      this->first = first;
      this->second = second;
   }

   Math(const Math& b)
   {// Конструктор копирования
      first = b.first;
      second = b.second;
   }

   Math()
   {// Конструктор без параметров
      first = 0;
      second = 0;
   }

   ~Math()
   {// Деструктор
     
   }

   inline void Set_first(double &first)
   {// Cеттер для first 
      this->first = first;
   }

   inline void Set_second(double& second)
   {// Cеттер для second
      this->second = second;
   }

   inline double Get_first() const
   {// Геттер для first
      return first;
   }

   inline double Set_second() const
   {// Геттер для second
      return second;
   }

   inline void Set_hipotenuse_result(double &hipotenuse_result)
   {// Cеттер для hipotenuse_result
      this->hipotenuse_result_class = hipotenuse_result;
   }

   inline double hipotenuse()
   {// Метод для нахождения гипотинузы
      return sqrt(pow(first, 2) + pow(second, 2));
   }

   Math& operator=(const Math& other) 
   {// Перегрузка оператора присваивания
      if (this != &other) { // Проверка на самоприсваивание
         first = other.first;
         second = other.second;
      }
      return *this;
   }

   inline void print(const Math &obj) const 
   {
      std::cout << obj.first << " " << obj.second;
   }

   friend std::ostream& operator<<(std::ostream& out, const Math& other);
};

std::ostream& operator<<(std::ostream& out, const Math& other)
{
   out << other.hipotenuse_result_class << std::endl;
   return out;
}


int main()
{
   srand(time(NULL));
   Math test1; // Создание первого объекта вызов конструктора без параметров

   double first = rand() % 10;
   std::cout << "First: " << first << std::endl;
   double second = rand() % 10;
   std::cout << "Second: " << second << std::endl;
   Math test2(first, second); //Создание и вызов конструктора с параметрами второго объекта

   test1 = test2; // Пример перегрузки оператора присваивания

   // Поиск и вывод(с перегрузкой <<) гипотенузы
   double hipotenuse_result_main = test2.hipotenuse();
   test2.Set_hipotenuse_result(hipotenuse_result_main);
   std::cout << "Hipotenuse: " << test2;

   return 0;
}
