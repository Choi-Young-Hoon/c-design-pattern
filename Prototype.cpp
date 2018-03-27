#include <iostream>

/*
* ���� ���� (Prototype Pattern)
* �̸� ������� ��ü(object)�� �����Ͽ� ��ü�� �����ϴ� ����. (�ڱ� �ڽ��� �����Ͽ� ��ȯ)
* �ټ��� ��ü �����ÿ� �߻��Ǵ� ��ü�� ���� ����� ȿ�������� ���� �� �ִ�.
*/


// Prototype �������̽� Ŭ����
class Prototype {
public:
	virtual Prototype* Clone() = 0;
};



// ConcretePrototype1 Ŭ����
class ConcretePrototype1 : public Prototype {
public:
	explicit ConcretePrototype1()
	{}
	explicit ConcretePrototype1(const ConcretePrototype1& concrete)
	{}


public:
	virtual Prototype* Clone() override {
		return new ConcretePrototype1(*this);
	}
};


// ConcretePrototype2 Ŭ����
class ConcretePrototype2 : public Prototype {
public:
	explicit ConcretePrototype2()
	{}
	explicit ConcretePrototype2(const ConcretePrototype2& concrete)
	{}


public:
	virtual Prototype* Clone() override {
		return new ConcretePrototype2(*this);
	}
};



int main(void) {
	Prototype* pOriginal = new ConcretePrototype1();

	Prototype* pClone = pOriginal->Clone();

	delete pOriginal;
	delete pClone;

	return 0;
}