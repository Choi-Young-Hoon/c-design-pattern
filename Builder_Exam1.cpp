#include <iostream>


/*
* 빌더 패턴 (Builder Pattern)
* 복합 객체의 생성 과정과 표현 방법을 분리하여 동일한 생성 절차에서 서로 다른 표현 결과를 만들 수 있게 하는 패턴이다.
*
* 쉽게 말해서 하나의 객체를 생성할 때 객체를 이루는 구성 요소들을 분리하여 객체의 세부 구성요소
* 클래스들을 별도로 만들고 그 구성 요소 클래스들을 조합하여 하나의 객체를 만드는 것이다.
*
* 자동차를 만든다고 한다면 자동차의 부품들을 모아서 하나의 자동차를 만드는 것을 예로 들 수 있다.
*
* (제품을 여러 단계로 나눠서 만들 수 있도록 제품 생산 단계들을 캡슐화할 떄 사용)
*/



// Product 클래스
class Product
{};


// Builder 클래스
class Builder {
public:
	virtual Product* GetResult() = 0;
	virtual void     BuildPart() = 0;
};


// ConcreteBuilder 상속 클래스
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



// Director 클래스
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