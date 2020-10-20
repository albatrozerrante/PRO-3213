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
	cout << "\nBom, primeiramente, vamos calcular o ganho anual do time. Como o salario mensal e de R$ 9MM, por ano se gasta R$ 108MM com a folha salarial.\n";
	cout << "Entao, considerando tambem o recebimento de R$15MM dos naming rights, a receita de R$200MM e outros custos de R$7MM, o time recebe anualmente\n";
	cout << "R$ 200-108-7+15=100MM.\nTemos que considerar tambem o ganho de 5 em 5 anos de R$30MM com patrocinio para fazer o fluxo de caixa.\nVamos agora trazer todos os ganhos e gastos para o valor presente.\n\n";
	cout << "Valor inicial (divida com o banco): -R$ 550MM\n";
	cout << "Total ganho no periodo de 20 anos pela receita total anual: R$" << ganho_anual(100, n) << "MM\n";
	cout << "Ganho com patrocinio: R$" << patrocinio_5_anos(30, 20) << "MM\n\n";
	cout << "Portanto, o VPL e a soma dos valores acima. -> VPL = R$" << -550+ganho_anual(100, n)+patrocinio_5_anos(30, 20) << "MM\n";
}

signed main(){
	PRECISION;
	solve();
}
