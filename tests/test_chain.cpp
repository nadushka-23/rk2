#define RUNNING_TESTS
#include "../src/worker.cpp"

void test_customer_supporter_can_handle_issue() {
    CustomerSupporter supporter(nullptr);
    // Проверяем: если дать саппорту задачу CustomerIssue, он должен вернуть true (справился)
    assert(supporter.Work(Task::CustomerIssue) == true);
    std::cout << "All tests passed successfully!" << std::endl;
}

int main() {
    test_customer_supporter_can_handle_issue();
    return 0;
}
