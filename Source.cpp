#include <iostream>
#include <string>
#include <vector>

class Talent
{
public:
    virtual ~Talent() = default;
    virtual std::string Abilities() const = 0;
};

class Swimming: public Talent
{
public:

    virtual std::string Abilities() const override
    {
        return "Swimm";
    }
};
class Dancing: public Talent
{
    virtual std::string Abilities() const override
    {
        return "Dance";
    }

};

class Counting: public Talent
{
    virtual std::string Abilities() const override
    {
        return "Count";
    }

};

class Dog
{
public:
    Dog(std::string inname);
    ~Dog();

    void AddTalents(Talent *talent);
    void Show_talents() const;

private:
    std::string _name;
    std::vector <Talent *> _talents;
};

Dog::Dog (std::string inname) : _name(inname)
{
}

// Не забываем чистить память!
Dog::~Dog()
{
    for(auto talent : _talents)
    {
        if (talent != nullptr)
            delete talent;
    }
}
void Dog::AddTalents(Talent *talent)
{
    _talents.push_back(talent);
}

void Dog::Show_talents() const
{
    std::cout << "This is " << _name << " and it has some talents:" << std::endl;;

    for(auto talent : _talents)
        std::cout << talent->Abilities() << std::endl;
}

int main()
{
    std::string DogName;
    std::cout << "What is the dog's name: ";
    std::cin >> DogName;
    Dog dog(DogName);

    // как вариант
    dog.AddTalents(new Swimming);
    dog.AddTalents(new Dancing);
    dog.AddTalents(new Counting);

    dog.Show_talents();

    return 0;
}
