#include <iostream>
#include <string>
#include <queue>
#include <ctime>

using namespace std;

struct PrintRequest {
    string clientName;
    string documentName;
    int priority;
};

struct PrintLog {
    string clientName;
    time_t startTime;
    time_t endTime;
};

bool operator<(const PrintRequest& left, const PrintRequest& right) {
    return left.priority < right.priority;
}

int main() {
    queue<PrintRequest> printQueue;
    queue<PrintLog> printLog;

    while (true) {
        cout << "Enter client name (or 'exit' to quit): ";
        string clientName;
        cin >> clientName;
        if (clientName == "exit") {
            break;
        }

        cout << "Enter document name: ";
        string documentName;
        cin >> documentName;

        cout << "Enter priority (0 - low, 1 - medium, 2 - high): ";
        int priority;
        cin >> priority;

        PrintRequest printRequest = { clientName, documentName, priority };
        printQueue.push(printRequest);

        time_t startTime = time(nullptr);
        while (!printQueue.empty()) {
            PrintRequest& request = printQueue.front();
            if (request.priority > priority) {
                break;
            }
            cout << "Printing document '" << request.documentName << "' for client '" << request.clientName << "'" << endl;
            time_t endTime = time(nullptr);
            PrintLog printEntry = { request.clientName, startTime, endTime };
            printLog.push(printEntry);
            printQueue.pop();
            startTime = endTime;
        }
    }

    cout << endl << "Printing log:" << endl;
    while (!printLog.empty()) {
        PrintLog& logEntry = printLog.front();
        cout << logEntry.clientName << ": " << difftime(logEntry.endTime, logEntry.startTime) << " seconds" << endl;
        printLog.pop();
    }

    return 0;
}
