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
class Peminjam {
    private:
        string nama;
        int totalPinjam;
    
    public:
        Peminjam(string n) : nama(n), totalPinjam(0) {}
        friend class Petugas;
        friend class Admin;
    };
    