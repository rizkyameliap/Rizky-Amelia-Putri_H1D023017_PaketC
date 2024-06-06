#include <iostream>
#define MAXQUEUE 10
using namespace std;

typedef struct {
    int count;
    int front;
    int rear;
    int item[MAXQUEUE];
} QUEUE;

QUEUE antrean;

void inisialisasi(QUEUE *Q) {
    Q->count = 0;
    Q->front = 0;
    Q->rear = -1;
}

bool isEmpty(QUEUE *Q) {
    return Q->count == 0;
}

bool isFull(QUEUE *Q) {
    return Q->count == MAXQUEUE;
}

void tampilkanAntrian(QUEUE *Q);

void insert (QUEUE *Q, int data) {
    if (isFull(Q)) {
        cout << "Antrian penuh, tidak bisa menambahkan " << data << endl;
    } else {
        Q->rear = (Q->rear + 1) % MAXQUEUE;
        Q->item[Q->rear] = data;
        Q->count++;
        cout << "Masukan " << data << endl;
        tampilkanAntrian(Q);
    }
}

void hapus (QUEUE *Q) {
    if (isEmpty(Q)) {
        cout << "Antrian kosong, tidak bisa menghapus elemen" << endl;
    } else {
        int data = Q->item[Q->front];
        Q->front = (Q->front + 1) % MAXQUEUE;
        Q->count--;
        cout << "Menghapus " << data << " dari antrian" << endl;
        tampilkanAntrian(Q);
    }
}

void tampilkanAntrian(QUEUE *Q) {
    if (isEmpty(Q)) {
        cout << "Antrian kosong" << endl;
    } else {
        cout << "Isi antrian: ";
        for (int i = 0; i < Q->count; i++) {
            int index = (Q->front + i) % MAXQUEUE;
            cout << Q->item[index] << " ";
        }
        cout << endl;
    }
}

int main() {
    inisialisasi(&antrean);

    insert(&antrean, 17);
    insert(&antrean, 45);
    insert(&antrean, 77);
    hapus(&antrean);
    insert(&antrean, 15);

    return 0;
}