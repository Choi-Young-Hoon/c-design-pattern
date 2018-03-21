#include <iostream>
#include <string>

/*
* ������Ʈ ���� (State Pattern)
* ��ü�� ���� ���°� �ٲ� ���� ��ü�� �ൿ�� �ٲ� �� �ִ�.
* ��ġ ��ü�� Ŭ������ �ٲ�� �Ͱ� ���� ����� ���� �� �ִ�.
*/

// State �������̽� Ŭ����
class State {
public:
	virtual void Handle() = 0;
};


// ConcreteState1 Ŭ����
class ConcreteState1 : public State {
public:
	virtual void Handle() override {
		std::cout << "ConcretState1" << std::endl;
	}
};


// ConcreteState2 Ŭ����
class ConcreteState2 : public State {
public:
	virtual void Handle() override {
		std::cout << "ConcretState2" << std::endl;
	}
};


// Context Ŭ����
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

	// State ��ȯ
	context.SetState(new ConcreteState2());
	context.Request();

	return 0;
}