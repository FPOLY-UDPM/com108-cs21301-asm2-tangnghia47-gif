/******************************************************************************
 * Họ và tên: [ĐIỀN TÊN TẠI ĐÂY]
 * MSSV:      [ĐIỀN MSSV TẠI ĐÂY]
 * Lớp:       [ĐIỀN LỚP TẠI ĐÂY]
 *****************************************************************************/

// Tạo file asm2.c và hoàn thiện nội dung Assignment từ nội dung file asm1.c


// Danh sách các chức năng trong ASM1:
// 1. Chức năng số 1: Kiểm tra số nguyên
// 2. Chức năng số 2. Tìm Ước số chung và bội số chung của 2 số 
// 3. Chức năng số 3: Chương trình tính tiền cho quán Karaoke
// 4. Chức năng số 4: Tính tiền điện 
// 5. Chức năng số 5: Chức năng đổi tiền 
// 6. Chức năng số 6: Xây dựng chức năng tính lãi suất vay ngân hàng vay trả góp 
// 7. Chức năng số 7: Xây dựng chương trình vay tiền mua xe
// 8. Chức năng số 8: Sắp xếp thông tin sinh viên
// 9. Chức năng số 9: Xây dựng game FPOLY-LOTT
// 10. Chức năng số 10: Xây dựng chương trình tính toán phân số 
// Viết chương trình C thực hiện các chức năng trên

  /******************************************************************************
 * Họ và tên: [ĐIỀN TÊN TẠI ĐÂY]
 * MSSV:      [ĐIỀN MSSV TẠI ĐÂY]
 * Lớp:       [ĐIỀN LỚP TẠI ĐÂY]
 *****************************************************************************/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h> // Thư viện cho hàm abs() và rand()

// --- Định nghĩa Cấu trúc ---
struct SinhVien {
    char ten[50];
    float diem;
};

struct PhanSo {
    int tu;
    int mau;
};

// --- Khai báo các hàm chức năng ---
void kiemTraSoNguyen();
void timUCLN_BCNN();
void tinhTienKaraoke();
void tinhTienDien();
void doiTien();
void laiSuatVay();
void vayMuaXe();
void sapXepSinhVien();
void gameLott();
void tinhPhanSo();

// --- Hàm Main duy nhất ---
int main() {
    int chonChucNang;

    do {
        printf("\n+-------------------------------------------------------+\n");
        printf("|              MENU CHUONG TRINH ASSIGNMENT             |\n");
        printf("+-------------------------------------------------------+\n");
        printf("1. Kiem tra so nguyen\n");
        printf("2. Tim Uoc so chung va boi so chung cua 2 so\n");
        printf("3. Tinh tien cho quan Karaoke\n");
        printf("4. Tinh tien dien\n");
        printf("5. Chuc nang doi tien\n");
        printf("6. Tinh lai suat vay ngan hang vay tra gop\n");
        printf("7. Vay tien mua xe\n");
        printf("8. Sap xep thong tin sinh vien\n");
        printf("9. Game FPOLY-LOTT\n");
        printf("10. Tinh toan phan so\n");
        printf("0. Thoat\n");
        printf("---------------------------------------------------------\n");
        printf("Nhap lua chon cua ban: ");
        
        // Kiểm tra nếu người dùng nhập chữ thay vì số
        if (scanf("%d", &chonChucNang) != 1) {
            printf("Loi: Vui long chi nhap con so!\n");
            while(getchar() != '\n'); // Xóa bộ nhớ đệm
            continue;
        }

        switch (chonChucNang) {
            case 1: kiemTraSoNguyen(); break;
            case 2: timUCLN_BCNN(); break;
            case 3: tinhTienKaraoke(); break;
            case 4: tinhTienDien(); break;
            case 5: doiTien(); break;
            case 6: laiSuatVay(); break;
            case 7: vayMuaXe(); break;
            case 8: sapXepSinhVien(); break;
            case 9: gameLott(); break;
            case 10: tinhPhanSo(); break;
            case 0: printf("Cam on ban da su dung chuong trinh. Tam biet!\n"); break;
            default: printf("Lua chon khong hop le!\n");
        }
    } while (chonChucNang != 0);

    return 0;
}

// --- Chi tiết các hàm chức năng ---

void kiemTraSoNguyen() {
    float x;
    printf("\nNhap vao x: "); scanf("%f", &x);
    if (x == (int)x) {
        int n = (int)x;
        printf("%.0f la so nguyen.\n", x);
        int check = (n < 2) ? 0 : 1;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) { check = 0; break; }
        }
        if (check) printf("%d la so nguyen to.\n", n);
        else printf("%d khong phai so nguyen to.\n", n);
        if (n >= 0 && sqrt(n) == (int)sqrt(n)) printf("%d la so chinh phuong.\n", n);
    } else {
        printf("%.2f khong phai la so nguyen.\n", x);
    }
}

void timUCLN_BCNN() {
    int a, b;
    printf("\nNhap 2 so a, b: "); scanf("%d %d", &a, &b);
    int tich = abs(a * b);
    int tempA = abs(a), tempB = abs(b);
    if (tempA == 0 || tempB == 0) {
        printf("UCLN: %d, BCNN: 0\n", tempA + tempB);
        return;
    }
    while (tempA != tempB) {
        if (tempA > tempB) tempA -= tempB;
        else tempB -= tempA;
    }
    printf("UCLN: %d, BCNN: %d\n", tempA, tich / tempA);
}

