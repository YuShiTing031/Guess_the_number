#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 7

int main() {
    int target, guess;
    int attempts = 0;
    char buffer[100];

    srand(time(NULL));
    target = rand() % 100 + 1; // 生成 1 到 100 的隨機數

    printf("猜一個 1 到 100 之間的數字。你有 %d 次機會。\n", MAX_ATTEMPTS);

    while (attempts < MAX_ATTEMPTS) {
        printf("你的猜測: ");
        
        // 使用 fgets 讀取整行輸入，然後將其轉換為整數
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("輸入錯誤，請再試一次。\n");
            continue;
        }

        if (sscanf(buffer, "%d", &guess) != 1) {
            printf("無效的輸入，請輸入一個整數。\n");
            continue;
        }

        // 檢查猜測是否在有效範圍內
        if (guess < 1 || guess > 100) {
            printf("請輸入一個 1 到 100 之間的數字。\n");
            continue;
        }

        attempts++;

        if (guess > target) {
            printf("太大了！\n");
        } else if (guess < target) {
            printf("太小了！\n");
        } else {
            printf("恭喜你，猜對了！你總共猜了 %d 次。\n", attempts);
            return 0;
        }

        printf("剩餘 %d 次機會。\n", MAX_ATTEMPTS - attempts);
    }

    printf("遊戲結束！正確的數字是 %d。\n", target);
    return 0;
}

