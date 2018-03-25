#include <iostream>
#include <string>

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



// ========================================================== Car Part 클래스
// Engine 클래스
class Engine {
public:
	explicit Engine(int nMPH)
		:m_nMPH(nMPH)
	{}


public: // Function
	int GetMPH() { return m_nMPH; }


private:
	int m_nMPH;	// 엔진 마력
};


// Wheel 클래스
class Wheel {
public:
	explicit Wheel(int nSize)
		: m_nSize(nSize)
	{}


public: // Function
	int GetSize() const { return m_nSize; }


private:
	int m_nSize;	// 휠 사이즈.
};



// Body 클래스
class Body {
public:
	explicit Body(std::string strShape)
		: m_strShape(strShape)
	{}


public: // Function
	std::string GetShape() const { return m_strShape; }


private:
	std::string m_strShape;
};



// ==========================================================  Product 클래스

// Car 클래스
class Car {
public:
	explicit Car()
		: m_pEngine(NULL), m_pWheel(NULL), m_pBody(NULL)
	{}

	virtual ~Car() {
		if (m_pEngine != NULL) {
			delete m_pEngine;
		}

		if (m_pWheel != NULL) {
			delete m_pWheel;
		}

		if (m_pBody != NULL) {
			delete m_pBody;
		}
	}


public:
	void SetEngine(Engine* pEngine) { m_pEngine = pEngine; }
	void SetWheel(Wheel* pWheel) { m_pWheel = pWheel; }
	void SetBody(Body* pBody) { m_pBody = pBody; }
	void SetManufacturer(std::string strM) { m_strManufactuer = strM; }

	void Print() const {
		std::cout << "제조 회사: " << m_strManufactuer << std::endl;
		std::cout << "엔진 마력: " << m_pEngine->GetMPH() << std::endl;
		std::cout << "휠 사이즈: " << m_pWheel->GetSize() << std::endl;
		std::cout << "외형 타입: " << m_pBody->GetShape() << std::endl;
	}


private:
	Engine* m_pEngine;
	Wheel*  m_pWheel;
	Body*   m_pBody;

	std::string m_strManufactuer;
};



// ========================================================== Builder 인터페이스
class Builder {
public:
	virtual Engine* GetEngine() = 0;
	virtual Wheel*  GetWheel() = 0;
	virtual Body*   GetBody() = 0;
	virtual std::string GetManufacturer() = 0;
};


// Jeep Builder 상속 클래스
class JeepBuilder : public Builder {
public:
	virtual Engine* GetEngine() override { return new Engine(120); }
	virtual Wheel*  GetWheel() override { return new Wheel(20); }
	virtual Body*   GetBody() override { return new Body("SUV"); }
	virtual std::string GetManufacturer() override { return "Jeep"; }
};


// Ford Builder 상속 클래스
class FordBuilder : public Builder {
public:
	virtual Engine* GetEngine() override { return new Engine(150); }
	virtual Wheel*  GetWheel() override { return new Wheel(18); }
	virtual Body*   GetBody() override { return new Body("해치백"); }
	virtual std::string GetManufacturer() override { return "Ford"; }
};



// Director 클래스
class Director {
public:
	explicit Director(Builder* pBuilder)
		: m_pBuilder(pBuilder)
	{}

	virtual ~Director() {
		if (m_pBuilder != NULL) {
			delete m_pBuilder;
		}
	}


public:
	Car* Construct() {
		Car* pCar = new Car();

		pCar->SetBody(m_pBuilder->GetBody());
		pCar->SetEngine(m_pBuilder->GetEngine());
		pCar->SetWheel(m_pBuilder->GetWheel());
		pCar->SetManufacturer(m_pBuilder->GetManufacturer());

		return pCar;
	}


private:
	Builder* m_pBuilder;
};




int main(void) {
	Director* pDirector = new Director(new FordBuilder());

	Car* pCar = pDirector->Construct();
	pCar->Print();

	delete pCar;
	delete pDirector;

	return 0;
}