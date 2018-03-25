#include <iostream>

/*
* 브리지 패턴 (Bridge Pattern)
* 구현부에서 추상층을 분리하여 각자 독립적으로 변형할 수 있게 하는 패턴이다.
* 즉 구현과 별도의 클래스로 정의해서 서로를 분리하는 방법이다.
* 전형적인 상속을 이용한 패턴으로 확장 설계에 용이하다.
*/


// Implementor 인터페이스
class Implementor {
public:
	virtual void OperationImpl() = 0;
};



// ConcreteImplementorA 상속 클래스
class ConcreteImplementorA : public Implementor {
public:
	virtual void OperationImpl() override {
		std::cout << "ConcreteImplementorA" << std::endl;
	}
};


// ConcreteImplementorB 상속 클래스
class ConcreteImplementorB : public Implementor {
public:
	virtual void OperationImpl() override {
		std::cout << "ConcreteImplementorB" << std::endl;
	}
};




// Abstraction 인터페이스
class Abstraction {
public:
	virtual void Operation() = 0;
};


// ConcreteAbstraction
class ConcreteAbstraction : public Abstraction {
public:
	explicit ConcreteAbstraction(Implementor* pImpl)
		: m_pImpl(pImpl)
	{}


public:
	virtual void Operation() override {
		m_pImpl->OperationImpl();
	}


private:
	Implementor* m_pImpl;
};





int main(void) {
	ConcreteImplementorA concreteImplA;
	ConcreteImplementorB concreteImplB;

	ConcreteAbstraction concreteAbstractionA(&concreteImplA);
	ConcreteAbstraction concreteAbstractionB(&concreteImplB);

	concreteAbstractionA.Operation();
	concreteAbstractionB.Operation();

	return 0;
}