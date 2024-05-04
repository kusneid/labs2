#include "header.h"

int main()
{
  system("chcp 65001");
  unsigned short ans;
  while (true)
  {
    std::cout << "\n\nвыберите задачу для демонстрации(нажмите 0 для выхода):";
    std::cin >> ans;
    std::cout << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // эта функция очищает поток чтобы была возможность последовательного ввода для заданий без применения getline
    switch (ans)
    {
    case 1:
      first();
      break;
    case 2:
      second();
      break;
    case 3:
      third();
      break;
    case 4:
      fourth();
      break;
    case 5:
      fifth();
      break;
    case 6:
      sixth();
      break;
    case 7:
      seventh();
      break;
    case 8:
      eighth();
      break;
    case 9:
      ninth();
      break;
    case 0:
      return 0;
    default:
      std::cout << "попробуй снова))" << std::endl;
      break;
    }
  }
}

void first()
{
  std::string str1, str2;
  do
  {
    std::cout << "\nEnter 2 words with size 8:";
    std::cin >> str1 >> str2;
  } while (str1.length() != 8 || str2.length() != 8);

  char lastSymbol = str1[str1.length() - 1];
  unsigned count = 0;

  for (size_t i = 0; i < str2.length(); i++)
  {
    if (str2[i] == lastSymbol)
    {
      count++;
    }
  }

  std::cout << "\nResult: " << count;
}

void second()
{
  std::string str1;
  std::cout << "\nEnter text:";
  std::getline(std::cin, str1);

  std::string str2 = "";

  for (size_t i = 0; i < str1.length(); i++)
  {
    if (str1[i] != ' ' && str1[i] != '(' && str1[i] != ')' && str1[i] != '{' && str1[i] != '}')
    {
      str2 += str1[i];
    }
  }

  std::cout << "\nResult: " << str2;
}

void third()
{
  std::ifstream source{"text.txt"};
  std::ofstream second{"2.txt"};
  std::ofstream first{"1.txt"};

  char temp;

  for (source.get(temp); !source.eof(); source.get(temp))
  {
    if ((temp <= 'Z' && temp >= 'A') || (temp >= 'a' && temp <= 'z') || static_cast<int>(temp) == 32)
    {
      first << temp;
    }
    else if ((temp >= '0' && temp <= '9') || static_cast<int>(temp) == 32)
    {
      second << temp;
    }
  }

  source.close();
  first.close();
  second.close();
}

void print(const std::vector<float> &vec)
{
  for (float i : vec)
  {
    std::cout << i << ' ';
  }
  std::cout << '\n';
}

void fourth()
{
  std::vector<float> v;

  for (size_t i = 0; i < 25; i++)
  {
    v.push_back(std::rand() / (double)RAND_MAX * 10);
  }

  std::cout << "start:\n";
  print(v);

  for (float &i : v)
  {
    i = i * i;
  }

  std::cout << "after sqrt:\n";
  print(v);

  v.erase(v.begin() + 5);

  std::cout << "result:\n";
  print(v);
}

class Card
{
private:
  std::string title;
  std::string author;
  unsigned number;

public:
  Card(std::string t, std::string a, unsigned n) : title(t), author(a), number(n) {}
  friend void fifth();
};

void fifth()
{

  std::vector<Card> v = {
      Card("how to become baddest guy", "kolya chernev", 3),
      Card("c++ best guide in da world", "olga yurevna", 5),
      Card("prikoly 2005", "kirill volkov", 6),
      Card("vs code guide", "ya", 7),
      Card("how to be coolest rector", "mikhail gordin", 0)};

  std::cout << "available:\n";
  for (const Card &c : v)
  {
    std::cout << "title: " << c.title << ", author: " << c.author << ", number: " << c.number << '\n';
  }

  std::string input;
  std::cout << "enter author:" << std::endl;
  std::getline(std::cin, input);

  bool haveFound = false;
  for (const Card &c : v)
  {
    if (c.author == input)
    {
      std::cout << "title: " << c.title << ", author: " << c.author << ", number: " << c.number << '\n';
      haveFound = true;
    }
  }

  if (!haveFound)
  {
    std::cout << "can't find((\n";
  }
}

void sixth()
{
  std::list<int> l = {-1, 4321, -2312, 123, -1212, 131, 124, -124124, 3, -4, 0};
  int x;
  std::cin >> x;
  for (int obj : l)
  {
    if (obj == x)
    {
      std::cout << "Yes\n";
      return;
    }
  }
  std::cout << "No\n";
}

class Complex
{
public:
  double real;
  double imag;

  Complex(double r = 0, double i = 0) : real(r), imag(i) {}

  Complex operator+(const Complex &c)
  {
    return Complex(real + c.real, imag + c.imag);
  }
  Complex &operator+=(const Complex &c)
  {
    *this = *this + c;
    return *this;
  }
  friend std::ostream &operator<<(std::ostream &out, const Complex &c)
  {
    if (c.imag > 0)
    {
      out << c.real << " +"
          << "i * " << fabs(c.imag) << '\n';
    }
    else
    {
      out << c.real << " -"
          << "i * " << fabs(c.imag) << '\n';
    }

    return out;
  }
};

void seventh()
{
  std::list<Complex> l = {
      Complex(-1.2, 6.3),
      Complex(4.0, 0.7),
      Complex(7.2, -0.8),
      Complex(5.3, 3.0),
      Complex(-4.9, 6.6),
      Complex(-9.3, 0.2)};
  for (Complex c : l)
  {
    std::cout << c;
  }
  Complex s;
  for (Complex c : l)
  {
    s += c;
  }

  std::cout << "answer:\n"
            << s;
}

void eighth()
{
  std::map<int, int> pairs;

  for (int i = 0; i < 20; i++)
  {
    pairs[i + 1] = (i + 1) * 10;
  }

  std::cout << "first\n";
  for (const auto &pair : pairs)
  {
    std::cout << pair.first << " - " << pair.second << '\n';
  }

  for (auto i = pairs.begin(); i != pairs.end();)
  {
    if (i->first % 2 != 0)
    {
      i = pairs.erase(i);
      // for (const auto &pair : pairs)
      // {
      //   std::cout << pair.first << " - " << pair.second << '\n';
      // }
    }
    else
    {
      i++;
    }
  }

  std::cout << "final:\n";
  for (const auto &pair : pairs)
  {
    std::cout << pair.first << " - " << pair.second << '\n';
  }
}

void ninth()
{

  std::map<std::string, unsigned> salaries{
      {"Ivanov", 45500},
      {"Petrov", 37000},
      {"Sidorov", 245000},
      {"Petrenko", 65000},
      {"Tovalds", 91200},
      {"Popov", 54600},
      {"Andrienko", 35000}};

  std::map<std::string, std::string> groups{
      {"Ivanov", "Research"},
      {"Petrov", "Research"},
      {"Sidorov", "Management"},
      {"Petrenko", "Management"},
      {"Tovalds", "Development"},
      {"Popov", "Research"},
      {"Andrienko", "Sales"}};

  std::map<std::string, unsigned> groupsSalaries;
  int totalSalary = 0;

  for (const auto &salaryRecord : salaries)
  {
    std::string employee = salaryRecord.first;
    unsigned salary = salaryRecord.second;
    std::string department = groups[employee];

    groupsSalaries[department] += salary;

    totalSalary += salary;
  }

  for (const auto &groupsalary : groupsSalaries)
  {
    std::cout << groupsalary.first << " " << groupsalary.second << '\n';
  }

  std::cout << "Overall " << totalSalary << '\n';
}
