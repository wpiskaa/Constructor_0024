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
