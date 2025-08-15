#include <stdio.h>
#include <stdlib.h>

void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

double mean(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return (double)sum / n;
}

double median(int arr[], int n) {
    sortArray(arr, n);
    if (n % 2 == 0)
        return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    else
        return arr[n / 2];
}

void mode(int arr[], int n) {
    sortArray(arr, n);
    int maxCount = 0;
    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] == arr[i])
                count++;
            else
                break;
        }
        if (count > maxCount)
            maxCount = count;
    }

    printf("Mode(s): ");
    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] == arr[i])
                count++;
            else
                break;
        }
        if (count == maxCount) {
            printf("%d ", arr[i]);
        }
        i += count - 1;
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 3, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Mean: %.2f\n", mean(arr, n));
    printf("Median: %.2f\n", median(arr, n));
    mode(arr, n);

    return 0;
}
