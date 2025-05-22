#include <stdio.h>
#include <math.h>

#define CAPACITY 100

int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int arr[CAPACITY];
    int currentLength = 0;
    int choice;

    do {
        printf("\n========== MENU ==========\n");
        printf("1. Nhập số phần tử và giá trị các phần tử\n");
        printf("2. In ra giá trị các phần tử đang quản lý\n");
        printf("3. In ra giá trị các phần tử chẵn và tính tổng\n");
        printf("4. In ra giá trị lớn nhất và nhỏ nhất trong mảng\n");
        printf("5. In ra các phần tử là số nguyên tố và tính tổng\n");
        printf("6. Nhập vào một số và thống kê số lượng phần tử đó\n");
        printf("7. Thêm một phần tử vào vị trí chỉ định\n");
        printf("8. Thoát\n");
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
                    printf("Các phần tử trong mảng:\n");
                    for (int i = 0; i < currentLength; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;
            }

            case 3: {
                int sum = 0;
                printf("Các phần tử chẵn: ");
                for (int i = 0; i < currentLength; i++) {
                    if (arr[i] % 2 == 0) {
                        printf("%d ", arr[i]);
                        sum += arr[i];
                    }
                }
                printf("\nTổng các phần tử chẵn: %d\n", sum);
                break;
            }

            case 4: {
                if (currentLength == 0) {
                    printf("Mảng rỗng.\n");
                    break;
                }
                int max = arr[0];
                int min = arr[0];
                for (int i = 1; i < currentLength; i++) {
                    if (arr[i] > max) max = arr[i];
                    if (arr[i] < min) min = arr[i];
                }
                printf("Giá trị lớn nhất: %d\n", max);
                printf("Giá trị nhỏ nhất: %d\n", min);
                break;
            }

            case 5: {
                int sum = 0;
                printf("Các số nguyên tố: ");
                for (int i = 0; i < currentLength; i++) {
                    if (isPrime(arr[i])) {
                        printf("%d ", arr[i]);
                        sum += arr[i];
                    }
                }
                printf("\nTổng các số nguyên tố: %d\n", sum);
                break;
            }

            case 6: {
                int x, count = 0;
                printf("Nhập số cần thống kê: ");
                scanf("%d", &x);
                for (int i = 0; i < currentLength; i++) {
                    if (arr[i] == x) {
                        count++;
                    }
                }
                printf("Số lần xuất hiện của %d là: %d\n", x, count);
                break;
            }

            case 7: {
                if (currentLength >= CAPACITY) {
                    printf("Mảng đã đầy, không thể thêm.\n");
                    break;
                }
                int value, index;
                printf("Nhập giá trị muốn thêm: ");
                scanf("%d", &value);
                printf("Nhập vị trí muốn thêm (0-%d): ", currentLength);
                scanf("%d", &index);
                if (index < 0 || index > currentLength) {
                    printf("Vị trí không hợp lệ.\n");
                    break;
                }
                for (int i = currentLength - 1; i >= index; i--) {
                    arr[i + 1] = arr[i];
                }
                arr[index] = value;
                currentLength++;
                printf("Đã thêm phần tử.\n");
                break;
            }

            case 8: {
                printf("Thoát chương trình.\n");
                break;
            }

            default: {
                printf("Lựa chọn không hợp lệ. Vui lòng thử lại.\n");
                break;
            }
        }

    } while (choice != 8);

    return 0;
}
