#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

enum class Task {
    CustomerIssue,
    Programming,
    HardProgramming,
    MoneyIssue,
    M_And_A,
    ImpossibleTask
};

inline std::string GetNameOfTask(Task task) {
    switch (task) {
        case Task::CustomerIssue:   return "CustomerIssue";
        case Task::Programming:     return "Programming";
        case Task::HardProgramming: return "HardProgramming";
        case Task::MoneyIssue:      return "MoneyIssue";
        case Task::M_And_A:         return "M_And_A";
        case Task::ImpossibleTask:  return "ImpossibleTask";
        default: throw std::invalid_argument("");
    }
}

class Worker {
public:
    explicit Worker(Worker* successor) : successor_(successor) {}
    virtual ~Worker() = default;

    bool Work(Task task) {
        if (WorkImpl_(task)) return true;
        if (successor_) return successor_->Work(task);
        return false;
    }
private:
    virtual bool WorkImpl_(Task task) = 0;
    Worker* successor_;
};

class CustomerSupporter : public Worker {
public: using Worker::Worker;
private:
    bool WorkImpl_(Task task) override {
        if (task == Task::CustomerIssue) {
            std::cout << "[CustomerSupporter] Resolve customer issue.\n";
            return true;
        }
        return false;
    }
};

class SoftwareEngineer : public Worker {
public: 
    using Worker::Worker;
    void Train() { isTrained_ = true; }
private:
    bool WorkImpl_(Task task) override {
        if (task == Task::Programming) {
            std::cout << "[SoftwareEngineer] Programming.\n";
            return true;
        }
        if (task == Task::HardProgramming) {
            if (isTrained_) {
                std::cout << "[SoftwareEngineer] Successfully solve hard problem!\n";
                return true;
            }
                std::cout << "[SoftwareEngineer] Try to solve hard problem. But failed.\n";
            return false;
        }
        return false;
    }
    bool isTrained_{ false };
};

#ifndef RUNNING_TESTS
int main() {
    SoftwareEngineer se(nullptr);
    CustomerSupporter supporter(&se);
    supporter.Work(Task::CustomerIssue);
    supporter.Work(Task::Programming);
    return 0;
}
#endif
