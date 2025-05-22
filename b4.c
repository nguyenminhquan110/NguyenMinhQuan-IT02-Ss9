#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 100

int main() {
    int arr[CAPACITY];
    int currentLength = 0;
    int choice;

    do {
        printf("\n========== MENU ==========\n");
        printf("1. Nhập vào mảng\n");
        printf("2. Hiển thị mảng\n");
        printf("3. Thêm phần tử\n");
        printf("4. Sửa phần tử\n");
        printf("5. Xóa phần tử\n");
        printf("6. Thoát\n");
        printf("Lựa chọn của bạn: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int n;
                do {
                    printf("Nhập số phần tử (0-%d): ", CAPACITY);
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
                break;
            }

            case 2: {
                if (currentLength == 0) {
                    printf("Mảng rỗng.\n");
                } else {
                    printf("Mảng hiện tại:\n");
                    for (int i = 0; i < currentLength; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;
            }

            case 3: {
                if (currentLength >= CAPACITY) {
                    printf("Mảng đã đầy, không thể thêm.\n");
                    break;
                }
                int addValue, addIndex;
                printf("Nhập giá trị muốn thêm: ");
                scanf("%d", &addValue);
                printf("Nhập vị trí muốn thêm (0-%d): ", currentLength);
                scanf("%d", &addIndex);

                if (addIndex < 0 || addIndex > currentLength) {
                    printf("Vị trí không hợp lệ.\n");
                    break;
                }

                for (int i = currentLength - 1; i >= addIndex; i--) {
                    arr[i + 1] = arr[i];
                }
                arr[addIndex] = addValue;
                currentLength++;
                printf("Đã thêm phần tử.\n");
                break;
            }

            case 4: {
                int index, newValue;
                if (currentLength == 0) {
                    printf("Mảng rỗng. Không thể sửa.\n");
                    break;
                }
                printf("Nhập vị trí muốn sửa (0-%d): ", currentLength - 1);
                scanf("%d", &index);
                if (index < 0 || index >= currentLength) {
                    printf("Vị trí không hợp lệ.\n");
                    break;
                }
                printf("Nhập giá trị mới: ");
                scanf("%d", &newValue);
                arr[index] = newValue;
                printf("Đã sửa phần tử.\n");
                break;
            }

            case 5: {
                int deleteIndex;
                if (currentLength == 0) {
                    printf("Mảng rỗng. Không thể xóa.\n");
                    break;
                }
                printf("Nhập vị trí muốn xóa (0-%d): ", currentLength - 1);
                scanf("%d", &deleteIndex);
                if (deleteIndex < 0 || deleteIndex >= currentLength) {
                    printf("Vị trí không hợp lệ.\n");
                    break;
                }
                for (int i = deleteIndex; i < currentLength - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                currentLength--;
                printf("Đã xóa phần tử.\n");
                break;
            }

            case 6: {
                printf("Thoát chương trình.\n");
                break;
            }

            default: {
                printf("Lựa chọn không hợp lệ. Vui lòng thử lại.\n");
            }
        }

    } while (choice != 6);

    return 0;
}
