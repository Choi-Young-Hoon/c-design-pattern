#include <iostream>
#include <map>


/*
* �ö��� ����Ʈ ���� (Fly weight pattern)
* � Ŭ������ �ν��Ͻ� �� ���������� ���� ���� "���� �ν��Ͻ�"�� �����ϰ� ���� �� Ȥ��
* �����͸� ���� ����Ͽ� �޸𸮸� ������ �� �ִ� �����̴�.
* �ѹ� ������ ��ü�� �ι� �������� �ʰ� Pool �� ���ؼ� ���� �� ���ȴ�.
*/


// Flyweight Ŭ����
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


// UnsharedConcreateFlyweight Ŭ����
class UnsharedConcreateFlyweight : public Flyweight {
public:
	virtual void Operation() override {
		std::cout << "UnsharedConcreateFlyweight" << std::endl;
	}
};


// FlyweightFactory Ŭ����
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