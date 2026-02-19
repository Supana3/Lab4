#include <iostream>
#include <iomanip>
using namespace std;

// this asks the user to enter each score one by one
void getScores(double* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter score " << (i + 1) << ": ";
        cin >> arr[i];

        // making sure they dont enter a negative score
        while (arr[i] < 0) {
            cout << "Score cannot be negative. Enter again: ";
            cin >> arr[i];
        }
    }
}

void sortScores(double* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            // if the current one is bigger than the next, swap them
            if (arr[j] > arr[j + 1]) {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// this adds up all the scores and divides by how many there are
double calculateAverage(const double* arr, int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

int main() {
    int numScores;

    // asking how many scores they want to enter
    cout << "How many test scores would you like to enter? ";
    cin >> numScores;

    // making sure they entered a positive number
    if (numScores <= 0) {
        cout << "Please enter a positive number. Exiting." << endl;
        return 1;
    }

    // creating an array based on what the user entered
    double* scores = new double[numScores];

    // getting all the scores from the user
    getScores(scores, numScores);

    // sorting them from lowest to highest
    sortScores(scores, numScores);

    // getting the average
    double avg = calculateAverage(scores, numScores);

    // printing the sorted scores with 2 decimal places
    cout << fixed << setprecision(2);
    cout << "\nThe sorted scores are: ";
    for (int i = 0; i < numScores; i++) {
        cout << scores[i] << " ";
    }
    cout << endl;

    // printing the average
    cout << "The average score is: " << avg << endl;

    // freeing the memory since we used new, and setting pointer to null
    delete[] scores;
    scores = nullptr;

    return 0;
}
