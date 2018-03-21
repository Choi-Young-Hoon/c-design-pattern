#include <iostream>

/*
* ���Ͻ� ���� (Proxy Pattern)
* �븮�ڷν� ���� �ñ�� �� ���� ó���ϰ� �Ϸ�Ǹ� �� ����� �˷��ִ� ����
* ���Ͻ� ������ �� �˷��� ���δ� ���� Ƚ�� ����Ʈ �����Ͱ� �ִ�. (shared_ptr, weak_ptr)
*/

// Subject �������̽�
class Subject {
public:
	virtual void Request() = 0;
};


// RealSubject ��� Ŭ����
class RealSubject : public Subject {
public:
	virtual void Request() {
		std::cout << "Response by RealSubject" << std::endl;
	}
};


// Proxy ��� Ŭ����
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