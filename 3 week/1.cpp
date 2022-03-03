#include <iostream>
#include <string>

class Animal {
private:
    std::string name; // кличка животного
    float weight; // вес животного
public:
    Animal(std::string name, float weight): name(name), weight(weight) {}
    std::string getName() {
        return name;
    }
    float getWeight() {
        return weight;
    }
    void setName(std::string new_name) {
        name = new_name;
    }
    virtual std::string speak() = 0;
    friend std::ostream& operator<<(std::ostream& out, Animal& animal) {
        std::cout << "name: " << animal.name << ", weight: " << animal.weight << ".\n";
        return out;
    }
};

class Cow: public Animal {
public:
    Cow(std::string name, float weight): Animal(name, weight) {}
    virtual std::string speak() override final {
        return "Moo!";
    }
};

class Duck: public Animal {
public:
    Duck(std::string name, float weight): Animal(name, weight) {}
    virtual std::string speak() override final {
        return "Quack!";
    }
};

signed main() {
    Cow cow("Jack", 100);
    std::cout << cow;
    std::cout << cow.speak() << '\n';
    Duck duck("Charlie", 5.5);
    std::cout << duck;
    std::cout << duck.speak() << '\n';
    return 0;
}
