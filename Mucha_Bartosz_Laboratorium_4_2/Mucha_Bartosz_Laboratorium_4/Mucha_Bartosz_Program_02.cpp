#include<iostream>
#include "Mucha_Bartosz_Program_02.h"
#include "libFiles.h"
#include "libTables.h"
#include<stack>

int priorytet(char op) {
	if (op == '=') return 0;
	if (op == '<' || op == '>') return 1;
	if (op == '+' || op == '-') return 2;
	if (op == '*' || op == '/' || op == '%') return 3;
	if (op == '^') return 4;
	if (op == '~') return 5;
	return -1;
}

bool czyPrawostronny(char op) {
	return op == '=' || op == '~' || op == '^';
}

bool walidacja(std::string& linia) {
	for (int i = 0; i < linia.length(); i++) {
        char c = linia[i];
        if (!((c >= 'a' && c <= 'z') || c == '(' || c == ')' || c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^' || c == '~' || c == '<' || c == '>' || c == '=')) {
            return false;
        }
    }
    return true;
}

std::string INF2ONP(const std::string& inf) {
    std::string onp = "";
    std::stack<char> s;
    int operandy = 0, operatory = 0;

    for (int i = 0; i < inf.length(); i++) {
        char c = inf[i];
        if (c >= 'a' && c <= 'z') {
            onp += c;
            operandy++;
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                onp += s.top();
                s.pop();
            }
            if (s.empty()) return "error";
            s.pop();
        }
        else {
            if (c != '~') operatory++;
            while (!s.empty() && s.top() != '(') {
                char top_op = s.top();
                int p1 = priorytet(c);
                int p2 = priorytet(top_op);
                if ((!czyPrawostronny(c) && p1 <= p2) || (czyPrawostronny(c) && p1 < p2)) {
                    onp += top_op;
                    s.pop();
                }
                else {
                    break;
                }
            }
            s.push(c);
        }
    }

    while (!s.empty()) {
        if (s.top() == '(' || s.top() == ')') return "error";
        onp += s.top();
        s.pop();
    }
    return onp;
}

struct Wyrazenie {
    std::string wyraz;
    int priorytet_op;
};

std::string ONP2INF(std::string& onp) {
    std::stack<Wyrazenie> s;
    for (char c : onp) {
        if (c >= 'a' && c <= 'z') {
            s.push({ std::string(1, c), 10 });
        }
        else if (c == '~') {
            if (s.empty()) return "error";
            Wyrazenie prawy = s.top(); s.pop();
            int p = priorytet(c);
            std::string str_wyraz = prawy.wyraz;
            if (prawy.priorytet_op < p) {
                str_wyraz = "(" + str_wyraz + ")";
            }
            s.push({ "~" + str_wyraz, p });
        }
        else {
            if (s.size() < 2) return "error";
            Wyrazenie prawy = s.top(); s.pop();
            Wyrazenie lewy = s.top(); s.pop();
            int p = priorytet(c);

            std::string str_lewy = lewy.wyraz;
            std::string str_prawy = prawy.wyraz;

            if (lewy.priorytet_op < p || (lewy.priorytet_op == p && czyPrawostronny(c))) {
                str_lewy = "(" + str_lewy + ")";
            }
            if (prawy.priorytet_op < p || (prawy.priorytet_op == p && c != '~')) {
                str_prawy = "(" + str_prawy + ")";
            }

            s.push({ str_lewy + c + str_prawy, p });
        }
    }
    if (s.size() != 1) return "error";
    return s.top().wyraz;
}





void Program_02() {
	std::ifstream wejscie;
	f_otworzPlikOdczyt(wejscie);
	std::ofstream wyjscie;
	f_otworzPlikZapis(wyjscie);


	int n = f_odczytajJednaLiczbe(wejscie);
	wejscie.ignore();
	std::string linia;

	for (int i = 0; i < n;i++) {
		f_odczytajJednaLinieDoStringa(wejscie, linia);
		t_usunSpacjeZeStringa(linia);
		if (linia.substr(0, 4) == "ONP:") {
			linia.erase(0, 4);
            if (walidacja(linia)) 
                wyjscie << "INF: " << ONP2INF(linia) << std::endl; 
            else
                wyjscie << "INF: error" << std::endl;
		}
		else {
			linia.erase(0, 4);
            if (walidacja(linia))
                wyjscie << "ONP: " << INF2ONP(linia) << std::endl;
            else
                wyjscie << "ONP: error" << std::endl;
		}

	}

	wyjscie.close();
	wejscie.close();
}

