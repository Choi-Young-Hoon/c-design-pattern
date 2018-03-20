#include <iostream>
#include <string>


/*
* 객체를 감싸서 새로운 행동을 제공한다.
*/
class DecoratorInterface {
public:
	explicit DecoratorInterface()
	{}

	virtual ~DecoratorInterface()
	{}


public: // Interface
	virtual void Print() = 0;
	virtual std::string GetValue() = 0;
};


/*
 * DecoratorClass1
 */
class DecoratorClass1 : public DecoratorInterface {
public:
	explicit DecoratorClass1()
	: m_pComponent(NULL)
	{}

	explicit DecoratorClass1(DecoratorInterface* pDecoratorComponent)
	: m_pComponent(pDecoratorComponent)
	{}

	virtual ~DecoratorClass1() {
		if (m_pComponent != NULL) {
			delete m_pComponent;
		}
	}


public:
	virtual void Print() {
		std::cout << GetValue() << std::endl;
		if (m_pComponent != NULL) {
			m_pComponent->Print();
		}
	}

	virtual std::string GetValue() {
		return "Class1";
	}


private:
	DecoratorInterface* m_pComponent;
};



/*
* DecoratorClass2
*/
class DecoratorClass2 : public DecoratorInterface {
public:
	explicit DecoratorClass2()
	: m_pComponent(NULL)
	{}

	explicit DecoratorClass2(DecoratorInterface* pDecoratorComponent)
	: m_pComponent(pDecoratorComponent)
	{}

	virtual ~DecoratorClass2() {
		if (m_pComponent != NULL) {
			delete m_pComponent;
		}
	}


public:
	virtual void Print() {
		std::cout << GetValue() << std::endl;

		if (m_pComponent != NULL) {
			m_pComponent->Print();
		}
	}

	virtual std::string GetValue() {
		return "Class2";
	}


private:
	DecoratorInterface* m_pComponent;
};



int main(int argc, char* argv[])
{
	DecoratorInterface* pDecorator = new DecoratorClass1(new DecoratorClass2(new DecoratorClass1(new DecoratorClass2())));
	
	pDecorator->Print();
	
	delete pDecorator;
	return 0;
}