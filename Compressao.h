#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> codificacao(string s1)
{
    cout << "Codificação:"<<endl;
    unordered_map<string, int> tabela;
    for (int i = 0; i <= 255; i++) {
        string ch = "";
        ch += char(i);
        tabela[ch] = i;
    }
  
    string p = "", c = "";
    p += s1[0];
    int codigo = 256;
    vector<int> codigoSaida;
    cout << "String\tSaida_Code\tAddition" << endl;
    for (int i = 0; i < s1.length(); i++) {
        if (i != s1.length() - 1)
            c += s1[i + 1];
        if (tabela.find(p + c) != tabela.end()) {
            p = p + c;
        }
        else {
            cout << p << "\t" << tabela[p] << "\t\t"
                 << p + c << "\t" << codigo << endl;
            codigoSaida.push_back(tabela[p]);
            tabela[p + c] = codigo;
            codigo++;
            p = c;
        }
        c = "";
    }
    cout << p << "\t" << tabela[p] << endl;
    codigoSaida.push_back(tabela[p]);
    return codigoSaida;
}
  
void decodificacao(vector<int> op)
{
    cout << endl <<"Decodificacao" << endl;
    unordered_map<int, string> tabela;
    for (int i = 0; i <= 255; i++) {
        string ch = "";
        ch += char(i);
        tabela[i] = ch;
    }
    int aux = op[0], n;
    string s = tabela[aux];
    string c = "";
    c += s[0];
    cout << s;
    int codigo = 256;
    for (int i = 0; i < op.size() - 1; i++) {
        n = op[i + 1];
        if (tabela.find(n) == tabela.end()) {
            s = tabela[aux];
            s = s + c;
        }
        else {
            s = tabela[n];
        }
        cout << s;
        c = "";
        c += s[0];
        tabela[codigo] = tabela[aux] + c;
        codigo++;
        aux = n;
    }
}

