#include <iostream>
#include <string>


/*
* 역할 사슬 패턴 (Chain Of Responsibility)
* 여러 개의 객체 중에서 어떤 것이 요구를 처리할 수 있는지를 사전에 알 수 없을 때 사용된다.
* 즉 요청 처리가 들어오고ㅔ 되면 그것을 수신하는 객체가 자신이 처리할 수 없는 경우에는 다음 객체에게 문제를 넘김으로써
* 최종적으로 요청을 처리할 수 있는 객체에 의해 처리가 가능하도록 하는 패턴이다
*/


// Handler 인터페이스 클래스
class Handler {
public:
	explicit Handler(Handler* pHandle)
		: m_pHandler(pHandle)
	{}


public:
	virtual void HandleRequest(int i) {
		if (m_pHandler != NULL) {
			m_pHandler->HandleRequest(i);
		}
	}


private:
	Handler* m_pHandler;
};



// ConcreteHandler1 상속 클래스
class ConcreteHandler1 : public Handler {
public:
	explicit ConcreteHandler1(Handler* pHandle)
		: Handler(pHandle)
	{}


public:
	virtual void HandleRequest(int i) override {
		if (i & 2 == 0) {
			std::cout << "짝수 입니다." << std::endl;
		}
		else {
			Handler::HandleRequest(i);
		}
	}
};



// ConcreateHandler2 상속 클래스
class ConcreteHandler2 : public Handler {
public:
	explicit ConcreteHandler2(Handler* pHandle)
		: Handler(pHandle)
	{}


public:
	virtual void HandleRequest(int i) override {
		if (i % 2 != 0) {
			std::cout << "홀수 입니다" << std::endl;
		}
		else {
			Handler::HandleRequest(i);
		}
	}
};




int main(void) {
	Handler* pHandler = new ConcreteHandler1(new ConcreteHandler2(NULL));

	pHandler->HandleRequest(25);

	delete pHandler;
	return 0;
}