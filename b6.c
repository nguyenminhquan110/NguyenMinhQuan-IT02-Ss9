#include <stdio.h>

#define MAX 100

int main() {
    int a[MAX][MAX];
    int rows = 0, cols = 0;
    int choice;

    do {
        printf("\n========== MENU ==========\n");
        printf("1. Nhập kích cỡ và giá trị các phần tử của mảng\n");
        printf("2. In giá trị các phần tử của mảng theo ma trận\n");
        printf("3. In giá trị các phần tử là lẻ và tính tổng\n");
        printf("4. In ra các phần tử nằm trên đường biên và tính tích\n");
        printf("5. In ra các phần tử nằm trên đường chéo chính\n");
        printf("6. In ra các phần tử nằm trên đường chéo phụ\n");
        printf("7. In ra dòng có tổng giá trị các phần tử là lớn nhất\n");
        printf("8. Thoát\n");
        printf("Lựa chọn của bạn: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                do {
                    printf("Nhập số dòng: ");
                    scanf("%d", &rows);
                    printf("Nhập số cột: ");
                    scanf("%d", &cols);
                    if (rows <= 0 || cols <= 0 || rows > MAX || cols > MAX)
                        printf("Kích thước không hợp lệ. Nhập lại.\n");
                } while (rows <= 0 || cols <= 0 || rows > MAX || cols > MAX);

                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        printf("a[%d][%d] = ", i, j);
                        scanf("%d", &a[i][j]);
                    }
                }
                break;
            }

            case 2: {
                printf("Ma trận hiện tại:\n");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        printf("%5d", a[i][j]);
                    }
                    printf("\n");
                }
                break;
            }

            case 3: {
                int sum = 0;
                printf("Các phần tử lẻ trong mảng: ");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        if (a[i][j] % 2 != 0) {
                            printf("%d ", a[i][j]);
                            sum += a[i][j];
                        }
                    }
                }
                printf("\nTổng các phần tử lẻ: %d\n", sum);
                break;
            }

            case 4: {
                long long product = 1;
                printf("Các phần tử trên đường biên: ");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                            printf("%d ", a[i][j]);
                            product *= a[i][j];
                        }
                    }
                }
                printf("\nTích các phần tử biên: %lld\n", product);
                break;
            }

            case 5: {
                if (rows != cols) {
                    printf("Không phải ma trận vuông => Không có đường chéo chính.\n");
                    break;
                }
                printf("Các phần tử trên đường chéo chính: ");
                for (int i = 0; i < rows; i++) {
                    printf("%d ", a[i][i]);
                }
                printf("\n");
                break;
            }

            case 6: {
                if (rows != cols) {
                    printf("Không phải ma trận vuông => Không có đường chéo phụ.\n");
                    break;
                }
                printf("Các phần tử trên đường chéo phụ: ");
                for (int i = 0; i < rows; i++) {
                    printf("%d ", a[i][cols - i - 1]);
                }
                printf("\n");
                break;
            }

            case 7: {
                int maxRow = 0, maxSum = 0;
                for (int j = 0; j < cols; j++) {
                    maxSum += a[0][j];
                }

                for (int i = 1; i < rows; i++) {
                    int rowSum = 0;
                    for (int j = 0; j < cols; j++) {
                        rowSum += a[i][j];
                    }
                    if (rowSum > maxSum) {
                        maxSum = rowSum;
                        maxRow = i;
                    }
                }

                printf("Dòng có tổng lớn nhất là dòng %d: ", maxRow);
                for (int j = 0; j < cols; j++) {
                    printf("%d ", a[maxRow][j]);
                }
                printf("\nTổng = %d\n", maxSum);
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
