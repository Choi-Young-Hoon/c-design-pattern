#include <iostream>
#include <string>
#include <vector>


class Drink {
public:
	explicit Drink(std::string strName)
		: m_strName(strName)
	{}
	virtual ~Drink()
	{}

	std::string GetName() { return m_strName; }


private:
	std::string m_strName;
};


template<typename T>
class Iterator {
public:
	virtual bool  IsDone() = 0;
	virtual T*	  Next() = 0;
};


class VendingMachineIterator : public Iterator<Drink> {
public:
	explicit VendingMachineIterator(std::vector<Drink*> drinkList) {
		m_Position = 0;
		m_DrinkList = drinkList;
	}


public:
	virtual bool IsDone() override {
		if (m_Position < m_DrinkList.size()) {
			return true;
		}
		return false;
	}

	virtual Drink* Next() override {
		Drink* pDrink = m_DrinkList[m_Position];
		m_Position++;
		return pDrink;
	}


private:
	std::vector<Drink*> m_DrinkList;
	unsigned int m_Position;
};


template<typename T2>
class Aggreate {
public:
	virtual Iterator<T2>* CreateIterator() = 0;
};


class VendingMachine : public Aggreate<Drink> {
public:
	explicit VendingMachine() {
		AddDrink("콜라");
		AddDrink("사이다");
	}
	virtual ~VendingMachine() {
		for (auto& iter : m_DrinkList) {
			delete iter;
		}
	}


public:
	void AddDrink(std::string strDrinkName) {
		Drink* pDrink = new Drink(strDrinkName);
		m_DrinkList.push_back(pDrink);
	}

	Iterator<Drink>* CreateIterator() {
		VendingMachineIterator* pIter = new VendingMachineIterator(m_DrinkList);
		return pIter;
	}

private:
	std::vector<Drink*> m_DrinkList;
};



int main(void) {
	VendingMachine machine;

	machine.AddDrink("Hello");

	Iterator<Drink>* pIter = machine.CreateIterator();
	while (pIter->IsDone()) {
		Drink* pDrink = pIter->Next();

		std::cout << "Drink Name: " << pDrink->GetName() << std::endl;
	}

	return 0;
}