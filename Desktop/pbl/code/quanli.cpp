#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TiemKem
{
private:
    double KemDau;
    double KemSua;
    double KemVani;
    double KemSocola;
    double KemSauRieng;
    double KemDua;
    double KemHanhNhan;
    double KemDauPhong;
    double total;

public:
    TiemKem() : KemDau(50000), KemSua(30000), KemVani(20000), KemSocola(25000), KemSauRieng(20000), KemDua(30000), KemHanhNhan(40000), KemDauPhong(40000), total(0.00)
    {
    }
    string ten;
    double gia;
    int soluong;
    TiemKem(string ten, float gia) : ten(ten), gia(gia) {}
    // Getter cho tên sản phẩm
    string getten() const
    {
        return ten;
    }

    // Getter cho giá sản phẩm
    float getgia() const
    {
        return gia;
    }

    void Menu()
    {
        cout << "                     Chao mung toi TiemKem nhom 4" << endl;
        cout << "                       ########################" << endl;
        cout << "                               M E N U " << endl;
        cout << "                       ########################" << endl;
        cout << "                   STT  Mon          Gia tien" << endl;
        cout << "                    1. KemDau      - " << KemDau << " dong" << endl;
        cout << "                    2. KemSua      - " << KemSua << " dong" << endl;
        cout << "                    3. KemVani     - " << KemVani << " dong" << endl;
        cout << "                    4. KemSocola   - " << KemSocola << " dong" << endl;
        cout << "                    5. KemSauRieng - " << KemSauRieng << " dong" << endl;
        cout << "                    6. KemDua      - " << KemDua << " dong" << endl;
        cout << "                    7. KemHanhNhan - " << KemHanhNhan << " dong" << endl;
        cout << "                    8. KemDauPhong - " << KemDauPhong << " dong" << endl;
    }

    void Order()
    {
        int chon, soluong;
        cout << "Vui long nhap STT mon (1-8) ma ban muon order (nhan 0 de ket thuc order): ";
        cin >> chon;

        while (chon != 0)
        {
            cout << "Nhap so luong: ";
            cin >> soluong;

            switch (chon)
            {
            case 1:
                total += KemDau * soluong;
                break;
            case 2:
                total += KemSua * soluong;
                break;
            case 3:
                total += KemVani * soluong;
                break;
            case 4:
                total += KemSocola * soluong;
                break;
            case 5:
                total += KemSauRieng * soluong;
                break;
            case 6:
                total += KemDua * soluong;
                break;
            case 7:
                total += KemHanhNhan * soluong;
                break;
            case 8:
                total += KemDauPhong * soluong;
                break;
            default:
                cout << "Mon ban chon khong co trong Menu, Vui long thu lai " << endl;
            }

            cout << "So tien phai tra bay gio dang la " << total << endl;
            cout << "Tiep tuc chon mon (1-8) hoac nhan 0 de ket thuc: ";
            cin >> chon;
        }

        cout << "Cam on ban da an o quan chung minh, Hoa don cua ban la" << total << "dong" << endl;
    }
};
//-------------------------------THEM SAN PHAM------------------------------------

vector<TiemKem> sanpham;

void AddTiemKem(vector<TiemKem> &sanpham)
{
    TiemKem newsanpham;
    cout << "Nhap ten san pham: ";
    cin >> newsanpham.ten;
    cout << "gia: ";
    cin >> newsanpham.gia;
    sanpham.push_back(newsanpham);
    cout << "Da them san pham \"" << newsanpham.ten << "\" vao danh sach.\n";
}

void ShowSanpham()
{
    cout << "Danh sach san pham:\n";
    for (const auto &TiemKem : sanpham)
    {
        cout << TiemKem.ten << " - " << TiemKem.gia << " dong\n";
    }
}
//-------------------------Sửa sản phẩm-----------------------
void suasp(TiemKem &tk)
{
    int chon;
    do
    {
        cout << "\n1. Sua ten san  pham:\n";
        cout << "2. Sua don gia:\n ";
        cout << "3. Sua so luong san pham:\n";
        cout << "4. Hoan tat chinh sua\nBan chon: ";
        cin >> chon;
        switch (chon)
        {
        case 1:
            cin.ignore();
            cout << " Nhap ten san pham moi: ";
            getline(cin, tk.ten);
            break;
        case 2:
            cout << "don gia moi: ";
            cin >> tk.gia;
            break;
        case 3:
            cout << " so luong san pham ";
            cin >> tk.soluong;
            break;
        case 4:
            suasp(tk);
            break;
        default:
            cout << " Hoan tat viec chinh sua: \n"
        }
    }
}

// Hàm xóa sản phẩm từ danh sách
void deleteTiemKem(vector<TiemKem> &sanpham)
{

    int index;
    cout << "Nhap san pham ban muon xoa: ";
    cin >> index;

    if (index >= 0 && index < sanpham.size())
    {
        sanpham.erase(sanpham.begin() + index);
        cout << "xoa san pham thanh cong" << endl;
    }
    else
    {
        cout << "Khong hop le. Vui long thu lai:" << endl;
    }
}

int main()
{

    TiemKem tiemkem;
    tiemkem.Menu();
    tiemkem.Order();

    sanpham.push_back(TiemKem("KemDau", 50000));
    sanpham.push_back(TiemKem("KemSocola", 25000));
    sanpham.push_back(TiemKem("Kemsua", 30000));

    int choice;

    do
    {
        cout << "\n1. Them san pham\n2. xoa\n3. Thoat/Nhap lua chon: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            AddTiemKem(sanpham);
            break;
        case 2:
            deleteTiemKem(sanpham);
            break;
        case 3:
            cout << "Thoat:";
            break;
        default:
            cout << "Khong hop le Vui long thu lai:" << endl;
        }
    } while (choice != 3);

    // int choice;

    do
    {
        cout << "\nDanh sach san pham:\n";
        for (int i = 0; i < sanpham.size(); ++i)
        {
            cout << i << ". " << sanpham[i].getten() << " - Gia: " << sanpham[i].getgia() << endl;
        }

        cout << "\nNhap chi so san pham ban muon xoa (Nhap -1 de thoat): ";
        cin >> choice;

        if (choice >= 0 && choice < sanpham.size())
        {
            deleteTiemKem(sanpham);
        }
        else if (choice != -1)
        {
            cout << "Chi so khong hop le. Vui long thu lai." << endl;
        }
    } while (choice != -1);

    cout << "Ket thuc chuong trinh. Tam biet!" << endl;

    return 0;
}
