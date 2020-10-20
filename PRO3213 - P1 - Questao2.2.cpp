#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define infinite 9123456789
#define PRECISION cout.precision(3); cout.setf(ios::fixed);

double n, i;

double exp(double x, double e){
	//Essa funcao serve somente para exponencial (retorna x^e)
	double resp=1;
	for(int i=1; i<=e; i++) resp*=x;
	return resp;
}

double ganho_anual(double valor, double tempo){
	//Essa funcao transforma o ganho anual total para o valor presente
	double taxa=1+i/100, ans=0;
	for(int j=1; j<=tempo; j++){
		double div=exp(taxa, j);
		ans+=valor/div;
	}
	return ans;
}

double patrocinio_5_anos(double valor, double tempo){
	//Essa funcao transforma o valor de parcelas recebida de 5 em 5 anos em valor presente
	double taxa=1+i/100, ans=0;
	for(int j=0; j<tempo; j+=5){
		double div=exp(taxa, j);
		ans+=valor/div;
	}
	return ans;
}

void solve(){
	cout << "Tempo analisado: ";
	cin >> n;
	cout << "\nCusto de oportunidade(em porcentagem): ";
	cin >> i; // n e o periodo e i o custo de oportunidade em porcentagem
	cout << "\nOs calculos levados em conta foram exatamente o do item a, porem com um adicional de R$4,84MM por mes, o que da R$58MM por ano a mais.\n";
	cout << "Total ganho no periodo de 20 anos pela receita total anual: R$" << ganho_anual(158, n) << "MM\n";
	cout << "Ganho com patrocinio: R$" << patrocinio_5_anos(30, 20) << "MM\n\n";
	cout << "Portanto, o VPL e a soma dos valores acima. -> VPL = R$" << -550+ganho_anual(158, n)+patrocinio_5_anos(30, 20) << "MM\n";
}

signed main(){
	PRECISION;
	solve();
}
