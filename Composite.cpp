#include <iostream>
#include <string>
#include <list>

/*
* ��ü�� ��ü�� �׷��� ���о��� �ϳ��� �������̽��� �ٷ� �� �ְ� �Ѵ�.
* ��ü(Leaf)�� ����(Comosite)�� Ʈ���� �����Ͽ� �ϳ��� �������̽����� ����ϵ��� ����� �����̴�.
*/

// Component �������̽�
class Component {
public:
	virtual void Operation() = 0;

	virtual void Add(Component* pComponent) {}
	virtual void Remove(Component* pComponent) {}

	virtual Component* GetChild(int i) { return 0; }
};


// Leaf ��� Ŭ����
class Leaf : public Component {
public:
	virtual void Operation() override {
		std::cout << "Leaf Operation" << std::endl;
	}
};


// Composite ��� Ŭ���� (��ü ����)
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