//Created by nhh
#include <iostream>
#include <any>
#include <random>
#include <vector>
#include <fstream>
#include <map>
#define ll long long
#define ac any_cast
#define NAME "bai1"
using namespace std;

//ham sinh ngau nhien
any Rand(const any &l, const any &r) {
    if (l.type() == typeid(int) && r.type() == typeid(int)) {
        int lower = ac<int>(l), upper = ac<int>(r);
        static random_device rd;
        static mt19937 gen(rd());
        uniform_int_distribution<> dis(lower, upper);
        return dis(gen);
    }
    else if (l.type() == typeid(ll) && r.type() == typeid(ll)) {
        ll lower = ac<ll>(l), upper = ac<ll>(r);
        static random_device rd;
        static mt19937 gen(rd());
        uniform_int_distribution<> dis(lower, upper);
        return dis(gen);
    }
    else if (l.type() == typeid(double) && r.type() == typeid(double)) {
        double lower = ac<double>(l), upper = ac<double>(r);
        static random_device rd;
        static mt19937 gen(rd());
        uniform_real_distribution<> dis(lower, upper);
        return dis(gen);
    }
    else if (l.type() == typeid(char) && r.type() == typeid(char)) {
        char lower = ac<char>(l), upper = ac<char>(r);
        static random_device rd;
        static mt19937 gen(rd());
        uniform_int_distribution<> dis(lower, upper);
        return static_cast<char>(dis(gen));
    }
    else
        throw invalid_argument("Kieu du lieu ko hop le");
}

//copy kq file source sang file dest
void copyFile(const string& sourceFile, const string& destFile) {
    ifstream source(sourceFile);
    ofstream dest(destFile);
    dest << source.rdbuf();
    source.close();
    dest.close();
}

//khai bao
bool numofTests, existArray;
int NFile, aTest, bTest, numofInp, arrayType, inpType[105], sizeofArray, hang, cot;
vector<any> aInp(105), bInp(105);
any aArray, bArray, stringlen[105];
string s[105];

//Cac cau hoi de sinh test
void Question() {
    cout << "Ban muon bao nhieu file testcase: "; cin >> NFile;
    cout << "+------------------------------------------------+" << endl;
    cout << "| Hay tra loi cac cau hoi duoi day de sinh input |" << endl;
    cout << "+------------------------------------------------+" << endl;
    cout << "==================================================" << endl;
    cout << "Co test t hay khong? (1: Co; 0: Khong) "; cin >> numofTests;

    //neu ton tai test t
    if (numofTests) {
        cout << endl << "**************************";
        cout << endl << "t nam trong khoang: [a, b]";
        cout << endl << "a = "; cin >> aTest;
        cout << "b = "; cin >> bTest;
        cout << "**************************";
    }
    cout << endl << "==================================================";
    cout << endl << "Moi test co may input co dinh: "; cin >> numofInp;
    cout << "******************************" << endl;
    cout << endl << "------------------------------";
    cout << endl << "| Input co kieu du lieu nao? |";
    cout << endl << "| 1. int                     |";
    cout << endl << "| 2. long long               |";
    cout << endl << "| 3. double                  |";
    cout << endl << "| 4. char                    |";
    cout << endl << "| 5. string                  |";
    cout << endl << "------------------------------" << endl;

    //nhap kieu du lieu cho input
    for (int i = 1; i <= numofInp; i++)
        cin >> inpType[i];
    cout << endl << "******************************";

    for (int i = 1; i <= numofInp; i++) {
        if (inpType[i] == 5)
            continue;
        cout << endl << "Khoang gia tri cua input " << i << ": [a, b]";
        cout << endl << "a = ";
        if (inpType[i] == 1) {
            int value; cin >> value;
            aInp[i] = value;
        }
        if (inpType[i] == 2) {
            ll value; cin >> value;
            aInp[i] = value;
        }
        if (inpType[i] == 3) {
            double value; cin >> value;
            aInp[i] = value;
        }
        if (inpType[i] == 4) {
            char value; cin >> value;
            aInp[i] = value;
        }
        
        cout << "b = ";
        if (inpType[i] == 1) {
            int value; cin >> value;
            bInp[i] = value;
        }
        if (inpType[i] == 2) {
            ll value; cin >> value;
            bInp[i] = value;
        }
        if (inpType[i] == 3) {
            double value; cin >> value;
            bInp[i] = value;
        }
        if (inpType[i] == 4) {
            char value; cin >> value;
            bInp[i] = value;
        }
    }
    cout << "==================================================";

    cout << endl << "Trong input co mang khong? (1: Co; 0: Khong) "; cin >> existArray;

    //neu ton tai mang
    if (existArray) {
        cout << endl << "Hay chon kieu mang:";
        cout << endl << "1. Mang 1 chieu kieu int";
        cout << endl << "2. Mang 1 chieu kieu long long";
        cout << endl << "3. Mang 1 chieu kieu double";
        cout << endl << "4. Mang 1 chieu kieu char";
        cout << endl << "5. Mang 2 chieu kieu int";
        cout << endl << "6. Mang 2 chieu kieu long long";
        cout << endl << "7. Mang 2 chieu kieu double";
        cout << endl << "8. Mang 2 chieu kieu char" << endl;
        cin >> arrayType;
        //mang 2 chieu
        if (arrayType >= 5) {
            cout << "Nhap so hang va so cot cua mang: "; cin >> hang >> cot;
        }
        //mang 1 chieu
        // else {
        //     cout << "Nhap kich thuoc mang: "; cin >> sizeofArray;
        // }
        cout << "Khoang gia tri cac phan tu trong mang: [a, b]";
        cout << endl << "a = ";
        if (arrayType == 1 || arrayType == 5) {
            int value; cin >> value;
            aArray = value;
        }
        if (arrayType == 2 || arrayType == 6) {
            ll value; cin >> value;
            aArray = value;
        }
        if (arrayType == 3 || arrayType == 7) {
            double value; cin >> value;
            aArray = value;
        }
        if (arrayType == 4 || arrayType == 8) {
            char value; cin >> value;
            aArray = value;
        }
        
        cout << "b = ";
        if (arrayType == 1 || arrayType == 5) {
            int value; cin >> value;
            bArray = value;
        }
        if (arrayType == 2 || arrayType == 6) {
            ll value; cin >> value;
            bArray = value;
        }
        if (arrayType == 3 || arrayType == 7) {
            double value; cin >> value;
            bArray = value;
        }
        if (arrayType == 4 || arrayType == 8) {
            char value; cin >> value;
            bArray = value;
        }
    }
}

