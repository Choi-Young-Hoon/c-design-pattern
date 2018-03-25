#include <iostream>
#include <string>


/*
* ���� �罽 ���� (Chain Of Responsibility)
* ���� ���� ��ü �߿��� � ���� �䱸�� ó���� �� �ִ����� ������ �� �� ���� �� ���ȴ�.
* �� ��û ó���� ������� �Ǹ� �װ��� �����ϴ� ��ü�� �ڽ��� ó���� �� ���� ��쿡�� ���� ��ü���� ������ �ѱ����ν�
* ���������� ��û�� ó���� �� �ִ� ��ü�� ���� ó���� �����ϵ��� �ϴ� �����̴�
*/


// Handler �������̽� Ŭ����
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



// ConcreteHandler1 ��� Ŭ����
class ConcreteHandler1 : public Handler {
public:
	explicit ConcreteHandler1(Handler* pHandle)
		: Handler(pHandle)
	{}


public:
	virtual void HandleRequest(int i) override {
		if (i & 2 == 0) {
			std::cout << "¦�� �Դϴ�." << std::endl;
		}
		else {
			Handler::HandleRequest(i);
		}
	}
};



// ConcreateHandler2 ��� Ŭ����
class ConcreteHandler2 : public Handler {
public:
	explicit ConcreteHandler2(Handler* pHandle)
		: Handler(pHandle)
	{}


public:
	virtual void HandleRequest(int i) override {
		if (i % 2 != 0) {
			std::cout << "Ȧ�� �Դϴ�" << std::endl;
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