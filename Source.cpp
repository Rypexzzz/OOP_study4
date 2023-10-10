#include <iostream>
#include <string>
#include <vector>

class Talent {
public:
	virtual void show_talents() = 0;
};

class Swimming : virtual public Talent {
public:
	virtual void show_talents() {
		std::cout << "It can swim" << std::endl;
	}
};

class Counting : virtual public Talent {
public:
	virtual void show_talents() {
		std::cout << "It can count" << std::endl;
	}
};

class Dancing : virtual public Talent {
public:
	virtual void show_talents() {
		std::cout << "It can dance" << std::endl;
	}
};

class Dog {
private:
	std::string name;
	std::vector<Talent*> talents;
public:
	Dog(std::string _name) {
		name = _name;
	}
	std::string get_name() {
		return name;
	}
	void set_name(std::string _name) {
		name = _name;
	}
	void set_talents() {
		std::string command = "";
		std::cout << "Input talents to add them or stop to stop." << std::endl;
		while (command != "stop") {
			std::cin >> command;
			if (command == "swim")
				talents.push_back(new Swimming());
			else if (command == "dance")
				talents.push_back(new Dancing());
			else if (command == "count")
				talents.push_back(new Counting());
		}
	}
	void showTal() {
		std::cout << get_name() << " has some talents:" << std::endl;
		for (int i = 0; i < talents.size(); i++) {
			talents[i]->show_talents();
		}
	}
};

int main() {
	Dog d("Steve");
	d.set_talents();
	d.showTal();
}