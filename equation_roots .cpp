// Создать абстрактный базовый класс с виртуальной функцией — корни уравнения.
// Создать производные классы: класс линейных уравнений и класс квадратных уравнений.
// Определить функцию вычисления корней уравнений.
  

#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;

class Equation
{
protected:
	double x1, x2;
public:
	Equation() : x1(0), x2(0) {}
	double GetX1() { return x1; }
	double GetX2() { return x2; }
	virtual int Solution() = 0;
	~Equation() {}
};

//Линейным уравнением - уравнение вида bx + c = 0, в котором с и b — действительные числа
//если b ≠ 0 — уравнение имеет единственный корень : х = -c : b;
//если b = 0 — уравнение корней не имеет;
//если b и c равны нулю, то корнем уравнения является любое число.
//При переносе из одной части в другую, член уравнения меняет свой знак на противоположный.
class LineEq : public Equation
{
protected:
	double b, c;
public:
	LineEq(double b, double c) : b(b), c(c) {}
	int Solution() 
	{
		if (b == 0 && c != 0)
			return -3;        // нет ниодного корня
		else 
		{
			if (b == 0 && c == 0)
				return -2;    // в уравнении куча корней
			x1 = -c / b;
			return 1;
		}

	}
	~LineEq() {}
};

// Квадратное уравнение — это уравнение вида ax2 + bx + c = 0, 
// где a — первый или старший коэффициент, не равный нулю, b — второй коэффициент, c — свободный член.
// если а = 0  D = b2 - 4*ac
// D = 0  x = -b / 2a один корень кратности 2 или 2 равных  корня
// D > 0  x = -b + - sqrt(D) / 2a

class SquareEq : public LineEq 
{
	double a;
public:
	SquareEq(double a, double b, double c) : a(a), LineEq(b, c) {}
	int Solution() 
	{
		if (a == 0) return LineEq::Solution();
		double D = b * b - 4 * a * c;
		int root = 0;
		if (D == 0)
		{
			root = 1;
			x1 = x2 = -b / (2 * a);                // 2 равных  корня
		}
		if (D > 0)                                 // 2 разных корня
		{
			root = 2;
			x1 = (b * -1 + sqrt(D)) / (2 * a);
			x2 = (b * -1 - sqrt(D)) / (2 * a);
		}
		
		return root;

	}
	~SquareEq() {}
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int res = 0;
	double a = 0, b = 0, c = 0;

	cout << "Класc линейных уравнений! Введите коэффициенты:\n";
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	LineEq LE(a, b);
	res = LE.Solution();
	if (res == -3)
		cout << "\nВ уравнении нет ниодного корня" << endl;
	else if (res == -2)
		cout << "\nВ уравнении куча корней (или любое число)" << endl;
	else
		cout << "\nx = " << LE.GetX1() << endl;


	cout << "\nКласс квадратных уравнений! Введите коэффициенты:\n";
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "с = ";
	cin >> c;
	SquareEq SE(a, b, c);
	res = SE.Solution();
	if (res > 0) 
	{
		cout << "\nx1 = " << SE.GetX1() << endl;
		if (a) cout << "x2 = " << SE.GetX2() << endl;
	}
	else if (res == -2)
		cout << "\nВ уравнении куча корней (или любое число)" << endl;
	else
		cout << "\nВ уравнении нет корней" << endl;

	

	return 0;
}