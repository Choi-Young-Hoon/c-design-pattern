#include <iostream>


/*
* �湮�� ���� (Visitor Pattern)
* ��ü�� ������ ����� �и���Ű�� ����
* ������ ������ ������ ��ɸ��� ���� �߰��ϰų� Ȯ��Ǿ�� �� ��쿡 ���Ǵ� �����̴�.
* ������Ʈ ����(Composite Pattern)�� �����Ǿ� ���Ǵ� ��찡 ����.
*/


// Visitor �������̽�
class Visitor {
public:
	virtual void VisitElementA(Element* pElement) = 0;
	virtual void VisitElementB(Element* pElement) = 0;
};


// Element �������̽�
class Element {
public:
	virtual void Accept(Visitor* pVisitor) = 0;
};


// ConcreteElementA ��� Ŭ����
class ConcreteElementA : public Element {
public:
	virtual void Accept(Visitor* pVisitor) override {
		pVisitor->VisitElementA(this);
	}
};


// ConcreteElementB ��� Ŭ����
class ConcreteElementB : public Element {
public:
	virtual void Accept(Visitor* pVisitor) override {
		pVisitor->VisitElementB(this);
	}
};


// ConcreteVisitor ��� Ŭ����
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