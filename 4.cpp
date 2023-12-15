#include <iostream> // Untuk menyertakan library standar input output C++
#include <stdio.h> // Untuk menyertakan library standar input output C
#include <conio.h> // Untuk menyertakan library console input output
#include <time.h> // Untuk menyertakan library yang berhubungan dengan waktu
#include <windows.h> // Untuk menyertakan library khusus Windows

// Agar bisa langsung pakai fungsi cout, cin, dll dari std
using namespace std;
struct trx // membuat struktur trx
{
	// Deklarasi array dari struct trx sebanyak 100 data
	int m, type, pil, status, lama, biaya;
	char plat[100];
	char tgl_masuk[100];

} trx[100]; // Deklarasi array dari struct trx sebanyak 100 data

// Fungsi untuk mencari data kendaraan berdasarkan nomor plat
int find_plat(string plat, int m)
{
	int ret = -1; // Variabel ret adalah variabel integer yang akan menyimpan hasil return value (nilai balik) dari fungsi find_plat.

	for (int b = 0; b <= m; b++)
	{
		if (plat == trx[b].plat)
		{
			ret = b;
			break;
		}
	}
	return ret; // untuk mengembalikan nilai dari fungsi find_plat. Nilai yang dikembalikan adalah isi dari variabel ret.
}

