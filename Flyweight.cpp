#include <iostream>
#include <map>


/*
* 플라이 웨이트 패턴 (Fly weight pattern)
* 어떤 클래스의 인스턴스 한 개만가지고 여러 개의 "가상 인스턴스"를 제공하고 싶을 떄 혹은
* 데이터를 공유 사용하여 메모리를 절약할 수 있는 패턴이다.
* 한번 생성된 객체는 두번 생성되지 않고 Pool 에 의해서 관리 및 사용된다.
*/


// Flyweight 클래스
class Flyweight {
public:
	virtual void Operation() = 0;
};


// ConcreateFlyeight 
class ConcreteFlyweight : public Flyweight {
public:
	virtual void Operation() override {
		std::cout << "Concreate Fly weight" << std::endl;
	}
};


// UnsharedConcreateFlyweight 클래스
class UnsharedConcreateFlyweight : public Flyweight {
public:
	virtual void Operation() override {
		std::cout << "UnsharedConcreateFlyweight" << std::endl;
	}
};


// FlyweightFactory 클래스
class FlyweightFactory {
public:
	explicit FlyweightFactory() {
		m_List[0] = new ConcreteFlyweight();
		m_List[1] = new UnsharedConcreateFlyweight();
	}
	virtual ~FlyweightFactory()
	{}


public:
	Flyweight* GetFlyweight(int nKey) {
		if (m_List.find(nKey) == m_List.end()) {
			m_List[nKey] = new ConcreteFlyweight();
		}

		return m_List[nKey];
	}


private:
	std::map<int, Flyweight*> m_List;
};




int main(void) {
	FlyweightFactory flyFactory;


	Flyweight* pFlyweight;

	pFlyweight = flyFactory.GetFlyweight(0);
	pFlyweight->Operation();
	delete pFlyweight;

	pFlyweight = flyFactory.GetFlyweight(1);
	pFlyweight->Operation();
	delete pFlyweight;

	return 0;
}