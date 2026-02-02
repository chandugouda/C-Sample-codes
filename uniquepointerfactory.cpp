#include <iostream>
#include <memory>
using namespace std;

enum class LoggerType {
    Console,
    File,
    Network
};

class Logger {
public:
    virtual void log(const string& message) = 0;
    virtual ~Logger() = default;
};

class ConsoleLogger : public Logger {
public:
    void log(const string& message) override {
        cout << "Console log: " << message << endl;
    }
};

class FileLogger : public Logger {
public:
    void log(const string& message) override {
        cout << "File log: " << message << endl;
    }
};

class NetworkLogger : public Logger {
public:
    void log(const string& message) override {
        cout << "Network log: " << message << endl;
    }
};

class LoggerFactory {
public:
    unique_ptr<Logger> create(LoggerType type) {
        if (type == LoggerType::Console)
            return make_unique<ConsoleLogger>();
        else if (type == LoggerType::File)
            return make_unique<FileLogger>();
        else if (type == LoggerType::Network)
            return make_unique<NetworkLogger>();

        return nullptr;
    }
};

int main() {
    LoggerFactory factory;

    auto logger = factory.create(LoggerType::File);
    logger->log("System started");
}
