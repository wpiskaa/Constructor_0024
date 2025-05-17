#include <iostream>
using namespace std;

class Peminjam;
class Petugas;
class Admin;

class Buku {
private:
    string judul;
    bool dipinjam;

public:
    Buku(string j) : judul(j), dipinjam(false) {}
    friend class Petugas;
    friend class Admin;
};

class Peminjam {
private:
    string nama;
    int totalPinjam;

public:
    Peminjam(string n) : nama(n), totalPinjam(0) {}
    friend class Petugas;
    friend class Admin;
};

class Petugas {
private:
    string nama, level;

public:
    Petugas(string n, string l) : nama(n), level(l) {}

    void pinjam(Buku* b, Peminjam* p) {
        if (!b->dipinjam) {
            b->dipinjam = true;
            p->totalPinjam++;
            cout << p->nama << " meminjam " << b->judul << endl;
        }
    }

    void kembali(Buku* b, Peminjam* p) {
        if (b->dipinjam) {
            b->dipinjam = false;
            p->totalPinjam--;
            cout << p->nama << " mengembalikan " << b->judul << endl;
        }
    }

    friend class Admin;
};

class Admin {
public:
    void lihat(Peminjam* p, Buku* b) {
        cout << "Statistik: " << p->nama << " meminjam "
             << p->totalPinjam << " buku. Status buku: "
             << (b->dipinjam ? "Dipinjam" : "Tersedia") << endl;
    }

    void ubahLevel(Petugas* t, string baru) {
        t->level = baru;
        cout << "Level petugas diubah ke " << baru << endl;
    }
};

int main() {
    Buku b("Dasar C++");
    Peminjam p("Piska");
    Petugas t("Rika", "Normal");
    Admin a;

    t.pinjam(&b, &p);
    a.lihat(&p, &b);
    t.kembali(&b, &p);
    a.ubahLevel(&t, "Admin");

    return 0;
}