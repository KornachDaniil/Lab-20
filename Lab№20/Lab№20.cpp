#include <iostream>
#include <cmath>
#include <ctime>
#include <string>

class Math {
private:
   double first_catheter;
   double second_catheter;
   double hipotenuse_result_class;

public:
   // 1. Конструкторы
   Math()
   {// Конструктор без параметров
      first_catheter = 0;
      second_catheter = 0;
   }

   Math(double &first_catheter, double &second_catheter) 
   {// Конструктор с параметрами
      this->first_catheter = first_catheter;
      this->second_catheter = second_catheter;
   }

   Math(const Math& b)
   {// Конструктор копирования
      first_catheter = b.first_catheter;
      second_catheter = b.second_catheter;
   }

   // Деструктор
   ~Math()
   {// Деструктор
     
   }

   // 3. Сеттеры
   inline void Set_param(double &first_catheter, double &second_catheter)
   {// Cеттер для first_catheter и second_catheter
      this->first_catheter = first_catheter;
      this->second_catheter = second_catheter;
   }

   inline void Set_hipotenuse_result(double& hipotenuse_result)
   {// Cеттер для hipotenuse_result
      this->hipotenuse_result_class = hipotenuse_result;
   }

   // 4. Геттеры
   inline double Get_param() const
   {// Геттер для first_catheter и second_catheter
      return first_catheter, second_catheter;
   }

   inline double hipotenuse()
   {// Метод для нахождения гипотинузы
      return sqrt(pow(first_catheter, 2) + pow(second_catheter, 2));
   }

   // 5. Перегрузка операторов =, <<
   Math& operator=(const Math& other) 
   {// Перегрузка оператора присваивания
      if (this != &other) { // Проверка на самоприсваивание
         first_catheter = other.first_catheter;
         second_catheter = other.second_catheter;
      }
      return *this;
   }

   friend std::ostream& operator<<(std::ostream& out, const Math& other);

   virtual void draw() const
   {// Функция вывода данных на экран
      std::cout << first_catheter << " " << second_catheter << std::endl;
   }
};

std::ostream& operator<<(std::ostream& out, const Math& other)
{// Перегрухка оператор "<<"
   out << other.hipotenuse_result_class << std::endl;
   return out;
}

class Exam : public Math
{// Дочерний класс от Math
   double mark;
   std::string FIO;
   std::string predmet;

public:
   // 1. Конструкторы
   Exam()
   {// Конструктор без параметров
      mark = 0;
      FIO = "None";
      predmet = "None";
   }

   Exam(double mark, std::string FIO, std::string predmet) 
   {// Конструктор c параметрами
      this->mark = mark;
      this->FIO = FIO;
      this->predmet = predmet;
   }

   // 2. Деструктор
   ~Exam()
   {// Деструктор

   }

   void draw() const override
   {// Функция вывода данных на экран
      std::cout << FIO << " " << predmet << " " << mark << std::endl;
   }
};

void drawMath(const Math& obj)
{// Функия подстановки
   obj.draw();
}



int main()
{
   srand(time(NULL));
   // 1. Создание и вывод первого объекта
   Math math_first; // Создание первого объекта вызов конструктора без параметров
   std::cout << "Part 1" << std::endl << "Math first: ";
   drawMath(math_first);

   // 2. Создание и вывод полей второго объекта типа Math
   double first_catheter = rand() % 10;
   double second_catheter = rand() % 10;
   std::cout << "First catheter: " << first_catheter << " " << "Second catheter: " << second_catheter << std::endl;
   Math math_second(first_catheter, second_catheter); //Создание и вызов конструктора с параметрами второго объекта

   // 3. Демонстрирование перегрузки оператора =
   math_first = math_second; // Пример перегрузки оператора присваивания
   std::cout << "Math first: ";
   drawMath(math_first);

   // 4. Поиск гипотенузы и демонстрация перегрузки оператора <<
   auto hipotenuse_result_main = math_second.hipotenuse();
   math_second.Set_hipotenuse_result(hipotenuse_result_main);
   std::cout << "Hipotenuse: " << math_second;

   // 5. Создание 3-го обекта типа Exam и демонстрация подстановки
   std::cout << std::endl << std::endl << "Part 2" << std::endl;
   double mark = 10.0;
   Exam exam(mark ,"Daniil Kornach", "Math");
   drawMath(exam);

   return 0;
  }
