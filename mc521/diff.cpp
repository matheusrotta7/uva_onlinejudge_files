#include<bits/stdc++.h>

using namespace std;

int main() {

    string pol;
    cin >> pol;
    vector<char> der;

    int ssize = pol.size();
    char state = 'c'; //c for coefficient, d for degree
    //we'll initially be waiting for coefficients
    for (int i = 0; i < ssize; i++) {
        char cur = pol[i];
        if (cur == '-' || cur == '+') {
            der.push_back(cur);
        }
        if (cur <= 57 && cur >= 48) {
            if (state == 'c') {
                if (i+1 == ssize) {
                    der.push_back(cur);
                    goto end;
                }
                else if (pol[i+1] == 'x') {
                    //then cur represents the whole coef.
                    int coef = cur - 48;
                    if (i+2 == ssize) {
                        der.push_back(cur);
                        goto end;
                    }
                    else if (pol[i+2] == '-' || pol[i+2] == '+'){
                        der.push_back(cur);
                        goto end; //because next term is constant
                    }
                    else if (pol[i+2] <= 57 && pol[i+2] >= 48) {
                        //one number or two number degree?
                        if (i+3 == ssize) {
                            //then the pol. ended and we must calculate
                            int exponent = pol[i+2] - 48;
                            int result_coef = coef*exponent;
                            vector<char> aux;
                            int cur;
                            while (result_coef > 0) {
                                cur = result_coef%10;
                                aux.insert(aux.begin(), cur);
                                result_coef /= 10;
                            }
                            int aux_size = aux.size();
                            for (int j = 0; j < aux_size; j++) {
                                der.push_back(aux[j]);
                            }
                            der.push_back('x');
                            if (exponent > 2) {
                                char exp_char = (char) pol[i+2] - 1;
                                der.push_back(exp_char);
                            }
                        }
                        else if (pol[i+3] <= 57 && pol[i+3] >= 48) {
                            int exp1 = pol[i+2] - 48;
                            int exp_2 = pol[i+3] - 48;
                            int exponent = exp1 * 10 + exp_2;

                            int result_coef = coef*exponent;
                            vector<char> aux;
                            int cur;
                            while (result_coef > 0) {
                                cur = result_coef%10;
                                aux.insert(aux.begin(), cur);
                                result_coef /= 10;
                            }
                            int aux_size = aux.size();
                            for (int j = 0; j < aux_size; j++) {
                                der.push_back(aux[j]);
                            }
                            der.push_back('x');
                            if (exponent > 2) {
                                char exp_char = (char) pol[i+2] - 1;
                                der.push_back(exp_char);
                            }
                        }
                        else {
                            int exponent = pol[i+2] - 48;
                            int result_coef = coef*exponent;
                            vector<char> aux;
                            int cur;
                            while (result_coef > 0) {
                                cur = result_coef%10;
                                aux.insert(aux.begin(), cur);
                                result_coef /= 10;
                            }
                            int aux_size = aux.size();
                            for (int j = 0; j < aux_size; j++) {
                                der.push_back(aux[j]);
                            }
                            der.push_back('x');
                            if (exponent > 2) {
                                char exp_char = (char) pol[i+2] - 1;
                                der.push_back(exp_char);
                            }
                        }
                    }
                }
                else if (pol[i+1] <= 57 && pol[i+1] >= 48) {
                    int coef1 = cur - 48;
                    int coef2 = pol[i+1] - 48;
                    int coef = coef1*10 + coef2;

                    if (i+2 == ssize) {
                        der.push_back(cur);
                        goto end;
                    }
                    else if (pol[i+2] == '-' || pol[i+2] == '+'){
                        der.push_back(cur);
                        goto end; //because next term is constant
                    }
                    else if (pol[i+2] <= 57 && pol[i+2] >= 48) {
                        //one number or two number degree?
                        if (i+3 == ssize) {
                            //then the pol. ended and we must calculate
                            int exponent = pol[i+2] - 48;
                            int result_coef = coef*exponent;
                            vector<char> aux;
                            int cur;
                            while (result_coef > 0) {
                                cur = result_coef%10;
                                aux.insert(aux.begin(), cur);
                                result_coef /= 10;
                            }
                            int aux_size = aux.size();
                            for (int j = 0; j < aux_size; j++) {
                                der.push_back(aux[j]);
                            }
                            der.push_back('x');
                            if (exponent > 2) {
                                char exp_char = (char) pol[i+2] - 1;
                                der.push_back(exp_char);
                            }
                        }
                        else if (pol[i+3] <= 57 && pol[i+3] >= 48) {
                            int exp1 = pol[i+2] - 48;
                            int exp_2 = pol[i+3] - 48;
                            int exponent = exp1 * 10 + exp_2;

                            int result_coef = coef*exponent;
                            vector<char> aux;
                            int cur;
                            while (result_coef > 0) {
                                cur = result_coef%10;
                                aux.insert(aux.begin(), cur);
                                result_coef /= 10;
                            }
                            int aux_size = aux.size();
                            for (int j = 0; j < aux_size; j++) {
                                der.push_back(aux[j]);
                            }
                            der.push_back('x');
                            if (exponent > 2) {
                                char exp_char = (char) pol[i+2] - 1;
                                der.push_back(exp_char);
                            }
                        }
                        else {
                            int exponent = pol[i+2] - 48;
                            int result_coef = coef*exponent;
                            vector<char> aux;
                            int cur;
                            while (result_coef > 0) {
                                cur = result_coef%10;
                                aux.insert(aux.begin(), cur);
                                result_coef /= 10;
                            }
                            int aux_size = aux.size();
                            for (int j = 0; j < aux_size; j++) {
                                der.push_back(aux[j]);
                            }
                            der.push_back('x');
                            if (exponent > 2) {
                                char exp_char = (char) pol[i+2] - 1;
                                der.push_back(exp_char);
                            }
                        }
                    }

                }
            }
            else {
                int do_nothing = 0;
            }
        }
    }
    end:
    int der_size = der.size();
    for (int i = 0; i < der_size; i++) {
        cout << der[i] << '\n';
    }

    return 0;
}