void tinhTienKaraoke() {
    int bd, kt;
    printf("\nGio bat dau (12h-23h): "); scanf("%d", &bd);
    printf("Gio ket thuc: "); scanf("%d", &kt);
    if (bd < 12 || kt > 23 || bd >= kt) {
        printf("Gio mo cua tu 12h - 23h va gio ket thuc phai lon hon bat dau!\n");
        return;
    }
    int gio = kt - bd;
    float tong = (gio <= 3) ? (gio * 150000) : (3 * 150000 + (gio - 3) * 150000 * 0.7);
    if (bd >= 14 && bd <= 17) tong *= 0.9;
    printf("Tong tien: %.0f VND\n", tong);
}

void tinhTienDien() {
    float kwh, tien;
    printf("\nNhap so dien tieu thu (kWh): "); scanf("%f", &kwh);
    if (kwh <= 50) tien = kwh * 1678;
    else if (kwh <= 100) tien = 50 * 1678 + (kwh - 50) * 1734;
    else if (kwh <= 200) tien = 50 * 1678 + 50 * 1734 + (kwh - 100) * 2014;
    else if (kwh <= 300) tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + (kwh - 200) * 2536;
    else tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + (kwh - 300) * 2834;
    printf("Tien dien: %.0f VND\n", tien);
}

void doiTien() {
    int menhGia[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    int soTien;
    printf("\nNhap so tien muon doi: "); scanf("%d", &soTien);
    for (int i = 0; i < 9; i++) {
        int soTo = soTien / menhGia[i];
        if (soTo > 0) printf("%d to menh gia %d\n", soTo, menhGia[i]);
        soTien %= menhGia[i];
    }
}

void laiSuatVay() {
    double soTien, laiSuat = 0.05, goc, lai, phaiTra;
    printf("\nNhap so tien vay: "); scanf("%lf", &soTien);
    goc = soTien / 12;
    printf("%-10s | %-12s | %-12s | %-12s\n", "Thang", "Lai", "Goc", "Con lai");
    for (int i = 1; i <= 12; i++) {
        lai = soTien * laiSuat;
        phaiTra = goc + lai;
        soTien -= goc;
        printf("Thang %-5d | %-12.0f | %-12.0f | %-12.0f\n", i, lai, goc, (soTien < 1) ? 0 : soTien);
    }
}

void vayMuaXe() {
    double giaTri, phanTram, laiSuat = 0.072;
    int nam;
    printf("\nGia tri xe: "); scanf("%lf", &giaTri);
    printf("Phan tram vay (VD 80): "); scanf("%lf", &phanTram);
    printf("So nam: "); scanf("%d", &nam);
    double khoanVay = giaTri * (phanTram / 100);
    double goc = khoanVay / (nam * 12);
    for (int i = 1; i <= nam * 12; i++) {
        double lai = khoanVay * (laiSuat / 12);
        khoanVay -= goc;
        printf("Thang %d: Lai %.0f, Goc %.0f, Con lai %.0f\n", i, lai, goc, (khoanVay < 1) ? 0 : khoanVay);
    }
}

void sapXepSinhVien() {
    int n;
    printf("\nNhap so luong SV: "); scanf("%d", &n);
    struct SinhVien sv[n], temp;
    for (int i = 0; i < n; i++) {
        printf("Ten SV %d: ", i + 1);
        scanf(" %[^\n]", sv[i].ten); // Nhập chuỗi có khoảng trắng
        printf("Diem SV %d: ", i + 1);
        scanf("%f", &sv[i].diem);
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sv[i].diem < sv[j].diem) {
                temp = sv[i]; sv[i] = sv[j]; sv[j] = temp;
            }
        }
    }
    printf("\n--- Danh sach sau sap xep ---\n");
    for (int i = 0; i < n; i++) {
        char *hl = (sv[i].diem >= 9) ? "Xuat sac" : (sv[i].diem >= 8) ? "Gioi" : (sv[i].diem >= 6.5) ? "Kha" : (sv[i].diem >= 5) ? "Trung binh" : "Yeu";
        printf("%-20s | Diem: %.1f | Hoc luc: %s\n", sv[i].ten, sv[i].diem, hl);
    }
}

void gameLott() {
    int so1, so2, l1 = rand() % 15 + 1, l2 = rand() % 15 + 1, count = 0;
    printf("\nNhap 2 so may man (1-15): "); scanf("%d %d", &so1, &so2);
    printf("Ket qua: %d - %d\n", l1, l2);
    if (so1 == l1 || so1 == l2) count++;
    if (so2 == l1 || so2 == l2) count++;
    if (count == 2) printf("Giai Nhat!\n");
    else if (count == 1) printf("Giai Nhi!\n");
    else printf("Chuc ban may man lan sau!\n");
}

void tinhPhanSo() {
    struct PhanSo p1, p2, kq;
    printf("\nPhan so 1 (tu mau): "); scanf("%d %d", &p1.tu, &p1.mau);
    printf("Phan so 2 (tu mau): "); scanf("%d %d", &p2.tu, &p2.mau);
    if (p1.mau == 0 || p2.mau == 0) { printf("Mau so phai khac 0!\n"); return; }
    
    printf("Tong: %d/%d\n", p1.tu * p2.mau + p2.tu * p1.mau, p1.mau * p2.mau);
    printf("Hieu: %d/%d\n", p1.tu * p2.mau - p2.tu * p1.mau, p1.mau * p2.mau);
    printf("Tich: %d/%d\n", p1.tu * p2.tu, p1.mau * p2.mau);
    if (p2.tu != 0) printf("Thuong: %d/%d\n", p1.tu * p2.mau, p1.mau * p2.tu);
}