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
* 아래처럼 구현이 가능하나 해당 예제에서는
* 추상 클래스로 구현하기로 한다.
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


// 상위 Strategy 객체에 현재 컨텍스트에서 필요한 객체를 할당한다.
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