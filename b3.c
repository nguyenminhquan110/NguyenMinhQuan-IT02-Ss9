#include <stdio.h>

#define CAPACITY 100

int main() {
    int arr[CAPACITY];
    int currentLength = 0;
    int n;

    do {
        printf("Nhập số phần tử ban đầu (0-%d): ", CAPACITY);
        scanf("%d", &n);
        if (n < 0 || n > CAPACITY) {
            printf("Số lượng không hợp lệ. Vui lòng nhập lại.\n");
        }
    } while (n < 0 || n > CAPACITY);

    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    currentLength = n;

    int deleteIndex;
    printf("\nNhập vị trí cần xóa (0-%d): ", currentLength - 1);
    scanf("%d", &deleteIndex);

    if (deleteIndex < 0 || deleteIndex >= currentLength) {
        printf("Vị trí không hợp lệ. Kết thúc chương trình.\n");
        return 1;
    }

    for (int i = deleteIndex; i < currentLength - 1; i++) {
        arr[i] = arr[i + 1];
    }

    currentLength--;

    printf("\nMảng sau khi xóa phần tử tại vị trí %d:\n", deleteIndex);
    for (int i = 0; i < currentLength; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
