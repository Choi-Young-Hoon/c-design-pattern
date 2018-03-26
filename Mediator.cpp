#include <iostream>
#include <string>
#include <list>
#include <typeinfo>

/*
* ������ ���� (Mediator Pattern)
* ��� Ŭ�������� ������ ����(��ȣ�ۿ�)�� ĸ��ȭ�Ͽ� �ϳ��� Ŭ������ �����Ͽ� ó���ϴ� ����
* M:N ���迡�� M:1 ����� ���⵵�� ����߷� ���� ���� �� ������ Ȯ�强�� �����ϴ�.
*/


// Mediator �������̽�
class Colleague;	// ���� ����
class Mediator {
public:
	virtual void AddColleague(Colleague* pColleage) = 0;
	virtual void Mediate(std::string strMessage, Colleague* pSender) = 0;
};


// Colleague �������̽�
class Colleague {
public:
	explicit Colleague(Mediator* pMediator)
		: m_pMediator(pMediator)
	{}


public:
	void SendMessage(std::string strData) {
		m_pMediator->Mediate(strData, this);
		std::cout << "Message: " << strData << ", Sent by: " << GetName() << std::endl;
	}

	void ReceiveMessages(std::string strData) {
		std::cout << "Message: " << strData << ", Recv by: " << GetName() << std::endl;
	}

	virtual std::string GetName() = 0;


protected:
	Mediator* m_pMediator;
};



// ConcreteColleague1 ��� Ŭ����
class ConcreteColleague1 : public Colleague {
public:
	explicit ConcreteColleague1(Mediator* pMediator)
		: Colleague(pMediator)
	{}

	std::string GetName() {
		return typeid(this).name();
	}
};


// ConcreteColleague2 ��� Ŭ����
class ConcreteColleague2 : public Colleague {
public:
	explicit ConcreteColleague2(Mediator* pMediator)
		: Colleague(pMediator)
	{}

	std::string GetName() {
		return typeid(this).name();
	}
};


// ConcreteMediator ��� Ŭ����
class ConcreteMediator : public Mediator {
public:
	void AddColleague(Colleague* pColleague) {
		m_List.push_back(pColleague);
	}

	void Mediate(std::string strMessage, Colleague* pSender) {
		for (Colleague* object : m_List) {
			if (object != pSender) {
				object->ReceiveMessages(strMessage);
			}
		}
	}


private:
	std::list<Colleague*> m_List;
};



int main(void) {
	ConcreteMediator concreteMediator;

	ConcreteColleague1 concreteColleague1(&concreteMediator);
	ConcreteColleague2 concreteColleague2(&concreteMediator);

	concreteColleague1.SendMessage("First  Message...");
	concreteColleague2.SendMessage("Second Message...");
	return 0;
}