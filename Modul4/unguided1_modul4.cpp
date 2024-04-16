#include <iostream>
using namespace std;

class Node {
public:
    string name;
    string nim;
    Node* next;
};

class LinkedList {
public:
    LinkedList() {
        head = nullptr;
    }

    void tambahAwal(string name, string nim) {
        Node* node = new Node();
        node->name = name;
        node->nim = nim;
        node->next = head;
        head = node;
    }

    void tambahAkhir(string name, string nim) {
        Node* node = new Node();
        node->name = name;
        node->nim = nim;
        node->next = nullptr;

        if (head == nullptr) {
            head = node;
        }
        else {
            Node* curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = node;
        }
    }

    void tambahTengah(string name, string nim, int pos) {
        Node* node = new Node();
        node->name = name;
        node->nim = nim;

        Node* curr = head;
        for (int i = 1; i < pos - 1; i++) {
            curr = curr->next;
        }
        node->next = curr->next;
        curr->next = node;
    }

    void ubahAwal(string name, string nim) {
        head->name = name;
        head->nim = nim;
    }

    void ubahAkhir(string name, string nim) {
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->name = name;
        curr->nim = nim;
    }

    void ubahTengah(string name, string nim, int pos) {
        Node* curr = head;
        for (int i = 1; i < pos; i++) {
            curr = curr->next;
        }
        curr->name = name;
        curr->nim = nim;
    }

    void hapusDepan() {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void hapusAkhir() {
        Node* curr = head;
        while (curr->next->next != nullptr) {
            curr = curr->next;
        }
        Node* temp = curr->next;
        curr->next = nullptr;
        delete temp;
    }

    void hapusTengah(int pos) {
        Node* curr = head;
        for (int i = 1; i < pos - 1; i++) {
            curr = curr->next;
        }
        Node* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
    }

    void hapusList() {
        Node* curr = head;
        while (head != nullptr) {
            head = head->next;
            delete curr;
            curr = head;
        }
    }

    void tampilkan() {
        Node* curr = head;
        while (curr != nullptr) {
            cout << "Nama: " << curr->name << ", NIM: " << curr->nim << endl;
            curr = curr->next;
        }
    }

private:
    Node* head;
};

void menu() {
    cout << "PROGRAM SINGLE LINKED LIST NON-CIRCULAR" << endl;
    cout << "1. Tambah Depan" << endl;
    cout << "2. Tambah Belakang" << endl;
    cout << "3. Tambah Tengah" << endl;
    cout << "4. Ubah Depan" << endl;
    cout << "5. Ubah Belakang" << endl;
    cout << "6. Ubah Tengah" << endl;
    cout << "7. Hapus Depan" << endl;
    cout << "8. Hapus Belakang" << endl;
    cout << "9. Hapus Tengah " << endl;
    cout << "10. Hapus List" << endl;
    cout << "11. Tampilkan isi data" << endl;
    cout << "0. Keluar" << endl;
    cout << "	" << endl;
    cout << "Masukkan pilihan Anda: ";
}

int main() {
    LinkedList list;
    int choice;
    do {
        menu();
        cin >> choice;

        switch (choice) {
        case 1: {
            string name;
            string nim;
            cout << "Masukkan nama dan NIM mahasiswa: ";
            cin >> name >> nim;
            list.tambahAwal(name, nim);
            break;
        }
        case 2: {
            string name;
            string nim;
            cout << "Masukkan nama dan NIM mahasiswa: ";
            cin >> name >> nim;
            list.tambahAkhir(name, nim);
            break;
        }
        case 3: {
            string name;
            string nim;
            int pos;
            cout << "Masukkan nama dan NIM mahasiswa: ";
            cin >> name >> nim;
            cout << "Masukkan posisi node: ";
            cin >> pos;
            list.tambahTengah(name, nim, pos);
            break;
        }
        case 4: {
            string name;
            string nim;
            cout << "Masukkan nama dan NIM mahasiswa baru: ";
            cin >> name >> nim;
            list.ubahAwal(name, nim);
            break;
        }
        case 5: {
            string name;
            string nim;
            cout << "Masukkan nama dan NIM mahasiswa baru: ";
            cin >> name >> nim;
            list.ubahAkhir(name, nim);
            break;
        }
        case 6: {
            string name;
            string nim;
            int pos;
            cout << "Masukkan nama dan NIM mahasiswa baru: ";
            cin >> name >> nim;
            cout << "Masukkan posisi node: ";
            cin >> pos;
            list.ubahTengah(name, nim, pos);
            break;
        }
        case 7: {
            list.hapusDepan();
            break;
        }
        case 8: {
            list.hapusAkhir();
            break;
        }
        case 9: {
            int pos;
            cout << "Masukkan posisi node: ";
            cin >> pos;
            list.hapusTengah(pos);
            break;
        }
        case 10: {
            list.hapusList();
            break;
        }
        case 11: {
            list.tampilkan();
            break;
        }
        case 0: {
            cout << "Terima kasih telah menggunakan program ini!" << endl;
            break;
        }
        default: {
            cout << "Pilihan tidak valid, silahkan coba lagi." << endl;
            break;
        }
        }

        cout << endl;
    } while (choice != 0);
    return 0;
}