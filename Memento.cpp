#include <iostream>
#include <string>
#include <stack>

/*
* 객체의 상태 정보를 저장 및 복원(Rollback)하는 패턴
* 객체의 내부 상태정보만 가지는 클래스를 따로 생성하여 관리하는 구조로써, 저장할 상태정보가 많을 경우 문제가 될 수 있다.
* 대표적인 예로 바둑, 장기 등 기보 되돌리기, 바둑이 물리기 기능 등을 꼽을 수 있다.
*/



// Memento 클래스
class Memento {
public:
	explicit Memento(std::string strState)
	{}


public:
	std::string GetState() { return m_strState; }


private:
	std::string m_strState;
};



// Originator 클래스
class Originator {
public:
	void SetState(std::string strState) {
		m_strState = strState;
		std::cout << "Originator: Setting state to " << m_strState << std::endl;
	}


public:
	void SetMemento(Memento* pMemento) {
		if (pMemento != NULL) {
			delete pMemento;
			std::cout << "Originator: State after restoring from Memento " << std::endl;
		}
		m_strState = pMemento->GetState();
	}


	Memento* CreateMemento() {
		std::cout << "Originator: Create to Memento " << m_strState << std::endl;
		return new Memento(m_strState);
	}


private:
	std::string m_strState;
};



// Caretaker 클래스
class Caretaker {
public:
	void PushMemento(Memento* pMemento) {
		m_Stack.push(pMemento);
	}


	Memento* PopMemento() {
		Memento* pMemento = m_Stack.top();
		m_Stack.pop();
		return pMemento;
	}


private:
	std::stack<Memento*> m_Stack;
};



int main(void) {
	Caretaker careTaker;

	Originator* pOriginator = new Originator();

	pOriginator->SetState("state1");
	careTaker.PushMemento(pOriginator->CreateMemento());

	pOriginator->SetState("state2");
	careTaker.PushMemento(pOriginator->CreateMemento());

	pOriginator->SetMemento(careTaker.PopMemento());
	pOriginator->SetMemento(careTaker.PopMemento());

	delete pOriginator;

	return 0;
}