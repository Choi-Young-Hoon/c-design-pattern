#include <iostream>
#include <string>

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



// ========================================================== Car Part Ŭ����
// Engine Ŭ����
class Engine {
public:
	explicit Engine(int nMPH)
		:m_nMPH(nMPH)
	{}


public: // Function
	int GetMPH() { return m_nMPH; }


private:
	int m_nMPH;	// ���� ����
};


// Wheel Ŭ����
class Wheel {
public:
	explicit Wheel(int nSize)
		: m_nSize(nSize)
	{}


public: // Function
	int GetSize() const { return m_nSize; }


private:
	int m_nSize;	// �� ������.
};



// Body Ŭ����
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



// ==========================================================  Product Ŭ����

// Car Ŭ����
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
		std::cout << "���� ȸ��: " << m_strManufactuer << std::endl;
		std::cout << "���� ����: " << m_pEngine->GetMPH() << std::endl;
		std::cout << "�� ������: " << m_pWheel->GetSize() << std::endl;
		std::cout << "���� Ÿ��: " << m_pBody->GetShape() << std::endl;
	}


private:
	Engine* m_pEngine;
	Wheel*  m_pWheel;
	Body*   m_pBody;

	std::string m_strManufactuer;
};



// ========================================================== Builder �������̽�
class Builder {
public:
	virtual Engine* GetEngine() = 0;
	virtual Wheel*  GetWheel() = 0;
	virtual Body*   GetBody() = 0;
	virtual std::string GetManufacturer() = 0;
};


// Jeep Builder ��� Ŭ����
class JeepBuilder : public Builder {
public:
	virtual Engine* GetEngine() override { return new Engine(120); }
	virtual Wheel*  GetWheel() override { return new Wheel(20); }
	virtual Body*   GetBody() override { return new Body("SUV"); }
	virtual std::string GetManufacturer() override { return "Jeep"; }
};


// Ford Builder ��� Ŭ����
class FordBuilder : public Builder {
public:
	virtual Engine* GetEngine() override { return new Engine(150); }
	virtual Wheel*  GetWheel() override { return new Wheel(18); }
	virtual Body*   GetBody() override { return new Body("��ġ��"); }
	virtual std::string GetManufacturer() override { return "Ford"; }
};



// Director Ŭ����
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