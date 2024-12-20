#include <iostream>
#include <vector>
#include <memory>
using namespace std;
class Detail {
protected:
    Detail() {
        cout << "Detail created" << endl;
    }

public:
    virtual void display() const = 0;
    virtual ~Detail() {}
};
class Assembly : public Detail {
protected:
    Assembly() {
        cout << "Assembly created" << endl;
    }

public:
    void display() const override {
        cout << "This is an assembly" << endl;
    }

    static shared_ptr<Assembly> create() {
        return shared_ptr<Assembly>(new Assembly());
    }
};
class SpecialDetail : public Detail {
protected:
    SpecialDetail() {
        cout << "The special detail created" << endl;
    }

public:
    void display() const override {
        cout << "This is a special detail" << endl;
    }

    static shared_ptr<SpecialDetail> create() {
        return shared_ptr<SpecialDetail>(new SpecialDetail());
    }
};

template<typename T>
void addDetail(vector<shared_ptr<Detail>>& storage) {
    storage.push_back(T::create());
}

int main() {
    vector<shared_ptr<Detail>> storage;

    addDetail<Assembly>(storage);
    addDetail<SpecialDetail>(storage);

    for (const auto& detail : storage) {
        detail->display();
    }

    return 0;
}
