#include <gtest/gtest.h>
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
    virtual std::string handle(const std::string& request) {
        if (next) {
            return next->handle(request);
        }
        return "unhandled";
    }
};

class TestHandler : public Handler {
public:
    std::string lastRequest;
    std::string handle(const std::string& request) override {
        lastRequest = request;
        if (request == "test") {
            return "handled_by_test";
        }
        return Handler::handle(request);
    }
};

TEST(ChainTest, HandleRequest) {
    auto h1 = std::make_shared<TestHandler>();
    auto h2 = std::make_shared<TestHandler>();
    h1->setNext(h2);
    
    std::string result = h1->handle("test");
    EXPECT_EQ(result, "handled_by_test");
    EXPECT_EQ(h1->lastRequest, "test");
}

TEST(ChainTest, PassToNext) {
    auto h1 = std::make_shared<TestHandler>();
    auto h2 = std::make_shared<TestHandler>();
    h1->setNext(h2);
    
    std::string result = h1->handle("other");
    EXPECT_EQ(result, "unhandled");
    EXPECT_EQ(h1->lastRequest, "other");
    EXPECT_EQ(h2->lastRequest, "other");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