main() // Fungsi utama program
{
	int pil, a, b, total;
	char ch, temp, yn;
	string cari;
	int m = -1;

menu: // Bagian menu program
	cout << "---- Sistem Parkir  ----" << endl;
	cout << "-------- Menu ----------\n";
	cout << " 1. Input Kendaraan	       \n";
	cout << " 2. Laporan 		       \n";
	cout << " 3. Search              \n";
	cout << " 4. Logout              \n";
	cout << "------------------------\n";
	cout << "Masukan Pilihan anda[ 1 s.d. 4 ] = ";
	cin >> pil;

	system("cls");
	if (pil == 1)
	{
	trxmasuk: // Bagian untuk input data kendaraan
		m++;
		cout << "\n\n \t\t\t ------- MASUKKAN KENDARAAN ------- \t\t\t";
		cout << "\n Masukkan Plat : ";
		cin >> trx[m].plat;
		// scanf("%s", &trx[m].plat, &temp);
		cout << "\n type kendaraan : \n  1. motor \n  2. mobil \n";
		cout << " pilih type kendaraan [1 / 2 ] : ";
		cin >> trx[m].type;
		cout << " Lama Parkir	: ";
		cin >> trx[m].lama;

		// sscanf(ctime(&waktu), "%s", &trx[m].tgl_masuk, &temp);

		time_t waktu;
		time(&waktu);
		strcpy(trx[m].tgl_masuk, ctime(&waktu));

		cout << " ++++++++++++++++++++++++++++++++ \n";
		cout << " + Plat  	 : " << trx[m].plat << endl;
		cout << " + Type  	 : ";

		if (trx[m].type == 1)
		{
			cout << "motor";
		}
		if (trx[m].type == 2)
		{
			cout << "mobil";
		}
		cout << endl;
		cout << " + Lama Parkir \t : " << trx[m].lama << " jam";
		cout << endl;
		cout << " + Biaya 	 : ";
		if (trx[m].type == 1)
		{
			if (trx[m].lama >= 1 && trx[m].lama < 6)
			{
				trx[m].biaya = trx[m].lama * 2000;
			}
			else
			{
				trx[m].biaya = 12000;
			}
		}
		if (trx[m].type == 2)
		{
			if (trx[m].lama >= 1 && trx[m].lama < 6)
			{
				trx[m].biaya = trx[m].lama * 4000;
			}
			else
			{
				trx[m].biaya = 24000;
			}
		}
		cout << trx[m].biaya;
		cout << endl;
		cout << " + Date		 : " << trx[m].tgl_masuk;
		cout << " ++++++++++++++++++++++++++++++++ \n";

		cout << " Tambah Lagi ? (y/n) :";
		cin >> yn;

		if (yn == 'y' || yn == 'Y')
		{
			system("pause");
			system("cls");
			goto trxmasuk;
		}
		else if (yn == 'n' || yn == 'N')
		{
			cout << "\n\n Data Berhasil Disimpan \n"
				 << endl;
			system("pause");
			system("cls");
			goto menu;
		}
		else
		{
			system("pause");
			system("cls");
			goto trxmasuk;
		}
	}
	else if (pil == 2)
	{
	laporan: // Bagian untuk menampilkan laporan
		system("cls");
		cout << "\n"
			 << endl;
		cout << "\t\t\t ------- FORM LAPORAN ------- \t\t\t";
		for (b = 0; b <= m; b++)
		{
			if (trx[b].type == 1)
			{
				if (trx[b].lama >= 1 && trx[b].lama < 6)
				{
					trx[b].biaya = trx[b].lama * 2000;
				}
				else
				{
					trx[b].biaya = 12000;
				}
			}
			if (trx[b].type == 2)
			{
				if (trx[b].lama >= 1 && trx[b].lama < 6)
				{
					trx[b].biaya = trx[b].lama * 4000;
				}
				else
				{
					trx[b].biaya = 24000;
				}
			}
			total = total + trx[b].biaya;
		}
		cout << "\n\n Pendapatan : " << total << endl;
		cout << endl;
		for (a = 0; a <= m; a++)
		{
			cout << " ++++++++++++++++++++++++++++++++ \n";
			cout << " + Plat  	  : " << trx[a].plat << endl;
			cout << " + Type  	  : ";

			if (trx[a].type == 1)
			{
				cout << "motor";
			}
			if (trx[a].type == 2)
			{
				cout << "mobil";
			}

			cout << endl;
			cout << " + Lama Parkir \t  : " << trx[m].lama << " jam";
			cout << endl;
			cout << " + Biaya 	  : ";
			if (trx[a].type == 1)
			{
				if (trx[a].lama >= 1 && trx[a].lama < 6)
				{
					trx[a].biaya = trx[a].lama * 2000;
				}
				else
				{
					trx[a].biaya = 12000;
				}
			}
			if (trx[a].type == 2)
			{
				if (trx[a].lama >= 1 && trx[a].lama < 6)
				{
					trx[a].biaya = trx[a].lama * 4000;
				}
				else
				{
					trx[a].biaya = 24000;
				}
			}
			cout << trx[a].biaya;
			cout << endl;
			cout << " + Date		  : " << trx[a].tgl_masuk;
			cout << " ++++++++++++++++++++++++++++++++ \n\n";
		}
		system("pause");
		system("cls");
		goto menu;
	}
	else if (pil == 3)
	{
	Search: // Bagian untuk mencari data kendaraan
		system("cls");
		cout << "\n";
		cout << "\t\t\t ------- FORM Pencarian data ------- \t\t\t";
		cout << "\n Masukkan Plat : ";
		cin >> cari;

		if (find_plat(cari, m) != -1)
		{
			cout << " ++++++++++++++++++++++++++++++++ \n";
			cout << " + Plat  	  : " << trx[m].plat << endl;
			cout << " + Type  	  : ";

			if (trx[a].type == 1)
			{
				cout << "motor";
			}
			if (trx[a].type == 2)
			{
				cout << "mobil";
			}

			cout << endl;
			cout << " + Lama Parkir \t  : " << trx[m].lama << " jam";
			cout << endl;
			cout << " + Biaya 	  : ";
			if (trx[a].type == 1)
			{
				if (trx[a].lama >= 1 && trx[a].lama < 6)
				{
					trx[a].biaya = trx[a].lama * 2000;
				}
				else
				{
					trx[a].biaya = 12000;
				}
			}
			if (trx[a].type == 2)
			{
				if (trx[a].lama >= 1 && trx[a].lama < 6)
				{
					trx[a].biaya = trx[a].lama * 4000;
				}
				else
				{
					trx[a].biaya = 24000;
				}
			}
			cout << trx[a].biaya;
			cout << endl;
			cout << " + Date		  : " << trx[m].tgl_masuk;
			cout << " ++++++++++++++++++++++++++++++++ \n\n";
		}
		else
		{
			cout << "data tidak ditemukan \n\n";
		}

		system("pause");
		system("cls");
		goto menu; // Pengecekan pilihan menu yang lain
	}
	else if (pil == 4)
	{
		cout << "\n\n -- Anda Telah Logout -- \n\n";
		system("pause");
		system("cls");
	}
	else
	{
		cout << "\n\n -- pilihan tidak tersedia -- \n\n";
		system("pause");
		system("cls");
		goto menu;
	}
}
