#include <iostream>
using namespace std;
 
const int MAX = 100; // Kích thước tối đa của mảng
 
struct List {
    int data[MAX]; // Mảng tĩnh lưu trữ các phần tử
    int n;         // Số lượng phần tử hiện tại trong danh sách
 
    // Khởi tạo danh sách rỗng
    void init() {
        n = 0;
    }
 
    // 1. Trả về phần tử tại vị trí i
    int getAt(int i) {
        if (i < 0 || i >= n) {
            cout << "Loi: Vi tri khong hop le!\n";
            return -1; // Giá trị báo lỗi
        }
        return data[i];
    }
 
    // 2. Thêm vào đầu danh sách (vị trí 0)
    void insertHead(int val) {
        if (n >= MAX) {
            cout << "Danh sach da day!\n";
            return;
        }
        for (int i = n; i > 0; i--) {
            data[i] = data[i - 1]; // Dịch phải các phần tử
        }
        data[0] = val;
        n++;
    }
 
    // 3. Thêm vào cuối danh sách
    void insertTail(int val) {
        if (n >= MAX) {
            cout << "Danh sach da day!\n";
            return;
        }
        data[n] = val;
        n++;
    }
 
    // 4. Thêm tại vị trí i
    void insertAt(int i, int val) {
        if (i < 0 || i > n) {
            cout << "Loi: Vi tri them khong hop le!\n";
            return;
        }
        if (n >= MAX) {
            cout << "Danh sach da day!\n";
            return;
        }
        for (int j = n; j > i; j--) {
            data[j] = data[j - 1]; // Dịch phải từ vị trí i
        }
        data[i] = val;
        n++;
    }
 
    // 5. Xóa đầu danh sách
    void deleteHead() {
        if (n <= 0) {
            cout << "Danh sach rong!\n";
            return;
        }
        for (int i = 0; i < n - 1; i++) {
            data[i] = data[i + 1]; // Dịch trái các phần tử
        }
        n--;
    }
 
    // 6. Xóa cuối danh sách, trả về phần tử vừa xóa
    int deleteTail() {
        if (n <= 0) {
            cout << "Danh sach rong!\n";
            return -1;
        }
        return data[--n]; // giảm n rồi trả về phần tử cuối cũ
    }
 
    // 7. Xóa tại vị trí i
    void deleteAt(int i) {
        if (i < 0 || i >= n) {
            cout << "Loi: Vi tri xoa khong hop le!\n";
            return;
        }
        for (int j = i; j < n - 1; j++) {
            data[j] = data[j + 1]; // Dịch trái từ vị trí i
        }
        n--;
    }
 
    // 8. Duyệt xuôi từ đầu đến cuối
    void traverseForward() {
        cout << "Duyet xuoi: ";
        for (int i = 0; i < n; i++) {
            cout << data[i] << " ";
        }
        cout << "\n";
    }
 
    // 9. Duyệt ngược từ cuối về đầu
    void traverseBackward() {
        cout << "Duyet nguoc: ";
        for (int i = n - 1; i >= 0; i--) {
            cout << data[i] << " ";
        }
        cout << "\n";
    }
 
    // Kiểm tra rỗng
    bool isempty() {
        return n == 0;
    }
 
    // Số phần tử hiện có
    int size() {
        return n;
    }
};
