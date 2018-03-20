#include <iostream>

/*
* 싱글턴 (Singleton pattern)
* 한개의 객체만 생성되도록 한다.
*/

class Singleton {
public:
	virtual ~Singleton()
	{}


private:
	explicit Singleton()
		: m_nValue(0)
	{}


public:
	static Singleton* GetInstance() {
		if (g_Instance == NULL) {
			g_Instance = new Singleton();
		}
		return g_Instance;
	}
	static void DestroyInstance() {
		if (g_Instance != NULL) {
			delete g_Instance;
		}
		g_Instance = NULL;
	}


public: // Member value  Getter, Setter 
	void SetValue(int nValue) { m_nValue = nValue; }
	int  GetValue() { return m_nValue; }


private:
	static Singleton* g_Instance;


private:
	int m_nValue;
};

Singleton* Singleton::g_Instance = NULL;


// Test
int main(int argc, char* argv[]) {
	Singleton* pSingle1 = Singleton::GetInstance();
	Singleton* pSingle2 = Singleton::GetInstance();

	pSingle1->SetValue(100);
	pSingle2->SetValue(200);
	std::cout << "pSingle1 Value: " << pSingle1->GetValue() << std::endl;
	std::cout << "pSingle2 Value: " << pSingle2->GetValue() << std::endl;
	Singleton::DestroyInstance();
	return 0;
}