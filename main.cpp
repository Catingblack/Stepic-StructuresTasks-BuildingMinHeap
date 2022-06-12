#include <iostream>
#include <random>


using namespace std;


void readMass(int* Arr, int n) {
    for(int i = 0; i < n; i++) {
        cin >> Arr[i];
    }
}

void readMassAuto(int* Arr, int n) {

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1,100);

    for(int i = 0; i <n; i++) {
        Arr[i] = dist(gen);
        cout << Arr[i] << " ";
    }
    cout << endl;
}

void printMass(int* Arr, int n) {

    cout << endl;
    for(int i = 0; i < n; i++) {
        cout << Arr[i] << " ";
    }
}



int LCh(int i) {
    return (2 * i) + 1;
}

int RCh(int i) {
    return (2 * i) + 2;
}

void Turn(int* Arr, int i, int j) {
    int x;
    x = Arr[i];
    Arr[i] = Arr[j];
    Arr[j] = x;
}

int SiftDown(int* Arr, int* outArr, int n, int i, int m) {

    int j;

    while(i < n/2) {
        j = i;

        if(Arr[LCh(i)] < Arr[i] and LCh(i) < n) {
            j = LCh(i);
        }

        if( (Arr[RCh(i)] < Arr[j]) and RCh(i) < n ) {
            j = RCh(i);
        }

        if(j == i) {
            break;
        }

        Turn(Arr, i, j);
        outArr[2 * m] = i;
        outArr[2 * m + 1] = j;
        i = j;
        m = m + 1;
    }
    return m;
}

void BuildHeap(int* Arr, int n) {

    int m = 0;
    int outArr[n*n];

    for(int i = (n/2 - 1); i >= 0; i--) {
        m = SiftDown(Arr, outArr, n, i, m);
    }

    cout << endl;
    cout << "m: " << m << endl;
    for(int i = 0; i < m; i++) {
        cout << outArr[2*i] << " " << outArr[2*i+1] << endl;
    }

}


int main()
{
    int n;
    int* Arr;

    cin >> n;

    Arr = new int[n];

    readMass(Arr, n);

    BuildHeap(Arr, n);

    printMass(Arr, n);

    delete [] Arr;

    return 0;
}
