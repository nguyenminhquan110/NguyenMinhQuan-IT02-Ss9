#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 100

int main() {
    int arr[CAPACITY];
    int currentLength = 0;
    int n;

    do {
        printf("Nhập số phần tử ban đầu (0-%d): ", CAPACITY);
        if (scanf("%d", &n) != 1) {
            printf("Giá trị không hợp lệ. Thoát.\n");
            return 1;
        }
        if (n < 0 || n > CAPACITY) {
            printf("Vui lòng nhập lại, số phần tử phải trong khoảng 0 đến %d.\n", CAPACITY);
        }
    } while (n < 0 || n > CAPACITY);

    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    currentLength = n;

    int addValue, addIndex;
    printf("\nNhập giá trị muốn thêm: ");
    scanf("%d", &addValue);
    printf("Nhập vị trí muốn thêm (0-%d): ", CAPACITY);
    scanf("%d", &addIndex);

    if (addIndex < 0 || addIndex > CAPACITY) {
        printf("Vị trí %d không hợp lệ. Chương trình kết thúc.\n", addIndex);
        return 1;
    }

    if (addIndex >= currentLength) {
        arr[addIndex] = addValue;
        currentLength = addIndex + 1;
        if (currentLength > CAPACITY) {
            currentLength = CAPACITY;
        }
    } else {
        if (currentLength == CAPACITY) {
            printf("Mảng đã đầy, không thể chèn thêm.\n");
            return 1;
        }
        for (int i = currentLength - 1; i >= addIndex; i--) {
            arr[i + 1] = arr[i];
        }
        arr[addIndex] = addValue;
        currentLength++;
    }

    printf("\nMảng sau khi chèn (%d phần tử):\n", currentLength);
    for (int i = 0; i < currentLength; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
