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

        if (KemDau != 0)
            cout << "                    1. KemDau      - " << KemDau << " dong" << endl;
        if (KemSua != 0)
            cout << "                    2. KemSua      - " << KemSua << " dong" << endl;
        if (KemVani != 0)
            cout << "                    3. KemVani     - " << KemVani << " dong" << endl;
        if (KemSocola != 0)
            cout << "                    4. KemSocola   - " << KemSocola << " dong" << endl;
        if (KemSauRieng != 0)
            cout << "                    5. KemSauRieng - " << KemSauRieng << " dong" << endl;
        if (KemDua != 0)
            cout << "                    6. KemDua      - " << KemDua << " dong" << endl;
        if (KemHanhNhan != 0)
            cout << "                    7. KemHanhNhan - " << KemHanhNhan << " dong" << endl;
        if (KemDauPhong != 0)
            cout << "                    8. KemDauPhong - " << KemDauPhong << " dong" << endl;

        // Hiển thị các sản phẩm được thêm vào
        for (size_t i = 0; i < sanpham.size(); ++i)
        {
            cout << "                    " << (i + 9) << ". " << sanpham[i].getten() << " - " << sanpham[i].getgia() << " dong" << endl;
        }
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

            if (chon >= 1 && chon <= 8)
            {
                switch (chon)
                {
                case 1:
                    if (KemDau != 0)
                        total += KemDau * soluong;
                    break;
                case 2:
                    if (KemSua != 0)
                        total += KemSua * soluong;
                    break;
                case 3:
                    if (KemVani != 0)
                        total += KemVani * soluong;
                    break;
                case 4:
                    if (KemSocola != 0)
                        total += KemSocola * soluong;
                    break;
                case 5:
                    if (KemSauRieng != 0)
                        total += KemSauRieng * soluong;
                    break;
                case 6:
                    if (KemDua != 0)
                        total += KemDua * soluong;
                    break;
                case 7:
                    if (KemHanhNhan != 0)
                        total += KemHanhNhan * soluong;
                    break;
                case 8:
                    if (KemDauPhong != 0)
                        total += KemDauPhong * soluong;
                    break;
                }
            }
            else if (chon >= 9 && chon < 9 + sanpham.size())
            {
                total += sanpham[chon - 9].getgia() * soluong;
            }
            else
            {
                cout << "Mon ban chon khong co trong Menu, Vui long thu lai " << endl;
            }

            cout << "So tien phai tra bay gio dang la " << total << endl;
            cout << "Tiep tuc chon mon (1-8) hoac nhan 0 de ket thuc: ";
            cin >> chon;
        }

        cout << "Cam on ban da an o quan chung minh, Hoa don cua ban la " << total << " dong" << endl;
    }

    //-------------------------------THEM SAN PHAM------------------------------------

    vector<TiemKem> sanpham;

    void AddTiemKem()
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

    // Hàm xóa sản phẩm từ danh sách
    void deleteTiemKem()
    {
        int index;
        cout << "Nhap chi so san pham can xoa: ";
        cin >> index;

        if (index >= 1 && index <= 8)
        {
            switch (index)
            {
            case 1:
                KemDau = 0;
                break;
            case 2:
                KemSua = 0;
                break;
            case 3:
                KemVani = 0;
                break;
            case 4:
                KemSocola = 0;
                break;
            case 5:
                KemSauRieng = 0;
                break;
            case 6:
                KemDua = 0;
                break;
            case 7:
                KemHanhNhan = 0;
                break;
            case 8:
                KemDauPhong = 0;
                break;
            }
            cout << "Xoa san pham thanh cong" << endl;
        }
        else if (index >= 9 && index < 9 + sanpham.size())
        {
            sanpham.erase(sanpham.begin() + (index - 9));
            cout << "Xoa san pham thanh cong" << endl;
        }
        else
        {
            cout << "Khong hop le. Vui long thu lai:" << endl;
        }
        Menu(); // Hiển thị lại menu sau khi xóa sản phẩm
    }
};

int main()
{
    TiemKem tiemkem;
    tiemkem.Menu();
    tiemkem.Order();
    int choice;

    do
    {
        cout << "\n1. Them san pham\n2. Xoa san pham\n3. Hien thi san pham\n4. Hien thi menu\n5. Thoat\nNhap lua chon: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            tiemkem.AddTiemKem();
            tiemkem.Menu(); // Hiển thị lại menu sau khi thêm sản phẩm mới
            break;
        case 2:
            tiemkem.deleteTiemKem();
            break;
        case 3:
            tiemkem.ShowSanpham();
            break;
        case 4:
            tiemkem.Menu();
            break;
        case 5:
            cout << "Thoat chuong trinh.";
            break;
        default:
            cout << "Khong hop le. Vui long thu lai:" << endl;
        }
    } while (choice != 5);

    cout << "Ket thuc chuong trinh. Tam biet!" << endl;

    return 0;
}
