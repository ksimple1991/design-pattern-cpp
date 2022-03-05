#include <iostream>
#include <string>

enum class RequestType {
    REQ_HANDLER1,
    REQ_HANDLER2,
    REQ_HANDLER3
};

class Request {
public:
    Request(const std::string &desc, RequestType type) : _description(desc), _reqType(type) {}
    RequestType getRequestType() const { return _reqType; }
    const std::string& getDescription() const { return _description; }

private:
    std::string _description;
    RequestType _reqType;
};

// 抽象的处理者实现三个职责：
//  1. 定义一个请求的处理方法handleRequest，唯一对外开发的方法
//  2. 定义一个链的编排方法setNext
//  3. 定义具体的请求者必须实现的两个方法：
//     定义自己能够处理的级别canHandleRequest 和 具体的处理任务processRequest
class ChainHandler {
public:
    ChainHandler() {
        _nextChain = nullptr;
    }

    virtual ~ChainHandler() {}

    void setNextChain(ChainHandler *next) {
        _nextChain = next;
    }

    void handleRequest(const Request &req) {
        if (canHandleRequest(req)) {
            processRequest(req);
        } else {
            sendRequestToNextHandler(req);
        }
    }

protected:
    virtual bool canHandleRequest(const Request &req) = 0;
    virtual void processRequest(const Request &req) = 0;

private:
    void sendRequestToNextHandler(const Request &req) {
        if (_nextChain != nullptr) {
            _nextChain->handleRequest(req);
        }
    }

private:
    ChainHandler *_nextChain;
};

class ConcreteHandler1 : public ChainHandler {
protected:
    bool canHandleRequest(const Request &req) override {
        return req.getRequestType() == RequestType::REQ_HANDLER1;
    }

    void processRequest(const Request &req) override {
        std::cout << "ConcreteHandle1 is processing: "
            << req.getDescription() << std::endl;
    }
};

class ConcreteHandler2 : public ChainHandler {
protected:
    bool canHandleRequest(const Request &req) override {
        return req.getRequestType() == RequestType::REQ_HANDLER2;
    }

    void processRequest(const Request &req) override {
        std::cout << "ConcreteHandle2 is processing: "
            << req.getDescription() << std::endl;
    }
};

class ConcreteHandler3 : public ChainHandler {
protected:
    bool canHandleRequest(const Request &req) override {
        return req.getRequestType() == RequestType::REQ_HANDLER3;
    }

    void processRequest(const Request &req) override {
        std::cout << "ConcreteHandle3 is processing: "
            << req.getDescription() << std::endl;
    }
};

int main() {
    ConcreteHandler1 handler1;
    ConcreteHandler2 handler2;
    ConcreteHandler3 handler3;

    handler1.setNextChain(&handler2);
    handler2.setNextChain(&handler3);

    Request req1("request message 1", RequestType::REQ_HANDLER1);
    handler1.handleRequest(req1);

    Request req2("request message 2", RequestType::REQ_HANDLER2);
    handler1.handleRequest(req2);

    Request req3("request message 3", RequestType::REQ_HANDLER3);
    handler1.handleRequest(req3);

    return 0;
}
