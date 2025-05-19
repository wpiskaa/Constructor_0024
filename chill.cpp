#include <iostream>
using namespace std;

class Mahasiswa
{
private:
    static int jumlahMahasiswa;

public:
    string nama;
    Mahasiswa(string pNama)
    {
        nama = pNama;
        ++jumlahMahasiswa;
        cout << "Mahasiswa Dibuat :" << nama << endl;
    }
    ~Mahasiswa()
    {
        --jumlahMahasiswa;
        cout << "Nama Terhapus : " << nama << endl;
    }
    static void setJumlah(int pJumlah)
    {
        jumlahMahasiswa = pJumlah;
    }

    static int getJumlahMahasiswa()
    {
        return jumlahMahasiswa;
    }
};

int Mahasiswa::jumlahMahasiswa = 0;

int main()
{
    cout << "Jumlah Mahasiswa :" << Mahasiswa::getJumlahMahasiswa() << endl;

    Mahasiswa mhs1("Pijun");
    Mahasiswa mhs2("Syahrini");
    cout << "Jumlah Mahasiswa :" << Mahasiswa::getJumlahMahasiswa() << endl;
    Mahasiswa::setJumlah(5);

    {
        Mahasiswa mhs3("Dizza");
        cout << "Jumlah Mahasiswa :" << Mahasiswa::getJumlahMahasiswa() << endl;
    }

    cout << "Jumlah Mahasiswa :" << Mahasiswa::getJumlahMahasiswa() << endl;
    return 0;
}