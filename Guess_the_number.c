#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 7

int main() {
    int target, guess;
    int attempts = 0;
    char buffer[100];

    srand(time(NULL));
    target = rand() % 100 + 1; // �ͦ� 1 �� 100 ���H����

    printf("�q�@�� 1 �� 100 �������Ʀr�C�A�� %d �����|�C\n", MAX_ATTEMPTS);

    while (attempts < MAX_ATTEMPTS) {
        printf("�A���q��: ");
        
        // �ϥ� fgets Ū������J�A�M��N���ഫ�����
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("��J���~�A�ЦA�դ@���C\n");
            continue;
        }

        if (sscanf(buffer, "%d", &guess) != 1) {
            printf("�L�Ī���J�A�п�J�@�Ӿ�ơC\n");
            continue;
        }

        // �ˬd�q���O�_�b���Ľd��
        if (guess < 1 || guess > 100) {
            printf("�п�J�@�� 1 �� 100 �������Ʀr�C\n");
            continue;
        }

        attempts++;

        if (guess > target) {
            printf("�Ӥj�F�I\n");
        } else if (guess < target) {
            printf("�Ӥp�F�I\n");
        } else {
            printf("���ߧA�A�q��F�I�A�`�@�q�F %d ���C\n", attempts);
            return 0;
        }

        printf("�Ѿl %d �����|�C\n", MAX_ATTEMPTS - attempts);
    }

    printf("�C�������I���T���Ʀr�O %d�C\n", target);
    return 0;
}

