#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void generatepermutaciones(int chocolate, int vanilla, string returnValue, vector<string>& permutaciones) {
    if (chocolate == 0 && vanilla == 0) {
        permutaciones.push_back(returnValue);
        return;
    }
    if (chocolate > 0) generatepermutaciones(chocolate - 1, vanilla, returnValue + "C", permutaciones);
    if (vanilla > 0) generatepermutaciones(chocolate, vanilla - 1, returnValue + "V", permutaciones);
}

void resuelveCaso(){
        int chocolate, vanilla;
        cin >> chocolate >> vanilla;
        vector<string> permutaciones;
        generatepermutaciones(chocolate, vanilla, "", permutaciones);
        sort(permutaciones.begin(), permutaciones.end());
        for (int j = 0; j < permutaciones.size(); ++j) {
            cout << permutaciones[j];
            if (j < permutaciones.size() - 1)
                cout << " ";
        }
        cout << endl;
}

int main() {
    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) resuelveCaso();
    return 0;
}
