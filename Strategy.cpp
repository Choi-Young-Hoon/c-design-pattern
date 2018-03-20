#include <iostream>

class Strategy {
public:
	virtual void Run() = 0;
};


class ConcreteStrategyA : public Strategy {
public:
	virtual void Run() override {
		std::cout << "ConcreteStrategyA" << std::endl;
	}
};


class ConcreteStrategyB : public Strategy {
public:
	virtual void Run() override {
		std::cout << "ConcreteStrategyB" << std::endl;
	}
};

/*
* �Ʒ�ó�� ������ �����ϳ� �ش� ����������
* �߻� Ŭ������ �����ϱ�� �Ѵ�.
*
class Context {
public:
	void SetStrategy(Strategy * stg) {
		this->stg = stg;
	}
	void Run() {
		stg->Run();
	}
private:
	Strategy * stg;
};
*/


class Context {
public:
	explicit Context() : stg(NULL)
	{}

	virtual ~Context()
	{}

public: // Function
	virtual void Run() {
		stg->Run();
	}

protected:
	Strategy * stg;
};


// ���� Strategy ��ü�� ���� ���ؽ�Ʈ���� �ʿ��� ��ü�� �Ҵ��Ѵ�.
class ContextA : public Context {
public:
	explicit ContextA() {
		stg = new ConcreteStrategyA();
	}

	virtual ~ContextA() {
		delete stg;
	}
};


class ContextB : public Context {
public:
	explicit ContextB() {
		stg = new ConcreteStrategyB();
	}

	virtual ~ContextB() {
		delete stg;
	}
};




int main(void) {
	ContextA con_a;
	ContextB con_b;

	con_a.Run();
	return 0;
}