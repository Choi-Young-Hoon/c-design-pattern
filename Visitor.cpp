#include <iostream>


/*
* 방문자 패턴 (Visitor Pattern)
* 객체의 구조와 기능을 분리시키는 패턴
* 구조는 변하지 않으며 기능만을 따로 추가하거나 확장되어야 할 경우에 사용되는 패턴이다.
* 컴포지트 패턴(Composite Pattern)과 연동되어 사용되는 경우가 많다.
*/


// Visitor 인터페이스
class Visitor {
public:
	virtual void VisitElementA(Element* pElement) = 0;
	virtual void VisitElementB(Element* pElement) = 0;
};


// Element 인터페이스
class Element {
public:
	virtual void Accept(Visitor* pVisitor) = 0;
};


// ConcreteElementA 상속 클래스
class ConcreteElementA : public Element {
public:
	virtual void Accept(Visitor* pVisitor) override {
		pVisitor->VisitElementA(this);
	}
};


// ConcreteElementB 상속 클래스
class ConcreteElementB : public Element {
public:
	virtual void Accept(Visitor* pVisitor) override {
		pVisitor->VisitElementB(this);
	}
};


// ConcreteVisitor 상속 클래스
class ConcreteVisitor : public Visitor {
public:
	virtual void VisitElementA(Element* pElement) override {
		std::cout << "VisitElementA" << std::endl;
	}

	virtual void VisitElementB(Element* pElement) override {
		std::cout << "VisitElementB" << std::endl;
	}
};



int main(void) {
	ConcreteElementA concreteA;
	ConcreteElementB concreteB;

	ConcreteVisitor concreteVisitor;

	concreteA.Accept(&concreteVisitor);
	concreteB.Accept(&concreteVisitor);

	return 0;
}