#include <iostream>
#include <memory>
#include <string>

class Handler {
protected:
    std::shared_ptr<Handler> next;
public:
    virtual ~Handler() = default;
    void setNext(std::shared_ptr<Handler> handler) {
        next = handler;
    }
    virtual void handle(const std::string& request) {
        if (next) {
            next->handle(request);
        }
    }
};

class ConcreteHandler1 : public Handler {
public:
    void handle(const std::string& request) override {
        if (request == "level1") {
            std::cout << "ConcreteHandler1 обработал: " << request << std::endl;
        } else {
            std::cout << "ConcreteHandler1 передал дальше" << std::endl;
            Handler::handle(request);
        }
    }
};

class ConcreteHandler2 : public Handler {
public:
    void handle(const std::string& request) override {
        if (request == "level2") {
            std::cout << "ConcreteHandler2 обработал: " << request << std::endl;
        } else {
            std::cout << "ConcreteHandler2 передал дальше" << std::endl;
            Handler::handle(request);
        }
    }
};

int main() {
    auto h1 = std::make_shared<ConcreteHandler1>();
    auto h2 = std::make_shared<ConcreteHandler2>();
    h1->setNext(h2);
    
    std::cout << "=== Тест Chain of Responsibility ===" << std::endl;
    h1->handle("level1");
    h1->handle("level2");
    h1->handle("unknown");
    
    return 0;
}
