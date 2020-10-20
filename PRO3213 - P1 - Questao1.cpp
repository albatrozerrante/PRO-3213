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

double custo_anual(double valor, double tempo){
	//Essa funcao transforma o custo anual total para o valor presente
	double taxa=1+i/100, ans=0;
	for(int j=1; j<=tempo; j++){
		double div=exp(taxa, j);
		ans+=valor/div;
	}
	return ans;
}

double custo_5_anos(double valor, double tempo){
	//Essa funcao transforma o valor de parcelas cobradas de 5 em 5 anos em valor presente
	double taxa=1+i/100, ans=0;
	for(int j=5; j<tempo; j+=5){
		double div=exp(taxa, j);
		ans+=valor/div;
	}
	return ans;
}

double valor_residual(double valor, double tempo){
	//Essa funcao transforma o valor residual no futuro em valor presente
	double taxa=1+i/100;
	double div=exp(taxa, tempo);
	return valor/div;
}

void solve(){
	cout << "Tempo analisado: ";
	cin >> n;
	cout << "\nCusto de oportunidade(em porcentagem): ";
	cin >> i; // n e o periodo e i o custo de oportunidade em porcentagem
	cout << "Vamos calcular o valor presente das maquinas considerando cada um dos parametros e um ciclo de 20 anos.\n\n-RONCA:\n";
	
	cout << " Valor de compra: -150000 reais\n";
	cout << " Custos anuais (energia+manutencao+mao-de-obra): " << -custo_anual(65000, n) << " reais\n";
	cout << " Custo das reformas: " << -custo_5_anos(30000, n) << " reais\n";
	cout << " Valor residual: " << valor_residual(25000, n) << " reais\n";
	double valor_RONCA=-custo_anual(65000, n)-custo_5_anos(30000, n)+valor_residual(25000, n)-150000;
	cout << " Valor presente total da RONCA: " << valor_RONCA << " reais\n";
	
	
	cout << "\n-BRONCA:\n *Unidade Basica:\n";
	cout << "  Valor de compra: -250000 reais\n";
	cout << "  Custos anuais (energia+manutencao+operacao): " << -custo_anual(90000, n) << " reais\n";
	cout << "  Custo das reformas " << -custo_5_anos(20000, n) << " reais\n";
	cout << "  Valor residual: " << valor_residual(40000, n) << " reais\n";
	double valor_unidade_basica=-custo_anual(90000, n)-custo_5_anos(20000, n)+valor_residual(40000, n)-250000;
	cout << "  Valor presente total da Unidade basica: " << valor_unidade_basica << " reais\n\n";
	
	cout << " *Unidade de contole:\n";
	cout << "  OBS: Estamos considerando que a maquina foi comprada 2 vezes no periodo de 20 anos\n";
	cout << "  Valor de compra: " << -125000-valor_residual(125000, n/2) << " reais\n";
	cout << "  Custos anuais (energia+manutencao): " << -custo_anual(27500, n) << " reais\n";
	cout << "  Valor residual: " << valor_residual(25000, 10)+valor_residual(25000, 20) << " reais\n";
	double valor_unidade_controle= valor_residual(25000, 10)+valor_residual(25000, 20)-custo_anual(27500, n)-125000-valor_residual(125000, n/2);
	cout << "  Valor presente total da Unidade de Controle: " << valor_unidade_controle << " reais\n\n";
	cout << " Valor presente total da BRONCA: " << valor_unidade_controle+valor_unidade_basica << " reais\n\n";
	
	cout << "DIFERENCA DE IMPOSTO DE RENDA: " << custo_anual(1500, n) << " reais\n\n";
	
	cout << "Ou seja, o valor presente da RONCA e de -737 mil reais e o valor presente da BRONCA e de -1.42 milhoes de reais.\nPortanto, como a RONCA e consideravelmente mais barata que a BRONCA, mesmo considerando imposto de\nrenda, vale mais a pena comprar a maquina RONCA.";
}

signed main(){
	PRECISION;
	solve();
}
