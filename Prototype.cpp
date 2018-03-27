#include <iostream>

/*
* 원형 패턴 (Prototype Pattern)
* 미리 만들어진 개체(object)를 복사하여 객체를 생성하는 패턴. (자기 자신을 복사하여 반환)
* 다수의 객체 생성시에 발생되는 객체의 생성 비용을 효과적으로 줄일 수 있다.
*/


// Prototype 인터페이스 클래스
class Prototype {
public:
	virtual Prototype* Clone() = 0;
};



// ConcretePrototype1 클래스
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


// ConcretePrototype2 클래스
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