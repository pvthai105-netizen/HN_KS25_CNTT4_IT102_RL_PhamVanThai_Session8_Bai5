#include <stdio.h>

struct Subscription {
    int sub_id;
    char plan_name[31];
    float monthly_fee;
    int user_limit;
};

int main(void) {
    struct Subscription subscriptions[100];
    int n;
    int i;
    float total_revenue = 0.0f;

    printf("Nhap so luong goi dich vu: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("So luong goi dich vu khong hop le!\n");
        return 0;
    }

    if (n > 100) {
        printf("So luong goi dich vu khong hop le!\n");
        return 0;
    }

    /* Nhap thong tin cac goi */
    for (i = 0; i < n; i++) {
        printf("\nGoi %d:\n", i + 1);

        printf("Ma goi: ");
        scanf("%d", &subscriptions[i].sub_id);

        printf("Ten goi: ");
        scanf("%30s", subscriptions[i].plan_name);

        printf("Cuoc phi thang: ");
        scanf("%f", &subscriptions[i].monthly_fee);

        printf("Gioi han user: ");
        scanf("%d", &subscriptions[i].user_limit);

        total_revenue += subscriptions[i].monthly_fee;
    }

    /* In bang */
    printf("\n===============================================================\n");
    printf("%-10s %-20s %-18s %-15s\n",
           "MA GOI", "TEN GOI", "CUOC PHI (USD)", "GIOI HAN USER");
    printf("---------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%-10d %-20s %-18.2f %-15d\n",
               subscriptions[i].sub_id,
               subscriptions[i].plan_name,
               subscriptions[i].monthly_fee,
               subscriptions[i].user_limit);
    }

    printf("---------------------------------------------------------------\n");
    printf("TONG DOANH THU HANG THANG: %.2f USD\n", total_revenue);

    return 0;
}
