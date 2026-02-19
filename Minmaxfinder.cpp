#include <iostream>
using namespace std;

void findMinAndMax(const int arr[], int size, int* min, int* max) {
    // we start from index 1 because min and max are already set to arr[0]
    for (int i = 1; i < size; i++) {
        // If current element is smaller than what min points to, update it
        if (arr[i] < *min) {
            *min = arr[i];
        }
        // If current element is larger than what max points to, update it
        if (arr[i] > *max) {
            *max = arr[i];
        }
    }
}

int main() {
    int numbers[] = {23, 5, 67, -2, 45, 87, 1, 99, 34, -10};
    int size = 10;

    //  both to the first element
    int min = numbers[0];
    int max = numbers[0];

    // we pass to the function
    findMinAndMax(numbers, size, &min, &max);

    cout << "The minimum value is: " << min << endl;
    cout << "The maximum value is: " << max << endl;

    return 0;
}
