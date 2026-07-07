#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int attackers, capacity;
    int totalRequests = 0;

    // Khởi tạo random
    srand(time(NULL));

    printf("Nhap so attacker (may tan cong): ");
    scanf("%d", &attackers);

    printf("Nhap suc chua cua server (so request xu ly duoc): ");
    scanf("%d", &capacity);

    for (int i = 0; i < attackers; i++) {
        int requests = rand() % 500; // mỗi attacker gửi ngẫu nhiên <= 500 request
        printf("Attacker %d gui %d request\n", i+1, requests);
        totalRequests += requests;
    }

    printf("\nTong so request gui den server: %d\n", totalRequests);

    if (totalRequests > capacity) {
        printf(">>> Server bi qua tai! Tan cong DoS/DDoS thanh cong.\n");
    } else {
        printf(">>> Server van hoat dong binh thuong.\n");
    }

    return 0;
}
