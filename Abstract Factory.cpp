#include <iostream>

/*
 * 추상 팩토리 패턴
 * 많은 수의 연관된 서브 클래스를 특정 그룹으로 묶어 한번에 교체할 수 있도록 만든 디자인 패턴이다.
 *
 * 예를 들어 특정 라이브러리를 배포하는데 OS 별로 지원한느 기능이 상이하다면 추상 팩토리 패턴을 사용해 OS 별 기능 변경을 통합적으로 변경할 수 있다.\
 */

class MachineA {
public:
	explicit MachineA()
	{}
	virtual ~MachineA()
	{}


public: // Interface
	virtual void Process() = 0;
};


class MachineA1 : public MachineA {
public:
	explicit MachineA1()
	{}
	virtual ~MachineA1()
	{}


public: // Interface
	virtual void Process() override {
		std::cout << "Execute MachineA_1" << std::endl;
	}
};


class MachineA2 : public MachineA {
public:
	explicit MachineA2()
	{}
	virtual ~MachineA2()
	{}


public: // Interface
	virtual void Process() override {
		std::cout << "Excute MachineA_2" << std::endl;
	}
};








class MachineB {
public:
	explicit MachineB()
	{}
	virtual ~MachineB()
	{}


public: // Interface
	virtual void Process() = 0;
};


class MachineB1 : public MachineB {
public:
	explicit MachineB1()
	{}
	virtual ~MachineB1()
	{}

public: // Interface
	virtual void Process() override {
		std::cout << "Execute MachineB_1" << std::endl;
	}
};


class MachineB2 : public MachineB {
public:
	explicit MachineB2()
	{}
	virtual ~MachineB2()
	{}


public: // Interface
	virtual void Process() override {
		std::cout << "Execute MachineB_2" << std::endl;
	}
};






class MachineFactory {
public:
	explicit MachineFactory()
	{}
	virtual ~MachineFactory()
	{}


public: // Interface
	virtual MachineA* GetMachineA() = 0;
	virtual MachineB* GetMachineB() = 0;
};


class MachineFactory1 : public MachineFactory {
public:
	explicit MachineFactory1()
	{}
	virtual ~MachineFactory1()
	{}


public: // Interface
	virtual MachineA* GetMachineA() override {
		return new MachineA1();
	}

	virtual MachineB* GetMachineB() override {
		return new MachineB1();
	}
};


class MachineFactory2 : public MachineFactory {
public:
	explicit MachineFactory2()
	{}
	virtual ~MachineFactory2()
	{}


public: // Interface
	virtual MachineA* GetMachineA() override {
		return new MachineA2();
	}

	virtual MachineB* GetMachineB() override {
		return new MachineB2();
	}
};




int main(int argc, char* argv[]) {
	MachineA* pMachineA = NULL;
	MachineB* pMachineB = NULL;

	// =================================================== MachineFactory1
	MachineFactory* pFactory1 = new MachineFactory1();
	pMachineA = pFactory1->GetMachineA();
	pMachineB = pFactory1->GetMachineB();
	pMachineA->Process();
	pMachineB->Process();

	delete pFactory1;
	delete pMachineA;
	delete pMachineB;


	// =================================================== MachineFactory2
	MachineFactory* pFactory2 = new MachineFactory2();
	pMachineA = pFactory2->GetMachineA();
	pMachineB = pFactory2->GetMachineB();
	pMachineA->Process();
	pMachineB->Process();

	delete pFactory1;
	delete pMachineA;
	delete pMachineB;

	return 0;
}