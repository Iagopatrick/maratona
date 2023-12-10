#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'countSort' function below.
 *
 * The function accepts 2D_STRING_ARRAY arr as parameter.
 */

void countSort(vector<vector<string>> arr) {
    int maiorN = -1, n = arr.size(); //quero ver qual o maior numero que o vetor auxiliar c poderá ter
    int c[100];
    vector<vector<string>> b, novoA;
    for(int i = 0; i < n; i++){ //Fazendo a contagem
        int index = int(arr[i][0][0]) - 49;     
        if(i < n/2){
            string newS = arr[i][0] + "-";
            b[i].push_back(newS);
            c[index]++;
            continue;
        }
        b[i].push_back(arr[i][0]);
        c[index]++;
        
    }
    cout << "Chefguei aqui";
    for(int i = 0; i < 99; i++){
        c[i+1] += c[i];
    }
    for(int i = n-1; i >= 0; i--){ //Colocando no vetor novoA de forma ordenada
        novoA[c[int(b[i][0][0])]].push_back(b[i][0]);
    }
    for(int i = 0; i < novoA.size(); i++){
        for(int j = 0; j < novoA[i].size(); j++){
            cout << novoA[i][j];
        }
        cout << " ";
    }
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<string>> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i].resize(2);

        string arr_row_temp_temp;
        getline(cin, arr_row_temp_temp);

        vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            string arr_row_item = arr_row_temp[j];

            arr[i][j] = arr_row_item;
        }
    }

    countSort(arr);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
