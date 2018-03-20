#include  <iostream>


/*
 * 메소드 팩토리 패턴
 */
class Animal {
public:
	explicit Animal()
	{}

	virtual ~Animal()
	{}


public: // Interface
	virtual void Speak() = 0;
};


class AnimalDog : public Animal {
public:
	explicit AnimalDog()
	{}

	virtual ~AnimalDog()
	{}


public: // Interface
	virtual void Speak() override {
		std::cout << "Dog Speak!" << std::endl;
	}
};


class AnimalCat : public Animal {
public:
	explicit AnimalCat()
	{}

	virtual ~AnimalCat()
	{}


public: // Interface
	virtual void Speak() override {
		std::cout << "Cat Speak!" << std::endl;
	}
};


// ==================================================  Factory Class
class Farm {
public:
	explicit Farm()
	: m_pAnimal(NULL)
	{
		std::cout << "Create Farm!" << std::endl;
	}

	virtual ~Farm() {
		std::cout << "Destroy Farm!" << std::endl;
		if (m_pAnimal != NULL) {
			delete m_pAnimal;
		}
	}


public: // Function
	void NewAnimal() {
		m_pAnimal = CreateAnimal();
		if (m_pAnimal == NULL) {
			std::cout << "Memory Alloc Failed" << std::endl;
		}
	}

	void Speak() {
		if (m_pAnimal != NULL) {
			m_pAnimal->Speak();
		}
	}


public:  // Interface
	virtual Animal* CreateAnimal() = 0;

private:
	Animal* m_pAnimal;
};



// ================================================== Dog Factory Class
class FarmDog : public Farm {
public:
	explicit FarmDog()
	{}

	virtual ~FarmDog()
	{}


public: // Interface
	virtual Animal* CreateAnimal() override {
		return new AnimalDog();
	}
};


// =================================================== Cat Factory Class
class FarmCat : public Farm {
public:
	explicit FarmCat()
	{}

	virtual ~FarmCat()
	{}


public:  // Interface
	virtual Animal* CreateAnimal() override {
		return new AnimalCat();
	}
};


int main() {
	FarmDog dogFarm;
	dogFarm.NewAnimal();
	dogFarm.Speak();


	FarmCat catFarm;
	catFarm.NewAnimal();
	catFarm.Speak();
	return 0;
}