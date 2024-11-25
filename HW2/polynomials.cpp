#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// �w�q Polynomial ���O
class Polynomial {
private:
    struct Term {
        int coefficient; // �Y��
        int exponent;    // ����
        Term(int c, int e) : coefficient(c), exponent(e) {}
    };
    vector<Term> terms; // �x�s�h����������

public:
    Polynomial() = default;
    // �s�W���ب�h����
    void addTerm(int coefficient, int exponent) {
        for (auto& term : terms) {
            if (term.exponent == exponent) {
                term.coefficient += coefficient; // �X�֦P����
                return;
            }
        }
        terms.emplace_back(coefficient, exponent);
    }

    // ������J�B��l >>
    friend istream& operator>>(istream& in, Polynomial& poly) {
        int coefficient, exponent;
        cout << "��J�Y�ƻP���ơ]��J 0 0 �����^�G\n";
        while (true) {
            in >> coefficient >> exponent;
            if (coefficient == 0 && exponent == 0) break;
            poly.addTerm(coefficient, exponent);
        }
        return in;
    }

    // ������X�B��l <<
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

    // ��J�h����
    cin >> p1;

    // ��X�h����
    cout << "�z��J���h�������G " << p1 << endl;

    return 0;
}