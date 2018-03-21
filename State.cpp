#include <iostream>
#include <string>

/*
* 스테이트 패턴 (State Pattern)
* 객체의 내부 상태가 바뀜에 따라서 객체의 행동을 바꿀 수 있다.
* 마치 객체의 클래스가 바뀌는 것과 같은 결과를 얻을 수 있다.
*/

// State 인터페이스 클래스
class State {
public:
	virtual void Handle() = 0;
};


// ConcreteState1 클래스
class ConcreteState1 : public State {
public:
	virtual void Handle() override {
		std::cout << "ConcretState1" << std::endl;
	}
};


// ConcreteState2 클래스
class ConcreteState2 : public State {
public:
	virtual void Handle() override {
		std::cout << "ConcretState2" << std::endl;
	}
};


// Context 클래스
class Context {
public:
	explicit Context(State* pState)
		: m_pState(pState)
	{}

	virtual ~Context() {
		if (m_pState != NULL) {
			delete m_pState;
		}
	}


public:
	void SetState(State* pState) {
		if (m_pState != NULL) {
			delete m_pState;
		}
		m_pState = pState;
	}

	void Request() {
		m_pState->Handle();
	}


private:
	State* m_pState;
};


int main(void) {
	Context context(new ConcreteState1());
	context.Request();

	// State 변환
	context.SetState(new ConcreteState2());
	context.Request();

	return 0;
}