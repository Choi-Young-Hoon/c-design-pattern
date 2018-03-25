#include <iostream>

/*
* �긮�� ���� (Bridge Pattern)
* �����ο��� �߻����� �и��Ͽ� ���� ���������� ������ �� �ְ� �ϴ� �����̴�.
* �� ������ ������ Ŭ������ �����ؼ� ���θ� �и��ϴ� ����̴�.
* �������� ����� �̿��� �������� Ȯ�� ���迡 �����ϴ�.
*/


// Implementor �������̽�
class Implementor {
public:
	virtual void OperationImpl() = 0;
};



// ConcreteImplementorA ��� Ŭ����
class ConcreteImplementorA : public Implementor {
public:
	virtual void OperationImpl() override {
		std::cout << "ConcreteImplementorA" << std::endl;
	}
};


// ConcreteImplementorB ��� Ŭ����
class ConcreteImplementorB : public Implementor {
public:
	virtual void OperationImpl() override {
		std::cout << "ConcreteImplementorB" << std::endl;
	}
};




// Abstraction �������̽�
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