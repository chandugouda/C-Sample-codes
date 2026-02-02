#include <iostream>
#include<memory>
using namespace std;

enum class ShapeType{
    Circle,
    Rectangle,
    Square
};

class Shape{
    public:
    virtual void draw()=0;
    virtual ~Shape() = default;
};
class Circle : public Shape{
    public:
    void draw() override {
        cout<<"Circle is created "<<endl;
    }
};
class Rectangle : public Shape{
    public:
    void draw() override {
        cout<<"Rectangle is created"<<endl;
    }
};
class Square : public Shape{
    public:
    void draw() override {
        cout<<"Square is created "<<endl;
    }
};
class ShapeFactory{
    public:
    Shape * createShape(ShapeType type){
        if(type==ShapeType::Circle){
            return new Circle();
        }
        else if(type == ShapeType :: Rectangle){
            return new Rectangle();
        }
        else{
            return new Square();
        }
        return nullptr;
}
};
int main() {
    ShapeFactory factory;
    Shape* circle = factory.createShape(ShapeType::Circle);
    Shape* rectangle = factory.createShape(ShapeType :: Rectangle);
    Shape* square = factory.createShape(ShapeType :: Square);

    circle->draw();
    rectangle->draw();
    square ->draw();

    delete circle;
    delete rectangle;
    delete square;

    return 0;
}
    
