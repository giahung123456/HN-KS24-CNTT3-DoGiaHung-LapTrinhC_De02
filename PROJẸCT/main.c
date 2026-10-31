#include <stdio.h>
#include <string.h>
typedef struct {
    int maThuoc;
    char tenThuoc[50];
    int soLuong;
    float donGia;
} Thuoc;
float tinhTongTienLoaiThuoc(Thuoc thuoc[], int n, int maLoai) {
    float tongTien = 0;
    for (int i = 0; i < n; i++) {
        if (thuoc[i].maThuoc == maLoai) {
            tongTien += thuoc[i].soLuong * thuoc[i].donGia;
        }
    }
    return tongTien;
}
int timIndexThuocTheoMa(Thuoc thuoc[], int n, int maThuoc) {
    for (int i = 0; i < n; i++) {
        if (thuoc[i].maThuoc == maThuoc) {
            return i;
        }
    }
    return -1;
}
void capNhatThongTinThuoc(Thuoc thuoc[], int n, int maThuoc) {
    int index = timIndexThuocTheoMa(thuoc, n, maThuoc);
    if (index != -1) {
        printf("Nhap ten thuoc moi: ");
        scanf("%s", thuoc[index].tenThuoc);
        printf("Nhap so luong moi: ");
        scanf("%d", &thuoc[index].soLuong);
        printf("Nhap don gia moi: ");
        scanf("%f", &thuoc[index].donGia);
        printf("Cap nhat thong tin thuoc thanh cong.\n");
    } else {
        printf("Khong tim thay thuoc voi ma %d.\n", maThuoc);
    }
}
void hienThiMenu(){
    printf("=== MENU ===\n");
    printf("1.them thuoc \n");
    printf("2.hien thi danh sach thuoc \n");
    printf("3.cap nhat thong tin thuoc theo ma \n");
    printf("4.xoa thuoc theo ma \n");
    printf("5.tim kiem thuoc theo ten \n");
    printf("6.thong ke kho hang \n");
    printf("0.thoat \n");
    printf("============\n");
    printf("Nhap lua chon cua ban: ");

}
int themThuoc(Thuoc thuoc[], int n) {
    if (n >= 50) {
        printf("Danh sach thuoc da day.\n");
        return n;
    }
    printf("Nhap ma thuoc: ");
    scanf("%d", &thuoc[n].maThuoc);
    printf("Nhap ten thuoc: ");
    scanf("%s", thuoc[n].tenThuoc);
    printf("Nhap so luong: ");
    scanf("%d", &thuoc[n].soLuong);
    printf("Nhap don gia: ");
    scanf("%f", &thuoc[n].donGia);
    return n + 1;
}
void hienThiDanhSachThuoc(Thuoc thuoc[], int n) {
    printf("Danh sach thuoc:\n");
    for (int i = 0; i < n; i++) {
        printf("Ma thuoc: %d, Ten thuoc: %s, So luong: %d, Don gia: %.2f\n",
               thuoc[i].maThuoc, thuoc[i].tenThuoc, thuoc[i].soLuong, thuoc[i].donGia);
    }
}
int xoaThuocTheoMa(Thuoc thuoc[], int n, int maThuoc) {
    int index = timIndexThuocTheoMa(thuoc, n, maThuoc);
    if (index != -1) {
        for (int i = index; i < n - 1; i++) {
            thuoc[i] = thuoc[i + 1];
        }
        printf("Xoa thuoc thanh cong.\n");
        return n - 1;
    } else {
        printf("Khong tim thay thuoc voi ma %d.\n", maThuoc);
        return n;
    }
}
void timKiemThuocTheoTen(Thuoc thuoc[], int n, const char* tenThuoc) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(thuoc[i].tenThuoc, tenThuoc) == 0) {
            printf("Ma thuoc: %d, Ten thuoc: %s, So luong: %d, Don gia: %.2f\n",
                   thuoc[i].maThuoc, thuoc[i].tenThuoc, thuoc[i].soLuong, thuoc[i].donGia);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay thuoc voi ten %s.\n", tenThuoc);
    }
}
void thongKeKhoHang(Thuoc thuoc[], int n) {
    float tongTien = 0;
    int soThuocNhoHonNam = 0;
    float giaTienLonNhat = 0;
    int indexThuocGiaTienLonNhat = -1;
    for (int i = 0; i < n; i++) {
        tongTien += thuoc[i].soLuong * thuoc[i].donGia;
        if (thuoc[i].soLuong < 5) {
            soThuocNhoHonNam++;
        }
        if (thuoc[i].donGia > giaTienLonNhat) {
            giaTienLonNhat = thuoc[i].donGia;
            indexThuocGiaTienLonNhat = i;
        }
    }

    printf("Tong gia tri kho hang: %.2f\n", tongTien);
    printf("So luong thuoc co so luong nho hon 5: %d\n", soThuocNhoHonNam);
    if (indexThuocGiaTienLonNhat != -1) {
        printf("Thuoc co gia tien lon nhat: Ma thuoc: %d, Ten thuoc: %s, So luong: %d, Don gia: %.2f\n",
               thuoc[indexThuocGiaTienLonNhat].maThuoc,
               thuoc[indexThuocGiaTienLonNhat].tenThuoc,
               thuoc[indexThuocGiaTienLonNhat].soLuong,
               thuoc[indexThuocGiaTienLonNhat].donGia);
    }
}
int main(void) {
    Thuoc thuoc[50];
    int n=0;
    printf("Hello, World!\n");
    int choice;
    do {
        hienThiMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                n = themThuoc(thuoc, n);
                break;
            case 2:
                hienThiDanhSachThuoc(thuoc, n);
                break;
            case 3:
                int maThuoc;
                printf("Nhap ma thuoc can cap nhat: ");
                scanf("%d", &maThuoc);
                capNhatThongTinThuoc(thuoc, n, maThuoc);
                break;
            case 4:
                printf("Nhap ma thuoc can xoa: ");
                scanf("%d", &maThuoc);
                n = xoaThuocTheoMa(thuoc, n, maThuoc);
                break;
            case 5:
                char tenThuoc[100];
                printf("Nhap ten thuoc can tim: ");
                scanf("%s", tenThuoc);
                timKiemThuocTheoTen(thuoc, n, tenThuoc);
                break;
        case 6:
                thongKeKhoHang(thuoc, n);
                break;
            case 0:
                printf("thoát.\n");
                break;
            default:
                printf("lựa chọn không hợp lệ,nhập lại.\n");;

        }
    } while (choice != 0);
    return 0;
}
