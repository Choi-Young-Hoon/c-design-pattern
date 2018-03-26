#include <iostream>
#include <string>
#include <list>
#include <typeinfo>

/*
* 중재자 패턴 (Mediator Pattern)
* 모든 클래스간의 복잡한 로직(상호작용)을 캡슐화하여 하나의 클래스에 위임하여 처리하는 패턴
* M:N 관계에서 M:1 관계로 복잡도를 떨어뜨려 유지 보수 및 재사용의 확장성에 유리하다.
*/


// Mediator 인터페이스
class Colleague;	// 전방 선언
class Mediator {
public:
	virtual void AddColleague(Colleague* pColleage) = 0;
	virtual void Mediate(std::string strMessage, Colleague* pSender) = 0;
};


// Colleague 인터페이스
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



// ConcreteColleague1 상속 클래스
class ConcreteColleague1 : public Colleague {
public:
	explicit ConcreteColleague1(Mediator* pMediator)
		: Colleague(pMediator)
	{}

	std::string GetName() {
		return typeid(this).name();
	}
};


// ConcreteColleague2 상속 클래스
class ConcreteColleague2 : public Colleague {
public:
	explicit ConcreteColleague2(Mediator* pMediator)
		: Colleague(pMediator)
	{}

	std::string GetName() {
		return typeid(this).name();
	}
};


// ConcreteMediator 상속 클래스
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