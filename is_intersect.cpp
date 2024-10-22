#include <iostream>

// объявляем наследников Shape
struct Rectangle;
struct Triangle;
struct Circle;

// все 6 вариантов функций пересечения
bool is_intersect(Rectangle * a, Rectangle * b) { std::cout << "R x R\n"; return true; }
bool is_intersect(Rectangle * a, Triangle  * b) { std::cout << "R x T\n"; return true; }
bool is_intersect(Rectangle * a, Circle    * b) { std::cout << "R x C\n"; return true; }
bool is_intersect(Triangle  * a, Triangle  * b) { std::cout << "T x T\n"; return true; }
bool is_intersect(Triangle  * a, Circle    * b) { std::cout << "T x C\n"; return true; }
bool is_intersect(Circle    * a, Circle    * b) { std::cout << "C x C\n"; return true; }

// В решении задачи используется так называемая "двойная диспетчеризация", 
// которая позволяет избежать использования dynamic_cast
// базовый класс фигуры
struct Shape 
{ 
    virtual ~Shape() {} 
    virtual bool intersect( Rectangle * r ) = 0;
    virtual bool intersect( Triangle  * t ) = 0;
    virtual bool intersect( Circle    * c ) = 0;
    virtual bool intersect( Shape     * s ) = 0;
};

// прямоугольник
struct Rectangle : Shape 
{
    bool intersect( Rectangle * r ) { return is_intersect(this, r); }
    bool intersect( Triangle  * t ) { return is_intersect(this, t); }
    bool intersect( Circle    * c ) { return is_intersect(this, c); }
    bool intersect( Shape     * s ) { 
        return s->intersect(this); 
    }
};

// треугольник
struct Triangle : Shape 
{
    bool intersect( Rectangle * r ) { return is_intersect(r, this); }
    bool intersect( Triangle  * t ) { return is_intersect(t, this); }
    bool intersect( Circle    * c ) { return is_intersect(this, c); }
    bool intersect( Shape     * s ) { 
        return s->intersect(this); 
    }
};

// круг
struct Circle : Shape 
{
    bool intersect( Rectangle * r ) { return is_intersect(r, this); }
    bool intersect( Triangle  * t ) { return is_intersect(t, this); }
    bool intersect( Circle    * c ) { return is_intersect(c, this); }
    bool intersect( Shape     * s ) { 
        return s->intersect(this); 
    }
};

// реализация самой функции
bool is_intersect(Shape * a, Shape * b) 
{ 
    return a->intersect(b); 
}

/*
Разберитесь, как устроено это решение: 
каким образом после двух последовательных вызовов метода intersect 
(сначала внутри функции is_intersect, а потом внутри реализации intersect(Shape*)) 
мы попадаем в метод intersect, в котором типы обоих аргументов уже известны, 
и в котором мы можем вызвать is_intersect для конкретных типов.
*/