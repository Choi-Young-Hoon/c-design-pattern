#include <iostream>


/*
* ���� ���� (Builder Pattern)
* ���� ��ü�� ���� ������ ǥ�� ����� �и��Ͽ� ������ ���� �������� ���� �ٸ� ǥ�� ����� ���� �� �ְ� �ϴ� �����̴�.
*
* ���� ���ؼ� �ϳ��� ��ü�� ������ �� ��ü�� �̷�� ���� ��ҵ��� �и��Ͽ� ��ü�� ���� �������
* Ŭ�������� ������ ����� �� ���� ��� Ŭ�������� �����Ͽ� �ϳ��� ��ü�� ����� ���̴�.
*
* �ڵ����� ����ٰ� �Ѵٸ� �ڵ����� ��ǰ���� ��Ƽ� �ϳ��� �ڵ����� ����� ���� ���� �� �� �ִ�.
*
* (��ǰ�� ���� �ܰ�� ������ ���� �� �ֵ��� ��ǰ ���� �ܰ���� ĸ��ȭ�� �� ���)
*/



// Product Ŭ����
class Product
{};


// Builder Ŭ����
class Builder {
public:
	virtual Product* GetResult() = 0;
	virtual void     BuildPart() = 0;
};


// ConcreteBuilder ��� Ŭ����
class ConcreteBuilder : public Builder {
public:
	virtual Product* GetResult() override {
		return m_pProduct;
	}

	virtual void BuildPart() override {
		m_pProduct = new Product();
	}


private:
	Product* m_pProduct;
};



// Director Ŭ����
class Director {
public:
	explicit Director(Builder* pBuilder)
		: m_pBuilder(pBuilder)
	{}
	virtual ~Director()
	{}


public:
	Product* Construct() {
		m_pBuilder->BuildPart();
		return m_pBuilder->GetResult();
	}


private:
	Builder* m_pBuilder;
};



int main(void) {
	Director* pDirector = new Director(new ConcreteBuilder());
	Product*  pProduct = pDirector->Construct();

	delete pProduct;
	delete pDirector;

	return 0;
}