#include <iostream>

/*
* 프록시 패턴 (Proxy Pattern)
* 대리자로써 일을 맡기면 그 일을 처리하고 완료되면 그 결과를 알려주는 패턴
* 프록시 패턴의 잘 알려진 예로는 참조 횟수 스마트 포인터가 있다. (shared_ptr, weak_ptr)
*/

// Subject 인터페이스
class Subject {
public:
	virtual void Request() = 0;
};


// RealSubject 상속 클래스
class RealSubject : public Subject {
public:
	virtual void Request() {
		std::cout << "Response by RealSubject" << std::endl;
	}
};


// Proxy 상속 클래스
class Proxy : public Subject {
public:
	explicit Proxy()
		: m_pRealSubject(NULL)
	{}

	virtual ~Proxy() {
		if (m_pRealSubject != NULL) {
			delete m_pRealSubject;
		}
	}


public: // Function
	void Request() {
		if (m_pRealSubject == NULL) {
			m_pRealSubject = new RealSubject();
		}
		m_pRealSubject->Request();
	}


private:
	RealSubject* m_pRealSubject;
};


int main(void) {
	Subject* pProxy = new Proxy();

	pProxy->Request();

	delete pProxy;
	return 0;
}