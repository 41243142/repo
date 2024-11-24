#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// 定義 Polynomial 類別
class Polynomial {
private:
    struct Term {
        int coefficient; // 係數
        int exponent;    // 指數
        Term(int c, int e) : coefficient(c), exponent(e) {}
    };
    vector<Term> terms; // 儲存多項式的項目

public:
    Polynomial() = default;
    // 新增項目到多項式
    void addTerm(int coefficient, int exponent) {
        for (auto& term : terms) {
            if (term.exponent == exponent) {
                term.coefficient += coefficient; // 合併同類項
                return;
            }
        }
        terms.emplace_back(coefficient, exponent);
    }

    // 重載輸入運算子 >>
    friend istream& operator>>(istream& in, Polynomial& poly) {
        int coefficient, exponent;
        cout << "輸入係數與指數（輸入 0 0 結束）：\n";
        while (true) {
            in >> coefficient >> exponent;
            if (coefficient == 0 && exponent == 0) break;
            poly.addTerm(coefficient, exponent);
        }
        return in;
    }

    // 重載輸出運算子 <<
    friend ostream& operator<<(ostream& out, const Polynomial& poly) {
        if (poly.terms.empty()) {
            out << "0";
            return out;
        }

        bool firstTerm = true;
        for (const auto& term : poly.terms) {
            if (term.coefficient == 0) continue;
            if (!firstTerm && term.coefficient > 0) out << " + ";
            if (term.coefficient < 0) out << " - ";
            if (abs(term.coefficient) != 1 || term.exponent == 0)
                out << abs(term.coefficient);
            if (term.exponent > 0) out << "x";
            if (term.exponent > 1) out << "^" << term.exponent;
            firstTerm = false;
        }
        return out;
    }
};

int main() {
    Polynomial p1;

    // 輸入多項式
    cin >> p1;

    // 輸出多項式
    cout << "您輸入的多項式為： " << p1 << endl;

    return 0;
}