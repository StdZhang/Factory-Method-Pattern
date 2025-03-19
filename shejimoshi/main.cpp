#include <iostream>
#include <memory>
#include <string>
using namespace std;
// 抽象产品类
class Shape {
public:
    virtual ~Shape() {}
    virtual void draw() const = 0;
    virtual void erase() const = 0;
};

// 具体产品类
class Circle : public Shape {
public:
    void draw() const override {
        cout << "Drawing Circle" << endl;
    }
    void erase() const override {
        cout << "Erasing Circle" << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() const override {
        cout << "Drawing Rectangle" << endl;
    }
    void erase() const override {
        cout << "Erasing Rectangle" << endl;
    }
};

class Square : public Shape {
public:
    void draw() const override {
        cout << "Drawing Square" << endl;
    }
    void erase() const override {
        cout << "Erasing Square" << endl;
    }
};

// 抽象工厂类
class ShapeFactory {
public:
    virtual ~ShapeFactory() {}
    virtual unique_ptr<Shape> createShape(const string& shapeType) const = 0;
};

// 具体工厂类
class ConcreteShapeFactory : public ShapeFactory {
public:
    unique_ptr<Shape> createShape(const string& shapeType) const override {
        if (shapeType == "Circle") {
            return make_unique<Circle>();
        } else if (shapeType == "Rectangle") {
            return make_unique<Rectangle>();
        } else if (shapeType == "Square") {
            return make_unique<Square>();
        }
        throw invalid_argument("Unknown shape type");
    }
};

int main() {
    ConcreteShapeFactory factory;
    unique_ptr<Shape> circle = factory.createShape("Circle");
    circle->draw();
    circle->erase();

    unique_ptr<Shape> rectangle = factory.createShape("Rectangle");
    rectangle->draw();
    rectangle->erase();

    unique_ptr<Shape> square = factory.createShape("Square");
    square->draw();
    square->erase();

    return 0;
}
