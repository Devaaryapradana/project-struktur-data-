#include <stdio.h>
#include <string.h>

#define MAX_LINGKARAN 20

typedef struct {
    char nama[50];
    char jenis_kelamin; 
} Mahasiswa;

typedef struct {
    Mahasiswa mahasiswa[MAX_LINGKARAN];
    int jumlah;
} Lingkaran;

void tambahMahasiswa(Lingkaran *lingkaran, char nama[], char jenis_kelamin) {
    if (lingkaran->jumlah < MAX_LINGKARAN) {
        strcpy(lingkaran->mahasiswa[lingkaran->jumlah].nama, nama);
        lingkaran->mahasiswa[lingkaran->jumlah].jenis_kelamin = jenis_kelamin;
        lingkaran->jumlah++;
        printf("%s berhasil ditambahkan ke lingkaran.\n", nama);
    } else {
        printf("Lingkaran sudah penuh, tidak bisa menambah %s.\n", nama);
    }
}

void hapusMahasiswa(Lingkaran *lingkaran, char nama[]) {
    int found = 0;
    int i = 0;
    while (i < lingkaran->jumlah && !found) {
        if (strcmp(lingkaran->mahasiswa[i].nama, nama) == 0) {
            found = 1;
            int j = i;
            while (j < lingkaran->jumlah - 1) {
                lingkaran->mahasiswa[j] = lingkaran->mahasiswa[j + 1];
                j++;
            }
            lingkaran->jumlah--;
            printf("%s telah keluar dari lingkaran.\n", nama);
        }
        i++;
    }
    if (!found) {
        printf("%s tidak ditemukan di lingkaran.\n", nama);
    }
}

void tampilkanLingkaran(Lingkaran *lingkaran) {
    printf("Mahasiswa di lingkaran:\n");
    int i = 0;
    while (i < lingkaran->jumlah) {
        printf("%d. %s (%c)\n", i + 1, lingkaran->mahasiswa[i].nama, lingkaran->mahasiswa[i].jenis_kelamin);
        i++;
    }
    printf("\n");
}

int main() {
    Lingkaran lingkaranMahasiswa = { .jumlah = 0 };
    Lingkaran lingkaranMahasiswi = { .jumlah = 0 };

    char nama[50];
    char jenis_kelamin;
    int pilihan;

    do {
        printf("1. Tambah mahasiswa ke lingkaran\n");
        printf("2. Hapus mahasiswa dari lingkaran\n");
        printf("3. Tampilkan lingkaran\n");
        printf("4. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan nama mahasiswa: ");
                scanf("%s", nama);
                printf("Masukkan jenis kelamin (L/P): ");
                scanf(" %c", &jenis_kelamin);

                if (strcmp(nama, "Cindy") == 0 && jenis_kelamin == 'L') {
                    printf("Cindy hanya ingin bergandengan dengan sesama mahasiswi, tidak bisa bergabung.\n");
                } else if (strcmp(nama, "Irsyad") == 0) {
                    tambahMahasiswa(&lingkaranMahasiswa, "Irsyad", 'L');
                    tambahMahasiswa(&lingkaranMahasiswa, "Arsyad", 'L');
                } else if (strcmp(nama, "Arsyad") == 0) {
                    tambahMahasiswa(&lingkaranMahasiswa, "Arsyad", 'L');
                    tambahMahasiswa(&lingkaranMahasiswa, "Irsyad", 'L');
                } else if (jenis_kelamin == 'L') {
                    tambahMahasiswa(&lingkaranMahasiswa, nama, jenis_kelamin);
                } else {
                    tambahMahasiswa(&lingkaranMahasiswi, nama, jenis_kelamin);
                }
                break;

            case 2:
                printf("Masukkan nama mahasiswa yang ingin keluar: ");
                scanf("%s", nama);
                hapusMahasiswa(&lingkaranMahasiswa, nama);
                hapusMahasiswa(&lingkaranMahasiswi, nama);
                break;

            case 3:
                printf("=== Lingkaran Mahasiswa ===\n");
                tampilkanLingkaran(&lingkaranMahasiswa);
                printf("=== Lingkaran Mahasiswi ===\n");
                tampilkanLingkaran(&lingkaranMahasiswi);
                break;

            case 4:
                printf("Keluar dari program.\n");
                break;

            default:
                printf("Pilihan tidak valid.\n");
                break;
        }
    } while (pilihan != 4);

    return 0;
}
