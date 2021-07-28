#include <iostream>
#include <vector>

class Component 
{
    public:
        Component() {}
        virtual ~Component() {}
        virtual void print(int) = 0;
};

class Composite : public Component
{
public:
    ~Composite() {}
    Composite() {}
    Composite(std::string id) : m_id(id) {}
    void add(Component *input){
        m_comp.push_back(input);
    }
    void print(int tap = 0) {
        for (int i = 0; i < tap; i++) printf("\t");
        printf("Composite : %s\n",m_id.c_str());

        for (auto dir : m_comp) {
            dir->print(tap + 1);
        }
    }

private:
    std::vector<Component*> m_comp;
    std::string m_id;
};

class Leaf : public Component {
public:
    ~Leaf() {}
    Leaf() {}
    Leaf(std::string id) : m_id(id) {}
    void print(int tap = 0) {
        for(int i= 0; i < tap ; i++) printf("\t");
        printf("Leaf : %s\n",m_id.c_str());
    }
private:
    std::string m_id;
};

int main() {
    Composite *market = new Composite("Market");
    Composite *fruits = new Composite("Fruits");
    Composite *beef = new Composite("Beef");
    Composite *beverages = new Composite("Beverages");
    Leaf *specialties = new Leaf("Specialties");
    market->add(specialties);
   
    fruits->add(new Leaf("Grape"));
    fruits->add(new Leaf("Apple"));
    fruits->add(new Leaf("Melon"));
    market->add(fruits);

    beef->add(new Leaf("Pig"));
    beef->add(new Leaf("Cow"));
    beef->add(new Leaf("Duck"));
    market->add(beef);

    beverages->add(new Leaf("Coffee"));
    beverages->add(new Leaf("Tea"));
    beverages->add(new Leaf("Soft drink"));
    market->add(beverages);

    market->print();
    
    return 0;
}