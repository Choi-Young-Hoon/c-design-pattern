#include <iostream>
#include <string>
#include <stack>

/*
* ��ü�� ���� ������ ���� �� ����(Rollback)�ϴ� ����
* ��ü�� ���� ���������� ������ Ŭ������ ���� �����Ͽ� �����ϴ� �����ν�, ������ ���������� ���� ��� ������ �� �� �ִ�.
* ��ǥ���� ���� �ٵ�, ��� �� �⺸ �ǵ�����, �ٵ��� ������ ��� ���� ���� �� �ִ�.
*/



// Memento Ŭ����
class Memento {
public:
	explicit Memento(std::string strState)
	{}


public:
	std::string GetState() { return m_strState; }


private:
	std::string m_strState;
};



// Originator Ŭ����
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



// Caretaker Ŭ����
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