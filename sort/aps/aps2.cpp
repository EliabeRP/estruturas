#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;


void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}


int hoarePartition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;

    while (true) {
        do { i++; } while (arr[i] < pivot);
        do { j--; } while (arr[j] > pivot);

        if (i >= j)
            return j;

        swap(arr[i], arr[j]);
    }
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int p = hoarePartition(arr, low, high);
        quickSort(arr, low, p);
        quickSort(arr, p + 1, high);
    }
}


void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (int t = 0; t < temp.size(); t++)
        arr[left + t] = temp[t];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}


double measure(void (*sortFunc)(vector<int>&), vector<int> arr) {
    auto start = high_resolution_clock::now();
    sortFunc(arr);
    auto stop = high_resolution_clock::now();

    return duration<double, micro>(stop - start).count();
}

int main() {

    vector<int> sizes = {1000, 5000, 10000};

    for (int n : sizes) {

        cout << "\n===== TAMANHO: " << n << " =====\n";

        // Aleatório uniforme
        vector<int> randomArr(n);
        mt19937 gen(42);
        uniform_int_distribution<> dist(0, n);
        for (int i = 0; i < n; i++)
            randomArr[i] = dist(gen);

        // Poucos valores únicos
        vector<int> fewUnique(n);
        uniform_int_distribution<> dist2(0, 10);
        for (int i = 0; i < n; i++)
            fewUnique[i] = dist2(gen);

        // Já ordenado
        vector<int> sortedArr(n);
        for (int i = 0; i < n; i++)
            sortedArr[i] = i;

        // Ordem inversa
        vector<int> reverseArr(n);
        for (int i = 0; i < n; i++)
            reverseArr[i] = n - i;

        vector<pair<string, vector<int>>> testCases = {
            {"Random", randomArr},
            {"FewUnique", fewUnique},
            {"Sorted", sortedArr},
            {"Reverse", reverseArr}
        };

        for (auto& test : testCases) {

            cout << "\nTipo: " << test.first << "\n";

            cout << "Insertion: "
                 << measure(insertionSort, test.second) << " µs\n";

            cout << "Selection: "
                 << measure(selectionSort, test.second) << " µs\n";

            auto quickWrapper = [](vector<int>& arr) {
                quickSort(arr, 0, arr.size() - 1);
            };
            cout << "Quick: "
                 << measure(quickWrapper, test.second) << " µs\n";

            auto mergeWrapper = [](vector<int>& arr) {
                mergeSort(arr, 0, arr.size() - 1);
            };
            cout << "Merge: "
                 << measure(mergeWrapper, test.second) << " µs\n";
        }
    }

    return 0;
}