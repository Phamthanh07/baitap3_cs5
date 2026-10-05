#include <stdio.h>

#define MAX 100
#define GIA_KHAM 150000

int main() {
    int ma_so[MAX];
    int tuoi[MAX];
    int bhyt[MAX];

    int n;
    int k;

    int tong_doanh_thu = 0;
    int so_uu_tien = 0;

    // Nhap so luong benh nhan
    do {
        printf("Nhap so luong benh nhan (0-%d): ", MAX);
        scanf("%d", &n);

        if (n < 0 || n > MAX) {
            printf("So luong benh nhan khong hop le!\n");
        }

    } while (n < 0 || n > MAX);

    // Nhap thong tin benh nhan
    for (int i = 0; i < n; i++) {

        printf("\n--- Benh nhan %d ---\n", i + 1);

        // Ma so thu tu
        printf("Nhap ma so thu tu: ");
        scanf("%d", &ma_so[i]);

        // Nhap tuoi
        do {
            printf("Nhap tuoi (1-120): ");
            scanf("%d", &tuoi[i]);

            if (tuoi[i] < 1 || tuoi[i] > 120) {
                printf("Tuoi khong hop le! Vui long nhap lai.\n");
            }

        } while (tuoi[i] < 1 || tuoi[i] > 120);

        // Nhap BHYT
        do {
            printf("Nhap BHYT (1: Co, 0: Khong): ");
            scanf("%d", &bhyt[i]);

            if (bhyt[i] != 0 && bhyt[i] != 1) {
                printf("Trang thai BHYT khong hop le! Vui long nhap lai.\n");
            }

        } while (bhyt[i] != 0 && bhyt[i] != 1);
    }

    // ==========================================
    // IN DANH SACH BAN DAU
    // ==========================================

    printf("\n============================================\n");
    printf("       DANH SACH HANG CHO BAN DAU\n");
    printf("============================================\n");

    tong_doanh_thu = 0;
    so_uu_tien = 0;

    for (int i = 0; i < n; i++) {

        int phi;

        if (bhyt[i] == 1) {
            phi = GIA_KHAM * 20 / 100;
        }
        else {
            phi = GIA_KHAM;
        }

        tong_doanh_thu += phi;

        if (tuoi[i] >= 70) {
            so_uu_tien++;
        }

        printf("Index %d | Ma so: %d | Tuoi: %d | BHYT: %d | Phi: %d VND",
               i, ma_so[i], tuoi[i], bhyt[i], phi);

        if (tuoi[i] >= 70) {
            printf(" | UU TIEN");
        }
        else {
            printf(" | THUONG");
        }

        printf("\n");
    }

    printf("--------------------------------------------\n");
    printf("So luong benh nhan: %d\n", n);
    printf("Tong doanh thu du kien: %d VND\n", tong_doanh_thu);
    printf("So benh nhan uu tien: %d\n", so_uu_tien);

    // ==========================================
    // NHAP VI TRI CAN HUY
    // ==========================================

    if (n == 0) {
        printf("\nHang cho dang rong, khong the huy!\n");
        return 0;
    }

    printf("\nNhap vi tri K can huy (0-%d): ", n - 1);
    scanf("%d", &k);

    // Kiem tra K
    if (k < 0 || k >= n) {
        printf("Vi tri K khong hop le! Tu choi thao tac huy.\n");
        return 0;
    }

    // ==========================================
    // DON DICH MANG
    // ==========================================

    printf("\nHuy benh nhan tai Index %d - Ma so %d\n",
           k, ma_so[k]);

    for (int i = k; i < n - 1; i++) {
        ma_so[i] = ma_so[i + 1];
        tuoi[i] = tuoi[i + 1];
        bhyt[i] = bhyt[i + 1];
    }

    // Giam so luong benh nhan
    n--;

    // ==========================================
    // TINH LAI DOANH THU VA UU TIEN
    // ==========================================

    tong_doanh_thu = 0;
    so_uu_tien = 0;

    for (int i = 0; i < n; i++) {

        int phi;

        if (bhyt[i] == 1) {
            phi = GIA_KHAM * 20 / 100;
        }
        else {
            phi = GIA_KHAM;
        }

        tong_doanh_thu += phi;

        if (tuoi[i] >= 70) {
            so_uu_tien++;
        }
    }

    // ==========================================
    // IN DANH SACH SAU KHI HUY
    // ==========================================

    printf("\n============================================\n");
    printf("       DANH SACH HANG CHO SAU KHI HUY\n");
    printf("============================================\n");

    for (int i = 0; i < n; i++) {

        int phi;

        if (bhyt[i] == 1) {
            phi = GIA_KHAM * 20 / 100;
        }
        else {
            phi = GIA_KHAM;
        }

        printf("Index %d | Ma so: %d | Tuoi: %d | BHYT: %d | Phi: %d VND",
               i, ma_so[i], tuoi[i], bhyt[i], phi);

        if (tuoi[i] >= 70) {
            printf(" | UU TIEN");
        }
        else {
            printf(" | THUONG");
        }

        printf("\n");
    }

    printf("--------------------------------------------\n");
    printf("So luong benh nhan con lai: %d\n", n);
    printf("Tong doanh thu sau khi huy: %d VND\n", tong_doanh_thu);
    printf("So benh nhan uu tien: %d\n", so_uu_tien);

    return 0;
}