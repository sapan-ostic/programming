#include<iostream>
#include<vector> 
class Shape{
private:
    double area;
    double side;
public:
    Shape(double side):
        side{side}{
        std::cout << "Shape ctr" << std::endl;
    };
    // virtual void get_area() const {std::cout << "shape area" << std::endl;};
    virtual void get_area() const = 0 ;
};

class Circle: public Shape{
private:
    int rad;
public:
    Circle(int rad_, double side):
        Shape(side),
        rad{rad_}{
        std::cout << "Circle ctr" << std::endl;
    };
    virtual void get_area() const override {std::cout << "circle area with rad: "<< rad << std::endl;};
};

void print_area(const Shape& s){
    s.get_area();
}
int main(){
    // std::vector<Shape> poly;
    // poly.push_back(Shape());
    // poly.push_back(Circle(3));
    // Circle disc(3, 1);
    Shape *c2 = new Circle(3, 1);
    // Shape *s1 = new Shape(3); // invalid
    // s1->get_area();
    c2->get_area();
    // disc.get_area(); 
    print_area(*c2);
    return 0;
}

