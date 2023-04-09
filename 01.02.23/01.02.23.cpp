#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Shape {
public:
    virtual float area() = 0;
    virtual void show() = 0;
    virtual void save() = 0;
    virtual void load() = 0;
    virtual void setCoordinates(float x, float y) {
        this->x = x;
        this->y = y;
    }
    virtual void getCoordinates(float& x, float& y) {
        x = this->x;
        y = this->y;
    }
protected:
    float x, y;
};

class Square : public Shape {
public:
    Square(float x = 0, float y = 0, float side = 0) {
        this->x = x;
        this->y = y;
        this->side = side;
    }
    float area() override {
        return side * side;
    }
    void show() override {
        cout << "Square at (" << x << ", " << y << "), side = " << side << endl;
    }
    void save() override {
        ofstream file("shapes.txt", ios::app);
        file << "Square " << x << " " << y << " " << side << endl;
        file.close();
    }
    void load() override {
        ifstream file("shapes.txt");
        string type;
        float x, y, side;
        while (file >> type >> x >> y >> side) {
            if (type == "Square") {
                Square* s = new Square(x, y, side);
                s->show();
            }
        }
        file.close();
    }
private:
    float side;
};

class Rectangle : public Shape {
public:
    Rectangle(float x = 0, float y = 0, float width = 0, float height = 0) {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
    }
    float area() override {
        return width * height;
    }
    void show() override {
        cout << "Rectangle at (" << x << ", " << y << "), width = " << width << ", height = " << height << endl;
    }
    void save() override {
        ofstream file("shapes.txt", ios::app);
        file << "Rectangle " << x << " " << y << " " << width << " " << height << endl;
        file.close();
    }
    void load() override {
        ifstream file("shapes.txt");
        string type;
        float x, y, width, height;
        while (file >> type >> x >> y >> width >> height) {
            if (type == "Rectangle") {
                Rectangle* r = new Rectangle(x, y, width, height);
                r->show();
            }
        }
        file.close();
    }
    float width, height;
};

class Circle : public Square {
private:
    float radius;
public:
    Circle(float x = 0, float y = 0, float radius = 0) : Square(x, y, radius * 2) {
        this->radius = radius;
        float area() {
            return pow(radius, 2) * M_PI;
        }
        virtual void show() {
            cout << "Circle at (" << x << ", " << y << "), radius = " << radius << endl;
        }
        virtual void save(ofstream & file) {
            file << "circle " << x << " " << y << " " << radius << endl;
        }
        virtual void load(ifstream & file) {
            file >> x >> y >> radius;
            width = height = radius * 2;
        }

};

class Ellipse : public Rectangle {
private:
    float radius;
public:
    Ellipse(float x = 0, float y = 0, float width = 0, float height = 0, float radius = 0) : Rectangle(x, y, width, height) {
        this->radius = radius;
    }

    float area() override {
        return (width * height / 4) * 3.1415926;
    }

    void show() override {
        std::cout << "Ellipse with center at (" << x << ", " << y << "), width " << width << ", height " << height << " and radius " << radius << std::endl;
    }

    void save(std::ofstream& file) override {
        file << "Ellipse " << x << " " << y << " " << width << " " << height << " " << radius << std::endl;
    }

    void load(std::ifstream& file) override {
        file >> x >> y >> width >> height >> radius;
    }
};

int main() {
    const int shapesCount = 4;
    Shape* shapes[shapesCount];

    // Создание объектов разных типов
    shapes[0] = new Square(0, 0, 5);
    shapes[1] = new Rectangle(0, 0, 10, 5);
    shapes[2] = new Circle(0, 0, 5);
    shapes[3] = new Ellipse(0, 0, 10, 5);

    // Вызов методов каждого объекта
    for (int i = 0; i < shapesCount; i++) {
        std::cout << "Shape " << i + 1 << ":" << std::endl;
        shapes[i]->show();
        shapes[i]->save(to_string(i));
        shapes[i]->load(to_string(1));
        shapes[i]->show();
        std::cout << "Area: " << shapes[i]->area() << std::endl;
        std::cout << std::endl;
    }

    // Очистка памяти
    for (int i = 0; i < shapesCount; i++) {
        delete shapes[i];
    }

    return 0;
}