//Sinh test
void MakeTest(int iTest) {
    ofstream inpFile(NAME ".inp");
    any t;
    vector<any> n(105), a(1005);
    map<int, any> b[hang + 1];

    //sinh so luong test
    if (numofTests) {
        t = Rand(aTest, bTest);
        inpFile << ac<int>(t) << endl;
    }
    else
        t = 1;

    //sinh input co dinh
    for (int k = 1; k <= ac<int>(t); k++) {
        for (int i = 1; i <= numofInp; i++) {
            if (inpType[i] == 1) {
                n[i] = Rand(ac<int>(aInp[i]), ac<int>(bInp[i]));
                inpFile << ac<int>(n[i]) << " ";
            }
            if (inpType[i] == 2) {
                n[i] = Rand(ac<ll>(aInp[i]), ac<ll>(bInp[i]));
                inpFile << ac<ll>(n[i]) << " ";
            }
            if (inpType[i] == 3) {
                n[i] = Rand(ac<double>(aInp[i]), ac<double>(bInp[i]));
                inpFile << ac<double>(n[i]) << " ";
            }
            if (inpType[i] == 4) {
                n[i] = Rand(ac<char>(aInp[i]), ac<char>(bInp[i]));
                inpFile << ac<char>(n[i]) << " ";
            }
            if (inpType[i] == 5) {
                stringlen[i] = Rand(ac<int>(1), ac<int>(100));
                int k = ac<int>(stringlen[i]);
                for (int j = 0; j < k; j++) {
                    any value = Rand(ac<char>('a'), ac<char>('z'));
                    s[i] += ac<char>(value);
                    inpFile << ac<char>(value);
                }
                inpFile << " ";
            }
        }
        inpFile << endl;
        
        //sinh mang
        if (existArray) {
            //mang 2 chieu
            if (arrayType >= 5) {
                for (int i = 1; i <= hang; i++) {
                    for (int j = 1; j <= cot; j++) {
                        if (arrayType == 5) {
                            b[i][j] = Rand(ac<int>(aArray), ac<int>(bArray));
                            inpFile << ac<int>(b[i][j]) << " ";
                        }
                        if (arrayType == 6) {
                            b[i][j] = Rand(ac<ll>(aArray), ac<ll>(bArray));
                            inpFile << ac<ll>(b[i][j]) << " ";
                        }
                        if (arrayType == 7) {
                            b[i][j] = Rand(ac<double>(aArray), ac<double>(bArray));
                            inpFile << ac<double>(b[i][j]) << " ";
                        }
                        if (arrayType == 8) {
                            b[i][j] = Rand(ac<char>(aArray), ac<char>(bArray));
                            inpFile << ac<char>(b[i][j]) << " ";
                        }
                    }
                    inpFile << endl;
                }
            }
            //mang 1 chieu
            else {
                for (int i = 1; i <= ac<int>(n[1]); i++) {
                    if (arrayType == 1) {
                        a[i] = Rand(ac<int>(aArray), ac<int>(bArray));
                        inpFile << ac<int>(a[i]) << " ";
                    }
                    if (arrayType == 2) {
                        a[i] = Rand(ac<ll>(aArray), ac<ll>(bArray));
                        inpFile << ac<ll>(a[i]) << " ";
                    }
                    if (arrayType == 3) {
                        a[i] = Rand(ac<double>(aArray), ac<double>(bArray));
                        inpFile << ac<double>(a[i]) << " ";
                    }
                    if (arrayType == 4) {
                        a[i] = Rand(ac<char>(aArray), ac<char>(bArray));
                        inpFile << ac<char>(a[i]) << " ";
                    }
                }
                inpFile << endl;
            }
        }
    }
    inpFile.close();
    copyFile(NAME ".inp", to_string(iTest) + ".inp");
}

int main() {
    srand(time(NULL));
    Question();
    for (int i = 1; i <= NFile; i++) {
        MakeTest(i);
        //ko co freopen
        system(NAME "_trau.exe <" NAME ".inp> " NAME ".ans");
        system(NAME ".exe <" NAME ".inp> " NAME ".out");

        copyFile(NAME ".out", to_string(i) + ".out");

        //so sanh kq 2 file out va ans
        if (system("fc " NAME ".out " NAME ".ans") != 0) {
            cout << "Test " << i << ": WRONG\n";
            return 0;
        }
        cout << "Test " << i << ": CORRECT\n";
    }
}