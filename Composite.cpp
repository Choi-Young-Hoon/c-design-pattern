#include <iostream>
#include <string>
#include <list>

/*
* 객체와 객체의 그룹을 구분없이 하나의 인터페이스로 다룰 수 있게 한다.
* 객체(Leaf)와 구성(Comosite)을 트리로 구성하여 하나의 인터페이스에서 사용하도록 고려한 패턴이다.
*/

// Component 인터페이스
class Component {
public:
	virtual void Operation() = 0;

	virtual void Add(Component* pComponent) {}
	virtual void Remove(Component* pComponent) {}

	virtual Component* GetChild(int i) { return 0; }
};


// Leaf 상속 클래스
class Leaf : public Component {
public:
	virtual void Operation() override {
		std::cout << "Leaf Operation" << std::endl;
	}
};


// Composite 상속 클래스 (객체 관리)
class Composite : public Component {
public:
	virtual void Operation() override {
		for (auto& iter : m_List) {
			iter->Operation();
		}
	}

	virtual void Add(Component* pComponent) override {
		m_List.push_back(pComponent);
	}

	virtual void Remove(Component* pComponent) override {
		m_List.remove(pComponent);
	}

	virtual Component* GetChild(int nIndex) override {
		int nListIndex = 0;
		for (auto& iter : m_List) {
			if (nListIndex == nIndex) {
				return iter;
			}
			nListIndex++;
		}

		return NULL;
	}


private:
	std::list<Component*> m_List;
};



int main(void) {
	Leaf leafA,
		leafB;

	Composite composite;

	composite.Add(&leafA);
	composite.Add(&leafB);

	composite.Operation();
	return 0;
}