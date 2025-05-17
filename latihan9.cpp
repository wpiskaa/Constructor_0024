#include <iostream>
using namespace std;

class Peminjam;
class Petugas;
class Admin;

class Buku
{
private:
    string judul;
    bool dipinjam;

public:
    Buku(string j) : judul(j), dipinjam(false) {}
    friend class Petugas;
    friend class Admin;
};
class Peminjam
{
private:
    string nama;
    int totalPinjam;

public:
    Peminjam(string n) : nama(n), totalPinjam(0) {}
    friend class Petugas;
    friend class Admin;
};

class Petugas
{
private:
    string nama, level;

public:
    Petugas(string n, string l) : nama(n), level(l) {}

    void pinjam(Buku *b, Peminjam *p)
    {
        if (!b->dipinjam)
        {
            b->dipinjam = true;
            p->totalPinjam++;
            cout << p->nama << " meminjam " << b->judul << endl;
        }
    }
    void kembali(Buku *b, Peminjam *p)
    {
        if (b->dipinjam)
        {
            b->dipinjam = false;
            p->totalPinjam--;
            cout << p->nama << " mengembalikan " << b->judul << endl;
        }
    }
    friend class Admin;
}
