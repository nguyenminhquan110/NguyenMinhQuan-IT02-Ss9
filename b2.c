#include <stdio.h>

#define SIZE 10

int main() {
    int arr[SIZE] = {5, 12, 7, 8, 20, 33, 15, 9, 0, 42};
    int index, newValue;

    printf("Mảng ban đầu:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Nhập vị trí muốn sửa (0-%d): ", SIZE - 1);
    scanf("%d", &index);

    if (index < 0 || index >= SIZE) {
        printf("Vị trí không hợp lệ.\n");
        return 1;
    }

    printf("Nhập giá trị mới: ");
    scanf("%d", &newValue);

    arr[index] = newValue;

    printf("Mảng sau khi sửa:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
