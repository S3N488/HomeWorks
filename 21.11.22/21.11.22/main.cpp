#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 100; // ������ �������
const int M = 10; // ������ ������� ������������������

int findMinSequence(int arr[], int start) {
    if (start > N - M) {
        return start - 1;
    }

    int sum = 0; // ����� ������ 10 ���������
    for (int i = start; i < start + M; i++) {
        sum += arr[i];
    }

    // ����������� ������ - ���������� ������� ����� � ����� ������� �� ���������� ��������
    int nextStart = findMinSequence(arr, start + 1);
    int nextSum = 0; // ����� ��������� 10 ���������
    for (int i = nextStart; i < nextStart + M; i++) {
        nextSum += arr[i];
    }

    return sum <= nextSum ? start : nextStart;
}

int main() {
    int arr[N];
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 100; // ��������� ������ ���������� �������
    }

    int start = findMinSequence(arr, 0);
    cout << "Start position: " << start << endl;

    return 0;
}
