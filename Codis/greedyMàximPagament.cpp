#include <bits/stdc++.h>
using namespace std;

signed main(){
	int nombreProductes; cin >> nombreProductes;

	int dinersTotals; cin >> dinersTotals;

	vector<int> preuProductes(nombreProductes);

	for (int i = 0; i < nombreProductes; i++){
	    cin >> preuProductes[i];
	}

	sort(preuProductes.rbegin(), preuProductes.rend());
	// ordenem els preus de més car a més barat

	int dinersGastats = 0;

	for (int i = 0; i < nombreProductes; i++){
	    if (dinersTotals >= preuProductes[i]){
		// si ens podem permetre el producte,
		// el comprem
		dinersGastats += preuProductes[i];
	    }
	}


	cout << dinersTotals - dinersGastats << endl;
	// dinersTotals - dinersGastats = 
	// diners que ens han quedat 
}
